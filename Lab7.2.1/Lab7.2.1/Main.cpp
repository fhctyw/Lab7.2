// Main.cpp
// Лісничук Арсен
// Лабораторна робота № 7.2.1
// Опрацювання багатовимірних масивів ітераційним і рекурсивним способами
// Варіант 13(Ітераційний спосіб)
#include <iostream>
#include <iomanip>
using namespace std;

void Create(int** arr, const int rowCount, const int colCount, const int Low = -10, const int High = 10);
void Print(int** arr, const int rowCount, const int colCount);
bool SearchMaxElem(int** arr, const int rowCount, const int colCount, int& maxElem);

int main()
{
	srand((unsigned)time(NULL));

	int n, k;
	cout << "k(width) = "; cin >> k;
	cout << "n(height) = "; cin >> n;

	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[k];

	Create(arr, k, n);
	Print(arr, k, n);
	int maxElem;
	if (SearchMaxElem(arr, k, n, maxElem))
		cout << "max elem = " << maxElem << endl;
	else
		cout << "there are no even elements" << endl;

	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}

void Create(int** arr, const int colCount, const int rowCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++) 
			arr[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** arr, const int colCount, const int rowCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << arr[i][j];
		cout << endl;
	}
	cout << endl;
}

bool SearchMaxElem(int** arr, const int colCount, const int rowCount, int& maxElem)
{
	int min_index = 0;
	for (int j = 0; j < colCount; j++)
		if (j % 2 == 0) {
			for (int i = 0; i < rowCount; i++)
			{
				if (arr[i][j] < arr[min_index][j])
				{
					min_index = i;
				}
			}
			maxElem = arr[min_index][j];
			break;
		}

	for (int j = 0; j < colCount; j++)
	{
		if (j % 2 == 0)
		{
			int min_index = 0;
			for (int i = 0; i < rowCount; i++)
			{
				if (arr[i][j] < arr[min_index][j])
				{
					min_index = i;
				}
			}

			if (arr[min_index][j] > maxElem)
			{
				maxElem = arr[min_index][j];
			}
		}
	}

	return true;
}
