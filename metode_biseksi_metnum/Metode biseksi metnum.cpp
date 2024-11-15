//
// Created by ACER on 25/10/2024.
//
#include <iostream>
#include <cmath>
using namespace std;

// Deklarasi fungsi yang akan dicari akarnya
double f(double x) {
    return x * x * x - x - 2; // Contoh: f(x) = x^3 - x - 2
}

// Implementasi Metode Biseksi
void bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "Fungsi tidak berubah tanda di interval [" << a << ", " << b << "]." << endl;
        return;
    }

    double c = a;
    while ((b - a) >= tol) {
        // Hitung titik tengah
        c = (a + b) / 2;

        // Jika nilai fungsi di c adalah nol, berarti akar ditemukan
        if (f(c) == 0.0)
            break;

        // Perbarui interval berdasarkan tanda f(c)
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        cout << "Akar sementara: " << c << endl; // Cetak hasil sementara di setiap iterasi
    }

    cout << "Akar ditemukan: " << c << endl;
}

int main() {
    double a = 1, b = 2; // Batas awal interval
    double tol = 0.0001;  // Toleransi error

    // Panggil fungsi Biseksi
    bisection(a, b, tol);

    return 0;
}
