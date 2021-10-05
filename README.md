# Blockchain based voting system

Organize your code in a similar structure as the provided example:

- `include` and `lib` directories contains common headers and libraries (just copy them from sample project);
- `src` directory contains the code of your program:

  - the function `main` defined in `src/main.c` should contain the code that reads user input and prints output;
  - the functions that implement the logic of your program (like computing area of a rectangle) should be defined in a separate module (like `src/rectangle.c` / `src/rectangle.h`). This separation is important because it allows us to write unit tests to check that the functions work as expected.

- `tests` directory contains the unit tests (UTs). Update the `tests/test_main.c` file with tests specific to the logic of your program. For some tasks we'll provide a list of UTs for others you may have to determine a list of suitable test cases. UTs are implemented using the [cmocka](https://cmocka.org/) framework where each test function has same prototype `void test_function_name_condition(void **state)`. Test functions name usually indicates which function is tested and what condition it tests.

- `Makefile` is the build file. Read the comments in this file to understand what changes should be done to build your projects. The sample `Makefile` uses `build` as output directory support the following targets:

  - `make` - compiles the main program;
  - `make test` - compiles and run the UTs;
  - `make all` - compiles the main program and UTs and run the UTs;
  - `make clean` - removes the output (`buils`) directory;
