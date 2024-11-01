#include <iostream>

struct Node {
    int data;
    Node *next;
};

Node *n = NULL, *head = NULL, *tail = NULL, *x = NULL;

// Function to create the first node
void buatNodeAwal(int i) {
    n = new Node;
    n->data = i;
    head = n;
    tail = n;
    tail->next = NULL;
    std::cout << "Nilai " << i << " berhasil dimasukkan di node awal.\n";
}

// Function to add a node at the end
void tambahDiBelakang(int i) {
    n = new Node;
    n->data = i;
    tail->next = n;
    tail = n;
    tail->next = NULL;
    std::cout << "Nilai " << i << " berhasil ditambahkan di belakang.\n";
}

// Function to add a node at the front
void tambahDiDepan(int i) {
    n = new Node;
    n->data = i;
    n->next = head;
    head = n;
    std::cout << "Nilai " << i << " berhasil ditambahkan di depan.\n";
}

// Function to add a node in the middle after a specific node
void tambahDiTengah(int i, int j) {
    x = head;
    while (x != NULL && x->data != j) {
        x = x->next;
    }
    if (x == NULL) {
        std::cout << "Node dengan nilai " << j << " tidak ditemukan.\n";
        return;
    }
    n = new Node;
    n->data = i;
    n->next = x->next;
    x->next = n;
    std::cout << "Nilai " << i << " berhasil ditambahkan setelah nilai " << j << ".\n";
}

// Function to delete the node at the front
void hapusDiDepan() {
    if (head == NULL) {
        std::cout << "Linked list kosong.\n";
        return;
    }
    x = head;
    head = head->next;
    delete x;
    std::cout << "Node di depan berhasil dihapus.\n";
}

// Function to delete the node at the end
void hapusDiBelakang() {
    if (head == NULL) {
        std::cout << "Linked list kosong.\n";
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
    std::cout << "Node di belakang berhasil dihapus.\n";
}

// Function to delete a specific node in the middle
void hapusDiTengah(int i) {
    Node *temp = NULL;
    x = head;
    while (x != NULL && x->data != i) {
        temp = x;
        x = x->next;
    }
    if (x == NULL) {
        std::cout << "Node dengan nilai " << i << " tidak ditemukan.\n";
        return;
    }
    if (temp == NULL) { // The node to delete is at the front
        head = head->next;
        delete x;
    } else {
        temp->next = x->next;
        delete x;
    }
    std::cout << "Node dengan nilai " << i << " berhasil dihapus.\n";
}

// Function to display the data in the linked list
void tampilData() {
    if (head == NULL) {
        std::cout << "Linked list kosong.\n";
        return;
    }
    x = head;
    std::cout << "Isi Linked List: ";
    while (x != NULL) {
        std::cout << x->data << " ";
        x = x->next;
    }
    std::cout << std::endl;
}

// Main function to display the menu and process user input
int main() {
    int choice, data, afterData;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Buat Node Awal\n";
        std::cout << "2. Tambah Node\n";
        std::cout << "3. Hapus Node\n";
        std::cout << "4. Tampil Data\n";
        std::cout << "5. Keluar\n";
        std::cout << "Masukkan pilihan [1..5]: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (head == NULL) {
                    std::cout << "Masukkan nilai: ";
                    std::cin >> data;
                    buatNodeAwal(data);
                } else {
                    std::cout << "Node awal sudah dibuat.\n";
                }
                break;
            case 2:
                if (head == NULL) {
                    std::cout << "Buat node awal terlebih dahulu.\n";
                } else {
                    std::cout << "Masukkan nilai: ";
                    std::cin >> data;
                    std::cout << "Tambah di:\n1. Depan\n2. Belakang\n3. Setelah nilai tertentu\nPilihan: ";
                    int subChoice;
                    std::cin >> subChoice;
                    if (subChoice == 1) {
                        tambahDiDepan(data);
                    } else if (subChoice == 2) {
                        tambahDiBelakang(data);
                    } else if (subChoice == 3) {
                        std::cout << "Masukkan nilai setelah node ini: ";
                        std::cin >> afterData;
                        tambahDiTengah(data, afterData);
                    } else {
                        std::cout << "Pilihan tidak valid!\n";
                    }
                }
                break;
            case 3:
                if (head == NULL) {
                    std::cout << "Linked list kosong.\n";
                } else {
                    std::cout << "Hapus di:\n1. Depan\n2. Belakang\n3. Nilai tertentu\nPilihan: ";
                    int subChoice;
                    std::cin >> subChoice;
                    if (subChoice == 1) {
                        hapusDiDepan();
                    } else if (subChoice == 2) {
                        hapusDiBelakang();
                    } else if (subChoice == 3) {
                        std::cout << "Masukkan nilai node yang ingin dihapus: ";
                        std::cin >> data;
                        hapusDiTengah(data);
                    } else {
                        std::cout << "Pilihan tidak valid!\n";
                    }
                }
                break;
            case 4:
                tampilData();
                break;
            case 5:
                std::cout << "Keluar dari program.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 5);

    return 0;
}
