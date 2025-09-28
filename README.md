# CS 3503 Assignment 1 - Number Base Conversion

## Author
Ethan Lynch

## Description
This project is my implementation of Owl Tech’s number base conversion utility. The program converts decimal numbers into binary, octal, decimal, and hexadecimal representations. It also includes a table-printing utility to demonstrate bitwise operations like left shifts and masking with `0xFF`.

## Build Instructions
```bash
gcc -o convert main.c
./convert
```
## Test Results
```
Test 1: div_convert(104,5) -> Expected:404 Got:404 [PASS]
Test 2: div_convert(156,8) -> Expected:234 Got:234 [PASS]
Test 3: div_convert(255,16) -> Expected:FF Got:FF [PASS]
Test 4: div_convert(255,10) -> Expected:255 Got:255 [PASS]
Test 5: div_convert(255,2) -> Expected:11111111 Got:11111111 [PASS]
Test 6: div_convert(42,2) -> Expected:101010 Got:101010 [PASS]
Test 7: div_convert(0,2) -> Expected:0 Got:0 [PASS]
Test 8: div_convert(0,8) -> Expected:0 Got:0 [PASS]
Test 9: div_convert(0,10) -> Expected:0 Got:0 [PASS]
Test 10: div_convert(0,16) -> Expected:0 Got:0 [PASS]
Test 11: div_convert(1,2) -> Expected:1 Got:1 [PASS]
Test 12: div_convert(1,8) -> Expected:1 Got:1 [PASS]
Test 13: div_convert(1,16) -> Expected:1 Got:1 [PASS]
Test 14: div_convert(8,2) -> Expected:1000 Got:1000 [PASS]
Test 15: div_convert(16,2) -> Expected:10000 Got:10000 [PASS]
Test 16: div_convert(64,8) -> Expected:100 Got:100 [PASS]
Test 17: div_convert(256,16) -> Expected:100 Got:100 [PASS]
Test 18: div_convert(4294967295,2) -> Expected:11111111111111111111111111111111 Got:11111111111111111111111111111111 [PASS]
Test 19: div_convert(4294967295,8) -> Expected:37777777777 Got:37777777777 [PASS]
Test 20: div_convert(4294967295,10) -> Expected:4294967295 Got:4294967295 [PASS]
Test 21: div_convert(4294967295,16) -> Expected:FFFFFFFF Got:FFFFFFFF [PASS]
Test 22: div_convert(42,5) -> Expected:132 Got:132 [PASS]
Test 23: div_convert(42,8) -> Expected:52 Got:52 [PASS]
Test 24: div_convert(42,10) -> Expected:42 Got:42 [PASS]
Test 25: div_convert(42,16) -> Expected:2A Got:2A [PASS]
Test 26: sub_convert(104,5) -> Expected:404 Got:404 [PASS]
Test 27: sub_convert(156,8) -> Expected:234 Got:234 [PASS]
Test 28: sub_convert(255,16) -> Expected:FF Got:FF [PASS]
Test 29: sub_convert(255,10) -> Expected:255 Got:255 [PASS]
Test 30: sub_convert(255,2) -> Expected:11111111 Got:11111111 [PASS]
Test 31: sub_convert(42,2) -> Expected:101010 Got:101010 [PASS]
Test 32: sub_convert(0,2) -> Expected:0 Got:0 [PASS]
Test 33: sub_convert(0,8) -> Expected:0 Got:0 [PASS]
Test 34: sub_convert(0,10) -> Expected:0 Got:0 [PASS]
Test 35: sub_convert(0,16) -> Expected:0 Got:0 [PASS]
Test 36: sub_convert(1,2) -> Expected:1 Got:1 [PASS]
Test 37: sub_convert(1,8) -> Expected:1 Got:1 [PASS]
Test 38: sub_convert(1,16) -> Expected:1 Got:1 [PASS]
Test 39: sub_convert(8,2) -> Expected:1000 Got:1000 [PASS]
Test 40: sub_convert(16,2) -> Expected:10000 Got:10000 [PASS]
Test 41: sub_convert(64,8) -> Expected:100 Got:100 [PASS]
Test 42: sub_convert(256,16) -> Expected:100 Got:100 [PASS]
Test 43: sub_convert(4294967295,2) -> Expected:11111111111111111111111111111111 Got:11111111111111111111111111111111 [PASS]
Test 44: sub_convert(4294967295,8) -> Expected:37777777777 Got:37777777777 [PASS]
Test 45: sub_convert(4294967295,10) -> Expected:4294967295 Got:4294967295 [PASS]
Test 46: sub_convert(4294967295,16) -> Expected:FFFFFFFF Got:FFFFFFFF [PASS]
Test 47: sub_convert(42,5) -> Expected:132 Got:132 [PASS]
Test 48: sub_convert(42,8) -> Expected:52 Got:52 [PASS]
Test 49: sub_convert(42,10) -> Expected:42 Got:42 [PASS]
Test 50: sub_convert(42,16) -> Expected:2A Got:2A [PASS]
Test 51: div_convert(7,2) -> Expected:111 Got:111 [PASS]
Test 52: sub_convert(7,2) -> Expected:111 Got:111 [PASS]
Test 53: div_convert(15,8) -> Expected:17 Got:17 [PASS]
Test 54: sub_convert(15,8) -> Expected:17 Got:17 [PASS]
Test 55: div_convert(31,16) -> Expected:1F Got:1F [PASS]
Test 56: sub_convert(31,16) -> Expected:1F Got:1F [PASS]
Test 57: div_convert(1000,2) -> Expected:1111101000 Got:1111101000 [PASS]
Test 58: sub_convert(1000,2) -> Expected:1111101000 Got:1111101000 [PASS]
Test 59: div_convert(1000,8) -> Expected:1750 Got:1750 [PASS]
Test 60: sub_convert(1000,8) -> Expected:1750 Got:1750 [PASS]
Test 61: div_convert(1000,16) -> Expected:3E8 Got:3E8 [PASS]
Test 62: sub_convert(1000,16) -> Expected:3E8 Got:3E8 [PASS]
Test 63: print_tables(5) -> [FORMATTED OUTPUT CHECK]

Original: Binary=101 Octal=5 Decimal=5 Hex=5
Left Shift by 3: Binary=101000 Octal=50 Decimal=40 Hex=28
AND with 0xFF: Binary=101 Octal=5 Decimal=5 Hex=5
[PASS assumed if format matches]
Test 64: print_tables(0) -> [FORMATTED OUTPUT CHECK]
Original: Binary=0 Octal=0 Decimal=0 Hex=0
Left Shift by 3: Binary=0 Octal=0 Decimal=0 Hex=0
AND with 0xFF: Binary=0 Octal=0 Decimal=0 Hex=0
[PASS assumed if format matches]
Test 65: print_tables(1) -> [FORMATTED OUTPUT CHECK]
Original: Binary=1 Octal=1 Decimal=1 Hex=1
Left Shift by 3: Binary=1000 Octal=10 Decimal=8 Hex=8
AND with 0xFF: Binary=1 Octal=1 Decimal=1 Hex=1
[PASS assumed if format matches]
Test 66: print_tables(7) -> [FORMATTED OUTPUT CHECK]
Original: Binary=111 Octal=7 Decimal=7 Hex=7
Left Shift by 3: Binary=111000 Octal=70 Decimal=56 Hex=38
AND with 0xFF: Binary=111 Octal=7 Decimal=7 Hex=7
[PASS assumed if format matches]
Test 67: print_tables(15) -> [FORMATTED OUTPUT CHECK]
Original: Binary=1111 Octal=17 Decimal=15 Hex=F
Left Shift by 3: Binary=1111000 Octal=170 Decimal=120 Hex=78
AND with 0xFF: Binary=1111 Octal=17 Decimal=15 Hex=F
[PASS assumed if format matches]
Test 68: print_tables(8) -> [FORMATTED OUTPUT CHECK]
Original: Binary=1000 Octal=10 Decimal=8 Hex=8
Left Shift by 3: Binary=1000000 Octal=100 Decimal=64 Hex=40
AND with 0xFF: Binary=1000 Octal=10 Decimal=8 Hex=8
[PASS assumed if format matches]
Test 69: print_tables(16) -> [FORMATTED OUTPUT CHECK]
Original: Binary=10000 Octal=20 Decimal=16 Hex=10
Left Shift by 3: Binary=10000000 Octal=200 Decimal=128 Hex=80
AND with 0xFF: Binary=10000 Octal=20 Decimal=16 Hex=10
[PASS assumed if format matches]
Test 70: print_tables(32) -> [FORMATTED OUTPUT CHECK]
Original: Binary=100000 Octal=40 Decimal=32 Hex=20
Left Shift by 3: Binary=100000000 Octal=400 Decimal=256 Hex=100
AND with 0xFF: Binary=100000 Octal=40 Decimal=32 Hex=20
[PASS assumed if format matches]
Test 71: print_tables(255) -> [FORMATTED OUTPUT CHECK]
Original: Binary=11111111 Octal=377 Decimal=255 Hex=FF
Left Shift by 3: Binary=11111111000 Octal=3770 Decimal=2040 Hex=7F8
AND with 0xFF: Binary=11111111 Octal=377 Decimal=255 Hex=FF
[PASS assumed if format matches]
Test 72: print_tables(256) -> [FORMATTED OUTPUT CHECK]
Original: Binary=100000000 Octal=400 Decimal=256 Hex=100
Left Shift by 3: Binary=100000000000 Octal=4000 Decimal=2048 Hex=800
AND with 0xFF: Binary=0 Octal=0 Decimal=0 Hex=0
[PASS assumed if format matches]
Test 73: print_tables(511) -> [FORMATTED OUTPUT CHECK]
Original: Binary=111111111 Octal=777 Decimal=511 Hex=1FF
Left Shift by 3: Binary=111111111000 Octal=7770 Decimal=4088 Hex=FF8
AND with 0xFF: Binary=11111111 Octal=377 Decimal=255 Hex=FF
[PASS assumed if format matches]
Test 74: print_tables(1000) -> [FORMATTED OUTPUT CHECK]
Original: Binary=1111101000 Octal=1750 Decimal=1000 Hex=3E8
Left Shift by 3: Binary=1111101000000 Octal=17500 Decimal=8000 Hex=1F40
AND with 0xFF: Binary=11101000 Octal=350 Decimal=232 Hex=E8
[PASS assumed if format matches]
Test 75: print_tables(65535) -> [FORMATTED OUTPUT CHECK]
Original: Binary=1111111111111111 Octal=177777 Decimal=65535 Hex=FFFF
Left Shift by 3: Binary=1111111111111111000 Octal=1777770 Decimal=524280 Hex=7FFF8
AND with 0xFF: Binary=11111111 Octal=377 Decimal=255 Hex=FF
[PASS assumed if format matches]
Test 76: print_tables(4294967295) -> [FORMATTED OUTPUT CHECK]
Original: Binary=11111111111111111111111111111111 Octal=37777777777 Decimal=4294967295 Hex=FFFFFFFF
Left Shift by 3: Binary=11111111111111111111111111111000 Octal=37777777770 Decimal=4294967288 Hex=FFFFFFF8
AND with 0xFF: Binary=11111111 Octal=377 Decimal=255 Hex=FF
[PASS assumed if format matches]

Test 77: div_convert(2147483647,2) -> Expected:1111111111111111111111111111111 Got:1111111111111111111111111111111 [PASS]
Test 78: sub_convert(2147483647,2) -> Expected:1111111111111111111111111111111 Got:1111111111111111111111111111111 [PASS]
Test 79: div_convert(1073741824,8) -> Expected:10000000000 Got:10000000000 [PASS]
Test 80: sub_convert(1073741824,8) -> Expected:10000000000 Got:10000000000 [PASS]
Test 81: div_convert(268435456,16) -> Expected:10000000 Got:10000000 [PASS]
Test 82: sub_convert(268435456,16) -> Expected:10000000 Got:10000000 [PASS]
Test 83: div_convert(4294967294,10) -> Expected:4294967294 Got:4294967294 [PASS]
Test 84: sub_convert(4294967294,10) -> Expected:4294967294 Got:4294967294 [PASS]
Test 85: div_convert(4294967294,16) -> Expected:FFFFFFFE Got:FFFFFFFE [PASS]
Test 86: sub_convert(4294967294,16) -> Expected:FFFFFFFE Got:FFFFFFFE [PASS]
Test 87: div_convert(4,5) -> Expected:4 Got:4 [PASS]
Test 88: sub_convert(4,5) -> Expected:4 Got:4 [PASS]
Test 89: div_convert(7,8) -> Expected:7 Got:7 [PASS]
Test 90: sub_convert(7,8) -> Expected:7 Got:7 [PASS]
Test 91: div_convert(15,16) -> Expected:F Got:F [PASS]
Test 92: sub_convert(15,16) -> Expected:F Got:F [PASS]
Test 93: div_convert(25,5) -> Expected:100 Got:100 [PASS]
Test 94: sub_convert(25,5) -> Expected:100 Got:100 [PASS]
Test 95: div_convert(124,5) -> Expected:444 Got:444 [PASS]
Test 96: sub_convert(124,5) -> Expected:444 Got:444 [PASS]
Test 97: div_convert(171,16) -> Expected:AB Got:AB [PASS]
Test 98: sub_convert(171,16) -> Expected:AB Got:AB [PASS]
Test 99: div_convert(3405774592,16) -> Expected:CAFFFF00 Got:CAFFFF00 [PASS]
Test 100: sub_convert(3405774592,16) -> Expected:CAFFFF00 Got:CAFFFF00 [PASS]
```
## Notes
- Working with binary, octal, decimal, and hexadecimal reinforced how numbers are represented differently in each base and how to convert between them.
- Proper formatting of the outputs allowed me to easily check test cases.
- Edge cases matter, because testing with 0, 1, and the maximum 32-bit unsigned integer showed me the bound conditions to be aware of. 
