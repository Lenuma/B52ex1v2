#ifndef SPACE_TIME_H
#define SPACE_TIME_H
#include "Rule.h"
#include <math.h>
// Declaration de constantes
														
const char stateActive{ '*' };														// Caract�re repr�sentant un �tat actif
const char stateInactive{ ' ' };													// Caract�re repr�sentant un �tat inactif
const size_t evolutionCount{ 24 };													// Nombre d'�volutions
const size_t timeSize{ evolutionCount + 1 };										// Taille du temps
// Declaration de types
typedef Space SpaceTime[timeSize];													// Type repr�sentant l'espace dans le temps	=> SpaceTime est un :	bool [80][24] 

																					// SpaceTime
void initializeSpaceTime(SpaceTime spaceTime);										// Initialise toute la simulation � false
int getNeighborhoodFromSpaceTime(SpaceTime spaceTime, size_t iTime, size_t iSpace); // Retourne la valeur du voisinage de la cellule � traiter (8 valeurs possibles entre 000 et 111)
void evolveOverSpace(SpaceTime spaceTime, Rule rule, size_t currentTime);			// Effectue l'�volution pour un temps donn�
void evolveOverTime(SpaceTime spaceTime, Rule rule);								// Effectue l'�volution pour toute la simulation
void evolve(SpaceTime spaceTime, size_t ruleValue);									// Effectue l'assignation de la r�gle et effectue l'�volution
void showSpaceTime(SpaceTime spaceTime, bool showTime);								// Affiche l'image cr��e par une simulation

#endif SPACE_TIME_H