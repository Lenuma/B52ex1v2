#ifndef ACE_H
#define ACE_H

// Fonctions sp�cifiques � cette application
void showWelcomeScreen();													// Affiche la page d'accueil
bool simulationStep(SpaceTime spaceTime, size_t * rule);					// Effectue un pas de simulation
void showOneStep(SpaceTime spaceTime, size_t ruleValue);					// Affiche la r�gle courante et l'image cr��e par la simulation
bool getInputUser(size_t * rule);											// Demande � l'usager quelle instruction faire et met � jour la r�gle - retourne si l'usager d�sire quitter
bool isQuitting();															// Retourne si l'usager confirme son d�sire de quitter l'application

#endif ACE_H