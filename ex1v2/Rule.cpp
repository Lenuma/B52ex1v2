
#include "Rule.h"

void setRule(Rule rule, size_t ruleValue)
{
	if (rule && ruleValue < ruleCount) {
		for (size_t r{}; r < ruleSize; ++r) {
			rule[r] = (ruleValue >> r) & 1;
		}
	}
}