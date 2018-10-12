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
	double Odds;//�z����
	int Winned;//��������
	int Played;//�Q������������
	std::string Name;
	double Speed;//�n�̍ő呬�x
	double Status;//�n�̃e���V����
	double Fatigue;//��J�l
	double Weight;//�n�̏d��
	double Level;
	double MaxLevel;
};

double Random(int Range);