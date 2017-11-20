#include <stdio.h>
#include <stdlib.h>

int multi(int *A, int *B, long long int *C);

int main(int argc, char *argv[]) {
	FILE * file1; FILE * file2;
	int *A = (int*)malloc(sizeof(int) * 4000 * 4000);
	int *B = (int*)malloc(sizeof(int) * 4000 * 4000);
	long long int* C = (long long int*)malloc(sizeof(long long int) * 4000 * 4000);

	if(argc != 3) {
		exit(-1);
	}
	file1 = fopen(argv[1], "r+");
	file2 = fopen(argv[2], "r+");
	
	fread(A, sizeof(int), 4000 * 4000, file1);
	fread(B, sizeof(int), 4000 * 4000, file2);

	multi(A, B, C);

	return 0;
}

int multi(int *A, int *B, long long int *C) {
	int i, j, k;
	
	for(i = 0; i < 4000; i++) {
		for(j = 0; j < 4000; j++) {
			C[i * 4000 + j] = 0;
			for(k = 0; k < 4000; k++) {
				C[i * 4000 + j] += A[k + i * 4000] * B[j + k * 4000];
			}
		}
	}

	for(i = 0; i < 4000; i++) {
		for(j = 0; j < 4000; j++) {
			printf("%lld ", C[j + i * 4000]);
		}
		printf("\n");
	}
	return 0;
}