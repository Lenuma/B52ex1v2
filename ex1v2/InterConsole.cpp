
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

// Fonctions d'intéraction avec la console
void clearScreen()
{
	system("cls");
}

char getUpperChar()
{
	int keyCode{ _getch() };
	if (keyCode == 224) {		// 224 => indicate a special key like arrow
		_getch();				//        next keyCode indicate the special key
		keyCode = 0;
	}
	// Cette fonction gère inadéquatement les clés spéciales et 
	// retourne '\0' au lieu.

	return (char)toupper(keyCode);
}

bool confirm(const char question[], char confirmationChar)
{
	clearScreen();
	printf("%s", question);

	return getUpperChar() == (char)toupper(confirmationChar);
}