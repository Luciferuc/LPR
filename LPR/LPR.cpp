#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void show_list(FILE *k) {
	char lakes[300] = { '\0' };

	while (fgets(lakes, sizeof(lakes), k) != NULL) {
		printf("%s", lakes);
	}
	printf("\n");
	fseek(k, 0, SEEK_SET);
}

void wanted_options(FILE* k) {
	char lakes[300] = { '\0' };
	char tmp[300] = { '\0' };
	int index = 0;
	float dp = 0, st = 0, ds = 0, dc = 0;

	printf("Введите глубину: ");
	scanf_s("%f", &dp);
	printf("Введите соленость: ");
	scanf_s("%f", &st);
	printf("\n");

	while (fgets(lakes, sizeof(lakes), k) != NULL) {
		strcat(tmp, lakes);
		if ((++index % 2) == 0) {
			fscanf(k, "%f", &ds);
			if ((++index % 3) == 0) {
				fscanf(k, "%f", &dc);
				if (ds < dp && dc >= st) {
					printf("%s", tmp);
					printf("%.1f\n", ds);
					printf("%.1f\n", dc);
					strcpy(tmp, "");
				}
				else {
					strcpy(tmp, "");
				}
			}
		}
	}
	printf("\n");
	fseek(k, 0, SEEK_SET);
}

int main() {

	setlocale(LC_ALL, "Rus");

	FILE* k;
	int wt = 0;

	if ((k = fopen("lakes.txt", "r")) == NULL) {
		printf("Ошибка открытия файла, создание нового файла\n");
		k = fopen("lakes.txt", "w");
	}

	for (;;) {
		printf("Введите действие: ");
		scanf_s("%i", &wt);
		switch (wt) {
		case 1: show_list(k); break;
		case 2: wanted_options(k); break;
		case 0: fclose(k); exit(0);
		default: printf("Неверно введено действие\n");
		}
	}
}