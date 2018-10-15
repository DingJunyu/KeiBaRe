#pragma once


void ChooseTheHorse(Runway *Temper, Horse Give, int TrackData);

void RandomListCreator(int Front, int Last,
	int List[HORSE_NUMBER_PER_MATCH]);

bool Equal(int a, int b);

int Race();
void RestCheck(int Winner, int OrderList[HORSE_NUMBER_PER_MATCH]);
void DrawTheBar(int Length);
int RandomTrack();

Horse Horses[NAME_NUMBER];
Runway Runways[HORSE_NUMBER_PER_MATCH];
Player Player1;