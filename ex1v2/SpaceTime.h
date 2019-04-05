#ifndef SPACE_TIME_H
#define SPACE_TIME_H
#include "Rule.h"
#include <math.h>
// Declaration de constantes
														
const char stateActive{ '*' };														// Caractère représentant un état actif
const char stateInactive{ ' ' };													// Caractère représentant un état inactif
const size_t evolutionCount{ 24 };													// Nombre d'évolutions
const size_t timeSize{ evolutionCount + 1 };										// Taille du temps
// Declaration de types
typedef Space SpaceTime[timeSize];													// Type représentant l'espace dans le temps	=> SpaceTime est un :	bool [80][24] 

																					// SpaceTime
void initializeSpaceTime(SpaceTime spaceTime);										// Initialise toute la simulation à false
int getNeighborhoodFromSpaceTime(SpaceTime spaceTime, size_t iTime, size_t iSpace); // Retourne la valeur du voisinage de la cellule à traiter (8 valeurs possibles entre 000 et 111)
void evolveOverSpace(SpaceTime spaceTime, Rule rule, size_t currentTime);			// Effectue l'évolution pour un temps donné
void evolveOverTime(SpaceTime spaceTime, Rule rule);								// Effectue l'évolution pour toute la simulation
void evolve(SpaceTime spaceTime, size_t ruleValue);									// Effectue l'assignation de la règle et effectue l'évolution
void showSpaceTime(SpaceTime spaceTime, bool showTime);								// Affiche l'image créée par une simulation

#endif SPACE_TIME_H