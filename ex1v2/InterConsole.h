#ifndef INTER_CONSOLE_H
#define INTER_CONSOLE_H
//D�claration de fonctions icitte

// Fonctions d'int�raction avec la console
void clearScreen();															// Efface la console
char getUpperChar();														// Fonction retournant la majuscule d'un caract�re lu � la console
bool confirm(const char question[], char confirmationChar);					// Efface l'�cran, pose une question, attend une touche au clavier
																			//et retourne si la r�ponse correspond au caract�re de comparaison(insensible � la casse)

#endif INTER_CONSOLE_H