#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num = 0;
char name[20];
char yazar[20];
int hash = 0;
int index[30][6];


 

void insertbook() {

	printf("Kitap no giriniz.(1-150)");
	scanf("%d", &num);
	printf("Kitap adi giriniz.");
	scanf("%s", name);
	printf("yazar adi gir.");
	scanf("%s", yazar);
	FILE *f = fopen("books.txt", "a+");

	if (f == NULL)
	{
		printf("Dosya acilamadi!\n");
		exit(1);
	}
	fprintf(f, "%d %s %s\n", num, name, yazar);
	fclose(f);

    FILE *d = fopen("index.txt", "w+");
	  if (d == NULL) { // dosya oluşmamışsa oluşturacak
		d = fopen("index.txt", "a+");
		if (d == NULL) {
			printf("dosya acilamadi.");
			return;
		}
		for (int i = 0;i < 30;i++) {
			//int k = 1;
			index[i][0] = i;
			for (int k = 1;k < 6;k++) {
				index[i][k] = NULL;

			}
		}
		hash = num % 30;
		for (int i = 0;i < 6;i++) {
			if (index[hash][i] == NULL) {
				index[hash][i] = num;
				break;
			}
		}
		for (int i = 0;i < 30;i++) {
			for (int j = 0;j < 6;j++) {
				fprintf(d, "%d ", index[i][j]);
			}
			fprintf(d, "\n");
		}
		fclose(d);
	  }

	else
	{
		for (int i = 0;i < 30;i++) {
			fscanf(f, "%d%d%d%d%d%d\n", &index[i][0], &index[i][1], &index[i][2], &index[i][3], &index[i][4], &index[i][5]); // önceki index bilgilerini tutuyor
		}
		hash = num % 30;
		for (int i = 0;i < 6;i++) {
			if (index[hash][i] == NULL) {
				index[hash][i] = num;
				break;
			}
		}
		for (int i = 0;i < 30;i++) {
			for (int j = 0;j < 6;j++) {
				fprintf(d, "%d ", index[i][j]); //dolan (değişen) yerleri yazıyor
			}
			fprintf(d, "\n");
		}
		fclose(d);
	}
}
void kitapfonk(int a) {
	
	FILE *f = fopen("books.txt", "r");
	while (!feof(f)) {
		fscanf(f, "%d %s %s\n", &num,name,yazar);
		if (num == a) {
			printf("%s\t",name);
		}

	}


	fclose(f);
}
void list_all() {
	int a, b, c, de, f, g;
	FILE *dosya = fopen("index.txt", "r");
	while (!feof(dosya)) {
		
		fscanf(dosya, "%d %d %d %d %d %d\n", &a, &b, &c, &de, &f, &g);
		//printf("%d\t", a);
		if (a == 0) {
			printf("%d ", a);
		}
		else kitapfonk(a); //doluysa kitap ismi yazılıyor
		if (b == 0) {
			printf("%d ", b);
		}
		else kitapfonk(b);
		if (c ==0) {
			printf("%d ", c);

		}
		else kitapfonk(c);
		if (de == 0) {
			printf("%d ", de);
		}
		else kitapfonk(de);
		if (f ==0) {
			printf("%d \n", f);
		}
		else kitapfonk(f);
		//printf("%d\n", g);


	}
	
	fclose(dosya);
}
void search() {
	char search[20];
	printf("aradiginiz kitabın adini girin.\n");
	scanf("%s", search);
	FILE *f = fopen("books.txt", "r");
	while (!feof(f)) {
		fscanf(f, "%d %s %s", &num, name, yazar);
		if (strcmp(name, search) == 0) {
			printf("kayit bulundu.\n");
			printf("\n%d %s %s\n", num, name, yazar);
			break;
		}
	}
	fclose(f);
}
void main() {
	int secim;

	
	while (1) {
		printf("1-Insert a book.\n");
		printf("2-Search a book.\n");
		printf("3-List all the bookshelf.\n");
		printf("4-Exit.\n");
		printf("Lutfen secimini giriniz:\n");
		scanf("%d", &secim);
		
		if (secim == 1) {
			insertbook();
}
		if (secim == 2) {
			search();
		}
		if (secim == 3) {
			list_all();

		}
		if (secim == 4) {
			break;
		}

	}
	
	


}
