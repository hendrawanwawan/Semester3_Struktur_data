#include <iostream>
#include <limits>
using namespace std;

struct Node {
    int data;
    Node *next;
};
Node *n = NULL, *head = NULL, *tail = NULL, *x = NULL;
void buatNodeAwal(int i) {
    n = new Node;
    n->data = i;
    head = n;
    tail = n;
    tail->next = NULL;
    cout << "Nilai " << i << " berhasil dimasukkan di node awal.\n";
}
void tambahDiBelakang(int i) {
    n = new Node;
    n->data = i;
    tail->next = n;
    tail = n;
    tail->next = NULL;
    cout << "Nilai " << i << " berhasil ditambahkan di belakang.\n";
}
void tambahDiDepan(int i) {
    n = new Node;
    n->data = i;
    n->next = head;
    head = n;
    cout << "Nilai " << i << " berhasil ditambahkan di depan.\n";
}
void tambahDiTengah(int i, int j) {
    x = head;
    while (x != NULL && x->data != j) {
        x = x->next;
    }
    if (x == NULL) {
        cout << "Node dengan nilai " << j << " tidak ditemukan.\n";
        return;
    }
    n = new Node;
    n->data = i;
    n->next = x->next;
    x->next = n;
    cout << "Nilai " << i << " berhasil ditambahkan setelah nilai " << j << ".\n";
}
void hapusDiDepan() {
    if (head == NULL) {
        cout << "Linked list kosong.\n";
        return;
    }
    x = head;
    head = head->next;
    delete x;
    cout << "Node di depan berhasil dihapus.\n";
}
void hapusDiBelakang() {
    if (head == NULL) {
        cout << "Linked list kosong.\n";
        return;
    }
    x = head;
    if (head == tail) {
        delete head;
        head = tail = NULL;
    } else {
        while (x->next != tail) {
            x = x->next;
        }
        delete tail;
        tail = x;
        tail->next = NULL;
    }
    cout << "Node di belakang berhasil dihapus.\n";
}
void hapusDiTengah(int i) {
    Node *temp = NULL;
    x = head;
    while (x != NULL && x->data != i) {
        temp = x;
        x = x->next;
    }
    if (x == NULL) {
        cout << "Node dengan nilai " << i << " tidak ditemukan.\n";
        return;
    }
    if (temp == NULL) { // Node yang dihapus ada di depan
        head = head->next;
        delete x;
    } else {
        temp->next = x->next;
        delete x;
    }
    cout << "Node dengan nilai " << i << " berhasil dihapus.\n";
}
void tampilData() {
    if (head == NULL) {
        cout << "Linked list kosong.\n";
        return;
    }
    x = head;
    cout << "Isi Linked List: ";
    while (x != NULL) {
        cout << x->data << " ";
        x = x->next;
    }
    cout << endl;
}
int getValidIntegerInput() {
    int input;
    while (true) {
        cin >> input;

        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Input tidak valid. Harap masukkan angka.\nMasukkan lagi: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any extra input in buffer
            return input; // Valid input received, break the loop
        }
    }
}

int main() {
    int choice, data, afterData;
    do {
        cout << "\nMenu:\n";
        cout << "1. Buat Node Awal\n";
        cout << "2. Tambah Node\n";
        cout << "3. Hapus Node\n";
        cout << "4. Tampil Data\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan [1..5]: ";
        choice = getValidIntegerInput();

        switch (choice) {
            case 1:
                if (head == NULL) {
                    cout << "Masukkan nilai: ";
                    data = getValidIntegerInput();
                    buatNodeAwal(data);
                } else {
                    cout << "Node awal sudah dibuat.\n";
                }
                break;
            case 2:
                if (head == NULL) {
                    cout << "Buat node awal terlebih dahulu.\n";
                } else {
                    cout << "Masukkan nilai: ";
                    data = getValidIntegerInput();
                    cout << "Pilihan:\n1. Tambah node di depan\n2. Tambah node di belakang\n3. Tambah node di tengah\n4. Batal\nMasukkan Pilihan: ";
                    int subChoice;
                    subChoice = getValidIntegerInput();

                    switch (subChoice) {
                        case 1:
                            tambahDiDepan(data);
                            break;
                        case 2:
                            tambahDiBelakang(data);
                            break;
                        case 3:
                            cout << "Masukkan nilai setelah node ini: ";
                            afterData = getValidIntegerInput();
                            tambahDiTengah(data, afterData);
                            break;
                        case 4:
                            cout << "Operasi dibatalkan.\n";
                            break;
                        default:
                            cout << "Pilihan tidak valid!\n";
                    }
                }
                break;
            case 3:
                if (head == NULL) {
                    cout << "Linked list kosong.\n";
                } else {
                    cout << "Pilihan:\n1. Hapus node di depan\n2. Hapus node di belakang\n3. Hapus node di tengah\n4. Batal\nMasukkan Pilihan: ";
                    int subChoice;
                    subChoice = getValidIntegerInput();

                    switch (subChoice) {
                        case 1:
                            hapusDiDepan();
                            break;
                        case 2:
                            hapusDiBelakang();
                            break;
                        case 3:
                            cout << "Masukkan nilai node yang ingin dihapus: ";
                            data = getValidIntegerInput();
                            hapusDiTengah(data);
                            break;
                        case 4:
                            cout << "Operasi dibatalkan.\n";
                            break;
                        default:
                            cout << "Pilihan tidak valid!\n";
                    }
                }
                break;
            case 4:
                tampilData();
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 5);
    return 0;
}









//#include <iostream>
//using namespace std;
//
//struct Node {
//    int data;
//    Node *next;
//};
//
//Node *n = NULL, *head = NULL, *tail = NULL, *x = NULL;
//
//void buatNodeAwal(int i) {
//    n = new Node;
//    n->data = i;
//    head = n;
//    tail = n;
//    tail->next = NULL;
//    cout << "Nilai " << i << " berhasil dimasukkan di node awal.\n";
//}
//
//void tambahDiBelakang(int i) {
//    n = new Node;
//    n->data = i;
//    tail->next = n;
//    tail = n;
//    tail->next = NULL;
//    cout << "Nilai " << i << " berhasil ditambahkan di belakang.\n";
//}
//
//void tambahDiDepan(int i) {
//    n = new Node;
//    n->data = i;
//    n->next = head;
//    head = n;
//    cout << "Nilai " << i << " berhasil ditambahkan di depan.\n";
//}
//
//void tambahDiTengah(int i, int j) {
//    x = head;
//    while (x != NULL && x->data != j) {
//        x = x->next;
//    }
//    if (x == NULL) {
//        cout << "Node dengan nilai " << j << " tidak ditemukan.\n";
//        return;
//    }
//    n = new Node;
//    n->data = i;
//    n->next = x->next;
//    x->next = n;
//    cout << "Nilai " << i << " berhasil ditambahkan setelah nilai " << j << ".\n";
//}
//
//void hapusDiDepan() {
//    if (head == NULL) {
//        cout << "Linked list kosong.\n";
//        return;
//    }
//    x = head;
//    head = head->next;
//    delete x;
//    cout << "Node di depan berhasil dihapus.\n";
//}
//
//void hapusDiBelakang() {
//    if (head == NULL) {
//        cout << "Linked list kosong.\n";
//        return;
//    }
//    x = head;
//    if (head == tail) {
//        delete head;
//        head = tail = NULL;
//    } else {
//        while (x->next != tail) {
//            x = x->next;
//        }
//        delete tail;
//        tail = x;
//        tail->next = NULL;
//    }
//    cout << "Node di belakang berhasil dihapus.\n";
//}
//
//void hapusDiTengah(int i) {
//    Node *temp = NULL;
//    x = head;
//    while (x != NULL && x->data != i) {
//        temp = x;
//        x = x->next;
//    }
//    if (x == NULL) {
//        cout << "Node dengan nilai " << i << " tidak ditemukan.\n";
//        return;
//    }
//    if (temp == NULL) { // Node yang dihapus ada di depan
//        head = head->next;
//        delete x;
//    } else {
//        temp->next = x->next;
//        delete x;
//    }
//    cout << "Node dengan nilai " << i << " berhasil dihapus.\n";
//}
//
//void tampilData() {
//    if (head == NULL) {
//        cout << "Linked list kosong.\n";
//        return;
//    }
//    x = head;
//        cout << "Isi Linked List: ";
//        while (x != NULL) {
//            cout << x->data << " ";
//            x = x->next;
//        }
//        cout << endl;
//}
//
//int main() {
//    int choice, data, afterData;
//    do {
//        cout << "\nMenu:\n";
//        cout << "1. Buat Node Awal\n";
//        cout << "2. Tambah Node\n";
//        cout << "3. Hapus Node\n";
//        cout << "4. Tampil Data\n";
//        cout << "5. Keluar\n";
//        cout << "Masukkan pilihan [1..5]: ";
//        cin >> choice;
//
//        switch (choice) {
//            case 1:
//                if (head == NULL) {
//                    cout << "Masukkan nilai: ";
//                    cin >> data;
//                    buatNodeAwal(data);
//                } else {
//                    cout << "Node awal sudah dibuat.\n";
//                }
//                break;
//            case 2:
//                if (head == NULL) {
//                    cout << "Buat node awal terlebih dahulu.\n";
//                } else {
//                    cout << "Masukkan nilai: ";
//                    cin >> data;
//                    cout << "Pilihan:\n1. Tambah node di depan\n2. Tambah node di belakang\n3. Tambah node di tengah\n4. Batal\nMasukkan Pilihan: ";
//                    int subChoice;
//                    cin >> subChoice;
//
//                    switch (subChoice) {
//                        case 1:
//                            tambahDiDepan(data);
//                            break;
//                        case 2:
//                            tambahDiBelakang(data);
//                            break;
//                        case 3:
//                            tampilData();
//                            cout << "Masukkan nilai setelah node ini: ";
//                            cin >> afterData;
//                            tambahDiTengah(data, afterData);
//                            break;
//                        case 4:
//                            cout << "Operasi dibatalkan.\n";
//                            break;
//                        default:
//                            cout << "Pilihan tidak valid!\n";
//                    }
//                }
//                break;
//            case 3:
//                if (head == NULL) {
//                    cout << "Linked list kosong.\n";
//                } else {
//                    cout << "Pilihan:\n1. Hapus node di depan\n2. Hapus node di belakang\n3. Hapus node di tengah\n4. Batal\nMasukkan Pilihan: ";
//                    int subChoice;
//                    cin >> subChoice;
//
//                    switch (subChoice) {
//                        case 1:
//                            hapusDiDepan();
//                            break;
//                        case 2:
//                            hapusDiBelakang();
//                            break;
//                        case 3:
//                            tampilData();
//                            cout << "Masukkan nilai node yang ingin dihapus: ";
//                            cin >> data;
//                            hapusDiTengah(data);
//                            break;
//                        case 4:
//                            cout << "Operasi dibatalkan.\n";
//                            break;
//                        default:
//                            cout << "Pilihan tidak valid!\n";
//                    }
//                }
//                break;
//            case 4:
//                tampilData();
//                break;
//            case 5:
//                cout << "Keluar dari program.\n";
//                break;
//            default:
//                cout << "Pilihan tidak valid!\n";
//        }
//    } while (choice != 5);
//    return 0;
//}
