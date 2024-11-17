#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur Data
struct Kontak {
    int kode;
    string nama;
    string alamat;
    string telepon;
};

// Fungsi untuk Menampilkan Menu
void tampilkanMenu() {
    cout << "=====================================\n";
    cout << "Nama    : [Nama Anda]\n";
    cout << "Stambuk : [Stambuk Anda]\n";
    cout << "=====================================\n";
    cout << "1. Tambah Kontak\n";
    cout << "2. Hapus Kontak\n";
    cout << "3. Lihat Kontak\n";
    cout << "4. Keluar\n";
    cout << "Masukkan Pilihan Anda [1..4]: ";
}

// Fungsi untuk Menambahkan Kontak
void tambahKontak(vector<Kontak> &kontakList) {
    Kontak kontakBaru;
    cout << "Masukkan kode kontak: ";
    cin >> kontakBaru.kode;
    cin.ignore(); // Membersihkan karakter newline di buffer

    cout << "Masukkan nama kontak: ";
    getline(cin, kontakBaru.nama);

    cout << "Masukkan alamat kontak: ";
    getline(cin, kontakBaru.alamat);

    cout << "Masukkan nomor telepon: ";
    getline(cin, kontakBaru.telepon);

    kontakList.push_back(kontakBaru);
    cout << "Kontak berhasil ditambahkan!\n";
}

// Fungsi untuk Menghapus Kontak
void hapusKontak(vector<Kontak> &kontakList) {
    if (kontakList.empty()) {
        cout << "Daftar kontak kosong! Tidak ada yang dapat dihapus.\n";
        return;
    }

    int pilihan;
    cout << "Hapus kontak dari:\n";
    cout << "1. Depan\n";
    cout << "2. Belakang\n";
    cout << "Masukkan pilihan [1/2]: ";
    cin >> pilihan;

    if (pilihan == 1) {
        kontakList.erase(kontakList.begin());
        cout << "Kontak di depan berhasil dihapus!\n";
    } else if (pilihan == 2) {
        kontakList.pop_back();
        cout << "Kontak di belakang berhasil dihapus!\n";
    } else {
        cout << "Pilihan tidak valid!\n";
    }
}

// Fungsi untuk Menampilkan Semua Kontak
void tampilkanKontak(const vector<Kontak> &kontakList) {
    if (kontakList.empty()) {
        cout << "Daftar kontak kosong! Tidak ada yang dapat ditampilkan.\n";
        return;
    }

    cout << "\nDaftar Kontak:\n";
    cout << "=====================================\n";
    for (const auto &kontak : kontakList) {
        cout << "Kode   : " << kontak.kode << "\n";
        cout << "Nama   : " << kontak.nama << "\n";
        cout << "Alamat : " << kontak.alamat << "\n";
        cout << "Telepon: " << kontak.telepon << "\n";
        cout << "-------------------------------------\n";
    }
}

// Fungsi Utama
int main() {
    vector<Kontak> kontakList; // Tempat menyimpan daftar kontak
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore(); // Bersihkan buffer sebelum membaca input berikutnya

        switch (pilihan) {
            case 1:
                tambahKontak(kontakList);
                break;
            case 2:
                hapusKontak(kontakList);
                break;
            case 3:
                tampilkanKontak(kontakList);
                break;
            case 4:
                cout << "Terima kasih telah menggunakan program ini!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

        if (pilihan != 4) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
        }

    } while (pilihan != 4);

    return 0;
}
