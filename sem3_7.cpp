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
		cout << "Ðåæèì íàáîðà âûñîòû" << endl;
	}
	else if (0.5 > a && a > 0)
	{
		cout << "Ðåæèì ãîðèçîíòàëüíîãî ïîë¸òà" << endl;
	}
	else
	{
		cout << "Ðåæèì ñíèæåíèÿ" << endl;
	}
	return 0;
}

void init(double& T, double& L, double& D, double& m)
{
	cout << "Ââåäèòå ïîäú¸ìóþ ñèëó (Í): ";
	cin >> L;
	while (L <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Îøèáêà! Ââåäèòå ïîëîæèòåëüíîå çíà÷åíèå: ";
		cin >> L;
	}
	cin.ignore(1000, '\n');

	cout << "Ââåäèòå ñèëó òÿãè (Í): ";
	cin >> T;
	while (T <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Îøèáêà! Ââåäèòå ïîëîæèòåëüíîå çíà÷åíèå: ";
		cin >> T;
	}
	cin.ignore(1000, '\n');

	cout << "Ââåäèòå ñèëó ñîïðîòèâëåíèÿ (Í): ";
	cin >> D;
	while (D <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Îøèáêà! Ââåäèòå ïîëîæèòåëüíîå çíà÷åíèå: ";
		cin >> D;
	}
	cin.ignore(1000, '\n');

	cout << "Ââåäèòå ìàññó (êã): ";
	cin >> m;
	while (m <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Îøèáêà! Ââåäèòå ïîëîæèòåëüíîå çíà÷åíèå: ";
		cin >> m;
	}
	cin.ignore(1000, '\n');


}
