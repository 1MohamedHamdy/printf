# Custom Printf Function

Welcome to our custom `printf` function project! We've developed a C program that replicates the functionality of the standard `printf` function in the C library. This project is part of our education at ALX, and we're excited to share our implementation with you.

## Table of Contents
- [Introduction](#introduction)
- [Concepts](#concepts)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Contributors](#contributors)
- [License](#license)

## Introduction

In this project, we've created a custom `printf` function that can produce output according to a given format string. Our implementation supports the following format specifiers:
- `%c`: Print a character.
- `%s`: Print a string.
- `%%`: Print a literal '%' character.
- `%d` or `%i`: Print integers.

We've strived to follow best practices, including code organization, documentation, and adherence to project requirements.

## Concepts

To successfully complete this project, we recommend reviewing the following concepts:
- Group Projects: Understanding collaborative work.
- Pair Programming: Guidelines for working in pairs.

- Printf Function Brief: Understanding the printf function's behavior.

## Getting Started

To use our custom `printf` function, follow these steps:

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/your-username/printf.git
   ```

2. Compile the code using GCC:

   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o custom_printf
   ```

3. Run the program:

   ```bash
   ./custom_printf
   ```

## Usage

You can use our `printf` function in your C programs by including the `main.h` header file and calling the `_printf` function. For example:

```c
#include <stdio.h>
#include "main.h"

int main(void)
{
    int len;
    char ch = 'A';
    char *str = "Hello, World!";
    len = _printf("Character: %c\n", ch);
    len += _printf("String: %s\n", str);
    _printf("Length: %d\n", len);
    return (0);
}
```

## File Structure

- `main.c`: Contains the main function and example usage.
- `main.h`: Header file with function prototypes.
- `printf.c`: Implementation of the `_printf` function.

## Contributors

This project was completed by the following team members:
- Mohamed Mareey
- Nyera Gbr

## License

This project is licensed under the [ALX License](LICENSE.md).

Thank you for checking out our custom `printf` function project! We hope you find it useful and educational. If you have any questions or suggestions, please feel free to reach out to us. Happy coding! 🚀
