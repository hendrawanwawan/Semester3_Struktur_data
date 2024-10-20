#include <iostream>
using namespace std;

#define MAX_STACK 5
struct Stack {
    int top;
    int elemen[MAX_STACK];
};
void createStack(Stack &stack) {
    stack.top= -1;
}
bool isEmpty(Stack stack) {
    return stack.top== -1;
}
bool isFull(Stack stack) {
    return stack.top == MAX_STACK - 1;
}
void push(Stack &stack,int i) {
    if(isFull(stack)) {
        cout << "Stack penuh. Tidak bisa menambah data!\n";
    }else {
        stack.top++;
        stack.elemen[stack.top] = i;
        cout << "Data " << i << " ditambahkan ke stack.\n";
    }
}
void pop(Stack &stack, int &i) {
    if(isEmpty(stack)) {
        cout << "Stack kosong. Tidak ada data untuk dihapus. \n";
    }else {
        i = stack.elemen[stack.top];
        stack.top--;
        cout<< "Data " << i << " dihapus dari stack. \n";
    }
}
void display(Stack stack) {
    if(isEmpty(stack)) {
        cout << "stack kosong. \n";
    }else {
        cout << "Isi stack : ";
        for(int i=0; i<=stack.top; i++) {
            cout << stack.elemen[i] << " ";
        }
        cout << "\n";
    }
}
void clearStack(Stack &stack) {
    stack.top = -1;
    cout << "Stack telah dikosongkan. \n";
}

int main() {
    Stack stack;
    createStack(stack);
    int choice,value;
    cout << "Implementasi Stack dengan array\n";
    cout << "===============================\n";
    do {
        cout << "\nMenu \n";
        cout << "1. Push Data  \n";
        cout << "2. Pop Data \n";
        cout << "3. Tampilkan Isi Stack \n";
        cout << "4. Kosongkan Stack \n";
        cout << "5. Keluar \n";
        cout << "Masukan Pilihan [1-5] : ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Masukan data : ";
            cin >> value;
            push(stack, value);
            break;
        case 2:
            pop(stack, value);
            break;
        case 3:
            display(stack);
            break;
        case 4:
            clearStack(stack);
            break;
        case 5:
            cout << "Program selesai. \n";
            break;
        default:
            cout << "Pilihan tidak valid. coba lagi.\n";
        }
    }while (choice !=5);
    return 0;
}