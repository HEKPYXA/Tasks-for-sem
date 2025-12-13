
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
	cout << "Ââåäèòå ÷èñëî ñàìîë¸òîâ: ";
	cin >> n;
	while (n <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ââåäèòå öåëîå ïîëîæèòåëüíîå ÷èñëî: ";
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
	cout << "ÐÅÇÓËÜÒÀÒÛ:" << endl;
	cout << string(40, '=') << endl;
	for (int i = 0; i < n; i++) {
		cout << "Ñàìîëåò " << (i + 1) << ": " << parameters[i].t << " ñ" << endl;
	}

	delete[] parameters;
	return 0;
}


void init(Aircraft* parameters, int n)
{
	cout << "Ââåäèòå âûñîòó ïîë¸òà(ì): ";
	cin >> h;
	while (h <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ââåäèòå ïîëîæèòåëüíîå ÷èñëî: ";
		cin >> h;
	}
	cin.ignore(1000, '\n');

	for (int i = 0; i < n; i++)
	{
		cout << "\n=== Ñàìîëåò" << (i + 1) << " ===" << endl;

		cout << "Ââåäèòå ìàññó ñàìîë¸òà(êã): ";
		cin >> parameters[i].m;
		while (parameters[i].m <= 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Ââåäèòå ïîëîæèòåëüíîå ÷èñëî: ";
			cin >> parameters[i].m;
		}
		cin.ignore(1000, '\n');

		cout << "Ââåäèòå ñèëó òÿãè ñàìîë¸òà(Í): ";
		cin >> parameters[i].T;
		while (parameters[i].T <= parameters[i].m*g || cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Ââåäèòå ïîëîæèòåëüíîå ÷èñëî, áîëüøåå âåñà P = " << parameters[i].m * g<< "Í : ";
			cin >> parameters[i].T;
		}
		cin.ignore(1000, '\n');

		cout << "Ââåäèòå êîýôôèöèåíò ïîú¸ìíîé ñèëû ñàìîë¸òà: ";
		cin >> parameters[i].CL;
		while (parameters[i].CL <= 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Ââåäèòå ïîëîæèòåëüíîå ÷èñëî: ";
			cin >> parameters[i].CL;
		}
		cin.ignore(1000, '\n');

		cout << "Ââåäèòå êîýôôèöèåíò ñîïðîòèâëåíèÿ ñàìîë¸òà: ";
		cin >> parameters[i].CD;
		while (parameters[i].CD <= 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Ââåäèòå ïîëîæèòåëüíîå ÷èñëî: ";
			cin >> parameters[i].CD;
		}
		cin.ignore(1000, '\n');
	}
}
