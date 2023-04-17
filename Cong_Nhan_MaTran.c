#include <stdio.h> 
#include <stdlib.h>

void nhapMaTran(int** arr, int row, int col) {
	int i,j;
	for(i=0; i<row; i++)
		for(j=0; j<col; j++) {
			printf("arr[%d][%d] = ", i, j);
			scanf("%d", &arr[i][j]);
		}
}

void xuatMaTran(int**arr, int row, int col) {
	int i,j;
	for(i=0; i<row; i++) {
		for(j=0; j<col; j++) printf("%5d", arr[i][j]);
		printf("\n");
	}
}

void congMaTran(int**arr1, int row1, int col1, int**arr2, int row2, int col2) {
	if(row1!=row2 || col1!=col2) printf("Khong cong duoc");
	else {
		int i,j;
		for(i=0; i<row1; i++) {
			for(j=0; j<col1; j++) printf("%5d", arr1[i][j]+arr2[i][j]);
			printf("\n");
		}
	}
}

void nhanMaTran(int**arr1, int row1, int col1, int**arr2, int row2, int col2) {
	if(row1!=col2) printf("Khong cong duoc");
	else {
		int i,j,k;
		for(i=0; i<row1; i++) {
			for(j=0; j<col2; j++) {
				int sum = 0;
				for(k=0; k<row2; k++) sum+=arr1[i][k]*arr2[k][j];
				printf("%5d ", sum);
			}
			printf("\n");
		}
	}
}

void giaiphong1(int** arr, int row, int col) {
	int i;
	for(i=0; i<row; i++) {
		free(arr[i]);
	}
	free(arr);
}

void giaiphong2(int** arr, int row, int col) {
	free(arr[0]);
	free(arr);
}

int main() {
	int rowA, colA, rowB, colB, i;
	//nhap ma tran A
	printf("Nhap so hang ma tran A: "); scanf("%d", &rowA);
	printf("Nhap so cot ma tran A: "); scanf("%d", &colA);
	
//	int** arrA = (int**)malloc(rowA*sizeof(int*));
//	for(i=0; i<rowA; i++) {
//		arrA[i] = (int*)malloc(colA*sizeof(int));
//	}
	int** arrA = (int**)malloc(rowA*sizeof(int*));
	int* temp = (int*)malloc(rowA*colA*sizeof(int));
	for(i=0; i<rowA; i++) {
		arrA[i] = temp;
		temp+=colA;
	}
	
	nhapMaTran(arrA, rowA, colA);
	//nhap ma tran B
	printf("Nhap so hang ma tran B: "); scanf("%d", &rowB);
	printf("Nhap so cot ma tran B: "); scanf("%d", &colB);
	
//	int** arrB = (int**)malloc(rowB*sizeof(int*));
//	for(i=0; i<rowB; i++) {
//		arrB[i] = (int*)malloc(colB*sizeof(int));
//	}
	int** arrB = (int**)malloc(rowB*sizeof(int*));
	int* temp1 = (int*)malloc(rowB*colB*sizeof(int));
	for(i=0; i<rowA; i++) {
		arrB[i] = temp1;
		temp1+=colB;
	}	
	nhapMaTran(arrB, rowB, colB);
	//xuat 2 ma tran
	printf("Ma tran A:\n");
	xuatMaTran(arrA, rowA, colA);
	printf("Ma tran B:\n");
	xuatMaTran(arrB, rowB, colB);
	//cong ma tran
	printf("Ma tran A + B :\n");
	congMaTran(arrA, rowA, colA, arrB, rowB, colB);
	//nhan ma tran
	printf("Ma tra A * B :\n");
	nhanMaTran(arrA, rowA, colA, arrB, rowB, colB);
	//giai phong
	giaiphong2(arrA, rowA, colA);
	giaiphong2(arrB, rowB, colB);
	
	return 0;
}
