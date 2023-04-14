#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct PointerType {
	char name[30];
	int age;
	char homeTown[30];
	char firstname[30];
	struct PointerType *next;
} SinhVien;

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

SinhVien* creatNode(char name[], int age, char homeTown[]) {
	SinhVien* NewNode;
	NewNode = (SinhVien*)malloc(sizeof(SinhVien));
	strcpy(NewNode->name, name);
	NewNode->age = age;
	strcpy(NewNode->homeTown, homeTown);
	strcpy(NewNode->firstname,getName(name));
	NewNode->next = NULL;
	return NewNode;
}

SinhVien* InsertToLast(SinhVien* First, char name[], int age, char homeTown[]) {
	SinhVien* NewNode = creatNode(name, age, homeTown);
	SinhVien* p;
	if(First==NULL) {
		First = NewNode;
	}
	else {
		p = First;
		while(p->next!=NULL) {
			p = p->next;
		}
		p->next = NewNode;
	}
	return First;
}

void sapxep(SinhVien* First) {
	char name[100][30], s[30], p[30], t[30];
	int b;
	SinhVien *m, *n;

	for(m = First; m!=NULL; m = m->next)
		for(n = m->next; n!=NULL; n = n->next) 
			if(strcmp(m->firstname,n->firstname)>0) {
				strcpy(s,m->name); strcpy(m->name,n->name); strcpy(n->name,s);
				b = m->age; m->age = n->age; n->age = b;
				strcpy(p,m->homeTown); strcpy(m->homeTown,n->homeTown); strcpy(n->homeTown,p);
				strcpy(t,m->firstname); strcpy(m->firstname, n->firstname); strcpy(n->firstname,t);
			}
			
//	for(m = First; m!=NULL; m = m->next)
//		for(n = m->next; n!=NULL; n = n->next) 
//			if(strcmp(m->name,n->name)>0) {
//				strcpy(s,m->name); strcpy(m->name,n->name); strcpy(n->name,s);
//				b = m->age; m->age = n->age; n->age = b;
//				strcpy(p,m->homeTown); strcpy(m->homeTown,n->homeTown); strcpy(n->homeTown,p);
//			}
}

void printInformation(SinhVien* First) {
	printf("DANH SACH SINH VIEN\n");
	printf("%-6s%-30s%-10s%30s\n", "STT", "Ho ten", "Tuoi", "Que quan");
	SinhVien* TempNode;
	TempNode = First;
	int i = 1;
	while(TempNode) {
		printf("%-6d%-30s%-10d%30s\n", i, TempNode->name, TempNode->age, TempNode->homeTown);
		i++;
		TempNode = TempNode->next;
	}
}

int main() {
	SinhVien *S1, *V1;
	S1 = NULL;
	int n, age;
	char name[30], homeTown[30];
	while(1) {
		printf("Application Manager Student Name\n");
		printf("Enter 1: Bo sung danh sach\n");
		printf("Enter 2: Sap xep danh sach theo thu tu ABC\n");
		printf("Enter 3: In danh sach\n");
		printf("Enter 4: Thoat\n");
		
		printf("Nhap lua chon: "); scanf("%d", &n);
		switch(n) {
			case 1:
				printf("Enter name: "); 
				fflush(stdin); gets(name);
				printf("Enter age: ");
				scanf("%d", &age);
				printf("Enter que quan: ");
				fflush(stdin); gets(homeTown);
				S1 = InsertToLast(S1,name,age,homeTown);
				break;
			case 2:
				sapxep(S1);
				break;
			case 3:
				printInformation(S1);
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
