#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
#include"DefineData.h"

struct HorseOnRunway {
	std::string Name;
	std::string ShortName;
	double Speed = 0;//馬の最大速度
	double Status = 0;//馬のテンション
	double Fatigue = 0;//疲労値
	double Weight = 0;//馬の重さ
};

class Runway {
public:
	Runway() :Length(0), AlreadyPass(0), FullSpeedTime(0),
		Acceleration(INIF_ACCELERATION), MaxFST(INIF_FST),
		CurrentSpeed(0) {}

	Runway& CopyFromHorse(std::string Nam,
		double Spe, double Sta, double Fat, double Wei, double Len);
	Runway& Inif();
	Runway& Running();
	void ShowWinner(int Winner);
	int EndofMatch();
	void Display();

private:
    HorseOnRunway HorseHere;
	double Length;
	double AlreadyPass;
	double FullSpeedTime;
	double Acceleration;
	double MaxFST;
	double CurrentSpeed;
	double MaxSpeedWhenTired;
};