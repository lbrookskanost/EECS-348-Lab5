/* 
 * Name: Lillian Brooks-Kanost
 * KU ID: 3115848
 * Class: EECS 348 Friday 4pm Lab
 * Lab 5
 * Given 2 matrices, the following operations are performed:
 * Matrix addition, multiplication, transposition, print
 * The two matrices are hard-coded into main.
 */

#define SIZE 5
#include <stdio.h>

void addMatrices (int m1[SIZE][SIZE], int m2[SIZE][SIZE]);
void multiplyMatrices (int m1[SIZE][SIZE], int m2[SIZE][SIZE]);
void transposeMatrix (int matrix[SIZE][SIZE]);
void printMatrix (int matrix[SIZE][SIZE]);

int main() {
	/* Initializes the two matrices; allows user to choose which operation to perform on which matrices */
	int m1[SIZE][SIZE] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};
	int m2[SIZE][SIZE] = {
		{25, 24, 23, 22, 21},
		{20, 19, 18, 17, 16},
		{15, 14, 13, 12, 11},
		{10, 9, 8, 7, 6},
		{5, 4, 3, 2, 1}
	};
	int i = 0;
	int input = 5;
	printf("Press 0 to STOP\n");
	printf("Press 1 for matrix addition, 2 for multiplication, 3 for transpose, 4 for print\n");
	scanf("%d", &input);
	if (input == 0) {
		return 0;
	} else if (input == 1) {
		addMatrices(m1, m2);
	} else if (input == 2) {
		multiplyMatrices(m1, m2);
	} else if (input == 3) {
		int to_transpose = 0;
		printf("Which matrix would you like to transpose? 1/2: ");
		scanf("%d", &to_transpose);
		if (to_transpose == 1) {
			transposeMatrix(m1);
		} else if (to_transpose == 2) {
			transposeMatrix(m2);
		} else {
			printf("Invalid input.\n");
		}
	} else if (input == 4) {
		int to_print = 0;
		printf("Which matrix would you like to print? 1/2: ");
		scanf("%d", &to_print);
		if (to_print == 1) {
			printMatrix(m1);
		} else if (to_print == 2 ){
			printMatrix(m2);
		} else {
			printf("Invalid input.\n");
		}
	} else {
		printf("Invalid input\n");
	}	
	return 0;
}

void addMatrices (int m1[SIZE][SIZE], int m2[SIZE][SIZE]){
	/* adds two matrices (assumed of equal size); prints said matrix */
	int added_matrix[SIZE][SIZE];
	for (int i =0; i < SIZE; i++) {
		for(int j=0; j < SIZE; j++) {
			added_matrix[i][j] = m1[i][j] + m2[i][j];
		}
	}
	printMatrix(added_matrix);
}

void multiplyMatrices (int m1[SIZE][SIZE], int m2[SIZE][SIZE]){
	/* multiplies two matrices; prints said
	 *since matrices are hard-coded to be square and equal-sized, there's no check for validity of input 
	 */
	int multiplied_matrix[SIZE][SIZE];
	for (int i=0; i<SIZE; i++) {
		for (int j=0; j< SIZE; j++) {
			multiplied_matrix[i][j] = 0;
			for (int k=0; k < SIZE; k++) {
				multiplied_matrix[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	printMatrix(multiplied_matrix);
}

void transposeMatrix (int matrix[SIZE][SIZE]){
	/* transposes a matrix; prints said matrix 
	 * again, no input-check since matrices are hard-coded to be square
	 */
	int transposed_matrix[SIZE][SIZE];
	for (int i=0; i< SIZE; i++) {
		for (int j=0; j< SIZE; j++) {
		transposed_matrix[i][j] = matrix[j][i];
		}
	}
	printMatrix(transposed_matrix);
}

void printMatrix (int matrix[SIZE][SIZE]){
	/* prints a matrix */
	for (int i=0; i<SIZE; i++) {
		for (int j=0; j< SIZE; j++) {
		printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}