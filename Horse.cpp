#include"stdafx.h"

Horse& Horse::Initiaize(std::string GivenName) {//馬のデータを初期化
	Speed = INIF_SPEED;
	Weight = INIF_WEIGHT;
	Status = INIF_STATUS;
	MaxLevel = INIF_MAXLEVEL;
	Level = 1;
	Fatigue = INIF_FATIGUE;
	Odds = 1;

	Name = GivenName;
	Speed += Random(CHAN_SPEED);
	Weight += Random(CHAN_WEIGHT);
	Status += Random(CHAN_STATUS);
	MaxLevel += Random(CHAN_LEVEL);

	return *this;
}

Horse& Horse::LevelUp() {
	++Level;
	Speed += SPEED_PER_LEVEL;
	Weight += Random(WEIGHT_CHAN_PER_LEVEL);
	Status += STATUS_PER_LEVEL;

	return *this;
}

Horse& Horse::Record(bool Win) {
	if (Win) {
		++Winned;
		Status -= STATUS_DOWN_WIN;
		if (Status <= 0)
			Status = 0;
		Odds -= ODDS_PER_WIN;
		if (Odds <= 0)
			Odds = 0.1;
	}
	else {
		Status += STATUS_UP_LOSE;
		if (Status >= 100)
			Status = 0;
		Odds += ODDS_PER_LOSE;
	}
	++Played;
	if (Played > Level * 5 && Level <= MaxLevel)
		LevelUp();
	return *this;
}

double& Horse::Query(int Num) {
	switch (Num)
	{
	case SPEED:return Speed;
	case STATUS:return Status;
	case FATIGUE:return Fatigue;
	case WEIGHT:return Weight;
	case ODDS:return Odds;
	};
}

double Random(int Range) {
	int RandomMark;//正数と負数の判定
	RandomMark = rand() % 2;
	if (RandomMark == 1)//正数を返す
		return (double)(((rand() % (Range*100)))/100);
	else//負数を返す
		return 0 - (double)(((rand() % (Range * 100))) / 100);
}

void Horse::Display() {
	std::cout << Name << " 体重:"
		<< Weight << "Kg テンション:"
		<< Status - INIF_STATUS << "% "
		<< "配当率:" << Odds;

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOut, &bInfo);
	COORD pos;
	pos = bInfo.dwCursorPosition;
	pos.X = LENGTH_SHOW + 3 + 3;
	//中の３は漢字一文字の位置、後ろのは最初の３文字
	SetConsoleCursorPosition(hOut, pos);

	std::cout << "|0" << std::endl;
}

Horse& Horse::rest(bool Played) {
	if (!Played) {
		Fatigue += FATIGUE_PER_MATCH;
		Odds += ODDS_PER_MATCH;//試合ことによって配当率が変わる
	}
	else {
		Fatigue -= FATIGUE_PER_REST;
		Odds += ODDS_PER_REST;//休んだ馬の配当率が上がる
	}
	if (Fatigue < 0)
		Fatigue = 0;
	return *this;
}

std::string Horse::BackName() {
	return Name;
}