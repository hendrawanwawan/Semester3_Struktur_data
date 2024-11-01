#include <iostream>
#define MAX_QUEUE 5

struct Queue {
    int elemen[MAX_QUEUE];
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

void enQ(Queue &q, int i) {
    if (isFull(q)) {
        std::cout << "Queue penuh!" << std::endl;
        return;
    }
    q.rear = (q.rear + 1) % MAX_QUEUE;
    q.elemen[q.rear] = i;
    q.jml++;
}

void deQ(Queue &q, int &i) {
    if (isEmpty(q)) {
        std::cout << "Queue kosong!" << std::endl;
        return;
    }
    i = q.elemen[q.front];
    q.front = (q.front + 1) % MAX_QUEUE;
    q.jml--;
}

void displayQueue(Queue q) {
    if (isEmpty(q)) {
        std::cout << "Queue kosong!" << std::endl;
        return;
    }
    std::cout << "Isi Queue: ";
    for (int i = 0; i < q.jml; i++) {
        int index = (q.front + i) % MAX_QUEUE;
        std::cout << q.elemen[index] << " ";
    }
    std::cout << std::endl;
}

void clearQueue(Queue &q) {
    createQ(q);
    std::cout << "Queue dikosongkan!" << std::endl;
}

int main() {
    Queue q;
    createQ(q);
    int choice, data;

    do {
        std::cout << "\nImplementasi Queue dengan Array\n";
        std::cout << "==============================\n";
        std::cout << "Menu:\n";
        std::cout << "1. Enqueue Data\n";
        std::cout << "2. Dequeue Data\n";
        std::cout << "3. Tampil Isi Queue\n";
        std::cout << "4. Kosongkan Queue\n";
        std::cout << "5. Keluar\n";
        std::cout << "Masukkan pilihan [1..5]: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Masukkan data: ";
                std::cin >> data;
                enQ(q, data);
                break;
            case 2:
                deQ(q, data);
                std::cout << "Data yang didequeue: " << data << std::endl;
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                clearQueue(q);
                break;
            case 5:
                std::cout << "Keluar dari program." << std::endl;
                break;
            default:
                std::cout << "Pilihan tidak valid!" << std::endl;
        }
    } while (choice != 5);

    return 0;
}
