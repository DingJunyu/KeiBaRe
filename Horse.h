#include<iostream>
#include<string>
#include"DefineData.h"
#include<conio.h>
#include<Windows.h>

class Horse {
public:
	//Horse() = default;
	Horse() :Speed(INIF_SPEED), Status(INIF_STATUS), Fatigue(INIF_FATIGUE),
		Weight(INIF_WEIGHT), Level(1) {}

	double& Query(int Num);

	Horse& Record(bool Win);
	void Display();
	Horse& LevelUp();
	Horse& Initiaize(std::string GivenName);
	std::string BackName();
	Horse& rest(bool Played);

private:
	double Odds;//配当率
	int Winned;//勝った回数
	int Played;//参加した試合回数
	std::string Name;
	double Speed;//馬の最大速度
	double Status;//馬のテンション
	double Fatigue;//疲労値
	double Weight;//馬の重さ
	double Level;
	double MaxLevel;
};

double Random(int Range);