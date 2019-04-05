#ifndef RULE_H
#define RULE_H
// Declaration de constantes
extern const size_t ruleCount;
const size_t ruleSize{ 8 };												// Taille d'une r�gle
// Declaration de types
typedef bool Rule[ruleSize];							// Type repr�sentant les valeurs associ�es � une r�gle		=> Rule est un :		bool [8]

// Rule
void setRule(Rule rule, size_t ruleValue);				// D�termine les 8 valeurs de la r�gle selon l'entier donn�

#endif RULE_H