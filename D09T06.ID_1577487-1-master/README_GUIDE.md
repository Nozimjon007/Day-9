# Beginner Guide: How to Complete and Verify Every Quest

This guide is based on:
- `README.md` quest requirements.
- `materials/from_developers.txt` advice.
- `materials/instructions_for_testing.md` auto-test expectations.
- `materials/7 principles of structural programming.md` coding principles.

## 0) First setup (do this once)

1. Go to project root:
   ```bash
   cd D09T06.ID_1577487-1-master
   ```
2. Create and switch to `develop` branch:
   ```bash
   git checkout -b develop
   ```
3. Work only inside `src/`.
4. Compile with strict flags (`-Wall -Wextra -Werror`) and avoid global variables.

---

## 1) Quest 1 — Modules (`data_module`)

### What to implement
- Fix `src/data_module/data_module_entry.c`:
  - read `n`, allocate memory, read array, normalize, print output.
- Implement data library functions used by module:
  - `src/data_libs/data_io.c`
  - `src/data_libs/data_stat.c`
- Fix normalization in `src/data_module/data_process.c`.

### Run & check
```bash
gcc -Wall -Wextra -Werror -std=c11 \
  src/data_module/data_module_entry.c \
  src/data_module/data_process.c \
  src/data_libs/data_io.c \
  src/data_libs/data_stat.c -lm -o build/quest1
printf "5\n1 2 3 4 5\n" | ./build/quest1
```
Expected output:
```text
0.00 0.25 0.50 0.75 1.00
```

---

## 2) Quest 2 — Modules II (`yet_another_decision_module`)

### What to implement
- Add proper header/prototypes in `decision.h`.
- Ensure `make_decision()` checks:
  - three-sigma rule (already in logic),
  - mean value `>= 0.618`.
- Fix entry file to read data and print `YES`/`NO`.

### Run & check
```bash
gcc -Wall -Wextra -Werror -std=c11 \
  src/yet_another_decision_module/yet_another_decision_module_entry.c \
  src/yet_another_decision_module/decision.c \
  src/data_libs/data_io.c \
  src/data_libs/data_stat.c -lm -o build/quest2
printf "4\n1 2 3 4\n" | ./build/quest2
```
Expected output:
```text
YES
```

---

## 3) Quest 3 — Makefile (`main_executable_module`)

### What to implement
- Create `src/main_executable_module/Makefile` with targets:
  - `all`, `clean`, `rebuild`.
- Build executable to `build/Quest_3`.

### Run & check
```bash
cd src/main_executable_module
make all
printf "5\n1 2 3 4 5\n" | ../../build/Quest_3
```

---

## 4) Bonus Quest 4 — Static library

### What to implement
- Make target `data_stat.a` for static library.
- Make target `build_with_static` outputting `build/Quest_4`.

### Run & check
```bash
cd src/main_executable_module
make build_with_static
printf "5\n1 2 3 4 5\n" | ../../build/Quest_4
```

---

## 5) Bonus Quest 5 — Dynamic library

### What to implement
- Make target `data_process.so` in `build/`.
- Make target `build_with_dynamic` outputting `build/Quest_5`.
- Add compile-time macro logic in `main_executable_module.c` (for dynamic mode).

### Run & check
```bash
cd src/main_executable_module
make build_with_dynamic
printf "5\n1 2 3 4 5\n" | ../../build/Quest_5
```

---

## 6) Quests 6–13 (`s21_string`) — practical roadmap

`src/s21_string` is not present yet in this repository, so create it when you start Chapter VII.

### Recommended order
1. Create:
   - `s21_string.h`
   - `s21_string.c`
   - `s21_string_test.c`
   - `Makefile`
2. Implement step by step in this order:
   - Q6: `s21_strlen` (+ test)
   - Q7: `s21_strcmp` (+ test)
   - Q8: `s21_strcpy`
   - Q9: `s21_strcat`
   - Q10: `s21_strchr`
   - Q11: `s21_strstr`
   - Q12: full tests for all above
   - Q13: `text_processor.c` (`-w` mode)
3. Do not use `string.h`.
4. Allowed libs only: `stdlib.h`, `stdio.h`.

---

## 7) How to verify before push (very important)

From project root:

1. **Style check** (from testing instructions):
   ```bash
   clang-format -n src/data_module/data_module_entry.c
   clang-format -n src/data_module/data_process.c
   clang-format -n src/data_libs/data_io.c
   clang-format -n src/data_libs/data_stat.c
   clang-format -n src/yet_another_decision_module/decision.c
   clang-format -n src/yet_another_decision_module/yet_another_decision_module_entry.c
   clang-format -n src/main_executable_module/main_executable_module.c
   ```
2. **Build checks**:
   ```bash
   cd src/main_executable_module
   make clean
   make all
   make build_with_static
   make build_with_dynamic
   ```
3. **Memory checks** (`valgrind` on Linux):
   ```bash
   valgrind --leak-check=full --show-leak-kinds=all ../../build/Quest_3
   valgrind --leak-check=full --show-leak-kinds=all ../../build/Quest_4
   valgrind --leak-check=full --show-leak-kinds=all ../../build/Quest_5
   ```

---

## 8) Structural-programming checklist (quick)

Before final push, confirm:
- no global variables;
- no `goto`, no `continue`;
- one clear exit point per function (except early argument validation);
- nesting depth is small (prefer <= 4);
- functions are small and readable;
- no `exit()` for normal error handling;
- no `system()` usage.

---

## 9) If you are new and stuck

Use this simple loop:
1. Read one quest only.
2. Implement minimal working version.
3. Compile with warnings as errors.
4. Run sample input.
5. Run style + valgrind.
6. Commit small progress.

If you want, next I can prepare a **very simple starter template** for `src/s21_string` (Q6–Q12) with beginner-friendly comments.
