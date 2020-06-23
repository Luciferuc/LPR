#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct lake {
	char name[25];
	char country[25] ;
	char deep[25] ;
	char salt[25] ;
};

/*
Данная функция считывает из файла по 4 строки и заполняет структуру данными.
int index - это переменная, которая возвращяется функцией и показывает сколько блоков структуры было считано.
FILE k - указатель на файл.
struct lake lakes - структура, содержащая в себе 4 строки(name, country, deep, salt)
*/
int show_list(FILE* k, struct lake* lakes) {
	int index = 0;
	while (!feof(k)) {
			fgets(lakes[index].name, sizeof(lakes[index].name), k);
			fgets(lakes[index].country, sizeof(lakes[index].country), k);
			fgets(lakes[index].deep, sizeof(lakes[index].deep), k);
			fgets(lakes[index].salt, sizeof(lakes[index].salt), k);
		index++;
	}
	fseek(k, 0, SEEK_SET);
	return index;
}
/*
void error() {
	while (!feof(k)) {
	if()
	}
	if (fscanf(k, "%s", sizeof())) {}
}
*/
int main() {

	setlocale(LC_ALL, "Rus");

	FILE* k;
	struct lake lakes[25];

	int index, wt = 0;
	float dp = 0, st = 0;
	double ds = 0, dc = 0;

	if ((k = fopen("lakes.txt", "r")) == NULL) {
		printf("Ошибка открытия файла, создание нового файла\n");
		k = fopen("lakes.txt", "w");
	}

	for (;;) {
		printf("Введите действие: ");
		scanf_s("%i", &wt);
		switch (wt) {
		case 1: 
			index = show_list(k, lakes);
			for (int i = 0; i < index; i++) {
				printf("%s", lakes[i].name);
				printf("%s", lakes[i].country);
				printf("%s", lakes[i].deep);
				printf("%s\n", lakes[i].salt);
			}
			printf("\n"); 
			break;
		case 2: 
			printf("Введите глубину: ");
			scanf_s("%f", &dp);
			printf("Введите соленость: ");
			scanf_s("%f", &st);
			printf("\n");

			index = show_list(k, lakes);
			for (int i = 0; i < index; i++) {
				ds = atof(lakes[i].deep);
				dc = atof(lakes[i].salt);
				if (ds < dp && dc > st) {
					printf("%s", lakes[i].name);
					printf("%s", lakes[i].country);
					printf("%s", lakes[i].deep);
					printf("%s\n", lakes[i].salt);
				}
			}
			fseek(k, 0, SEEK_SET);
			printf("\n");
			break;
		case 0: fclose(k); exit(0);
		default: printf("Неверно введено действие\n");
		}
	}
}