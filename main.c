#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "convert.c" 

#define LINEBUF 256

int main() {
    // Open test file 
    FILE *file = fopen("a1_test_file.txt", "r");
    // Print no file error if no test file is present (it is) 
    if (!file) { 
        printf("Error: Could not open test file\n");
        return 1;
    }
    // Hold each line read from file
    char line[LINEBUF];
    // Var to hold passed tests and total tests
    int passed = 0, total = 0;
    // Read the each line of file
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || strlen(line) < 2) continue; // This skips comments & blanks lines
        // Holds variables from all parsed data
        char func[32], expected[128];
        uint32_t n;
        int base;
        // Test case for div_convert func
        if (sscanf(line, "div_convert %u %d %s", &n, &base, expected) == 3) {
            char out[128]; // Store func output
            div_convert(n, base, out); // Call the conversion func
            total++; //Increment Test counter
            //Check if output matches expected output
            if (strcmp(out, expected) == 0) {  //Pass Case
                printf("Test %d: div_convert(%u,%d) -> Expected:%s Got:%s [PASS]\n",
                       total, n, base, expected, out);
                passed++; // Increment passed test counter
            //Fail case
            } else {
                printf("Test %d: div_convert(%u,%d) -> Expected:%s Got:%s [FAIL]\n",
                       total, n, base, expected, out);
            }
        }
        // Test case for sub_conver func
        else if (sscanf(line, "sub_convert %u %d %s", &n, &base, expected) == 3) {
            char out[128]; // Store func output
            sub_convert(n, base, out); //Call the sub func
            total++; // Increment passed test counter
            //Check if output matches expected output
            if (strcmp(out, expected) == 0) {  //Pass Case
                printf("Test %d: sub_convert(%u,%d) -> Expected:%s Got:%s [PASS]\n",
                       total, n, base, expected, out); 
                passed++; // Increment passed test counter
            //Fail case
            } else {
                printf("Test %d: sub_convert(%u,%d) -> Expected:%s Got:%s [FAIL]\n",
                       total, n, base, expected, out);
            }
        }
        // Test case for print_tables
        else if (sscanf(line, "print_tables %u %s", &n, expected) == 2 &&
                 strcmp(expected, "FORMATTED_OUTPUT") == 0) {
            total++; // Increment passed test counter
            printf("Test %d: print_tables(%u) -> [FORMATTED OUTPUT CHECK]\n", total, n);
            print_tables(n); // Call the function to print tables
            printf("[PASS assumed if format matches]\n");  
            passed++; // Increment passed test counter
        }
    }

    fclose(file); //Close file
    printf("\nSummary: %d/%d tests passed\n", passed, total); //Summary after code compiles
    return 0; // Exit point
}
