//
// Created by ACER on 09/11/2024.
//


#include <iostream>
#include <cmath>
using namespace std;

// Fungsi yang akan dicari akarnya
double f(double x) {
    return x * x - 4;  // Contoh: x^2 - 4 = 0
}

// Implementasi metode Biseksi
void bisection(double a, double b, double tolerance) {
    if (f(a) * f(b) >= 0) {
        cout << "Metode Biseksi tidak dapat digunakan.\n";
        return;
    }

    double c = a;
    while ((b - a) >= tolerance) {
        c = (a + b) / 2;

        // Jika akar ditemukan
        if (f(c) == 0.0) {
            break;
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    cout << "Akar ditemukan pada: " << c << endl;
}

int main() {
    double a = 0, b = 3, tolerance = 0.01;
    bisection(a, b, tolerance);
    return 0;
}
