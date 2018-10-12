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
	Player& Contrast(int WinNum, double Odds);//���ʂ��Q��
	bool GameOverCheck();
	void ShowChoice();
private:
	int Money;
	int BetNum;//�q��������
	int Choice;//�I�񂾔n�̔ԍ�
	int LowestBetMount;
};