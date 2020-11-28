#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char number[10];//书号
	char name[20];//书名
	char author[20];//作者
	char publish[50];//出版社
	char time[20];//出版时间
	float price;
} mbook;
typedef struct {
	int count;//书的本数
	mbook book[100];//最大可有100本书
} mlibrary;
mlibrary library;

void save() { //保存图书信息。
	FILE* fp;
	if ((fp = fopen("library.txt", "w+")) == NULL) {
		printf("\n不能保存图书信息\n");
		return;
	}
	fwrite(&library.count, sizeof(int), 1, fp);
	fwrite(library.book, sizeof(library.book[0]), library.count, fp);
}

void putin() {    /*定义录入函数*/
	int y = 1;
	system("cls");
	while (y) {
		printf("\t请输入您的书籍的书号:");
		scanf("%s", library.book[library.count].number);
		printf("\t请输入书名:");
		scanf("%s", library.book[library.count].name);
		printf("\t请输入作者名:");
		scanf("%s", library.book[library.count].author);
		printf("\t请输入出版社:");
		scanf("%s", library.book[library.count].publish);
		printf("\t请输入出版时间:");
		scanf("%s", library.book[library.count].time);
		printf("\t请输入该书的价格:");
		fflush(stdin);
		scanf("%f", &library.book[library.count].price);
		library.count++;
		printf("\n是否继续录入(1.继续;0,退出录入):");
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

	printf("图书号\t图书名\t作者名\t出版社\t出版日期\t图书价格\n");
	for (int i = 0; i < library.count; i++) {
		printf("%s\t%s\t%s\t%s\t%s\t%6.2f\n", library.book[i].number, library.book[i].name, library.book[i].author, library.book[i].publish, library.book[i].time, library.book[i].price);
	}
	fflush(stdin);
	getchar();
}

void search_by_name() {        /*定义按书名查询*/

	char s2[20];
	int flag = 1;
	printf("\n请输入要查询的书名: ");
	fflush(stdin);
	scanf("%s", s2);
	printf("图书号\t图书名\t作者名\t出版社\t出版日期\t图书价格\n");
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

void search_by_author() {        /*定义按作者名查询*/
	char s3[20];
	int flag = 1;
	printf("请输入要查询的书的作者: ");
	fflush(stdin);
	scanf("%s", s3);
	printf("图书号\t图书名\t作者名\t出版社\t出版日期\t图书价格\n");
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

void search() {      /*定义查询函数*/
	int a;
	system("cls");         /*进行清屏*/
	printf("\t\t******************************\n");
	printf("开始查询\n");
	printf("\t\t\t1---------------search_by_name\n");
	printf("\t\t\t2---------------search_by_writer\n");
	printf("\t\t\t0---------------exit\n");
	printf("\t\t******************************\n");
	printf("\t\t请选择你想要的查询方式:");
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

void del() {                 /*定义删除函数*/
	char number[10];
	system("cls");            /*清屏*/
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
void update() { //修改图书信息
	char number[10];
	system("cls");            /*清屏*/
	printf("\n   Please type in the number of the book you want to delete:");
	fflush(stdin);
	scanf("%s", number);
	int i;
	for (i = 0; i < library.count; i++) {
		if (strcmp(number, library.book[i].number) == 0) {
			printf("图书号\t图书名\t作者名\t出版社\t出版日期\t图书价格\n");
			printf("%s\t%s\t%s\t%s\t%s\t%6.2f\n", library.book[i].number, library.book[i].name, library.book[i].author, library.book[i].publish, library.book[i].time, library.book[i].price);
			break;
		}
	}
	if (i != library.count) {
		mbook book;
		printf("\n\t\t请输入修改后此图书的信息\n");
		printf("\t请输入图书号:");
		scanf("%s", book.number);
		printf("\t请输入图书名:");
		scanf("%s", book.name);
		printf("\t请输入作者名:");
		scanf("%s", book.author);
		printf("\t请输入出版社:");
		scanf("%s", book.publish);
		printf("\t请输入出版时间:");
		scanf("%s", book.time);
		printf("\t请输入该书的价格:");
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
		printf("\n不能打开图书信息库\n");
		fp = fopen("library.txt", "w+");
		printf("\n初始化图书信息库,初始化之后要重启程序\n");
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
		printf("\n\n\n\n\n\t\t\t\t图书信息管理系统\t\t\t\t\n");
		printf("\t\t*********************************************\n");
		printf("\t\t\t1 ------------------图书信息录入\n");
		printf("\t\t\t2 ------------------图书信息浏览\n");
		printf("\t\t\t3 ------------------图书信息查询\n");
		printf("\t\t\t4 ------------------图书信息删除\n");
		printf("\t\t\t5 ------------------图书信息修改\n");
		printf("\t\t\t0 -----------------退出图书信息系统\n");
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
			printf("\n\n退出\n\n");
			break;
		default:
			printf("\n序号不对\n");
		}
	} while (a != 0);
	save();
}