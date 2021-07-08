#pragma once


//该文件定义了枚举类型
//地形的枚举类型
enum enumLandForm
{
	LAND,      //陆地
	RIVER,     //河流
	RED_TRAP,  //红方陷阱
	BLUE_TRAP, //蓝方陷阱
	RED_DEN,   //红方兽穴
	BLUE_DEN   //蓝方兽穴
};
//阵营的枚举类型
enum enumCamp
{
	red, //红方
	blue //蓝方
};
//棋子类型的枚举类型
enum enumCheckerType
{
	RAT = 1,//鼠
	CAT,//猫
	DOG,//狗
	WOLF,//狼
	LEOPARD,//豹
	TIGER,//虎
	LION,//狮
	ELEPHANT//象

};

