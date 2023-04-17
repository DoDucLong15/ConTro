#include <stdio.h>
#include <stdlib.h>

void alloc2DArray(int*** arr, int m, int n) {
	*arr = (int**)malloc(m*sizeof(int*));
	int i;
	for(i=0; i<m; i++) {
		(*arr)[i] = (int*)malloc(n*sizeof(int));
	}
}

void nhapMatrix(int **arr, int m, int n) {
	int i,j;
	for(i=0; i<m; i++)
		for(j=0; j<n; j++) {
			printf("arr[%d][%d] = ", i, j);
			scanf("%d", &arr[i][j]);
		}
}

void xuatMatrix(int **arr, int m, int n) {
	int i,j;
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) printf("%-5d", arr[i][j]);
		printf("\n");
	}
}

void freeM(int **arr, int m, int n) {
	int i;
	for(i=0; i<m; i++) free(arr[m]);
	free(arr);
}

int main() {
	int **arr, m, n;
	printf("Nhap so dong, cot ma tran: ");
	scanf("%d %d", &m, &n);
	alloc2DArray(&arr,m,n);
	nhapMatrix(arr,m,n);
	xuatMatrix(arr,m,n);
	freeM(arr,m,n);
	
	return 0;
}
