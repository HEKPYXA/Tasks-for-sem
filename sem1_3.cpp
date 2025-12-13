#include <iostream>
#include <math.h>
using namespace std;

double calculetea(double m, double t, double d) {
    return (t - d) / m;
}
double calculeteay(double m, double l, double g) {
    return (l - m * g) / m;
}

int main()
{
    double m, t, d, l;
    const double g = 9.81;
    cout << "Input m:\n";
    cin >> m;
    cout << "Input T:\n";
    cin >> t;
    cout << "Input D:\n";
    cin >> d;
    cout << "Input L:\n";
    cin >> l;
    cout << "a: " << calculetea(m, t, d) << "\nay: " << calculeteay(m, l, g) << endl;
    return 0;
}
