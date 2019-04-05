// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Exercice 1 
//	version 1
// 
// Exercice incr�mental d'approfondissement du langage C++
// 
// Auteur : CVM
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Pour cet exemple, les choix suivants ont �t� faits :
//	- chaque cellule poss�de un �tat repr�sent� par un bool		type State
//	- l'espace est repr�sent� par un tableau de cellule			type Space
//	- la simulation est repr�sent�e par un tableau d'espace		type SpaceTime
//	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Notes : 
//	- Afin d'all�ger ce premier exemple, les fonctions r�alis�es g�rent les cas 
//		probl�matiques sans gestion externe. La strat�gie est simpliste : 
//			- chaque fonction valide tous les param�tres d'entr�e :
//				- si tous les param�tres sont valides : r�alise la t�che 
//				- si un param�tre est invalide : la fonction termine sans 
//					r�aliser sa t�che
//		Le probl�me avec cette approche est que le programme continue sans autre 
//		mesure. Cette approche na�ve (et incorrecte) est suffisante pour ce 
//		premier exemple. 
//	- Cet exemple est tr�s pr�s d'un programme en langage C. Sachez que ces 
//		�l�ments du langage C++ n'existent pas en C :
//			- type bool
//	- Cet exemple n'utilise pas les r�f�rences du C++ � titre de d�monstration 
//		p�dagogique. Sachez que leur usage est souhaitable lorque possible.
//	- Cet exemple en est un parmi plusieurs possibles. Il reste simple et 
//		pr�sente plusieurs concepts importants. Plusieurs am�liorations sont 
//		possibles et certains exemples sont donn�s dans les exercices suivants.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Inclusion des librairies
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Inclusion des headers
#include "utilitaires.h"
#include "InterConsole.h"
#include "State.h"
#include "Space.h"
#include "SpaceTime.h"
#include "Ace.h"



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// D�finition des constantes globales (via des variables symboliques)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const size_t ruleCount{ (size_t)pow(2, ruleSize) };
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const char mainTitle[]{ "ACE" };
const char subTitle[]{ "Logiciel de simulation d'un automate cellulaire elementaire" };
const char lineTitle[]{ "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" };
const char menu[]{ "Menu :\n\t(Q)uitter\n\t(R)eprendre la regle\n\t(...) toute autre touche pour poursuivre\n\n\nAppuyez sur une touche pour poursuivre..." };
const char questionToQuit[]{ "Voulez-vous quitter?\n\n\t(O)ui\n\t(...) toute autre touche pour poursuivre" };
const char charQuit{ 'Q' };
const char charRule{ 'R' };
const char charConfirmQuit{ 'O' };

const char spaceQuestion[]{ "Combien voulez-vous de Space (axe des X)?" };
const char spaceTimeQuestion[]{ "Combien voulez-vous de SpaceTime (axe des Y)?" };
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -





// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Point d'entr�e du programme
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int main()
{
	// Initialisation du g�n�rateur de nombre al�atoire
	srand(unsigned int(time(nullptr)));

	// Conteneur de la simulation et initialisation
	size_t currentRule{};
	SpaceTime spaceTime;
	initializeSpaceTime(spaceTime);

	// Message d'accueil
	showWelcomeScreen();

	// Boucle de traitement
	while (simulationStep(spaceTime, &currentRule));

	return 0;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// D�finition des fonctions
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Fonctions g�n�riques
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// Fonctions li�es � l'automate
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -







// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// D�finitions
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void showWelcomeScreen()
{
	printf("\n\n\n%s\n%s\n\n\n%s\n%s\n%s\n", mainTitle, subTitle, menu, spaceQuestion, spaceTimeQuestion);
	getUpperChar();
}

bool simulationStep(SpaceTime spaceTime, size_t * rule)
{
	if (!rule) {
		return false;
	}

	evolve(spaceTime, *rule);
	showOneStep(spaceTime, *rule);
	return getInputUser(rule);
}

void showOneStep(SpaceTime spaceTime, size_t ruleValue)
{
	char ruleBinValue[256];
	int2bin((int)ruleValue, 8, ruleBinValue, 256);

	clearScreen();
	printf("%s\n", lineTitle);
	printf("Current rule : %zd (%s)\n", ruleValue, ruleBinValue);
	printf("%s\n", lineTitle);
	showSpaceTime(spaceTime, true);
}

bool getInputUser(size_t * rule)
{
	if (!rule) {
		return true;
	}

	bool quitting{ false };
	switch (getUpperChar()) {
	case charQuit:
		quitting = isQuitting();
	case charRule:
		break;
	default:
		*rule = (*rule + 1) % ruleCount;
	}

	return !quitting;
}

bool isQuitting()
{
	return confirm(questionToQuit, charConfirmQuit);
}

int utilisateurSpace()
{
	int spaceReponse;
	int spaceTimeReponse;
}

int utilisateurSpaceTime()
{
}


