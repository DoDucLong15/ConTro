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
	int n, hs = 0, i, j;
	char *ptr[100], ds[100][30], name[100][30], p[30], *temp;
	while(1) {
		printf("Application Manager Student Name\n");
		printf("Enter 1: Bo sung danh sach\n");
		printf("Enter 2: Sap xep danh sach theo thu tu ABC\n");
		printf("Enter 3: In danh sach\n");
		printf("Enter 4: Thoat\n");
		
		printf("Nhap lua chon: "); scanf("%d", &n);
		switch(n) {
			case 1:
				printf("Nhap ten hoc sinh thu %d: ", (hs+1));
				fflush(stdin); gets(ds[hs]);
				ptr[hs] = ds[hs];
				hs++;
				break;
			case 2:
//				for(i=0; i<hs-1; i++)
//					for(j=i+1; j<hs; j++)
//						if(strcmp(ds[i],ds[j])>0) {
//							temp = ptr[i]; 
//							ptr[i] = ptr[j]; 
//							ptr[j] = temp;
//						}
				for(i=0; i<hs; i++) strcpy(name[i], getName(ds[i]));
				for(i=0; i<hs-1; i++)
					for(j=i+1; j<hs; j++)
						if(strcmp(name[i],name[j])>0) {
							temp = ptr[i]; ptr[i] = ptr[j]; ptr[j] = temp;
							strcpy(p,name[i]); strcpy(name[i],name[j]); strcpy(name[j],p);
						}
				break;
			case 3:
				printf("DANH SACH HOC SINH\n");
				for(i=0; i<hs; i++) printf("%d. %s\n", (i+1), ptr[i]);
				break;
			case 4:
				return 0;
			default:
				printf("Invalid\n");
				continue;
		}
	}
	
	return 0;
}
