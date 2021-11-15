// Lab_7_2(iter).cpp
// Козубенко Андрій
// Лабораторна робота № 7.2
// Опрацювання багатовимірних масивів ітераційним і рекурсивним способами.
// Варіант 10
// Ітераційний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::setw;

void Create(int **a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int **a, const int rowCount, const int colCount);
void SumOddColMax(int **a, const int rowCount, const int colCount, int &S);

int main() 
{
	srand((unsigned)time(NULL));
	int Low;
	int High;
	int rowCount;
	int colCount;
	int S = 0;

	cout << "How many rows should a new matrix consist of?\n  k = "; cin >> rowCount;
	if (rowCount < 1)
	{
		cerr << "Amount of rows should be >= 1";
		return -1;
	}

	cout << "How many columns should a new matrix consist of?\n  n = "; cin >> colCount;
	if (colCount < 1)
	{
		cerr << "Amount of columns should be >= 1";
		return -1;
	}

	cout << "What interval should RNG satisfy? (i.e. [A;B], A <= B)\n  A = "; cin >> Low;
	cout << "  B = "; cin >> High;
	if (Low > High)
	{
		cerr << "A should be <= B";
		return -1;
	}

	int **Q = new int *[rowCount];
	for (int row = 0; row < rowCount; row++)
		Q[row] = new int[colCount];

	Create(Q, rowCount, colCount, Low, High);
	Print(Q, rowCount, colCount);
	SumOddColMax(Q, rowCount, colCount, S);

	cout << "Sum of maximal elements in odd columns = " << S << endl;

	for (int row = 0; row < rowCount; row++)
		delete[] Q[row];
	delete[] Q;

	return 0;
}

void Create(int **a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int row = 0; row < rowCount; row++)
		for (int col = 0; col < colCount; col++)
			a[row][col] = Low + rand() % (High - Low + 1);
}

void Print(int **a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int row = 0; row < rowCount; row++)
	{
		for (int col = 0; col < colCount; col++)
			cout << setw(4) << a[row][col];
		cout << endl;
	}
	cout << endl;
}

void SumOddColMax(int **a, const int rowCount, const int colCount, int &S)
{
	int z = 0;
	for (int col = 0; z < colCount / 2.; col += 2)
	{
		int max = a[0][col];
		for (int row = 0; row < rowCount; row++)
		{
			if (a[row][col] > max)
				max = a[row][col];
		}

		S += max;
		z++;
	}
		
}