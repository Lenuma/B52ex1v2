
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
// � titre d'exemple, cette fonction ne fait aucune validation des 
// param�tres d'entr�e. C'est la responsabilit� de la fonction appelante 
// de faire cette validation.
// Pr�conditions :	space must be valid
//					index E [1, sSize - 1[
int getNeighborhoodFromSpace(Space space, size_t index)
{
	return	(int(space[index + 1]) << 0) |
		(int(space[index]) << 1) |
		(int(space[index - 1]) << 2);
}