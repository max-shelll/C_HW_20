# Домашнее задание к работе 20

## Условие задачи
Считать текстовsй файл winter.txt и выполнить над тестом    
преобразование согласно варианту (полученный вариант текст записать     
новый файл с именем, указанным пользователем):     
Первое слово каждой повторить два раза.     

## 1. Реализация программы
```
#include <stdio.h>
#include <locale.h>
#include <string.h>

int dublicateWordInFile(FILE* file, char outFile[100]);

int main() {
	setlocale(LC_CTYPE, "RUS");

	FILE* file = fopen("winter.txt", "r");
	char outFile[100];

	if (file == NULL) {
		puts("Ошибка открытия файла winter.txt");
		return -1;
	}

	printf("Введите имя нового файла: ");
	fgets(outFile, sizeof(outFile), stdin);
	outFile[strcspn(outFile, "\n")] = '\0';

	int res = dublicateWordInFile(file, outFile);
	if (res == -1) {
		puts("Ошибка открытия файла");
		fclose(file);
		return -1;
	}

	printf("Файл успешно обработан.\n");
	fclose(file);
	return 0;
}

int dublicateWordInFile(FILE* file, char outFile[100]) {
	FILE* newFile = fopen(outFile, "w");
	char line[200];
	char firstWord[200];

	if (newFile == NULL) {
		return -1;
	}

	while (!feof(file)) {
		if (fscanf(file, "%s", firstWord) != 1)
			break;

		fgets(line, sizeof(line), file);
		fprintf(newFile, "%s %s%s", firstWord, firstWord, line);
	}

	fclose(newFile);
	return 0;
}
```

## 2. Результаты работы программы
```
Введите имя нового файла: test.txt
Файл успешно обработан.
```

## 3. Информация о разработчике

Шалаев Максим [БИЦ-252]
