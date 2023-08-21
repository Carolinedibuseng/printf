#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @ind: Pointer to the current position in the format string.
 * @list: List of arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Width specification.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: Number of characters printed or -1 on error.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
                 int flags, int width, int precision, int size)
{
    int i, unknow_len = 0, printed_chars = -1;
    fmt_t fmt_types[] = {
        {'c', print_char}, {'s', print_string}, {'%', print_percent},
        // ... other format specifiers ...
        {'\0', NULL}
    };

    for (i = 0; fmt_types[i].fmt != '\0'; i++) {
        if (fmt[*ind] == fmt_types[i].fmt) {
            return fmt_types[i].fn(list, buffer, flags, width, precision, size);
        }
    }

    if (fmt_types[i].fmt == '\0') {
        if (fmt[*ind] == '\0') {
            return -1;
        }
        // Handle unknown format specifier or special cases
        // ... implementation details ...

        return unknow_len;
    }

    return printed_chars;
}
