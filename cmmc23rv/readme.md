


run

```bash
./cmake.sh
./compiler -S -o ./test.s ./test.c -O0
./compiler -S -o ./test.s ./test.c -O1

```

debug: launch.json


项目结构：
- cmmc: main src dir
  - Driver: compiler driver, CMMCDriver.cpp is the main driver file
  - Frontend
  - IR
  - ExecutionEngine: virtual machine for ir, to verify the correctness of ir
  - Analysis
  - Transforms
  - CodeGen: mir, lowering
  - Target: target specific cpp files
  - Support:
- ARM/RISCV/Generic: auto generated code for target platform
  - Generic: generic target
- Spl/SysY: auto generated code for specific language
  - Spl: Standard Program Library
  - SysY: subset of C
