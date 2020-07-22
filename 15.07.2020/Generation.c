#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
char* GeneratePesswordLengthN(int N, char* AfterChance) {
	N = abs(N);
	srand(time(NULL));
	char* Ans = malloc(N * sizeof(char));
	for (int i = 0; i < N; i++) {
		Ans[i] = AfterChance[ rand() % (strlen(AfterChance) - ' ') +' '];
	}
	Ans[N] = '\0';
	return Ans;
}
char* GeneratePesswordLengthAToZ(int A, int Z, char* AfterChance) {
	srand(time(NULL));
	A = abs(A);
	Z = abs(Z);
	int Length = A;
	if (A != Z) {
		Length = rand() % (Z - A) + A;
	}
	return GeneratePesswordLengthN(Length, AfterChance);
}