#ifndef SPACE_H
#define SPACE_H
#include "State.h"
// Declaration de constantes
const size_t spaceSize{ 80 };												// Taille de l'espace 

// Declaration de types
typedef State Space[spaceSize];												// Type représentant l'espace => Space est un : bool [80]

// Fonctions
void randomizeSpace(Space space);											// Détermine l'espace aléatoirement
int getNeighborhoodFromSpace(Space space, size_t index);					// Retourne la valeur du voisinage de la cellule à traiter (8 valeurs possibles entre 0b000 et 0b111)

#endif SPACE_H