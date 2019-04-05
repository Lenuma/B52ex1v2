
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Fonctions utilitaires
void int2bin(int value, size_t nFirstDigit, char string[], size_t stringSize)
{
	if (nFirstDigit <= sizeof(int) * 8 && string && nFirstDigit < stringSize) {
		for (size_t i{}; i < nFirstDigit; ++i) {
			string[nFirstDigit - 1 - i] = ((value >> i) & 1 ? '1' : '0');
		}
		string[nFirstDigit] = '\0';
	}
}
bool randomEvent()
{
	return rand() < RAND_MAX / 2;
}