
#include <memory.h>
#include <stdio.h>

#include "Space.h"
#include "SpaceTime.h"


void initializeSpaceTime(SpaceTime spaceTime)
{
	if (spaceTime) {
		memset(spaceTime, 0, sizeof(bool) * spaceSize * timeSize);
	}
}

int getNeighborhoodFromSpaceTime(SpaceTime spaceTime, size_t iTime, size_t iSpace)
{
	return getNeighborhoodFromSpace(spaceTime[iTime], iSpace);
}

void evolveOverSpace(SpaceTime spaceTime, Rule rule, size_t currentTime)
{
	if (spaceTime && currentTime > 0 && currentTime < timeSize && rule) {
		spaceTime[currentTime][0] = spaceTime[currentTime][spaceSize - 1] = false;
		for (size_t space{ 1 }; space < spaceSize - 1; ++space) {
			spaceTime[currentTime][space] = rule[getNeighborhoodFromSpaceTime(spaceTime, currentTime - 1, space)];
		}
	}
}

void evolveOverTime(SpaceTime spaceTime, Rule rule)
{
	if (spaceTime && rule) {
		randomizeSpace(spaceTime[0]);
		for (size_t time{ 1 }; time < timeSize; ++time) {
			evolveOverSpace(spaceTime, rule, time);
		}
	}
}

void evolve(SpaceTime spaceTime, size_t ruleValue)
{
	if (spaceTime && ruleValue < ruleCount) {
		Rule rule;
		setRule(rule, ruleValue);
		evolveOverTime(spaceTime, rule);
	}
}

void showSpaceTime(SpaceTime spaceTime, bool showTime)
{
	if (spaceTime) {
		for (size_t time{}; time < timeSize; ++time) {
			if (showTime) {
				printf("%02zd   ", time);
			}
			for (size_t space{}; space < spaceSize; ++space) {
				printf("%c", spaceTime[time][space] ? stateActive : stateInactive);
			}
			printf("\n");
		}
	}
}