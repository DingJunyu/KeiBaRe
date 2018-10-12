#pragma once
#include"stdafx.h"

Runway& Runway::CopyFromHorse(std::string Nam,
	double Spe, double Sta, double Fat, double Wei, double Len) {
	HorseHere.Name = Nam;
	HorseHere.ShortName = HorseHere.Name.substr(0, 2);
	HorseHere.Speed = Spe;
	HorseHere.Status = Sta;
	HorseHere.Fatigue = Fat;
	HorseHere.Weight = Wei;
	Length = Len;
	return *this;
}

Runway& Runway::Inif() {
	CurrentSpeed = 0;
	AlreadyPass = 0;
	FullSpeedTime = 0;
	Acceleration = INIF_ACCELERATION;
	MaxFST = INIF_FST;

	MaxSpeedWhenTired = HorseHere.Speed * (SPEED_DOWN_WITH_FST*
		(HorseHere.Weight / INIF_WEIGHT));

	MaxFST += (double)(HorseHere.Weight - INIF_WEIGHT)*WEIGHT_TO_FST;
	//重量と最大速度維持時間の関係
	MaxFST += (double)(HorseHere.Status - STANDARD_STATUS)*STATUS_TO_FST;
	//状態と最大速度維持時間の関係
	Acceleration -= (double)(HorseHere.Weight - INIF_WEIGHT)
		*WEIGHT_TO_ACC;
	//重量と加速度の関係
	Acceleration += (double)(HorseHere.Status - STANDARD_STATUS)
		*STATUS_TO_ACC;
	//状態と加速度の関係
	if (Acceleration <= ACC_MIN)
		Acceleration = ACC_MIN;
	if (MaxFST <= FST_MIN)
		MaxFST = FST_MIN;
	return *this;
}

Runway& Runway::Running() {
	//最大速度になる前であればスピードが上がる
	CurrentSpeed += Acceleration;

	if (FullSpeedTime < MaxFST && CurrentSpeed > HorseHere.Speed)
		CurrentSpeed = HorseHere.Speed;

	if (FullSpeedTime >= MaxFST && CurrentSpeed >
		MaxSpeedWhenTired)
		CurrentSpeed = MaxSpeedWhenTired;

	//最大速度と疲労の関係
	if ((rand() % 100 + 1) <= HorseHere.Fatigue&&CurrentSpeed >=
		HorseHere.Speed - SPEED_MIN)
		CurrentSpeed -= SPEED_DOWN_WITH_FATIGUE;

	++FullSpeedTime;
	AlreadyPass += CurrentSpeed;//走った距離を記録
	return *this;
}

int Runway::EndofMatch() {
	if (AlreadyPass >= Length)
		return (int)(AlreadyPass - Length);
	else
		return -1;
}

void Runway::Display() {
	double Blocks;
	Blocks = AlreadyPass / Length*LENGTH_SHOW;
	if (Blocks >= LENGTH_SHOW)
		Blocks = LENGTH_SHOW;//描く範囲越えない
	for (int i = 0; i <= (int)Blocks; ++i)
		printf("-");
	std::cout << HorseHere.ShortName;

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOut, &bInfo);
	COORD pos;
	pos = bInfo.dwCursorPosition;
	pos.X = LENGTH_SHOW + 3 +3;
	//中の３は漢字一文字の位置、後ろのは最初の３文字
	SetConsoleCursorPosition(hOut, pos);

	printf("|%4.1f/%4.0f\n",AlreadyPass, Length);
}

void Runway::ShowWinner(int Winner) {
	std::cout << Winner+1 << "番" <<
		HorseHere.Name << "が優勝しました" << std::endl;
}