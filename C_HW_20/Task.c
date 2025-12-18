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