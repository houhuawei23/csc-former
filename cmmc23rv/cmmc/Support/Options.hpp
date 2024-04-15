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
#include "../../cmmc/Config.hpp"
#include <cstdint>
#include <getopt.h>
#include <ostream>
#include <string>
#include <string_view>

CMMC_NAMESPACE_BEGIN

class OptionBase {
    const char* mName;
    char mShortName;
    const char* mDesc;
    enum class ArgType { Flag = no_argument, Required = required_argument, Optional = optional_argument } mType;

public:
    OptionBase();
    virtual ~OptionBase() = default;
    OptionBase(const OptionBase&) = delete;
    OptionBase& operator=(const OptionBase&) = delete;
    OptionBase(OptionBase&&) = delete;
    OptionBase& operator=(OptionBase&&) = delete;

    OptionBase& setName(const char* name, char shortName = '\0');
    OptionBase& hasDefault();
    OptionBase& requireArg();
    OptionBase& setDesc(const char* desc);
    virtual void printDefault(std::ostream& out) const = 0;
    virtual void handle(const char* str) = 0;
    [[nodiscard]] option getOption() const;
    [[nodiscard]] char getShortName() const noexcept {
        return mShortName;
    }
    [[nodiscard]] std::string_view getName() const noexcept {
        return mName;
    }
    void printHelp();
};

class Flag final : public OptionBase {
    bool mFlag;

public:
    Flag();
    Flag& withDefault(bool flag);
    void printDefault(std::ostream& out) const override;
    void handle(const char* str) override;
    [[nodiscard]] bool get() const noexcept {
        return mFlag;
    }
};

class StringOpt final : public OptionBase {
    std::string mStr;
    bool mHasValue = false;

public:
    StringOpt();
    StringOpt& withDefault(std::string value);
    void printDefault(std::ostream& out) const override;
    void handle(const char* str) override;
    [[nodiscard]] const std::string& get(bool required = true) const noexcept;
};

class IntegerOpt final : public OptionBase {
    uint32_t mValue = 0;
    bool mHasValue = false;

public:
    IntegerOpt();
    IntegerOpt& withDefault(uint32_t value);
    void printDefault(std::ostream& out) const override;
    void handle(const char* str) override;
    [[nodiscard]] uint32_t get(bool required = true) const noexcept;
};

int parseCommands(int argc, char** argv);
void printHelpInfo();

#define CMMC_INIT_OPTIONS_BEGIN [[maybe_unused]] static const int __placeholder = ([] {
#define CMMC_INIT_OPTIONS_END \
    }                         \
    (), 0);

CMMC_NAMESPACE_END
