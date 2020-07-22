#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include"Chance.h"
#include"Generation.h"
int main(int argc, char* argv[]) {
	int mIndecator = 0;
	int minLength = 0;
	int MIndecator = 0;
	int MaxLength = 0;
	int NIndecator = 0;
	int Length = 0;
	int aIndecator = 0;
	char* Alphabet = malloc(0 * sizeof(char));
	int cIndecator = 0;
	int VIndecator = 0;
	char* Set = malloc(0 * sizeof(char));
	int* Array = malloc(sizeof(int));
	int size = 1;
	Array[0] = 0;
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			if (argv[i][0] == '-' && argv[i][1] == 'm' && strlen(argv[i]) == 2) {
				if (mIndecator == 1) {
					printf("You printf >=2 -m\n");
					system("pause");
					return 0;
				}
				if (i + 1 == argc) {
					printf("You don't write -m indicator\n");
					system("pause");
					return 0;
				}
				mIndecator = 1;
				minLength = atoi(argv[i + 1]);
			}
			if (argv[i][0] == '-' && argv[i][1] == 'M' && strlen(argv[i]) == 2) {
				if (MIndecator == 1) {
					printf("You printf >=2 -M\n");
					system("pause");
					return 0;
				}
				MIndecator = 1;
				if (i + 1 == argc) {
					printf("You don't write -M indicator\n");
					system("pause");
					return 0;
				}
				MaxLength = atoi(argv[i + 1]);
			}
			if (argv[i][0] == '-' && argv[i][1] == 'n' && strlen(argv[i]) == 2) {
				if (NIndecator == 1) {
					printf("You printf >=2 -n\n");
					system("pause");
					return 0;
				}
				if (i + 1 == argc) {
					printf("You don't write -n indicator\n");
					system("pause");
					return 0;
				}
				NIndecator = 1;
				Length = atoi(argv[i + 1]);
			}
			if (argv[i][0] == '-' && argv[i][1] == 'a' && strlen(argv[i]) == 2) {
				if (aIndecator == 1) {
					printf("You printf >=2 -a\n");
					system("pause");
					return 0;
				}
				if (i + 1 == argc) {
					printf("You don't write -a indicator\n");
					system("pause");
					return 0;
				}
				aIndecator = 1;
				Alphabet = argv[i + 1];
			}
			if (argv[i][0] == '-' && argv[i][1] == 'C' && strlen(argv[i]) == 2) {
				if (cIndecator == 1) {
					printf("You printf >=2 -C\n");
					system("pause");
					return 0;
				}
				if (strlen(argv[i]) == 2) {
					printf("You printf incorrect -C\n");
					system("pause");
					return 0;
				}
					cIndecator = 1;
					Set = argv[i];
			}
			if (argv[i][0] == '-' && argv[i][1] == 'v' && strlen(argv[i]) == 2) {
				if (VIndecator == 1) {
					printf("You printf >=2 -v\n");
					system("pause");
					return 0;
				}
				if (i + 1 == argc) {
					printf("You don't write -v indicator\n");
					system("pause");
					return 0;
				}
				VIndecator = 1;
				char* NextStr = argv[i + 1];
				char* Rasdel = ".";
				Array[size - 1] = atoi(strtok(NextStr, Rasdel));
				size++;
				while (1)
				{
					char* instr = strtok(NULL, Rasdel);
					if (instr == NULL) { 
						break; 
					}
					Array = realloc(Array, size * sizeof(int));
					Array[size - 1] = atoi(instr);
					size++;
				}
				size--;
				Array = realloc(Array, size * sizeof(int));
			}
		}
	}
	if (((mIndecator == 1 || MIndecator == 1) && NIndecator == 1) || (mIndecator == 0 && MIndecator == 0 && NIndecator == 0) || (mIndecator==0 && MIndecator==1) || (mIndecator == 1 && MIndecator == 0)) {
		printf("You write incorrect size length -m and -M or -n\n");
		system("pause");
		return 0;
	}
	else
	{
		if ((aIndecator == 1 && cIndecator == 1) || (aIndecator == 0 && cIndecator == 0)) {
			printf("You write incorrect Alphabet or Sets\n");
			system("pause");
			return 0;
		}
		else
		{
			char* Ans = malloc(0 * sizeof(char));
			if (aIndecator == 1 && NIndecator == 1) {
				Ans = GeneratePesswordLengthN(Length, ChanceOfAlpabet(Alphabet,Array,size));
			}
			if (aIndecator == 1 && mIndecator == 1 && MIndecator == 1) {
				Ans = GeneratePesswordLengthAToZ(minLength, MaxLength, ChanceOfAlpabet(Alphabet, Array,size));
			}
			if (cIndecator == 1 && NIndecator == 1) {
				Ans = GeneratePesswordLengthN(Length, ÑhanceOnSet(Set,Array,size));
			}
			if (cIndecator == 1 && mIndecator == 1 && MIndecator == 1) {
				Ans = GeneratePesswordLengthAToZ(minLength, MaxLength, ÑhanceOnSet(Set, Array,size));
			}
			printf("Password = %s\n", Ans);
		}
	}
	return 0;
}