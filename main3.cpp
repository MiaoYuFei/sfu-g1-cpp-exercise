/*****************************************************************************
*
* 实验三
* 缪雨霏 计算机二班 171340236
* 2017年11月8日
* 远程地址 https://github.com/MiaoYuFei/sfu-g1-cpp-exercise/blob/master/main3.cpp
*
*****************************************************************************/

#include <iostream>

using namespace std;

bool isLeapYear(size_t);
void printGrade(int);
int ReverseDigit(int);
int MaxNum(int, int);
double MaxNum(double, double);
int MaxNum(int, int, int);
size_t Fibonacci(size_t, size_t, long &prev);

long zeroptr = 0;

int main() {


	//1.计算x的y次幂
	size_t x, y, sum = 1;
	cout << "输入x:";
	cin >> x;
	cout << "输入y:";
	cin >> y;
	for (size_t i = 0; i < y; i++)
	{
		sum *= x;
	}
	cout << "x^y = " << sum << endl;
	//1

	/*

	//2.闰年函数
	cout << "输入年份：";
	size_t year;
	cin >> year;
	if (isLeapYear(year))
		cout << year << "年是闰年。" << endl;
	else
		cout << year << "年不是闰年。" << endl;
	//2


	//3.成绩分级
	cout << "输入成绩：";
	int grade;
	cin >> grade;
	printGrade(grade);
	//3


	//4.整数反转
	cout << "输入一个正整数：";
	int num;
	cin >> num;
	cout << "反转后为 " << ReverseDigit(num) << endl;
	//4


	//5.最大值
	cout << "判断最大值。1-两个整数, 2-两个双精度数, 3-三个整数：";
	size_t choice;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
	{
		int a, b;
		cout << "输入第一个整数：";
		cin >> a;
		cout << "输入第二个整数：";
		cin >> b;
		cout << MaxNum(a, b);
		break;
	}
	case 2:
	{
		double a, b;
		cout << "输入第一个双精度数：";
		cin >> a;
		cout << "输入第二个双精度数：";
		cin >> b;
		cout << MaxNum(a, b);
		break;
	}
	case 3:
	{
		int a, b, c;
		cout << "输入第一个整数：";
		cin >> a;
		cout << "输入第二个整数：";
		cin >> b;
		cout << "输入第三个整数：";
		cin >> c;
		cout << MaxNum(a, b, c);
		break;
	}
	default:
		break;
	}
	//5


	//6.斐波那契数列
	cout << "需要输出斐波那契数列的多少级？：";
	size_t grade;
	cin >> grade;
	cout << "提供了两种方法实现。需要哪种？" << endl;
	cout << "1-二分递归法" << endl;
	cout << "2-线性递归法" << endl << "输入编号：";
	size_t type;
	cin >> type;
	long ptr;
	for (size_t i = 1; i <= grade; i++)
		cout << "第" << i << "级是：" << Fibonacci(type, i, ptr) << endl;
	//6


	*/


}

bool isLeapYear(size_t year) {
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

void printGrade(int grade) {
	switch (grade / 10)
	{
	case 10:
	case 9:
		cout << "成绩为A。";
		break;
	case 8:
		cout << "成绩为B。";
		break;
	case 7:
		cout << "成绩为C。";
		break;
	case 6:
		cout << "成绩为D。";
		break;
	default:
		cout << "成绩为F。";
		break;
	}
	cout << endl;
}

int ReverseDigit(int num) {
	int rtn = num % 10;
	for (; num /= 10; )
	{
		rtn = rtn * 10 + num % 10;
	}
	return rtn;
}

int MaxNum(int param1, int param2) {
	if (param1 == param2)
		throw new exception("we are figuring out who is bigger but you give me two same numbers.");
	return (param1 > param2 ? param1 : param2);
}

double MaxNum(double param1, double param2) {
	if (param1 == param2)
		throw new exception("we are figuring out who is bigger but you give me two same numbers.");
	return (param1 > param2 ? param1 : param2);
}

int MaxNum(int param1, int param2, int param3) {
	if ((param1 == param2) || (param1 == param3) || (param2 == param3))
		throw new exception("we are figuring out who is bigger but you give me at least two same numbers.");
	return (param1 > param2 ? (param1 > param3 ? param1 : param3) : (param2 > param3 ? param2 : param3));
}

size_t Fibonacci(size_t type, size_t grade, long &prev) {
	switch (type) {
	case 1:
		if ((grade == 1) || (grade == 2))
			return 1;
		return Fibonacci(1, grade - 1, zeroptr) + Fibonacci(1, grade - 2, zeroptr);
		break;
	case 2:
		if (grade == 0)
		{
			prev = 1;
			return 0;
		}
		else
		{
			long prev2;
			prev = Fibonacci(2, grade - 1, prev2);
			return prev2 + prev;
		}
		break;
	default:
		throw new exception("unknown choice");
		break;
	}
}