#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char number[10];//���
	char name[20];//����
	char author[20];//����
	char publish[50];//������
	char time[20];//����ʱ��
	float price;
} mbook;
typedef struct {
	int count;//��ı���
	mbook book[100];//������100����
} mlibrary;
mlibrary library;

void save() { //����ͼ����Ϣ��
	FILE* fp;
	if ((fp = fopen("library.txt", "w+")) == NULL) {
		printf("\n���ܱ���ͼ����Ϣ\n");
		return;
	}
	fwrite(&library.count, sizeof(int), 1, fp);
	fwrite(library.book, sizeof(library.book[0]), library.count, fp);
}

void putin() {    /*����¼�뺯��*/
	int y = 1;
	system("cls");
	while (y) {
		printf("\t�����������鼮�����:");
		scanf("%s", library.book[library.count].number);
		printf("\t����������:");
		scanf("%s", library.book[library.count].name);
		printf("\t������������:");
		scanf("%s", library.book[library.count].author);
		printf("\t�����������:");
		scanf("%s", library.book[library.count].publish);
		printf("\t���������ʱ��:");
		scanf("%s", library.book[library.count].time);
		printf("\t���������ļ۸�:");
		fflush(stdin);
		scanf("%f", &library.book[library.count].price);
		library.count++;
		printf("\n�Ƿ����¼��(1.����;0,�˳�¼��):");
		fflush(stdin);
		scanf("%d", &y);
		if (y != 1) {
			y = 0;
			break;
		}
	}
	save();
}

void lookup() {
	system("cls");

	printf("ͼ���\tͼ����\t������\t������\t��������\tͼ��۸�\n");
	for (int i = 0; i < library.count; i++) {
		printf("%s\t%s\t%s\t%s\t%s\t%6.2f\n", library.book[i].number, library.book[i].name, library.book[i].author, library.book[i].publish, library.book[i].time, library.book[i].price);
	}
	fflush(stdin);
	getchar();
}

void search_by_name() {        /*���尴������ѯ*/

	char s2[20];
	int flag = 1;
	printf("\n������Ҫ��ѯ������: ");
	fflush(stdin);
	scanf("%s", s2);
	printf("ͼ���\tͼ����\t������\t������\t��������\tͼ��۸�\n");
	for (int i = 0; i < library.count; i++)
		if (strcmp(s2, library.book[i].name) == 0) {
			flag = 0;
			printf("%s\t%s\t%s\t%s\t%s\t%6.2f\n", library.book[i].number, library.book[i].name, library.book[i].author, library.book[i].publish, library.book[i].time, library.book[i].price);
		}
	if (flag) {
		printf("cannot found!");
	}
	fflush(stdin);
	getchar();
}

void search_by_author() {        /*���尴��������ѯ*/
	char s3[20];
	int flag = 1;
	printf("������Ҫ��ѯ���������: ");
	fflush(stdin);
	scanf("%s", s3);
	printf("ͼ���\tͼ����\t������\t������\t��������\tͼ��۸�\n");
	for (int i = 0; i < library.count; i++)
		if (strcmp(s3, library.book[i].author) == 0) {
			flag = 0;
			printf("%s\t%s\t%s\t%s\t%s\t%6.2f\n", library.book[i].number, library.book[i].name, library.book[i].author, library.book[i].publish, library.book[i].time, library.book[i].price);
		}
	if (flag) {
		printf("cannot found!");
	}
	fflush(stdin);
	getchar();
}

void search() {      /*�����ѯ����*/
	int a;
	system("cls");         /*��������*/
	printf("\t\t******************************\n");
	printf("��ʼ��ѯ\n");
	printf("\t\t\t1---------------search_by_name\n");
	printf("\t\t\t2---------------search_by_writer\n");
	printf("\t\t\t0---------------exit\n");
	printf("\t\t******************************\n");
	printf("\t\t��ѡ������Ҫ�Ĳ�ѯ��ʽ:");
	fflush(stdin);
	scanf("%d", &a);
	switch (a) {
	case 1:
		search_by_name();
		break;
	case 2:
		search_by_author();
		break;
	case 0:
		return;
	}
}

void del() {                 /*����ɾ������*/
	char number[10];
	system("cls");            /*����*/
	printf("\n   Please type in the number of the book you want to delete:");
	fflush(stdin);
	scanf("%s", number);
	int i;
	for (i = 0; i < library.count; i++) {
		if (strcmp(number, library.book[i].number) == 0)break;
	}
	if (i != library.count) {
		for (; i < library.count - 1; i++) {
			strcpy(library.book[i].name, library.book[i + 1].name);
			strcpy(library.book[i].number, library.book[i + 1].number);
			strcpy(library.book[i].publish, library.book[i + 1].publish);
			strcpy(library.book[i].author, library.book[i + 1].author);
			strcpy(library.book[i].time, library.book[i + 1].time);
			library.book[i].price = library.book[i + 1].price;
		}
		library.count--;
	}
	else
		printf("\n cannot found!\n");
	save();
	fflush(stdin);
	getchar();
}
void update() { //�޸�ͼ����Ϣ
	char number[10];
	system("cls");            /*����*/
	printf("\n   Please type in the number of the book you want to delete:");
	fflush(stdin);
	scanf("%s", number);
	int i;
	for (i = 0; i < library.count; i++) {
		if (strcmp(number, library.book[i].number) == 0) {
			printf("ͼ���\tͼ����\t������\t������\t��������\tͼ��۸�\n");
			printf("%s\t%s\t%s\t%s\t%s\t%6.2f\n", library.book[i].number, library.book[i].name, library.book[i].author, library.book[i].publish, library.book[i].time, library.book[i].price);
			break;
		}
	}
	if (i != library.count) {
		mbook book;
		printf("\n\t\t�������޸ĺ��ͼ�����Ϣ\n");
		printf("\t������ͼ���:");
		scanf("%s", book.number);
		printf("\t������ͼ����:");
		scanf("%s", book.name);
		printf("\t������������:");
		scanf("%s", book.author);
		printf("\t�����������:");
		scanf("%s", book.publish);
		printf("\t���������ʱ��:");
		scanf("%s", book.time);
		printf("\t���������ļ۸�:");
		fflush(stdin);
		scanf("%f", &book.price);

		strcpy(library.book[i].name, book.name);
		strcpy(library.book[i].number, book.number);
		strcpy(library.book[i].publish, book.publish);
		strcpy(library.book[i].author, book.author);
		strcpy(library.book[i].time, book.time);
		library.book[i].price = book.price;
		save();
	}
	else
		printf("\n cannot found!\n");
	fflush(stdin);
	getchar();
}
int main() {
	FILE* fp;
	if ((fp = fopen("library.txt", "r")) == NULL) {
		printf("\n���ܴ�ͼ����Ϣ��\n");
		fp = fopen("library.txt", "w+");
		printf("\n��ʼ��ͼ����Ϣ��,��ʼ��֮��Ҫ��������\n");
		library.count = 0;
		fwrite(&library.count, sizeof(int), 1, fp);
		fclose(fp);
		return 0;
	}
	fread(&library.count, sizeof(int), 1, fp);
	fread(library.book, sizeof(library.book[0]), library.count, fp);
	fclose(fp);
	int a;
	do {
		system("cls");
		printf("\n\n\n\n\n\t\t\t\tͼ����Ϣ����ϵͳ\t\t\t\t\n");
		printf("\t\t*********************************************\n");
		printf("\t\t\t1 ------------------ͼ����Ϣ¼��\n");
		printf("\t\t\t2 ------------------ͼ����Ϣ���\n");
		printf("\t\t\t3 ------------------ͼ����Ϣ��ѯ\n");
		printf("\t\t\t4 ------------------ͼ����Ϣɾ��\n");
		printf("\t\t\t5 ------------------ͼ����Ϣ�޸�\n");
		printf("\t\t\t0 -----------------�˳�ͼ����Ϣϵͳ\n");
		printf("\t\t*********************************************\n");
		printf("\t\tPlease Enter Choose:    ");
		fflush(stdin);
		scanf("%d", &a);
		switch (a) {
		case 1:
			putin();
			break;
		case 2:
			lookup();
			break;
		case 3:
			search();
			break;
		case 4:
			del();
			break;
		case 5:
			update();
			break;
		case 0:
			printf("\n\n�˳�\n\n");
			break;
		default:
			printf("\n��Ų���\n");
		}
	} while (a != 0);
	save();
}