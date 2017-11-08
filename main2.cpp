/*****************************************************************************
*
* 实验二  C++简单程序设计
* 缪雨霏 计算机二班 171340236
* 2017年11月1日
*
*****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

#define pi 3.1415926

void ShowWelcome();
void ShowAnswer(int);
void ShowIndex();
void ShowIndex(int);

int main() {
	int a;
	while (true) {
		ShowWelcome();
		ShowIndex();
		cin >> a;
		ShowAnswer(a);
	}
}

void ShowWelcome() {
	system("cls");
	system("title 实验二  C++简单程序设计 - 缪雨霏 171340236");
	cout << "2017年11月1日" << endl << "171340236 计算机2班 缪雨霏" << endl;
	cout << "实验二  C++简单程序设计" << endl << endl;
}

void ShowAnswer(int index) {
	ShowWelcome();
	cout << "现在开始演示" << endl;
	ShowIndex(index);
	switch (index) {
	case 1:
		int a, b;
		cout << "请输入参数 a:";
		cin >> a;
		cout << "请输入参数 b:";
		cin >> b;
		if (a > b) {
			cout << "a 比 b 大。";
		}
		else if (b > a) {
			cout << "b 比 a 大。";
		}
		else {
			cout << "a 和 b 一样大。";
		}
		break;
	case 2:
		size_t n;
		cout << "请输入整数参数 n , 范围为 -1 至 16 :";
		cin >> n;
		{
			if (n != -1) {
				int val = 1;
				for (size_t i = 1; i <= n; i++)
				{
					val *= i;
				}
				cout << n << "的阶乘是 " << val;
			}
			else {
				cout << "-1的阶乘是-1";
			}
		}
		break;
	case 3:
		int s;
		cout << "输入成绩：";
		cin >> s;
		switch (s / 10)
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
		break;
	case 4:
		for (size_t i = 100; i <= 300; i++)
		{
			if (i % 17 == 0) {
				cout << "找到了，这个数是" << i;
				break;
			}
		}
		break;
	case 5:
		int nums[10];
		int curMax, curMin;
		cout << "输入第1个数：";
		cin >> nums[0];
		curMax = 0;
		curMin = 0;
		for (size_t i = 1; i < 10; i++)
		{
			cout << "输入第" << i + 1 << "个数：";
			cin >> nums[i];
			if (nums[i] < nums[curMin]) {
				curMin = i;
			}
			else if (nums[i] > nums[curMax])
			{
				curMax = i;
			}
		}
		ShowWelcome(); {
			cout << "现在开始演示" << endl;
			ShowIndex(index);
			cout << "您输入的10个数分别为：" << endl; }
		for (size_t i = 0; i < 10; i++)
		{
			cout << nums[i] << " ";
		}
		cout << endl << "最大数为第" << curMax + 1 << "个，其值为" << nums[curMax] << endl;
		cout << "最小数为第" << curMin + 1 << "个，其值为" << nums[curMin];
		break;
	case 6:
	reenter:
		cout << "图形的类型为？（1-圆形 2-长方形 3-正方形）:";
		int itype;
		cin >> itype;
		if ((itype < 1) || (itype > 3)) {
			goto reenter;
		}
		switch (itype) {
		case 1:
			cout << "圆的半径为：";
			int r;
			cin >> r;
			cout << "面积为：" << pi * r * r;
			break;
		case 2:
			int a, b;
			cout << "矩形的长为：";
			cin >> a;
			cout << "矩形的宽为：";
			cin >> b;
			cout << "面积为：" << a * b;
			break;
		case 3:
			cout << "正方形的边长为：";
			int s;
			cin >> s;
			cout << "面积为：" << s * s;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	cout << endl << "演示完毕。按任意键继续。";
	_getch();
}

void ShowIndex() {
	cout << "答案目录：" << endl;
	for (size_t i = 1; i < 7; i++)
	{
		ShowIndex(i);
	}
	cout << endl << "请输入想查看答案的题号：";
}

void ShowIndex(int index) {
	switch (index) {
	case 1:
		cout << "1.编程实现两个整数大小的比较。" << endl;
		break;
	case 2:
		cout << "2.从键盘上输入一个整数n，编程实现打印输出n的阶乘n！" << endl;
		break;
	case 3:
		cout << "3.从键盘输入一个百分制的成绩，将它转化成五分制。（A(100~90)、B(89~80)、C(79~70)、D(69~60)、F(59~0)）。" << endl;
		break;
	case 4:
		cout << "4.编程实现找出100~300之间第一个能被17整除的数。" << endl;
		break;
	case 5:
		cout << "5.输入10个整数，求出其中的最大值与最小值。" << endl;
		break;
	case 6:
		cout << "6.编程计算图形的面积。程序可以计算圆形、长方形、正方形的面积、运行时先提示用户选择图形类型，然后，对圆形要求用户输入半径、对长方形要求用户输入长和宽的值，对正方形要求用户输入边长，计算出面积后将其显示出来。要求使用debug调试功能观察程序运行中变量值的变化情况。" << endl;
		break;
	default:
		break;
	}
}