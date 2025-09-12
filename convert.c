#include <stdio.h>
#include <stdint.h>
#include <string.h>


//Division 
void div_convert(uint32_t n, int base, char *out) {
    char temp[65]; // Temporary buffer to store digits in reverse order
    int pos = 0;
    // Special case: if n is 0 then return 0
    if (n == 0) {
        strcpy(out, "0");
        return;
    }
    // Convert number by repeated division
    while (n > 0) {
        int remainder = n % base; // Get remainder
        n = n / base; // Reduce n
        if (remainder < 10)
            temp[pos++] = '0' + remainder; // For digits 0-9
        else
            temp[pos++] = 'A' + (remainder - 10); // For letters A-F in hex
    }

    // reverse into output string 
    for (int i = 0; i < pos; i++) {
        out[i] = temp[pos - 1 - i];
    }
    out[pos] = '\0'; // Null-terminate the string
}
//Subtraction
void sub_convert(uint32_t n, int base, char *out) {
    // Special case: if n is 0, return "0"
    if (n == 0) {
        strcpy(out, "0");
        return;
    }
    // Find the highest power of the base <= to n
    uint32_t power = 1;
    while (power <= n / base) {
        power *= base;
    }

    int pos = 0;
    // Extract digits by dividing by descending powers of the base
    while (power > 0) {
        int digit = n / power; // Determine current digit
        n -= digit * power; // Remove that digit's value from n
        power /= base; // Move to next lower power

        if (digit < 10) // Digits 0-9
            out[pos++] = '0' + digit;
        else
            out[pos++] = 'A' + (digit - 10); // Letters A-F for hex
    }
    out[pos] = '\0'; // Null-terminate the string
}

//Print Tables
void print_tables(uint32_t n) {
    char bin[65], oct[32], hex[32];

    // Original
    div_convert(n, 2, bin); // Convert to binary
    div_convert(n, 8, oct); // Convert to octal
    div_convert(n, 16, hex); // Convert to hexadecimal
    printf("Original: Binary=%s Octal=%s Decimal=%u Hex=%s\n", bin, oct, n, hex);

    // Left shift by 3
    uint32_t shifted = n << 3; // Multiply by 8 using bit shift
    div_convert(shifted, 2, bin);
    div_convert(shifted, 8, oct);
    div_convert(shifted, 16, hex);
    printf("Left Shift by 3: Binary=%s Octal=%s Decimal=%u Hex=%s\n", bin, oct, shifted, hex);

    // AND with 0xFF
    uint32_t masked = n & 0xFF; // Keep only last 8 bits
    div_convert(masked, 2, bin);
    div_convert(masked, 8, oct);
    div_convert(masked, 16, hex);
    printf("AND with 0xFF: Binary=%s Octal=%s Decimal=%u Hex=%s\n", bin, oct, masked, hex);
}
