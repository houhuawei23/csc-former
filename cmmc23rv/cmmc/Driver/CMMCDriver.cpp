#define NDEBUG
/*
    SPDX-License-Identifier: Apache-2.0
    Copyright 2023 CMMC Authors
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
        http://www.apache.org/licenses/LICENSE-2.0
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

// Mini driver for online judge

#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <type_traits>
#include <variant>
#include "../../cmmc/CodeGen/Lowering.hpp"
#include "../../cmmc/CodeGen/Target.hpp"
#include "../../cmmc/ExecutionEngine/Interpreter.hpp"
#include "../../cmmc/Frontend/Driver.hpp"
#include "../../cmmc/IR/ConstantValue.hpp"
#include "../../cmmc/IR/Module.hpp"
#include "../../cmmc/Support/Diagnostics.hpp"
#include "../../cmmc/Support/Options.hpp"
#include "../../cmmc/Support/Profiler.hpp"
#include "../../cmmc/Support/StaticReflection.hpp"
#include "../../cmmc/Support/Tune.hpp"
#include "../../cmmc/Transforms/TransformPass.hpp"

using namespace cmmc;

CMMC_NAMESPACE_BEGIN

static_assert(!Config::debug);

Flag strictMode;               // NOLINT
IntegerOpt optimizationLevel;  // NOLINT
extern Flag hideSymbol;
extern Flag enableAggressive;
namespace mir {
extern StringOpt targetName;  // NOLINT
}

std::optional<int> runMain(Module&, SimulationIOContext&, const std::string&) {
    return std::nullopt;
}
void verifyModuleExec(Module&, AnalysisPassManager&, const std::string_view&) {}

CMMC_NAMESPACE_END

static int runIRPipeline(Module& module,
                         OptimizationLevel optLevel,
                         const std::string& outputPath) {
    AnalysisPassManager analysis{&module};
    const auto& target = module.getTarget();
    target.transformModuleBeforeOpt(module, analysis);
    analysis.invalidateModule();

    const auto opt = PassManager<Module>::get(optLevel);
    opt->run(module, analysis);

    std::ofstream out{outputPath};
    const auto machineModule =
        mir::lowerToMachineModule(module, analysis, optLevel);  //
    target.emitAssembly(*machineModule, out, mir::RuntimeType::SysYRuntime);

    return EXIT_SUCCESS;
}

int main(int argc, char** argv) {
    strictMode.handle("false");
    hideSymbol.handle("true");

#include "../../cmmc/Driver/Target.hpp"

    if (argc != 5 && argc != 6) {
        reportInfo() << "CMMC " CMMC_VERSION << std::endl;
        reportInfo() << "Build time: " __TIME__ " " __DATE__ << std::endl;
        return EXIT_SUCCESS;
    }

    if (!(argv[1] == "-S"sv && argv[2] == "-o"sv)) {
        std::cerr << "Unexpected arguments for the mini driver"sv << std::endl;
        return EXIT_FAILURE;
    }

    /* add by hhw*/
    OptimizationLevel opt;
    if (argv[5] == "-O0"sv) {
        opt = OptimizationLevel::O0;
    } else if (argv[5] == "-O1"sv) {
        opt = OptimizationLevel::O1;

    } else if (argv[5] == "-O2"sv) {
        opt = OptimizationLevel::O2;
    } else if (argv[5] == "-O3"sv) {
        opt = OptimizationLevel::O3;
    } else {
        std::cerr << "Unexpected optimization level: "sv << argv[5]
                  << std::endl;
    }
    /* add end */

    try {
        std::string path = argv[4];
        std::string outputPath = argv[3];

        if (opt == OptimizationLevel::O3)
            enableAggressive.handle("true");
        // only enable parallel for performance testcases

        Module module;
        const auto target = mir::TargetRegistry::get().selectTarget();
        module.setTarget(target.get());

        {
            Driver driver{path, FrontEndLang::SysY, false, false};
            driver.emit(module);
        }
        module.dump(std::cout);
        CMMC_UNUSED(opt);
        initTune(path, mir::targetName.get());
        return runIRPipeline(module, opt, outputPath);
    } catch (const std::exception& ex) {
        std::cerr << "Unexpected exception: "sv << ex.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error"sv << std::endl;
    }
    return EXIT_FAILURE;
}
