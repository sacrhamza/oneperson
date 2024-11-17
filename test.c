#include <stdarg.h>
#include <stdio.h>

void my_variadic_function(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        // Always retrieve as an int and then cast
        int value = va_arg(args, int);
        char c = (char)value;
        printf("Character: %c\n", c);
    }

    va_end(args);
}

int main() {
    // Passing single char or last char
    my_variadic_function(1, 'A');  // Single char
    my_variadic_function(3, 'A', 'B', 'C');  // Multiple chars
    return 0;
}
