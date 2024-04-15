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

#pragma once
#include "../../cmmc/IR/ConstantValue.hpp"
#include "../../cmmc/IR/Function.hpp"
#include <cstdio>
#include <memory>
#include <variant>

CMMC_NAMESPACE_BEGIN

enum class SimulationFailReason {
    ExceedMemoryLimit,        //
    ExceedTimeLimit,          //
    ExceedMaxRecursiveDepth,  //
    MemoryError,              //
    DividedByZero,            //
    UnknownError,             //
    UnsupportedTarget,        //
    UnsupportedHost,          //
    Undefined,                //
    Unreachable,              //
    EnterNoreturnFunc,        //
    NoEntry,                  //
    RuntimeError
};

// NOTE: don't use std::iostream since it doesn't support hexfloat parsing in libc++

class InputStream final {
    FILE* mFile;

public:
    InputStream(const std::string& path);
    InputStream(const InputStream&) = delete;
    InputStream(InputStream&&) = delete;
    InputStream& operator=(const InputStream&) = delete;
    InputStream& operator=(InputStream&&) = delete;
    ~InputStream();

    template <typename... T>
    void get(const char* fmt, T&... args) {
        int ret = std::fscanf(mFile, fmt, &args...);
        CMMC_UNUSED(ret);
    }
};

class OutputStream final {
    FILE* mFile;

public:
    OutputStream(const std::string& path);
    OutputStream(const OutputStream&) = delete;
    OutputStream(OutputStream&&) = delete;
    OutputStream& operator=(const OutputStream&) = delete;
    OutputStream& operator=(OutputStream&&) = delete;
    ~OutputStream();

    template <typename... T>
    void put(const char* fmt, T... args) {
        int ret = std::fprintf(mFile, fmt, args...);
        CMMC_UNUSED(ret);
    }

    void putch(int ch) {
        int ret = std::fputc(ch, mFile);
        CMMC_UNUSED(ret);
    }
};

struct SimulationIOContext final {
    InputStream& stdinStream;
    OutputStream& stdoutStream;
};

class Interpreter final {
    size_t mTimeBudget,      // in ns
        mMemBudget,          // in bytes
        mMaxRecursiveDepth;  //
    bool mDumpStatistics;

public:
    Interpreter(size_t timeBudget, size_t memBudget, size_t maxRecursiveDepth, bool dumpStatistics);
    std::variant<ConstantValue*, SimulationFailReason>
    execute(Module& module, Function& func, const std::vector<ConstantValue*>& arguments, SimulationIOContext* ioCtx) const;
};

CMMC_NAMESPACE_END
