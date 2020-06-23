#define _CRT_SECURE_NO_WARNINGS
#define MAX_STR 25
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "lists.h"

struct lake {
	char name[MAX_STR];
	char country[MAX_STR] ;
	char deep[MAX_STR];
	char salt[MAX_STR];
};

/*
Данная функция считывает из файла по 4 строки и заполняет структуру данными, а также проверяет хватает ли в структуре места для записи.
int index - это переменная, которая возвращяется функцией и показывает сколько блоков структуры было считано.
FILE k - указатель на файл.
struct lake lakes - структура, содержащая в себе 4 строки(name, country, deep, salt).
char str - временный массив, через который будет проверятся строка на переполнение.
*/
/*
int show_list(FILE* k, struct lake* lakes) {
	char str[100];
	int index = 0;

	while (!feof(k)) {
		fgets(str, sizeof(str), k);
		if (strlen(str) >= MAX_STR) {
			strcpy(str, "Строка переполнена\n");
		}
		strcpy(lakes[index].name, str);
		fgets(str, sizeof(str), k);
		if (strlen(str) >= MAX_STR) {
			strcpy(str, "Строка переполнена\n");
		}
		strcpy(lakes[index].country, str);
		fgets(str, sizeof(str), k);
		if (strlen(str) >= MAX_STR) {
			strcpy(str, "Строка переполнена\n");
		}
		strcpy(lakes[index].deep, str);
		fgets(str, sizeof(str), k);
		if (strlen(str) >= MAX_STR) {
			strcpy(str, "Строка переполнена\n");
		}
		strcpy(lakes[index].salt, str);
		index++;
	}
	fseek(k, 0, SEEK_SET);
	return index;
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
			for (int i = 0; i < 12; i++) {
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

			if (dp < 0 || st < 0 || st > 100) {
				printf("Неверно введены условия\n");
				break;
			}

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