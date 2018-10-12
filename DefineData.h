#pragma once

//馬の数とTRACK数
#define NAME_NUMBER 32
#define HORSE_NUMBER_PER_MATCH 16

//TRACKの長さ
#define TRACK_LONG 3000
#define TRACK_MEDIUM 1500
#define TRACK_SHORT 500

//馬状態関連
#define CHAN_SPEED 1
#define CHAN_WEIGHT 50
#define CHAN_STATUS 10
#define CHAN_LEVEL 5
#define STATUS_PER_LEVEL 2
#define SPEED_PER_LEVEL 1
#define WEIGHT_CHAN_PER_LEVEL 10
#define INIF_MAXLEVEL 25
#define FATIGUE_PER_MATCH 5
#define FATIGUE_PER_REST 5
#define STATUS_UP_LOSE 1
#define STATUS_DOWN_WIN 5
#define STATUS_PER_REST 1
#define ODDS_PER_WIN 0.15
#define ODDS_PER_LOSE 0.05
#define ODDS_PER_MATCH 0.02
#define ODDS_PER_REST 0.01	

//初期化データ
#define INIF_SPEED 12
#define INIF_WEIGHT 250
#define INIF_STATUS 60
#define INIF_FATIGUE 10

//試合中データ
#define STANDARD_STATUS 60
#define WEIGHT_TO_FST 0.25
#define WEIGHT_TO_ACC 0.02
#define STATUS_TO_FST 0.1
#define STATUS_TO_ACC 0.03
#define SPEED_DOWN_WITH_FATIGUE 2//疲労値がたまるとスピードがランダム落とす
#define SPEED_DOWN_WITH_FST 0.6
#define SPEED_MIN 8//一番遅い速度と速度の差
#define LENGTH_SHOW 61//Trackの長さ
#define INIF_ACCELERATION 2
#define INIF_FST 120//全速最大時間
#define ACC_MIN 1//最少加速度
#define FST_MIN 5

//選択肢文字化
#define SPEED 1
#define STATUS 2
#define FATIGUE 3
#define WEIGHT 4
#define ODDS 5

#define FRAME_WAIT 20

//難易度関連
#define DIFFICULTY_DIFFICULT 2000
#define DIFFICULTY_NORMAL 4000
#define DIFFICULTY_EASY 10000
#define LOWEST_BET_MOUNT_EASY 200
#define LOWEST_BET_MOUNT_NORMAL 400
#define LOWEST_BET_MOUNT_HARD 800