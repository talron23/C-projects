#include <stdio.h>

unsigned int bits_zero_count(unsigned int num) {
    unsigned int count = 0;
    unsigned int total_bits = sizeof(num) * 8;
    while (num) { /* will get out from while when we shifted out all 1 bits so number is 0 */
        count += (num & 1);  /* Add 1 if most right bit is 1 */
        num = num >> 1;           /* Shift right to process next bit */
    }
    return total_bits - count;
}

int main(void) {
    unsigned int num;
    printf("Enter an integer: \n");
    scanf("%u", &num);  /* Read an unsigned integer from input */
    printf("You entered: %u\n", num);
    printf("Number of zero bits are: %d\n", bits_zero_count(num)); /* print result */
    return 0;
}
