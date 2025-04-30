#include <stdio.h>
#include <stdlib.h>

/* Dimension of Matrix */
#define MATRIX_SIZE 5

void matrixInput(int arr[MATRIX_SIZE][MATRIX_SIZE]) {
    int i,j;
    int read_result;
    int extra_value;

    /* building a 2d array from the given numbers */
    printf("Matrix Size is: %d \n", MATRIX_SIZE);
    printf("Please Enter %d numbers: \n", MATRIX_SIZE*MATRIX_SIZE);
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            read_result = scanf("%d", &arr[i][j]);
            if (read_result != 1) {
                printf("Error: invalid input.\n");
                exit(1); /* Could be not enough numbers or not a valid integer was given */
            }
        }
    }

    /* Checking if we have more numbers than needed in input */
    if (scanf("%d", &extra_value) != -1) {
        printf("Error: invalid input. Too many numbers. \n");
        exit(1);
    }
}

/* Returns 1 if given matrix is a magic square and 0 if not */
int isMagicSquare(int arr[MATRIX_SIZE][MATRIX_SIZE]) {

    int sum_diag = 0, sum_anti_diag = 0;
    int sum_rows[MATRIX_SIZE] = {0}, sum_cols[MATRIX_SIZE] = {0};
    int used[MATRIX_SIZE * MATRIX_SIZE + 1] = {0};  /* array for all indexes */
    int i, j;

    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {

            /* checking duplicates or 1-N^2 range */
            if (arr[i][j] < 1 || arr[i][j] > MATRIX_SIZE*MATRIX_SIZE || used[arr[i][j]]) {
                return 0;
            }
            used[arr[i][j]] = 1;

            /* Calculating all needed sums */
            sum_rows[i] += arr[i][j];
            sum_cols[j] += arr[i][j];
            if (i == j)
                sum_diag += arr[i][j];
            if (i + j == MATRIX_SIZE - 1)
                sum_anti_diag += arr[i][j];
        }
    }

    /* exit if diagonals dont match */
    if (sum_diag != sum_anti_diag || sum_diag != sum_rows[0])
        return 0;

    /* if diagonals match, compare every row and col sum. Not comparing the diagonals cause of transitivity from the previous if */
    for (i = 0; i < MATRIX_SIZE; i++) {
        if (sum_rows[i] != sum_cols[i])
            return 0;
    }

    /* if we got here, we have a magic square */
    return 2;
}

int main(void) {
    int i,j;
    int numbers[MATRIX_SIZE][MATRIX_SIZE];

    /* building matrix from input */
    matrixInput(numbers);

    /* printing matrix */
    printf("Here is your Matrix: \n");
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }

    /* results of magic square */
    if (isMagicSquare(numbers))
        printf("We have a MagicSquare!\n");
    else
        printf("No MagicSquare was found :(\n");
    return 0;
}
