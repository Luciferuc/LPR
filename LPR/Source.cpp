#define _CRT_SECURE_NO_WARNINGS
#define MAX_STR 25
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "lists.h"

struct lake {
	char name[MAX_STR];
	char country[MAX_STR];
	char deep[MAX_STR];
	char salt[MAX_STR];
};

int show_list(FILE* k, struct lake *lakes) {
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