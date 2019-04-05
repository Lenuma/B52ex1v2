
#include "utilitaires.h"


void randomizeState(bool * cell)
{
	if (cell) {
		*cell = randomEvent();
	}
}