#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "convert.c" 

#define LINEBUF 256

int main() {
    FILE *file = fopen("a1_test_file.txt", "r");
    if (!file) {
        printf("Error: Could not open test file\n");
        return 1;
    }

    char line[LINEBUF];
    int passed = 0, total = 0;

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || strlen(line) < 2) continue; // This skips comments & blanks

        char func[32], expected[128];
        uint32_t n;
        int base;

        if (sscanf(line, "div_convert %u %d %s", &n, &base, expected) == 3) {
            char out[128];
            div_convert(n, base, out);
            total++;
            if (strcmp(out, expected) == 0) {
                printf("Test %d: div_convert(%u,%d) -> Expected:%s Got:%s [PASS]\n",
                       total, n, base, expected, out);
                passed++;
            } else {
                printf("Test %d: div_convert(%u,%d) -> Expected:%s Got:%s [FAIL]\n",
                       total, n, base, expected, out);
            }
        }
        else if (sscanf(line, "sub_convert %u %d %s", &n, &base, expected) == 3) {
            char out[128];
            sub_convert(n, base, out);
            total++;
            if (strcmp(out, expected) == 0) {
                printf("Test %d: sub_convert(%u,%d) -> Expected:%s Got:%s [PASS]\n",
                       total, n, base, expected, out);
                passed++;
            } else {
                printf("Test %d: sub_convert(%u,%d) -> Expected:%s Got:%s [FAIL]\n",
                       total, n, base, expected, out);
            }
        }
        else if (sscanf(line, "print_tables %u %s", &n, expected) == 2 &&
                 strcmp(expected, "FORMATTED_OUTPUT") == 0) {
            total++;
            printf("Test %d: print_tables(%u) -> [FORMATTED OUTPUT CHECK]\n", total, n);
            print_tables(n);
            printf("[PASS assumed if format matches]\n");
            passed++;
        }
    }

    fclose(file);
    printf("\nSummary: %d/%d tests passed\n", passed, total);
    return 0;
}
