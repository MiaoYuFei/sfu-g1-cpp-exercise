/*****************************************************************************
*
* 实验六
* 缪雨霏 计算机二班 171340236
* 2018年01月06日
* 远程地址 https://github.com/MiaoYuFei/sfu-g1-cpp-exercise/blob/master/main6.cpp
*
*****************************************************************************/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
using namespace std;

int *change(int *matrix);
void printMatrix(int **matrix);
char* concat(char* ch1, char* ch2);
int main() {
	cout << "分别输入9个数。\n";
	int tmpmatrix[9];
	for (size_t i = 0; i < 9; i++)
	{
		cin >> tmpmatrix[i];
	}
	cout << "------" << endl;
	printMatrix((int **)tmpmatrix);
	cout << "------" << endl;
	int *matrix;
	matrix = change((int *)&tmpmatrix);
	int o_matrix[3][3];
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			o_matrix[j][i] = int(*(matrix + i + 3 * j));
		}
	}
	printMatrix((int **)o_matrix);
	cout << "------" << endl;
	cout << "输入第一个字符串：" << endl;
	char ch1[100];
	cin >> ch1;
	cout << "输入第二个字符串：" << endl;
	char ch2[100];
	cin >> ch2;
	cout << concat(ch1, ch2) << endl;
	cout << "分别输入10个数。" << endl;
	int nums[10];
	int max = 0, min = 0;
	int imax = 0, imin = 0;
	cin >> nums[0];
	max = nums[0];
	min = nums[0];
	int sum = 0;
	for (size_t i = 1; i < 10; i++)
	{
		cin >> nums[i];
		if (nums[i] > max)
		{
			max = nums[i];
			imax = i;
		}
		else if (nums[i] < min)
		{
			min = nums[i];
			imin = i;
		}
		sum += nums[i];
	}
	cout << "Avg: " << sum / 10 << endl;
	cout << "Max: " << "nums[" << imax << "] = " << max << endl;
	cout << "Min: " << "nums[" << imin << "] = " << min << endl;
	int fivefive[5][5];
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			fivefive[i][j] = int(rand());
		}
	}
	for (size_t i = 0; i < 5; i++)
	{
		int sum = 0;
		for (size_t j = 0; j < 5; j++)
		{
			sum += fivefive[j][i];
		}
		cout << "Row " << i + 1 << " sum: " << sum << endl;
	}

	for (size_t i = 0; i < 5; i++)
	{
		int sum = 0;
		for (size_t j = 0; j < 5; j++)
		{
			sum += fivefive[i][j];
		}
		cout << "Column " << i + 1 << " sum: " << sum << endl;
	}
}

void printMatrix(int **matrix) {
	for (size_t k = 0; k < 3; k++)
	{
		for (size_t l = 0; l < 3; l++)
		{
			cout << (int)*(matrix + 3 * k + l) << " ";
		}
		cout << endl;
	}
}

int *change(int *matrix) {
	int o_matrix[3][3];
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			o_matrix[i][j] = int(*(matrix + i + 3 * j));
		}
	}
	return (int *)&o_matrix;
}

char *concat(char* ch1, char* ch2) 
{
	string str1 = ch1;
	string str2 = ch2;
	string rtn = str1 + str2;
	char* ch;
	int len = rtn.length();
	ch = new char[len];
	strcpy(ch, rtn.c_str());
	return ch;
}
