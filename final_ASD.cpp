//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool konfirmasi;
//
//const int MAX_QUEUE = 1000;
//
//vector<string> listPembelianTiket;
//
//struct Queue
//{
//    string elemen[MAX_QUEUE];
//    int rear;
//    int front;
//    int jml;
//};
//
//void createQ(Queue &q)
//{
//    q.front = 0;
//    q.rear = -1;
//    q.jml = 0;
//}
//
//bool isFull(Queue q)
//{
//    return q.jml == MAX_QUEUE;
//}
//
//bool isEmpty(Queue q)
//{
//    return q.jml == 0;
//}
//
//void enQ(Queue &q, string i)
//{
//    if (isFull(q))
//    {
//        cout << "tiket telah habis\n\n";
//    }
//    q.rear++;
//    q.jml++;
//    q.elemen[q.rear] = i;
//}
//
//void deQ(Queue &q, string &name)
//{
//    if (isEmpty(q))
//    {
//        cout << "antriant telah kosong \n" << endl;
//    }
//    int n = sizeof(q.elemen) / sizeof(q.elemen[0]);
//    for (int i = 0; i < n; i++)
//    {
//        if (q.elemen[i] == name)
//        {
//            listPembelianTiket.push_back(q.elemen[i]);
//            q.front++;
//            q.jml--;
//            break;
//        }
//        else
//        {
//            if(i == n - 1){
//                 cout << "name tidak ditemukan" << endl;
//            }
//        }
//    }
//}
//
//void del(Queue &q, string name)
//{
//    int n = sizeof(q.elemen) / sizeof(q.elemen[0]);
//    for (int i = 0; i < n; i++)
//    {
//        if (q.elemen[i] == name)
//        {
//            q.elemen[i] = "";
//            q.elemen[i] = q.elemen[q.front];
//            q.front++;
//            q.jml--;
//            break;
//        }
//        else
//        {
//             if(i == n - 1){
//                 cout << "name tidak ditemukan\n" << endl;
//            }
//        }
//    }
//}
//
//
//void menu()
//{
//    cout << "1. pesan tiket \n2. batalkan tiket\n\n";
//}
//
//void role()
//{
//    cout << "1. Pembeli \n2. Petugas \n3. Keluar \n\n";
//}
//void menuPetugas()
//{
//    cout << "1. konfirmasi pembelian tiket \n2. list pembelian tiket" << endl;
//}
//
//int main()
//{
//
//    Queue q;
//    createQ(q);
//
//    string pilih;
//    int pilihan;
//    string name;
//    int sandi;
//    int code = 159;
//
//    while (pilihan <= 2)
//    {
//        /* code */
//        cout << "\n\n";
//        role();
//        cout << "masuk sebagai : ";
//        cin >> pilih;
//
//        if (pilih == "1")
//        {
//            menu();
//            cout << "masukan pilihan : ";
//            cin >> pilih;
//            if (pilih == "1")
//            {
//                cout << "jumlah " << q.jml << endl;
//                for (int i = 0; i < 1; i++)
//                {
//                    cout << "masukan nama : ";
//                    // getline(cin, name);
//                    cin >> name;
//                    cout << "\n\n";
//                    enQ(q, name);
//                }
//            }
//            else if (pilih == "2")
//            {
//                cout << "masukan nama yang akan dihapus : ";
//                cin >> name;
//                del(q, name);
//            }
//            else
//            {
//                cout << "maaf menu tidak tersedia\n" << endl;
//            }
//        }
//        else if (pilih == "2")
//        {
//            cout << "masukan sandi : ";
//            cin >> sandi;
//            if (sandi == code)
//            {
//                menuPetugas();
//                cout << "masukan pilihan : ";
//                cin >> pilih;
//                if (pilih == "1")
//                {
//                    cout << "masukan name : ";
//                    cin >> name;
//                    deQ(q, name);
//                }
//                else if (pilih == "2")
//                {
//
//                    cout << "nama yang telah dikonfirmasi" << endl;
//                    int i;
//                    for (string value : listPembelianTiket)
//                    {
//                        i++;
//                        cout << i << ". " << value << endl;
//                    }
//                }
//                else
//                {
//                    cout << "pilihan tidak ada\n" << endl;
//                }
//            }
//        }else if(pilih == "3"){
//            break;
//        }else {
//            cout << "menu tidak tersedia" << endl;
//            // break;
//        }
//    }
//
//    cout << "terima kasih" << endl;
//
//    return 0;
//}

#include <iostream>
#include <vector>

using namespace std;

bool konfirmasi;
const int MAX_QUEUE = 1000;
vector<string> listPembelianTiket;

struct Queue {
    string elemen[MAX_QUEUE];
    int rear;
    int front;
    int jml;
};

void createQ(Queue &q) {
    q.front = 0;
    q.rear = -1;
    q.jml = 0;
}

bool isFull(Queue q) {
    return q.jml == MAX_QUEUE;
}

bool isEmpty(Queue q) {
    return q.jml == 0;
}

void enQ(Queue &q, string i) {
    if (isFull(q)) {
        cout << "Tiket telah habis\n\n";
        return;
    }
    q.rear++;
    q.jml++;
    q.elemen[q.rear] = i;
}

void deQ(Queue &q) {
    if (isEmpty(q)) {
        cout << "Antrian telah kosong\n" << endl;
        return;
    }
    listPembelianTiket.push_back(q.elemen[q.front]);
    q.front++;
    q.jml--;
}

void del(Queue &q, string name) {
    if (isEmpty(q)) {
        cout << "Antrian kosong\n";
        return;
    }

    bool found = false;
    for (int i = q.front; i <= q.rear; i++) {
        if (q.elemen[i] == name) {
            found = true;
            for (int j = i; j < q.rear; j++) {
                q.elemen[j] = q.elemen[j + 1];
            }
            q.rear--;
            q.jml--;
            break;
        }
    }

    if (!found) {
        cout << "Nama tidak ditemukan\n";
    }
}

void menu() {
    cout << "1. Pesan tiket\n2. Batalkan tiket\n\n";
}

void role() {
    cout << "1. Pembeli\n2. Petugas\n3. Keluar\n\n";
}

void menuPetugas() {
    cout << "1. Konfirmasi pembelian tiket\n2. List pembelian tiket\n";
}

int main() {
    Queue q;
    createQ(q);

    int pilihan;
    string pilih, name;
    int sandi;
    int code = 159;

    while (true) {
        cout << "\n\n";
        role();
        cout << "Masuk sebagai: ";
        cin >> pilih;

        if (pilih == "1") {
            menu();
            cout << "Masukkan pilihan: ";
            cin >> pilih;
            if (pilih == "1") {
                cout << "Jumlah: " << q.jml << endl;
                cout << "Masukkan nama: ";
                cin >> name;
                cout << "\n\n";
                enQ(q, name);
            } else if (pilih == "2") {
                cout << "Masukkan nama yang akan dihapus: ";
                cin >> name;
                del(q, name);
            } else {
                cout << "Maaf, menu tidak tersedia\n" << endl;
            }
        } else if (pilih == "2") {
            cout << "Masukkan sandi: ";
            cin >> sandi;
            if (sandi == code) {
                menuPetugas();
                cout << "Masukkan pilihan: ";
                cin >> pilih;
                if (pilih == "1") {
                    cout << "Masukkan nama: ";
                    cin >> name;
                    deQ(q);
                } else if (pilih == "2") {
                    cout << "Nama yang telah dikonfirmasi:\n";
                    for (size_t i = 0; i < listPembelianTiket.size(); i++) {
                        cout << i + 1 << ". " << listPembelianTiket[i] << endl;
                    }
                } else {
                    cout << "Pilihan tidak ada\n" << endl;
                }
            } else {
                cout << "Sandi salah\n";
            }
        } else if (pilih == "3") {
            break;
        } else {
            cout << "Menu tidak tersedia\n";
        }
    }

    cout << "Terima kasih\n";
    return 0;
}
