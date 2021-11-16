// Main.cpp
// Лісничук Арсен
// Лабораторна робота № 7.2.2
// Опрацювання багатовимірних масивів ітераційним і рекурсивним способами
// Варіант 13(Рекурсивний спосіб)
#include <iostream>
#include <iomanip>
using namespace std;

void CreateRow(int** arr, const int rowNo, const int N, int colNo, const int Low, const int High);
void CreateRows(int** arr, const int N1, int rowNo, const int N2, const int Low=-10, const int High=10);
void PrintRow(int** arr, const int rowNo, const int N, int colNo);
void PrintRows(int** arr, const int N1, int rowNo, const int N2);
bool SearchMaxElem(int** a, const int N, int i, int& minEven, int& k);

void InitArrayZeros(int* arr, const int size, const int i);
void FindMinElemCol(int** arr, int *tmpArr, const int rowNo, const int N, int colNo);

int main()
{
	srand((unsigned)time(NULL));

	int n, k;
	cout << "k(width) = "; cin >> k;
	cout << "n(height) = "; cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[k];
	CreateRows(arr, k, n, 0);
	PrintRows(arr, k, n, 0);
	int maxElem;
	if (SearchMaxElem(arr, k, n, maxElem))
		cout << "min elem = " << maxElem << endl;
	else
		cout << "there are no even elements" << endl;

	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}

void CreateRow(int** arr, const int rowNo, const int N, int colNo, const int Low, const int High)
{
	arr[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < N - 1)
		CreateRow(arr, rowNo, N, colNo + 1, Low, High);
}

void CreateRows(int** arr, const int colCount, const int rowCount, int rowNo, const int Low, const int High)
{
	CreateRow(arr, rowNo, colCount, 0, Low, High);
	if (rowNo < rowCount - 1)
		CreateRows(arr, colCount, rowCount, rowNo + 1, Low, High);
}

void PrintRow(int** arr, const int rowNo, const int N, int colNo)
{
	cout << setw(4) << arr[rowNo][colNo];
	if (colNo < N - 1)
		PrintRow(arr, rowNo, N, colNo + 1);
	else
		cout << endl;
}

void PrintRows(int** arr, const int colCount, const int rowCount, int rowNo)
{
	PrintRow(arr, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		PrintRows(arr, colCount, rowCount, rowNo + 1);
	else
		cout << endl;
}

bool SearchMaxElem(int** arr, const int N, int i, int& maxElem, int& k)
{
	//if (arr[i][N - i - 1]);
	if 
}

void InitArrayZeros(int* arr, const int size, const int i)
{
	arr[i] = 0;
	if (i < size - 1)
		InitArrayZeros(arr, size, i + 1);
}

/*
* for (int j = 0; j < rowCount; j++)
		if (j % 2 == 0) {
			for (int i = 0; i < colCount; i++)
				if (arr[i][j] < arr[tmpArr[ti]][j])
					tmpArr[ti] = i;
			ti++;
		}
*/

void FindMinElemCol(int** arr, int* tmpArr, const int rowNo, const int N, int colNo)
{
	if (arr[rowNo][colNo] < arr[tmpArr])

}
