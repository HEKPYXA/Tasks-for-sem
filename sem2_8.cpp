
#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>
using namespace std;
double h;
const double g = 9.81;
struct Aircraft
{
	double m, T, CL, CD, h, ay, t;
};
void init(Aircraft* parameters, int n);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << fixed << setprecision(2);
	
	int n;
	cout << "¬ведите число самолЄтов: ";
	cin >> n;
	while (n <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "¬ведите целое положительное число: ";
		cin >> n;
	}
	cin.ignore(1000, '\n');
	
	Aircraft* parameters = new Aircraft[n];
	init(parameters, n);

	for (int i = 0; i < n; i++)
	{
		parameters[i].ay = (parameters[i].T - parameters[i].m * g) / parameters[i].m;
		parameters[i].t = sqrt(2 * h / parameters[i].ay);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (parameters[j].t > parameters[j + 1].t) {
				Aircraft temp = parameters[j];
				parameters[j] = parameters[j + 1];
				parameters[j + 1] = temp;
			}
		}
	}

	cout << "\n" << string(40, '=') << endl;
	cout << "–≈«”Ћ№“ј“џ:" << endl;
	cout << string(40, '=') << endl;
	for (int i = 0; i < n; i++) {
		cout << "—амолет " << (i + 1) << ": " << parameters[i].t << " с" << endl;
	}

	delete[] parameters;
	return 0;
}


void init(Aircraft* parameters, int n)
{
	cout << "¬ведите высоту полЄта(м): ";
	cin >> h;
	while (h <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "¬ведите положительное число: ";
		cin >> h;
	}
	cin.ignore(1000, '\n');

	for (int i = 0; i < n; i++)
	{
		cout << "\n=== —амолет" << (i + 1) << " ===" << endl;

		cout << "¬ведите массу самолЄта(кг): ";
		cin >> parameters[i].m;
		while (parameters[i].m <= 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "¬ведите положительное число: ";
			cin >> parameters[i].m;
		}
		cin.ignore(1000, '\n');

		cout << "¬ведите силу т€ги самолЄта(Ќ): ";
		cin >> parameters[i].T;
		while (parameters[i].T <= parameters[i].m*g || cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "¬ведите положительное число, большее веса P = " << parameters[i].m * g<< "Ќ : ";
			cin >> parameters[i].T;
		}
		cin.ignore(1000, '\n');

		cout << "¬ведите коэффициент поъЄмной силы самолЄта: ";
		cin >> parameters[i].CL;
		while (parameters[i].CL <= 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "¬ведите положительное число: ";
			cin >> parameters[i].CL;
		}
		cin.ignore(1000, '\n');

		cout << "¬ведите коэффициент сопротивлени€ самолЄта: ";
		cin >> parameters[i].CD;
		while (parameters[i].CD <= 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "¬ведите положительное число: ";
			cin >> parameters[i].CD;
		}
		cin.ignore(1000, '\n');
	}
}
