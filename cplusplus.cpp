#include<stdio.h>
#include<stdlib.h>

typedef struct quanLiFresher
{
	char MSNV;
	char ten;
	char account;
	float diemTB;
	struct quanLiFresher *next;
};
typedef quanLiFresher *list;

quanLiFresher *makeNode(quanLiFresher*, char MSNV[10], char ten[20], char account[10], float diem);
void themNhanVien(list &L, char MSNV[10], char ten[20], char account[10], float diem);
int timTen(list l, char ten[20]);
int timMSNV(list l, char MSNV[10]);
int timDiem(list l, float diem);
int timAccount(list l, char account[10]);

int main() {

}

quanLiFresher *makeNode(quanLiFresher* nhanVien, char MSNV[10], char ten[20], char account[10], float diem) {
	nhanVien = ( quanLiFresher*) malloc(sizeof(quanLiFresher));
	nhanVien->next = NULL;
	nhanVien->MSNV = *MSNV;
	nhanVien->ten = *ten;
	nhanVien->account = *account;
	nhanVien->diemTB = diem;
	return nhanVien;
}

void themNhanVien(list &L, char MSNV[10], char ten[20], char account[10], float diem) {
	quanLiFresher *nhanVien;
	nhanVien = makeNode(nhanVien, MSNV, ten, account, diem);
	nhanVien->next = L;
	L = nhanVien;
}

int timTen(list l, char ten[20]) {
	quanLiFresher *nhanVien = l;
	int i = 1;
	while (nhanVien != NULL && nhanVien->ten != *ten) {
		nhanVien = nhanVien->next;
		i++;
	}
	if (nhanVien != NULL) return i;
	else return 0;
}

int timMSNV(list l, char MSNV[10]) {
	quanLiFresher *nhanVien = l;
	int i = 1;
	while (nhanVien != NULL && nhanVien->MSNV != *MSNV) {
		nhanVien = nhanVien->next;
		i++;
	}
	if (nhanVien != NULL) return i;
	else return 0;
}

int timDiem(list l, float diem) {
	quanLiFresher *nhanVien = l;
	int i = 1;
	while (nhanVien != NULL && nhanVien->diemTB != diem) {
		nhanVien = nhanVien->next;
		i++;
	}
	if (nhanVien != NULL) return i;
	else return 0;
}

int timAccount(list l, char account[10]) {
	quanLiFresher *nhanVien = l;
	int i = 1;
	while (nhanVien != NULL && nhanVien->account != *account) {
		nhanVien = nhanVien->next;
		i++;
	}
	if (nhanVien != NULL) return i;
	else return 0;
}

void xoaMSNV(list l, char msnv[10], char )