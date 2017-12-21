/*****************************************************************************
*
* 实验五
* 缪雨霏 计算机二班 171340236
* 2017年12月20日
* 远程地址 https://github.com/MiaoYuFei/sfu-g1-cpp-exercise/blob/master/main5/main.cpp
*
*****************************************************************************/

#include <iostream>
#include "cat.h"
using namespace std;

static class myMath {
private:

	static double _pow(double num1, int num2)
	{
		double num = 1;
		for (int i = 0; i < num2; i++) 
		{ 
			num *= num1; 
		}
		return num;
	}

	static double _pow(double num1, double num2)
	{
		double num = 0, 
			      x = num1 - 1, 
			   tmpm = 1;
		int j;
		for (int i = 1; tmpm > 1e-6 || tmpm < -1e-6; i++)
		{
			for (j = 1, tmpm = 1; j <= i; j++)
			{
				tmpm *= ((num2 - j + 1) * x / j);
			}
			num += tmpm;
		}
		return num + 1;
	}

public:

	static double pow(double num1, double num2)
	{
		if (num1 == 0 && num2 != 0) return 0;
		else if ((num1 == 0) && (num2 == 0)) return 1;
		else if ((num1 < 0) && (num2 - int(num2) != 0)) return 0;
		if (num1 > 2)
		{
			num1 = 1 / num1;
			num2 = -num2;
		}
		if (num2 < 0) return 1 / pow(num1, -num2);
		if (num2 - int(num2) == 0) 
			return _pow(num1, int(num2));
		else 
			return (_pow(num1, num2 - int(num2)) * _pow(num1, int(num2)));
	}

};

class Point {
	friend class Distance;
private:
	float a, b;
public:
	Point(char *ptName = NULL) {
		a = 0; b = 0;
		name = ptName;
	}
	Point(float x, float y, char *ptName = NULL) {
		a = x; b = y;
		name = ptName;
	}
	void print() {
		cout << (name ? name : "P") << "(" << a << "," << b << ")" << endl;
	}
	char *name;
};

class Distance {
public:
	static double getDistance(Point pt1, Point pt2) {
		return myMath::pow(myMath::pow(pt1.a - pt2.a, 2) + myMath::pow(pt1.b - pt2.b, 2), 0.5);
	}
};

int main() {
	Cat cat;
	int n;
	cout << "How many cats do you have? ";
	cin >> n;
	cat.setNumofCats(n);
	cout << "Now you have " << cat.getNumofCats() << " cats." << endl;
	while (true) {
		cout << "Point 1:";
		float x1, y1;
		cin >> x1 >> y1;
		Point *pt1 = new Point(x1, y1, "P1");
		pt1->print();
		cout << "Point 2:";
		float x2, y2;
		cin >> x2 >> y2;
		Point *pt2 = new Point(x2, y2, "P2");
		pt2->print();
		cout << "Distance between two points :" << Distance::getDistance(*pt1, *pt2) << endl;
	}
}
