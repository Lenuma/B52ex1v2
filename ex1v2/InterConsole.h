#ifndef INTER_CONSOLE_H
#define INTER_CONSOLE_H
//Déclaration de fonctions icitte

// Fonctions d'intéraction avec la console
void clearScreen();															// Efface la console
char getUpperChar();														// Fonction retournant la majuscule d'un caractère lu à la console
bool confirm(const char question[], char confirmationChar);					// Efface l'écran, pose une question, attend une touche au clavier
																			//et retourne si la réponse correspond au caractère de comparaison(insensible à la casse)

#endif INTER_CONSOLE_H