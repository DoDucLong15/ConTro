#include <stdio.h>
#include <string.h>

char* getName(char* s) {
	char* result;
	int i, length = 0;
	for(i=strlen(s)-1; i>=0; i--) {
		if(s[i]==' ') break;
		result[length] = s[i];
		length++;
	}
	result[length] = '\0';
	for(i=0; i<length/2; i++) {
		char temp = result[i];
		result[i] = result[length-i-1];
		result[length-i-1] = temp;
	}
	return result;
}

int main() {
	int i, n, j;
	char ds[100][30], name[100][30], s[30];
	char *ptr[100], *tmp;
	printf("Nhap so hoc sinh trong lop: ");
	scanf("%d", &n);
	getchar();
	
	for(i=0; i<n; i++) {
		printf("Nhap ten hoc sinh thu %d: ", (i+1));
		fgets(ds[i], 30, stdin);
		if(strlen(ds[i])==0) break;
		ptr[i] = ds[i];
		strcpy(name[i], getName(ds[i]));
	}
	
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(strcmp(name[i], name[j])>0) {
				tmp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = tmp;
				strcpy(s,name[i]);
				strcpy(name[i], name[j]);
				strcpy(name[j], s);
			}
	printf("DANH SACH HOC SINH\n");
	for(i=0; i<n; i++) printf("%d. %s", (i+1), ptr[i]);
	
	return 0;
}
