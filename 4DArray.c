#include <stdio.h>
#include <stdlib.h>

void alloc4DArray(int***** arr, int x, int y, int z, int t) {
	*arr = (int****)malloc(x*sizeof(int***));
	int i, j, k;
	for(i=0; i<x; i++) (*arr)[i] = (int***)malloc(y*sizeof(int**));
	for(i=0; i<x; i++)
		for(j=0; j<y; j++)
			((*arr)[i])[j] = (int**)malloc(z*sizeof(int*));
	for(i=0; i<x; i++)
		for(j=0; j<y; j++)
			for(k=0; k<z; k++)
				(*arr)[i][j][k] = (int*)malloc(t*sizeof(int));
}

void nhapMatrix(int ****arr, int x, int y, int z, int t) {
	int i,j,k,m;
	for(i=0; i<x; i++)
		for(j=0; j<y; j++) 
			for(k=0; k<z; k++) 
				for(m=0; m<t; m++) {
					printf("arr[%d][%d][%d][%d] = ",i,j,k,m);
					scanf("%d", &arr[i][j][k][m]);
				}
}

void xuatMatrix(int ****arr, int x, int y, int z, int t) {
	int i,j,k,m;
	for(i=0; i<x; i++)
		for(j=0; j<y; j++) 
			for(k=0; k<z; k++) {
				for(m=0; m<t; m++) printf("%-3d ", arr[i][j][k][m]);
				printf("\n");
			}
}

void freeM(int ****arr, int x, int y, int z, int t) {
	int i, j, k;
	for(i=0; i<x; i++)
		for(j=0; j<y; j++) 
			for(k=0; k<z; k++) free(arr[i][j][k]);
	for(i=0; i<x; i++)
		for(j=0; j<y; j++) free(arr[i][j]);
	for(i=0; i<x; i++) free(arr[i]);
	free(arr);
}

int main() {
	int ****arr, x, y, z, t;
	printf("Nhap kich thuoc mang 4 chieu: ");
	scanf("%d %d %d %d", &x, &y, &z, &t);
	alloc4DArray(&arr,x,y,z,t);
	nhapMatrix(arr,x,y,z,t);
	xuatMatrix(arr,x,y,z,t);
	freeM(arr,x,y,z,t);
	
	return 0;
}
