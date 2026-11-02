
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    const double a = 0.1;
    const double b = 1.0;
    const int intervals = 10;
    const int n = 10;
    const double eps = 0.0001;

    const double ln3 = log(3.0);
    const double h = (b - a) / intervals;

    cout << fixed << setprecision(6);
    cout << "X\t\tSN\t\tSE\t\tY\n";

    for (int i = 0; i <= intervals; ++i) {
        double x = a + i * h;

        // Sum with a fixed number of terms
        double term = 1.0;
        double sn = term;

        for (int k = 1; k <= n; ++k) {
            term *= (x * ln3) / k;
            sn += term;
        }

        // Sum with the required precision
        term = 1.0;
        double se = term;
        int k = 0;

        do {
            ++k;
            term *= (x * ln3) / k;

            if (fabs(term) >= eps) {
                se += term;
            }

        } while (fabs(term) >= eps && k < 1000);

        // Exact value of the function
        double y = pow(3.0, x);

        cout << x << "\t"
             << sn << "\t"
             << se << "\t"
             << y << '\n';
    }

    return 0;
}
