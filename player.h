#include<string>
#include<iostream>
#include"DefineData.h"

bool GameOver();

class Player {
public:
	Player() = default;
	Player& StartGame();
	void InputBet();
	Player& Bet(int Num,int Mount);
	Player& Contrast(int WinNum, double Odds);//Œ‹‰Ê‚ğQÆ
	bool GameOverCheck();
	void ShowChoice();
private:
	int Money;//‚Á‚Ä‚é‚¨‹à
	int BetNum;//“q‚¯‚½‚¨‹à
	int Choice;//‘I‚ñ‚¾”n‚Ì”Ô†
	int LowestBetMount;//Å’á“q‚¯‚é‹à
};