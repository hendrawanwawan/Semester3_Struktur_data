//1. Mengelola Data Antrian Mahasiswa dengan Stack
//Deskripsi: Buat program yang menerima data mahasiswa (nama, NIM, dan jurusan) dan menyimpannya dalam stack. Data yang terakhir dimasukkan adalah data yang pertama kali dihapus (Last In First Out).
//Operasi:
//Push: Menambahkan data mahasiswa ke stack.
//Pop: Mengeluarkan data mahasiswa dari stack.
//Display: Menampilkan seluruh data mahasiswa di stack.



#include <iostream>
//#include <string>
//#include <stack>


using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string jurusan;
};

struct Stack {
    Mahasiswa data[MAX];
    int top;
};

void iniStack(Stack &stack) {
    stack.top = -1;
}

void isFull(Stack stack) {
    stack.top == MAX - 1;
}

void isEmpty(Stack stack) {
    return stack.top=-1;
}

void push(stack &stack, Mahasiswa mhs) {
    if (isFull(stack)) {
        cout << "Stack penuh! \n";
    }else {
        stack.top++;
        stack.data[Stack.top] = mhs;
        cout << "Data mahasiswa ditambahkan ke stack. \n";
    }
}

void pop(Stack &stack) {
    if(isEmpty(stack)) {
        cout <<"Stack kosong! \n";
    }else {
        cout << "Data mahasiswa" << stack.data[stack.top].nama << " dihapus dari stack \n";
    }
}

void display(Stack stack) {
    if(isEmpty(stack)) {
        cout << "Stack kosong! \n";
    }else {
        cout << "Data mahasiswa di stack :\n" ;
        for (int i=0l i<=stack.top; i++) {
            cout<<"Nama : " <<stack.data[i].nama <<", NIm: " << stack.data[i].nim <<", Jurusan: "<<stack.data[i].jurusan <<endl;
        }
    }
}


int main() {
    Stack stack;
    iniStack(stack);
    int choice;
    Mahasiswa mhs;

    do {
        cout << "\n Menu : \n1. Tambah  Mahasiswa \n2. Hapus Mahasiswa \n3. Tampilkan Mahasiwa \n4. Keluar \n";
        cout << "Masukan pilihan : ";
        cin >>choice;
        cin.ignore();
        switch(choice) {
            case 1:
                cout << "Masukan nama : ";
                getline(cin,mhs.nama);
                cout << "Masukan NIM : ";
                getline(cin,mhs.nim);
                cout << "Masukan Jurusan : ";
                getline(cin,mhs.jurusan);
                push(stack, mhs);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                cout<< "Keluar. \n";
                break;
            default:
                cout <<"Pilihan salah!\n";
        }
    } while (choice !=4);
    return 0;
}