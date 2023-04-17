#include <stdio.h>
#include <stdlib.h>

void alloc3DArray(int**** arr, int x, int y, int z) {
	*arr = (int***)malloc(x*sizeof(int**));
	int i, j;
	for(i=0; i<x; i++) (*arr)[i] = (int**)malloc(y*sizeof(int*));
	for(i=0; i<x; i++)
		for(j=0; j<y; j++)
			((*arr)[i])[j] = (int*)malloc(z*sizeof(int));
}

void nhapMatrix(int ***arr, int x, int y, int z) {
	int i,j,k;
	for(i=0; i<x; i++)
		for(j=0; j<y; j++) 
			for(k=0; k<z; k++) {
				printf("arr[%d][%d][%d] = ",i,j,k);
				scanf("%d", &arr[i][j][k]);
			}
}

void xuatMatrix(int ***arr, int x, int y, int z) {
	int i,j,k;
	for(i=0; i<x; i++)
		for(j=0; j<y; j++) {
			for(k=0; k<z; k++) printf("%3d ", arr[i][j][k]);
			printf("\n");
		}
}

void freeM(int ***arr, int x, int y, int z) {
	int i, j;
	for(i=0; i<x; i++)
		for(j=0; j<y; j++) free(arr[i][j]);
	for(i=0; i<x; i++) free(arr[i]);
	free(arr);
}

int main() {
	int ***arr, x, y, z;
	printf("Nhap kich thuoc mang 3 chieu: ");
	scanf("%d %d %d", &x, &y, &z);
	alloc3DArray(&arr,x,y,z);
	nhapMatrix(arr,x,y,z);
	xuatMatrix(arr,x,y,z);
	freeM(arr,x,y,z);
	
	return 0;
}
