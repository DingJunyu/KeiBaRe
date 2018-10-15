#pragma once

//馬の数とTRACK数
#define NAME_NUMBER 32
#define HORSE_NUMBER_PER_MATCH 16

//TRACKの長さ
#define TRACK_LONG 3000
#define TRACK_MEDIUM 1500
#define TRACK_SHORT 500

//馬状態関連
//初期値
#define INIF_SPEED 12
#define INIF_WEIGHT 250
#define INIF_STATUS 60
#define INIF_FATIGUE 10//初期疲労値
#define INIF_MAXLEVEL 25
#define INIF_ODDS 1
#define INIF_LEVEL 1
//初期化
#define CHAN_SPEED 1 //速度
#define CHAN_WEIGHT 50 //重量
#define CHAN_STATUS 10 //テンション
#define CHAN_LEVEL 5 //最大レーベル

//レーベルアップによるステータスの変動
#define STATUS_PER_LEVEL 2//テンション
#define SPEED_PER_LEVEL 1//速度
#define WEIGHT_CHAN_PER_LEVEL 10//重量

//疲労値関係
#define FATIGUE_PER_MATCH 10//参加による下がる
#define FATIGUE_PER_REST 15//参加しないによる上がる
#define FATIGUE_MAX 100//最大値
#define FATIGUE_MIN 0//最小値

//テンション関係
#define STANDARD_STATUS 60//標準値
#define STATUS_UP_LOSE 2//失敗毎の変化
#define STATUS_DOWN_WIN 8//勝利毎の変化
#define STATUS_PER_REST 1//参加しない時
#define STATUS_MAX 130//最大値
#define STATUS_MIN 0//最小値

//配当率
#define ODDS_PER_WIN 0.25
#define ODDS_PER_LOSE 0.05
#define ODDS_PER_MATCH 0.02
#define ODDS_PER_REST 0.01	
#define ODDS_MIN 0.1

//Runwayの初期値
#define INIF_ACCELERATION 2
#define INIF_FST 120//全速最大時間

//試合中データ
#define WEIGHT_TO_FST 0.25
#define WEIGHT_TO_ACC 0.05
#define STATUS_TO_FST 0.2
#define STATUS_TO_ACC 0.03
#define SPEED_DOWN_WITH_FATIGUE 3//疲労値がたまるとスピードがランダム落とす
#define SPEED_DOWN_WITH_FST 0.6
#define SPEED_MIN 8//一番遅い速度と速度の差
#define ACC_MIN 1//最小加速度
#define FST_MIN 60//最小全速最大時間

//選択肢文字化
#define SPEED 1
#define STATUS 2
#define FATIGUE 3
#define WEIGHT 4
#define ODDS 5

//輸出関係
#define FRAME_WAIT 20
#define LENGTH_SHOW 61//Trackの長さ

//難易度関連
#define DIFFICULTY_DIFFICULT 2000
#define DIFFICULTY_NORMAL 4000
#define DIFFICULTY_EASY 10000
#define LOWEST_BET_MOUNT_EASY 200
#define LOWEST_BET_MOUNT_NORMAL 400
#define LOWEST_BET_MOUNT_HARD 800