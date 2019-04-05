#ifndef ACE_H
#define ACE_H

// Fonctions spécifiques à cette application
void showWelcomeScreen();													// Affiche la page d'accueil
bool simulationStep(SpaceTime spaceTime, size_t * rule);					// Effectue un pas de simulation
void showOneStep(SpaceTime spaceTime, size_t ruleValue);					// Affiche la règle courante et l'image créée par la simulation
bool getInputUser(size_t * rule);											// Demande à l'usager quelle instruction faire et met à jour la règle - retourne si l'usager désire quitter
bool isQuitting();															// Retourne si l'usager confirme son désire de quitter l'application

#endif ACE_H