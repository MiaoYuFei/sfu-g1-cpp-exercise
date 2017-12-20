/*****************************************************************************
*
* 实验五
* 缪雨霏 计算机二班 171340236
* 2017年12月20日
* 远程地址 https://github.com/MiaoYuFei/sfu-g1-cpp-exercise/blob/master/main5/cat.h
*
*****************************************************************************/

#ifndef __MAIN5_CAT_H__
#define __MAIN5_CAT_H__

class Cat {
private:
	static int numofCats;
public:
	~Cat();
	static int getNumofCats();
	static void setNumofCats(int);
};

#endif