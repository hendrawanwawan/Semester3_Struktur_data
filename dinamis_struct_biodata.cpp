#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa{
    string nama;
    int usia;
    string alamat;
};

struct Matakuliah {
    string nama_matkul;
    int sks;
    string dosen;
};

void kakangangang() {
    Mahasiswa mhs;
    Matakuliah mk;
    char ulang;

    do{
        cout << "Masukan nama Mahasiswa : ";
        getline(cin,mhs.nama);

        cout << "Masukan Usia mahasiswa : ";
        cin >> mhs.usia;
        cin.ignore();

        cout << "Masukan alamat mahasiswa : ";
        getline(cin,mhs.alamat);

        cout << "Masukan nama Matkul : ";
        getline(cin,mk.nama_matkul);

        cout << "Masukan jumlah sks : ";
        cin >>mk.sks;
        cin.ignore();

        cout << "Masukan nama dosen pengampu : ";
        getline(cin,mk.dosen);

        cout<<" \n Data Mahasiswa" <<endl;
        cout<<" Nama : "<<mhs.nama <<endl;
        cout<<" Usia : "<<mhs.usia <<endl;
        cout<<" Alamat : "<<mhs.alamat <<endl;

        cout<<" \n Data Mata kuliah : "<<endl;
        cout<<" Nama Mata Kuliah : "<<mk.nama_matkul<<endl;
        cout<<" Jumlah Sks : "<<mk.sks<<endl;
        cout<<" Nama Dosen : "<<mk.dosen<<endl;

        cout << "\n Apakah anda ingin mengimput data lagi? (y/n)";
        cin >> ulang;
        cin.ignore();

        cout << endl;
    }while (ulang == 'y' || ulang == 'Y');
}
int main() {
    kakangangang();
    return 0;
}