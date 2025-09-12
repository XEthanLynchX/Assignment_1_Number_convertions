#include <stdio.h>
#include <stdint.h>
#include <string.h>


//Division 
void div_convert(uint32_t n, int base, char *out) {
    char temp[65];
    int pos = 0;

    if (n == 0) {
        strcpy(out, "0");
        return;
    }

    while (n > 0) {
        int remainder = n % base;
        n = n / base;
        if (remainder < 10)
            temp[pos++] = '0' + remainder;
        else
            temp[pos++] = 'A' + (remainder - 10);
    }

    // reverse into out
    for (int i = 0; i < pos; i++) {
        out[i] = temp[pos - 1 - i];
    }
    out[pos] = '\0';
}
//Subtraction
void sub_convert(uint32_t n, int base, char *out) {
    if (n == 0) {
        strcpy(out, "0");
        return;
    }

    uint32_t power = 1;
    while (power <= n / base) {
        power *= base;
    }

    int pos = 0;
    while (power > 0) {
        int digit = n / power;
        n -= digit * power;
        power /= base;

        if (digit < 10)
            out[pos++] = '0' + digit;
        else
            out[pos++] = 'A' + (digit - 10);
    }
    out[pos] = '\0';
}

//Print Tables
void print_tables(uint32_t n) {
    char bin[65], oct[32], hex[32];

    // Original
    div_convert(n, 2, bin);
    div_convert(n, 8, oct);
    div_convert(n, 16, hex);
    printf("Original: Binary=%s Octal=%s Decimal=%u Hex=%s\n", bin, oct, n, hex);

    // Left shift by 3
    uint32_t shifted = n << 3;
    div_convert(shifted, 2, bin);
    div_convert(shifted, 8, oct);
    div_convert(shifted, 16, hex);
    printf("Left Shift by 3: Binary=%s Octal=%s Decimal=%u Hex=%s\n", bin, oct, shifted, hex);

    // AND with 0xFF
    uint32_t masked = n & 0xFF;
    div_convert(masked, 2, bin);
    div_convert(masked, 8, oct);
    div_convert(masked, 16, hex);
    printf("AND with 0xFF: Binary=%s Octal=%s Decimal=%u Hex=%s\n", bin, oct, masked, hex);
}
