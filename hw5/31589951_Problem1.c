#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//*ptr is the same as *argv
void display_bytes(unsigned char *ptr) {
    unsigned char *byte_ptr = ptr;
    size_t byte_count = sizeof(ptr);

    for (size_t i = 0; i < byte_count; i += 8) {
        for (size_t j = (i + 7 < byte_count ? 7 : byte_count - i - 1); j < 8; j--) {
            printf("%02x ", byte_ptr[i + j]);
        }

        for (size_t j = byte_count - i; j < 8; j++) {
            printf("   ");
        }

        printf("| ");
        printf("%p\n", byte_ptr + i);
    }
}
//params refers to the argv parameter and count the argc parameter
void display_arguments(char **params, int count) {
    for (int i = 0; i < count; i++) {
        unsigned char *arg = (unsigned char *)params[i];
        size_t len = 0;

        while (arg[len] != '\0') {
            len++;
        }
        len++;

        int line_limit = 0;
        for (size_t j = 0; j < len && line_limit < 4; j += 8) {
            for (size_t k = 0; k < 8; k++) {
                if (j + k < len) {
                    unsigned char byte = arg[j + k];
                    if (byte == '\0') {
                        printf("0(\\0) ");
                    } else {
                        printf("%02x(%c) ", byte, isprint(byte) ? byte : '.');
                    }
                } else {
                    printf("00(\\0) ");
                }
            }
            printf("| %p\n", (void *)(arg + j));
            line_limit++;
        }
    }
}
//again count is argc and params argv 
int main(int count, char *params[]) {
    printf("argv | ");
    display_bytes((unsigned char *)&params);
    printf("\n");

    for (int i = 0; i < count; i++) {
        printf("argv[%d] | ", i);
        display_bytes((unsigned char *)params[i] + i);
    }

    printf("\n");

    display_arguments(params, count);  

    return 0;
}
