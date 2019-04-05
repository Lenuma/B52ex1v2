#ifndef RULE_H
#define RULE_H
// Declaration de constantes
extern const size_t ruleCount;
const size_t ruleSize{ 8 };												// Taille d'une règle
// Declaration de types
typedef bool Rule[ruleSize];							// Type représentant les valeurs associées à une règle		=> Rule est un :		bool [8]

// Rule
void setRule(Rule rule, size_t ruleValue);				// Détermine les 8 valeurs de la règle selon l'entier donné

#endif RULE_H