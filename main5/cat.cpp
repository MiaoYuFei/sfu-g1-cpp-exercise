/*****************************************************************************
*
* 实验五
* 缪雨霏 计算机二班 171340236
* 2017年12月20日
* 远程地址 https://github.com/MiaoYuFei/sfu-g1-cpp-exercise/blob/master/main5/cat.cpp
*
*****************************************************************************/

#include "cat.h"

int Cat::getNumofCats() {
	return Cat::numofCats;
}

void Cat::setNumofCats(int num) {
	Cat::numofCats = num;
}

Cat::~Cat() {
	Cat::numofCats = 0;
}

int Cat::numofCats = 0;