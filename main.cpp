#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void adding(int n1, int n2, int* A1, int* A2)
{
	if (n1 > n2)
	{
		int* result = new int[n1 + 1];
		result[0] = n1;
		int i(n1), j(n2),k(n1-n2);
		while (j >= 0)
		{
			result[i] = A1[i - 1] + A2[j - 1];
			i--; j--;
		}
		for (int h = 1; h < k + 1; h++)
		{
			result[h] = A1[h-1];
		}
		for (int h = 0; h < n1 + 1; h++)
		{
			cout << result[h]<<" ";
		}
		delete[] result;
	}
	else if (n1 < n2)
	{
		int* result = new int[n2 + 1];
		result[0] = n2;
		int i(n1), j(n2), k(n2 - n1);
		while (i >= 0)
		{
			result[j] = A1[i - 1] + A2[j - 1];
			i--; j--;
		}
		for (int h = 1; h < k + 1; h++)
		{
			result[h] = A2[h-1];
		}
		for (int h = 0; h < n2 + 1; h++)
		{
			cout << result[h]<<" ";
		}
		delete[] result;
	}
	else if(n1==n2)
	{
		int* result = new int[n1 + 1];
		result[0] = n1;	
		for (int i = n1; i > 0; i--)
		{
			result[i] = A1[i-1] + A2[i-1];
		}
		for (int h = 0; h < n1 + 1; h++)
		{
			cout << result[h]<<" ";
		}
		delete[] result;
	}
}
int main(int argc, char *argv[])
{
	ifstream file1, file2;
	file1.open(argv[1]);
	int tmp_A1[100];
	int i = 0;
	while (!file1.eof())
	{
		file1 >> tmp_A1[i];
		cout << tmp_A1[i] << " ";
		i++;
	}
	int n1 = tmp_A1[0];
	int *A1 = new int[n1];
	for (int i = 0; i < n1; i++)
	{
		A1[i] = tmp_A1[i + 1];
		
	}
	cout << endl;
	file1.close();
	file2.open(argv[2]);
	int tmp_A2[100];
	i = 0;
	while (!file2.eof())
	{
		file2 >> tmp_A2[i];
		cout << tmp_A2[i] << " ";
		i++;
	}
	int n2 = tmp_A2[0];
	int* A2 = new int[n2];
	for (int i = 0; i < n2; i++)
	{
		A2[i] = tmp_A2[i + 1];
		
	}
	cout << endl;
	file2.close();
	adding(n1, n2, A1, A2);
	delete[] A1;
	delete[] A2;
	system("pause");
	return 0;
}