#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>
#include <vector>
using namespace std;
void init(double** aircraft, int n, double& v);
void taska9(double** aircraft, double* L, double* D, double* a, int n, double p, double g, double& v);
void result(double* a,int n);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << fixed << setprecision(2);
	const double p = 0.17;
	const double g = 9.81;

	int n; double v;
	cout << "Введите число самолётов: ";
	cin >> n;
	while (n <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка! Введите целое положительное число: ";
		cin >> n;
	}
	cin.ignore(1000, '\n');
	
	double** aircraft = new double*[n];
	init(aircraft, n, v);
	double* L = new double[n];
	double* D = new double[n];
	double* a = new double[n];
	taska9(aircraft, L, D, a, n, p, g, v);
	result(a, n);



	for (int i = 0; i < n; i++) {
		delete[] aircraft[i];
	}
	delete[] aircraft;
	delete[] D; delete[] L; delete[] a;
	return 0;
}

void init(double** aircraft, int n, double &v)
{
	cout << "Введите скорость самолётов(м/с): ";
	cin >> v;
	while (v <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка! Введите положительное число: ";
		cin >> v;
	}
	cin.ignore(1000, '\n');

	vector < string > parameters = { "'масса' (кг)", "'площадь крыла'(м^2)", "'тяга'(Н)", "'коэффициент сопротивления'", "'коэффициент подъёмной силы'" };
	for (int i = 0; i < n; i++)
	{
		aircraft[i] = new double[5];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << "Введите парамметр " << parameters[j] << " самолёта " << i+1 << " : ";
			cin >> aircraft[i][j];

			while (aircraft[i][j] <= 0 || cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Ошибка! Введите положительное число: ";
				cin >> aircraft[i][j];
			}
			cin.ignore(1000, '\n');
		}
	}

	cout << "\n=== ПРОВЕРКА ВВЕДЕННЫХ ДАННЫХ ===" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Самолёт " << i + 1 << ": ";
		for (int j = 0; j < 5; j++) {
			cout << aircraft[i][j] << " ";
		}
		cout << endl;
	}
}

void taska9(double** aircraft, double* L, double* D, double* a, int n,const double p,const double g, double& v)
{
	for (int i = 0; i < n; i++)
	{
		L[i] = 0.5 * p * v * v * aircraft[i][1] * aircraft[i][4];
		D[i] = 0.5 * p * v * v * aircraft[i][1] * aircraft[i][3];
		double ax = (aircraft[i][2] - D[i]) / aircraft[i][0]; double ay = (L[i] - g * aircraft[i][0]) / aircraft[i][0];
		a[i] = sqrt(pow(ax, 2) + pow(ay, 2));
	}
	
}

void result(double* a, int n)
{
	cout << "\n=== РЕЗУЛЬТАТЫ РАСЧЕТОВ ===" << endl;
	double max = a[0];
	int count = 0;

	for (int i = 1; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (max == a[i])
		{
			count++;
		}
	}

	int* index_max = new int[count];
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (max == a[i])
		{
			index_max[k] = i;
			k++;
		}
	}
	if (n == 1)
	{
		cout << "Самолёт " << 1 << " имеет ускорение " << max << " м/c^2.";
	}
	else if (k == n)
	{
		cout << "У всех самолётов одинаковое ускорение."<< endl;
	}
	else if (k == 1)
	{
		cout << "Самолёт " << index_max[k-1]+1 << " имеет наибольшее ускорение " << max << " м/c^2.";
	}
	else
	{
		cout << "Самолёты ";
		for (int i = 0; i < k-1; i++)
		{
			cout << index_max[i]+1 << " ,";
		}
		cout << " и " << index_max[k-1] + 1  << " имеют наибольшее ускорение " << max << " м/c^2.";
	}
	
	
	delete[] index_max;
}