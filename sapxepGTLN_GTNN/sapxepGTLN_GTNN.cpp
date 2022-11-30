#include <iostream>
#include <random> 
#include <ctime>
using namespace std;

void xuatmang(int b[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << "b[" << i << "] = " << b[i] << endl;
	}
	cout << endl;
}
void nhapmang(int a[][100], int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << endl;
}

void xuatmang(int a[][100], int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << "a[" << i << "][" << j << "] = " << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
void GTLN(int a[][100], int n, int m)
{

	int max = a[1][1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] > max)
			{
				max = a[i][j];
			}
	cout << max;
}
void sapxep(int a[][100], int n, int m)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)                     // sắp xếp 1 cột/dọc thì cần 2 for
			for (int k = 1; k <= m; k++)
				if (a[i][j] > a[i][k])                  // sắp xếp hết mảng 2 chiều thì cần 3 for 
				{
					swap(a[i][j], a[i][k]);
				}
}

void songaunhien(int a[][100], int n, int m)
{
	random_device rd;
	mt19937 rng(rd());


	uniform_int_distribution<int> uni(1, 10);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			a[i][j] = uni(rng);
	}
}
int soNT(int n)
{
	if (n <= 1) return 0;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)  return 0; 
	}
	return 1;
	
}
void songuyentotrung(int a[][100], int n, int m)
{
	int dem = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (soNT(a[i][j]) == 0) continue;
			else if (soNT(a[i][j]) == 1)
			{
				dem++;
				cout << a[i][j] << " ";
			}
	cout << endl << dem;
}
void songuyentokotrung(int a[][100], int n, int m, int b[])
{
	 int k = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (soNT(a[i][j]) == 0) continue;
			else if (soNT(a[i][j]) == 1)
			{
				k++;
				b[k] = a[i][j];
			}
}
void xoadong(int a[][100], int& n, int m, int c)
{
	for (int i = c; i <= n - 1; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = a[i + 1][j];
	n--;
}

void xoacot(int a[][100], int n, int& m, int c)
{
	for (int i = 1; i <= n; i++)
		for (int j = c; j <= m - 1; j++)
			a[i][j] = a[i][j + 1];
	m--;
}
int Max(int a[][100], int n)
{
	int max = a[0][0];
	for (int i = 1; i < n; i++)
		if (a[i][i] > max)
			max = a[i][i];
	return max;
}
int main()
{
	// n: doc. m: nganga
	int b[100] = { 0 };
	int a[100][100]; int n = 0, m = 0; cin >> n >> m;
	songaunhien(a, n, m);
	xuatmang(a, n, m);
	cout << endl;
	xoadong(a, n, m, 3);
	xuatmang(a, n,m);
	cout << endl;

	cout << endl;
}