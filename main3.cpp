/*****************************************************************************
*
* ʵ����
* ������ ��������� 171340236
* 2017��11��8��
* Զ�̵�ַ https://github.com/MiaoYuFei/sfu-g1-cpp-exercise/blob/master/main3.cpp
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


	//1.����x��y����
	size_t x, y, sum = 1;
	cout << "����x:";
	cin >> x;
	cout << "����y:";
	cin >> y;
	for (size_t i = 0; i < y; i++)
	{
		sum *= x;
	}
	cout << "x^y = " << sum << endl;
	//1

	/*

	//2.���꺯��
	cout << "������ݣ�";
	size_t year;
	cin >> year;
	if (isLeapYear(year))
		cout << year << "�������ꡣ" << endl;
	else
		cout << year << "�겻�����ꡣ" << endl;
	//2


	//3.�ɼ��ּ�
	cout << "����ɼ���";
	int grade;
	cin >> grade;
	printGrade(grade);
	//3


	//4.������ת
	cout << "����һ����������";
	int num;
	cin >> num;
	cout << "��ת��Ϊ " << ReverseDigit(num) << endl;
	//4


	//5.���ֵ
	cout << "�ж����ֵ��1-��������, 2-����˫������, 3-����������";
	size_t choice;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
	{
		int a, b;
		cout << "�����һ��������";
		cin >> a;
		cout << "����ڶ���������";
		cin >> b;
		cout << MaxNum(a, b);
		break;
	}
	case 2:
	{
		double a, b;
		cout << "�����һ��˫��������";
		cin >> a;
		cout << "����ڶ���˫��������";
		cin >> b;
		cout << MaxNum(a, b);
		break;
	}
	case 3:
	{
		int a, b, c;
		cout << "�����һ��������";
		cin >> a;
		cout << "����ڶ���������";
		cin >> b;
		cout << "���������������";
		cin >> c;
		cout << MaxNum(a, b, c);
		break;
	}
	default:
		break;
	}
	//5


	//6.쳲���������
	cout << "��Ҫ���쳲��������еĶ��ټ�����";
	size_t grade;
	cin >> grade;
	cout << "�ṩ�����ַ���ʵ�֡���Ҫ���֣�" << endl;
	cout << "1-���ֵݹ鷨" << endl;
	cout << "2-���Եݹ鷨" << endl << "�����ţ�";
	size_t type;
	cin >> type;
	long ptr;
	for (size_t i = 1; i <= grade; i++)
		cout << "��" << i << "���ǣ�" << Fibonacci(type, i, ptr) << endl;
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
		cout << "�ɼ�ΪA��";
		break;
	case 8:
		cout << "�ɼ�ΪB��";
		break;
	case 7:
		cout << "�ɼ�ΪC��";
		break;
	case 6:
		cout << "�ɼ�ΪD��";
		break;
	default:
		cout << "�ɼ�ΪF��";
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