/*****************************************************************************
*
* ʵ���  C++�򵥳������
* ������ ��������� 171340236
* 2017��11��1��
* Զ�̵�ַ https://github.com/MiaoYuFei/sfu-g1-cpp-exercise/blob/master/main2.cpp
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
	system("title ʵ���  C++�򵥳������ - ������ 171340236");
	cout << "2017��11��1��" << endl << "171340236 �����2�� ������" << endl;
	cout << "ʵ���  C++�򵥳������" << endl << endl;
}

void ShowAnswer(int index) {
	ShowWelcome();
	cout << "���ڿ�ʼ��ʾ" << endl;
	ShowIndex(index);
	switch (index) {
	case 1:
		int a, b;
		cout << "��������� a:";
		cin >> a;
		cout << "��������� b:";
		cin >> b;
		if (a > b) {
			cout << "a �� b ��";
		}
		else if (b > a) {
			cout << "b �� a ��";
		}
		else {
			cout << "a �� b һ����";
		}
		break;
	case 2:
		size_t n;
		cout << "�������������� n , ��ΧΪ -1 �� 16 :";
		cin >> n;
		{
			if (n != -1) {
				int val = 1;
				for (size_t i = 1; i <= n; i++)
				{
					val *= i;
				}
				cout << n << "�Ľ׳��� " << val;
			}
			else {
				cout << "-1�Ľ׳���-1";
			}
		}
		break;
	case 3:
		int s;
		cout << "����ɼ���";
		cin >> s;
		switch (s / 10)
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
		break;
	case 4:
		for (size_t i = 100; i <= 300; i++)
		{
			if (i % 17 == 0) {
				cout << "�ҵ��ˣ��������" << i;
				break;
			}
		}
		break;
	case 5:
		int nums[10];
		int curMax, curMin;
		cout << "�����1������";
		cin >> nums[0];
		curMax = 0;
		curMin = 0;
		for (size_t i = 1; i < 10; i++)
		{
			cout << "�����" << i + 1 << "������";
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
			cout << "���ڿ�ʼ��ʾ" << endl;
			ShowIndex(index);
			cout << "�������10�����ֱ�Ϊ��" << endl; }
		for (size_t i = 0; i < 10; i++)
		{
			cout << nums[i] << " ";
		}
		cout << endl << "�����Ϊ��" << curMax + 1 << "������ֵΪ" << nums[curMax] << endl;
		cout << "��С��Ϊ��" << curMin + 1 << "������ֵΪ" << nums[curMin];
		break;
	case 6:
	reenter:
		cout << "ͼ�ε�����Ϊ����1-Բ�� 2-������ 3-�����Σ�:";
		int itype;
		cin >> itype;
		if ((itype < 1) || (itype > 3)) {
			goto reenter;
		}
		switch (itype) {
		case 1:
			cout << "Բ�İ뾶Ϊ��";
			int r;
			cin >> r;
			cout << "���Ϊ��" << pi * r * r;
			break;
		case 2:
			int a, b;
			cout << "���εĳ�Ϊ��";
			cin >> a;
			cout << "���εĿ�Ϊ��";
			cin >> b;
			cout << "���Ϊ��" << a * b;
			break;
		case 3:
			cout << "�����εı߳�Ϊ��";
			int s;
			cin >> s;
			cout << "���Ϊ��" << s * s;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	cout << endl << "��ʾ��ϡ��������������";
	_getch();
}

void ShowIndex() {
	cout << "��Ŀ¼��" << endl;
	for (size_t i = 1; i < 7; i++)
	{
		ShowIndex(i);
	}
	cout << endl << "��������鿴�𰸵���ţ�";
}

void ShowIndex(int index) {
	switch (index) {
	case 1:
		cout << "1.���ʵ������������С�ıȽϡ�" << endl;
		break;
	case 2:
		cout << "2.�Ӽ���������һ������n�����ʵ�ִ�ӡ���n�Ľ׳�n��" << endl;
		break;
	case 3:
		cout << "3.�Ӽ�������һ���ٷ��Ƶĳɼ�������ת��������ơ���A(100~90)��B(89~80)��C(79~70)��D(69~60)��F(59~0)����" << endl;
		break;
	case 4:
		cout << "4.���ʵ���ҳ�100~300֮���һ���ܱ�17����������" << endl;
		break;
	case 5:
		cout << "5.����10��������������е����ֵ����Сֵ��" << endl;
		break;
	case 6:
		cout << "6.��̼���ͼ�ε������������Լ���Բ�Ρ������Ρ������ε����������ʱ����ʾ�û�ѡ��ͼ�����ͣ�Ȼ�󣬶�Բ��Ҫ���û�����뾶���Գ�����Ҫ���û����볤�Ϳ��ֵ����������Ҫ���û�����߳�����������������ʾ������Ҫ��ʹ��debug���Թ��ܹ۲���������б���ֵ�ı仯�����" << endl;
		break;
	default:
		break;
	}
}