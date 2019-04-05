
#include "State.h"
#include "Space.h"

void randomizeSpace(Space space)
{
	if (space) {
		for (size_t iSpace{}; iSpace < spaceSize; ++iSpace) {
			randomizeState(space + iSpace);
		}
	}
}
// À titre d'exemple, cette fonction ne fait aucune validation des 
// paramètres d'entrée. C'est la responsabilité de la fonction appelante 
// de faire cette validation.
// Préconditions :	space must be valid
//					index E [1, sSize - 1[
int getNeighborhoodFromSpace(Space space, size_t index)
{
	return	(int(space[index + 1]) << 0) |
		(int(space[index]) << 1) |
		(int(space[index - 1]) << 2);
}