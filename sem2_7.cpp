#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>
using namespace std;
void init(double& T, double& L, double& D, double& m);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << fixed << setprecision(2);

	double T, L, D, m;
	const double g = 9.81;
	init(T, L, D, m);

	double ay = (L - m * g) / m;
	double ax = (T - D) / m;
	double a = sqrt(ax * ax + ay * ay);

	if (a > 0.5)
	{
		cout << "Режим набора высоты" << endl;
	}
	else if (0.5 > a && a > 0)
	{
		cout << "Режим горизонтального полёта" << endl;
	}
	else
	{
		cout << "Режим снижения" << endl;
	}
	return 0;
}

void init(double& T, double& L, double& D, double& m)
{
	cout << "Введите подъёмую силу (Н): ";
	cin >> L;
	while (L <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка! Введите положительное значение: ";
		cin >> L;
	}
	cin.ignore(1000, '\n');

	cout << "Введите силу тяги (Н): ";
	cin >> T;
	while (T <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка! Введите положительное значение: ";
		cin >> T;
	}
	cin.ignore(1000, '\n');

	cout << "Введите силу сопротивления (Н): ";
	cin >> D;
	while (D <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка! Введите положительное значение: ";
		cin >> D;
	}
	cin.ignore(1000, '\n');

	cout << "Введите массу (кг): ";
	cin >> m;
	while (m <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка! Введите положительное значение: ";
		cin >> m;
	}
	cin.ignore(1000, '\n');


}