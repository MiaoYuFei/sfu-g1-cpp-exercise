
/*****************************************************************************
*
* 实验四
* 缪雨霏 计算机二班 171340236
* 2017年11月22日
* 远程地址 https://github.com/MiaoYuFei/sfu-g1-cpp-exercise/blob/master/main4.cpp
*
*****************************************************************************/

#include <iostream>
#include <cstdarg>
#include <string>
#include <list>

using namespace std;

string concat(size_t count, ...)
{
	va_list vas;
	va_start(vas, count);
	char *arg, *rtn;
	list<char *> args;
	size_t dlength = 0;
	for (size_t i = 0; i < count; i++)
	{
		arg = va_arg(vas, char *);
		args.push_back(arg);
		dlength += strlen(arg);
	}
	va_end(vas);
	rtn = (char *)malloc(dlength);
	memset(rtn, '\0', dlength);
	for (list<char *>::iterator i = args.begin(); i != args.end(); ++i)
	{
		strcat_s(rtn, dlength + 1, *i);
	}
	args.clear();
	return rtn;
}

class Rectangle {
public:
	long top, left, bottom, right;
	long getArea() {
		return (right - left) * (top - bottom);
	}
};


class Complex {
public:
	int real, imaginary;
	Complex() {}
	Complex(int real, int imaginary) {
		Complex::real = real; Complex::imaginary = imaginary;
	}

	void Add(Complex cp) {
		Complex::real += cp.real;
		Complex::imaginary += cp.imaginary;
	}

	string Show() {
		return concat(4, to_string(real).c_str(), "+", to_string(imaginary).c_str(), "i");
	}
};

class Tree {
public:
	int ages = 0;
	void grow(int years) {
		ages += years;
	}

	int age() {
		return ages;
	}
};

class ThreeCubes {
public:
	int length[3], width[3], height[3];
	void inputdata() {
		for (size_t i = 0; i < 3; i++)
		{
			cout << "输入第" << i + 1 << "个立方体的长：";
			cin >> ThreeCubes::length[i];
			cout << "输入第" << i + 1 << "个立方体的宽：";
			cin >> ThreeCubes::width[i];
			cout << "输入第" << i + 1 << "个立方体的高：";
			cin >> ThreeCubes::height[i];
		}
	}

	void outputdata() {
		for (size_t i = 0; i < 3; i++)
		{
			cout << "第" << i + 1 << "个立方体的体积：" << (ThreeCubes::length[i] * ThreeCubes::width[i] * ThreeCubes::height[i]) << endl;
		}
	}
};

int main() {
	cout << "输入 top，left，bottom，right，以空格分开：";
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	Rectangle rc;
	rc.top = a;
	rc.left = b;
	rc.bottom = c;
	rc.right = d;
	cout << "矩形面积为：" << rc.getArea() << endl;

	cout << "输入虚数1的 real，imaginary，以空格分开：";
	int e, f;
	cin >> e >> f;
	Complex *c1 = new Complex(e, f);
	cout << "虚数c1为 " << c1->Show() << endl;	
	cout << "输入虚数2的 real，imaginary，以空格分开：";
	int g, h;
	cin >> g >> h;
	Complex *c2 = new Complex(g, h);
	cout << "虚数c2为 " << c2->Show() << endl;
	cout << "现在c1加c2，保存在c1" << endl;
	c1->Add(*c2);
	cout << "加法之后虚数c1为 " << c1->Show()<<endl;
	cout << "输入一棵树的年龄：";
	int i;
	cin >> i;
	Tree tr;
	tr.ages = i;
	cout << "现在树龄" << tr.age() << "岁" << endl;
	cout << "希望它长多少岁？";
	int j;
	cin >> j;
	tr.grow(j);
	cout << "现在树龄" << tr.age() << "岁" << endl;
	ThreeCubes tc;
	tc.inputdata();
	tc.outputdata();
}