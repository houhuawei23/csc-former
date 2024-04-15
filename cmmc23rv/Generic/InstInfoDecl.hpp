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
// Automatically generated file, do not edit!

#pragma once
#include "../cmmc/CodeGen/MIR.hpp"
#include "../cmmc/CodeGen/Target.hpp"

#define CMMC_TARGET_NAMESPACE_BEGIN namespace cmmc::mir::Generic {
#define CMMC_TARGET_NAMESPACE_END }

CMMC_TARGET_NAMESPACE_BEGIN
enum GenericInst {
    GenericInstBegin = ISASpecificBegin,
    Jump,
    Branch,
    Unreachable,
    Load,
    Store,
    Add,
    Sub,
    Mul,
    UDiv,
    URem,
    And,
    Or,
    Xor,
    Shl,
    LShr,
    AShr,
    SDiv,
    SRem,
    SMin,
    SMax,
    Neg,
    Abs,
    FAdd,
    FSub,
    FMul,
    FDiv,
    FNeg,
    FAbs,
    FFma,
    ICmp,
    FCmp,
    SExt,
    ZExt,
    Trunc,
    F2U,
    F2S,
    U2F,
    S2F,
    FCast,
    Copy,
    Select,
    LoadGlobalAddress,
    LoadImm,
    LoadStackObjectAddr,
    CopyFromReg,
    CopyToReg,
    LoadImmToReg,
    LoadRegFromStack,
    StoreRegToStack,
    GenericInstEnd
};

const TargetInstInfo& getGenericInstInfo();

CMMC_TARGET_NAMESPACE_END