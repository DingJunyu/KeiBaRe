// KeiBaRe.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include"stdafx.h"
#include"DefineData.h"
#include"KeiBaHeader.h"

int main()
{
	srand((unsigned)time(NULL));

	//馬の名前リスト
	std::string NameList[NAME_NUMBER] = {
		"ロードカナロア","クモハタ","セントライト","クリフジ",
		"トキツカゼ","トサミドリ","トキノミノル","メイヂヒカリ",
		"ハクチカラ","セイユウ","コダマ","シンザン","スピードシンボリ",
		"タケシバオー","グランドマーチス","ハイセイコー","トウショウボーイ",
		"テンポイント","マルゼンスキー","ミスターシービー","シンボリルドルフ",
		"メジロラモーヌ","オグリキャップ","メジロマックイーン",
		"トウカイテイオー","ナリタブライアン","タイキシャトル",
		"エルコンドルパサー","テイエムオペラオー","ディープインパクト"
		"ウオッカ","オルフェーヴル","ジェンティルドンナ"
	};

	int OrderList[HORSE_NUMBER_PER_MATCH];//保存するのはいる馬の番号
	while (1) {
		//馬の状態を初期化
		for (int i = 0; i < NAME_NUMBER; ++i) {
			Horses[i].Initiaize(NameList[i]);//
		}
		bool GameOverMark = false;

		system("cls");
		Player1.StartGame();//難易度を選択

		while (!GameOverMark) {

			//順番リストを生成
			RandomListCreator(0, NAME_NUMBER - 1, OrderList);

			system("cls");
			DrawTheBar(LENGTH_SHOW + PLUS_SHOW);
			int TrackLength = RandomTrack();
			//trackにいる馬のデータを初期化
			for (int i = 0; i < HORSE_NUMBER_PER_MATCH; ++i) {
				std::cout << std::setw(2) <<
					std::setiosflags(std::ios::left) << i + 1 << ":";
				ChooseTheHorse(&Runways[i], Horses[OrderList[i]], 
					TrackLength);//馬の状態を描く
			}
			DrawTheBar(LENGTH_SHOW + PLUS_SHOW);
			std::cout << "TRACKの長さは:" << TrackLength << std::endl;
			int Winner;
			Player1.InputBet();//プレーヤーの賭ける番号と金額を入力
			Winner = Race();//勝った馬の番号を保存
			
			Runways[Winner].ShowWinner(Winner);//勝った馬の名前を展示する
			Horses[OrderList[Winner]].Display();//勝った馬の状態を展示する
			Player1.Contrast(Winner,Horses[OrderList[Winner]].Query(ODDS));
			/*修正履歴:渡された馬の番号はOrderList[Winner]に変わりました*/
			//賭けた結果
			GameOverMark = Player1.GameOverCheck();
			//ゲームオーバー確認
			RestCheck(Winner, OrderList);
			//馬の状態を回復
		}
	}

    return 0;
}

void RandomListCreator(int Front, int Last,
	int List[HORSE_NUMBER_PER_MATCH]) {	
	int RanNumReceive;//ランダム数を保存する変数
	int Counter=0;
	bool Ident1, Ident2, Ident3;
	for (int i = 0; i < HORSE_NUMBER_PER_MATCH; ++i) {
		List[i] = -1;
	}
	while (1) {
		RanNumReceive = rand() % Last + Front;
		Ident1 = Ident2 = Ident3 = false;
		if(Counter!=0)
			for (int i = 0; i < Counter; ++i)
			{
				if (!Ident1) Ident1 = Equal(RanNumReceive, List[i]);
				if (!Ident2) Ident2 = Equal(RanNumReceive + 1, List[i]);
				if (!Ident3) Ident3 = Equal(RanNumReceive + 2, List[i]);
				/*ランダム生まれた数字とその後の二つの数字
				はリストあるかどうかを確認*/
			}
		/*ランダム生まれた数字からリストに入れるものを入れる*/
		if (!Ident1) {
			List[Counter] = RanNumReceive;
			++Counter;
		}
		else if (!Ident2) {
			List[Counter] = RanNumReceive + 1;
			if(List[Counter]<HORSE_NUMBER_PER_MATCH)
				++Counter;
		}
		else if (!Ident3) {
			List[Counter] = RanNumReceive + 2;
			if (List[Counter]<HORSE_NUMBER_PER_MATCH)
				++Counter;
		}
		if (Counter == HORSE_NUMBER_PER_MATCH)//必要な数字を確保したっら終わる
			break;
	}
}

void ChooseTheHorse(Runway *Temper, Horse Give, int TrackData) {
	Give.Display();//runwayにいる馬を展示する
	Temper->CopyFromHorse(Give.BackName(),
		Give.Query(SPEED),
		Give.Query(STATUS), Give.Query(FATIGUE),
		Give.Query(WEIGHT), TrackData);//馬のデータをRunwayに渡す
	Temper->Inif();//runwayのデータを初期化
}

bool Equal(int a, int b) {
	if (a == b)
		return true;
	else
		return false;
}

int Race() {
	double Mark = -1;
	double WinnerDistance = -1;
	int Winner;

	while (Mark = -1) {
		system("cls");
		for (int i = 0; i < HORSE_NUMBER_PER_MATCH; ++i) {
			Runways[i].Running();//馬全体１フレームに進む
		}
		Player1.ShowChoice();//プレーヤーの選択を一番上に載せる
		DrawTheBar(LENGTH_SHOW + 6);
		for (int i = 0; i < HORSE_NUMBER_PER_MATCH; ++i) {
			std::cout << std::setw(2) <<
				std::setiosflags(std::ios::left) << i + 1 << ":";
			Runways[i].Display();//TRACKの状況を描く
		}
		DrawTheBar(LENGTH_SHOW + 6);
		for (int i = 0; i < HORSE_NUMBER_PER_MATCH; ++i) {
			Mark = Runways[i].EndofMatch();//終点に着いた馬がいるか
			if (Mark != -1)
			{
				if (Mark > WinnerDistance) {
					WinnerDistance = Mark;//一番長い距離を記録
					Winner = i;//その馬のトラック番号を記録
				}
			}
		}
		if (WinnerDistance != -1)
			break;
		Sleep(FRAME_WAIT);
	}
	return Winner;
}

void RestCheck(int Winner,int OrderList[HORSE_NUMBER_PER_MATCH]) {
	for (int i = 0; i < HORSE_NUMBER_PER_MATCH; ++i) {
		bool Checker = false;
		if (i == Winner)
			Checker = true;//馬が勝ったのかを確認
		Horses[OrderList[i]].Record(Checker);
	}//試合数と状態の変化を記録
	for (int i = 0; i < NAME_NUMBER; ++i) {
		bool Checker = false;
		for (int j = 0; j < HORSE_NUMBER_PER_MATCH; ++j) {
			if (i == OrderList[j]) {
				Checker = true;//馬が試合に出るかどうか
			}
		}
		Horses[i].rest(Checker);
	}//疲労値は試合参加したかどうかによる回復/削減

}

void DrawTheBar(int Length) {
	for (int i = 0; i < Length; ++i)
		printf("=");//辺を描く
	printf("\n");
}

int RandomTrack() {
	int Mark;
	Mark = rand() % 3;
	switch (Mark) {
	case 0:return TRACK_SHORT;
	case 1:return TRACK_MEDIUM;
	case 2:return TRACK_LONG;
	};
	return 0;
}//３つのトラックに一つを選ぶ