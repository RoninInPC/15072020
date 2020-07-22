#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
int* ChanceFix(char* Arr, int* Chance, int size) {
	int SizeArr = strlen(Arr);
	Chance = realloc(Chance, (strlen(Arr)) * sizeof(int));
	if (Arr[0] == '-' && Arr[1] == 'C') {
		Chance = realloc(Chance, ((strlen(Arr))-2) * sizeof(int));
		SizeArr -= 2;
	}
	if (size == 1 && Chance[0] == 0) {
		for (int i = 0; i < SizeArr; i++) {
			Chance[i] = 0;
			size = 0;
		}
	}
	int sum = 0;
	if (size > SizeArr) {
		size = SizeArr;
	}
	for (int i = 0; i < size; i++) {
		sum += Chance[i];
	}
	
	int LowHundred = 100 - sum;
	if (LowHundred > 0 && SizeArr == size) {
		Chance[0] += LowHundred;
	}
	for (int i = size; i < SizeArr; i++) {
		if (LowHundred == 0 || SizeArr - size == 0) {
			Chance[i] = 0;
		}
		else {
			Chance[i] = LowHundred / (SizeArr - size);
		}
	}
	return Chance;
}
char* ÑhanceOnSet(char* SetNames, int* Chance, int size) {
	Chance = ChanceFix(SetNames, Chance, size);
	char* ASCII = malloc(128 * sizeof(char));
	for (int i = 0; i < 128; i++) {
		ASCII[i] = 0;
	}
	for (int i = 0; i < strlen(SetNames); i++) {
		if (SetNames[i] == 'a') {
			for (int j = 'a'; j <= 'z'; j++) {

				ASCII[j] = Chance[i - 2];
			}
		}
		if (SetNames[i] == 'A') {
			for (int j = 'A'; j <= 'Z'; j++) {
				ASCII[j] = Chance[i - 2];
			}
		}
		if (SetNames[i] == 'D') {
			for (int j = '0'; j <= '9'; j++) {
				ASCII[j] = Chance[i - 2];
			}
		}
		if (SetNames[i] == 'S') {
			for (int j = 32; j <= 47; j++) {
				ASCII[j] = Chance[i - 2];
			}
			for (int j = 58; j <= 64; j++) {
				ASCII[j] = Chance[i - 2];
			}
			for (int j = 91; j <= 96; j++) {
				ASCII[j] = Chance[i - 2];
			}
			for (int j = 123; j <= 127; j++) {
				ASCII[j] = Chance[i - 2];
			}
		}
	}
	int NewSize = 0;
	for (int i = 0; i < 128; i++) {
		NewSize += ASCII[i];
	}
	char* Ans = malloc(NewSize * sizeof(char));
	int k = 0;
	for (int i = 32; i < 128; i++) {
		for (int j = k; j < k + ASCII[i]; j++) {
			Ans[j] = i;
		}
		k += ASCII[i];
	}
	printf("%s\n", Ans);
	Ans[NewSize] = '\0';
	
	return Ans;
}
char* ChanceOfAlpabet(char* Alphabet, int* Chance, int size) {
	Chance = ChanceFix(Alphabet, Chance, size);
	int NewSize = 0;
	for (int i = 0; i < strlen(Alphabet); i++) {
		NewSize += Chance[i];
	}
	char* Ans = malloc(NewSize * sizeof(char));
	int k = 0;
	for (int i = 0; i < strlen(Alphabet); i++) {
		for (int j = k; j < k + Chance[i]; j++) {
			Ans[j] = Alphabet[i];
		}
		k += Chance[i];
	}
	printf("%s\n", Ans);
	Ans[NewSize] = '\0';
	return Ans;
}