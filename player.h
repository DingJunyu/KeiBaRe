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
	Player& Contrast(int WinNum, double Odds);//結果を参照
	bool GameOverCheck();
	void ShowChoice();
private:
	int Money;//持ってるお金
	int BetNum;//賭けたお金
	int Choice;//選んだ馬の番号
	int LowestBetMount;//最低賭ける金
};