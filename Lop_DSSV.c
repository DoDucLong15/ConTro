#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LOP 100

typedef struct dssv {
	char shsv[20];
	char *Hoten;
	struct Date {
		int Ng;
		int Th;
		int Na;
	} ngaysinh;
	char gioi;
	float diem;
	struct dssv * next;
} SV;

typedef struct dslop {
	char* tenlop;
	struct dslop *nextlop;
	struct dssv *firstsvOflop;
} Lop;

SV* creatSV(char shsv[], char* Hoten, struct Date ngaysinh, char gioi, float diem) {
	SV* newNode = (SV*)malloc(sizeof(SV));
	strcpy(newNode->shsv, shsv);
	newNode->Hoten = Hoten;
	newNode->ngaysinh.Ng = ngaysinh.Ng;
	newNode->ngaysinh.Th = ngaysinh.Th;
	newNode->ngaysinh.Na = ngaysinh.Na;
	newNode->gioi = gioi;
	newNode->diem = diem;
	newNode->next = NULL;
}

SV* insertSV(SV* head, char shsv[], char* Hoten, struct Date ngaysinh, char gioi, float diem) {
	SV* newNode = creatSV(shsv, Hoten, ngaysinh, gioi, diem);
	if(head==NULL) {
		head = newNode;
	}
	else {
		SV* p = head;
		while(p->next != NULL) {
			p = p->next;
		}
		p->next = newNode;
	}
	return head;
}

Lop* creatLop(char* tenlop, SV* headSV) {
	Lop* newNode = (Lop*)malloc(sizeof(Lop));
	newNode->tenlop = tenlop;
	newNode->firstsvOflop = headSV;
	newNode->nextlop = NULL;
	return newNode;
}

Lop* insertLop(Lop* head, char* tenlop, SV* headSV) {
	Lop* newNode = creatLop(tenlop, headSV);
	if(head==NULL) {
		head = newNode;
	}
	else {
		Lop* p = head;
		while(p->nextlop != NULL) {
			p = p->nextlop;
		}
		p->nextlop = newNode;
	}
	return head;
}

void showLop(Lop* head) {
	Lop* p = head;
	while(p) {
		printf("------\n");
		printf("Ten lop: %s\n", p->tenlop);
		printf("DANH SACH SINH VIEN\n");
		printf("%-5s%-15s%-30s%-30s%-10s%10s\n", "STT", "Ma so SV", "Ho va ten", "Ngay sinh", "Gioi tinh", "Diem");
		SV* q = p->firstsvOflop;
		int i =1;
		while(q) {
			printf("%-5d%-15s%-30s%d-%d-%d%-21s%-10s%10.1f\n", i, q->shsv, q->Hoten, q->ngaysinh.Ng, q->ngaysinh.Th, q->ngaysinh.Na, " ", (q->gioi=='0') ? "Nu" : "Nam", q->diem);
			i++;
			q = q->next;
		}
		p = p->nextlop;
	}
}

void sortName(Lop* head) {
	char shsv[9];
	char* Hoten;
	struct Date ngaysinh;
	int Ng, Th, Na;
	char gioi;
	float diem;
	Lop* p = head;
	while(p) {
		SV *a, *b;
		for(a=p->firstsvOflop; a!=NULL; a=a->next)
			for(b=a->next; b!=NULL; b=b->next)
				if(strcmp(a->Hoten, b->Hoten)>0) {
					strcpy(shsv, a->shsv); strcpy(a->shsv, b->shsv); strcpy(b->shsv, shsv);
					strcpy(Hoten, a->Hoten); strcpy(a->Hoten, b->Hoten); strcpy(b->Hoten, Hoten);
					Ng = a->ngaysinh.Ng; a->ngaysinh.Ng = b->ngaysinh.Ng; b->ngaysinh.Ng = Ng;
					Th = a->ngaysinh.Th; a->ngaysinh.Th = b->ngaysinh.Th; b->ngaysinh.Th = Th;
					Na = a->ngaysinh.Na; a->ngaysinh.Na = b->ngaysinh.Na; b->ngaysinh.Na = Na;
					gioi = a->gioi; a->gioi = b->gioi; b->gioi = gioi;
					diem = a->diem; a->diem = b->diem; b->diem = diem;
				}
		p = p->nextlop;
	}
}

int main() {
	Lop* head = NULL;
	SV* firstSV[MAX_LOP];
	int soLop = 0, option, soSV, i;
	char tenLop[MAX_LOP][10];

	while(1) {
		printf("=====================================================\n");
		printf("Application manager Classroom\n");
		printf("Enter 1: Them lop\n");
		printf("Enter 2: Sap xep hsinh cac lop theo bang chu cai\n");
		printf("Enter 3: Hien thi danh sach hoc sinh cac lop\n");
		printf("Enter 4: Thoat\n");
		printf("=====================================================\n");

		printf("Nhap lua chon: ");
		scanf("%d", &option);
		getchar();
		switch(option) {
			case 1:
				printf("Enter ten lop: ");
				fgets(tenLop[soLop], 10, stdin); fflush(stdin);
				tenLop[soLop][strlen(tenLop[soLop])-1] = '\0';
				printf("Enter so sinh vien: ");
				scanf("%d", &soSV);
				getchar();
				//
				char shsv[20];
				char Hoten[100][30];
				struct Date ngaysinh;
				int Ng, Th, Na;
				char gioi;
				float diem;
				//
				for(i=0; i<soSV; i++) {
					printf("Nhap thong tin sinh vien thu %d:\n", (i+1));
					printf("Enter ma so Sv: ");
					fgets(shsv, 20, stdin); fflush(stdin);
					shsv[strlen(shsv)-1] = '\0';
					printf("Enter name: ");
					fgets(Hoten[i], 30, stdin); fflush(stdin);
					Hoten[i][strlen(Hoten[i])-1] = '\0';
					printf("Enter ngay, thang, nam sinh: ");
					scanf("%d %d %d", &Ng, &Th, &Na);
					ngaysinh.Ng = Ng; ngaysinh.Th = Th; ngaysinh.Na = Na;
					printf("Enter gioi tinh(0-Nu, 1-Nam): ");
					scanf("%c", &gioi);
					getchar();
					printf("Enter diem: ");
					scanf("%f", &diem);
					getchar();
					firstSV[soLop] = insertSV(firstSV[soLop], shsv, Hoten[i], ngaysinh, gioi, diem);
				}
				head = insertLop(head, tenLop[soLop], firstSV[soLop]);
				soLop++;
				break;
			case 2:
				sortName(head);
				break;
			case 3:
				showLop(head);
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
