
/*****************************************************************************
*
* ʵ����
* ������ ��������� 171340236
* 2017��11��22��
* Զ�̵�ַ https://github.com/MiaoYuFei/sfu-g1-cpp-exercise/blob/master/main4.cpp
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
			cout << "�����" << i + 1 << "��������ĳ���";
			cin >> ThreeCubes::length[i];
			cout << "�����" << i + 1 << "��������Ŀ�";
			cin >> ThreeCubes::width[i];
			cout << "�����" << i + 1 << "��������ĸߣ�";
			cin >> ThreeCubes::height[i];
		}
	}

	void outputdata() {
		for (size_t i = 0; i < 3; i++)
		{
			cout << "��" << i + 1 << "��������������" << (ThreeCubes::length[i] * ThreeCubes::width[i] * ThreeCubes::height[i]) << endl;
		}
	}
};

int main() {
	cout << "���� top��left��bottom��right���Կո�ֿ���";
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	Rectangle rc;
	rc.top = a;
	rc.left = b;
	rc.bottom = c;
	rc.right = d;
	cout << "�������Ϊ��" << rc.getArea() << endl;

	cout << "��������1�� real��imaginary���Կո�ֿ���";
	int e, f;
	cin >> e >> f;
	Complex *c1 = new Complex(e, f);
	cout << "����c1Ϊ " << c1->Show() << endl;	
	cout << "��������2�� real��imaginary���Կո�ֿ���";
	int g, h;
	cin >> g >> h;
	Complex *c2 = new Complex(g, h);
	cout << "����c2Ϊ " << c2->Show() << endl;
	cout << "����c1��c2��������c1" << endl;
	c1->Add(*c2);
	cout << "�ӷ�֮������c1Ϊ " << c1->Show()<<endl;
	cout << "����һ���������䣺";
	int i;
	cin >> i;
	Tree tr;
	tr.ages = i;
	cout << "��������" << tr.age() << "��" << endl;
	cout << "ϣ�����������ꣿ";
	int j;
	cin >> j;
	tr.grow(j);
	cout << "��������" << tr.age() << "��" << endl;
	ThreeCubes tc;
	tc.inputdata();
	tc.outputdata();
}