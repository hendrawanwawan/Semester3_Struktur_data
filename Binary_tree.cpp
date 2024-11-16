//#include <iostream>
//#include <queue>
//using namespace std;
//
//struct Node {
//    int data;
//    Node *left;
//    Node *right;
//};
//
//Node *root = NULL, *n = NULL, *temp = NULL;
//
//Node *createNode(int data) {
//    Node *n = new Node;
//    n->data = data;
//    n->left = NULL;
//    n->right = NULL;
//    return n;
//}
//
//// Function insert
//void insert(Node *&root, int data) {
//    if (root == NULL)
//        root = createNode(data);
//    else if (data <= root->data)
//        insert(root->left, data);
//    else
//        insert(root->right, data);
//}
//
//// Fungsi Traversal
//void levelOrder(Node *root) {
//    if (root == NULL) return;
//    queue<Node*> q;
//    q.push(root);
//    while (!q.empty()) {
//        cout << q.front()->data << " ";
//        if (q.front()->left != NULL)
//            q.push(q.front()->left);
//        if (q.front()->right != NULL)
//            q.push(q.front()->right);
//        q.pop();
//    }
//    cout << endl;
//}
//
//void preOrder(Node *root) {
//    if (root == NULL) return;
//    cout << root->data << " ";
//    preOrder(root->left);
//    preOrder(root->right);
//    cout << endl;
//}
//
//void inOrder(Node *root) {
//    if (root == NULL) return;
//    inOrder(root->left);
//    cout << root->data << " ";
//    inOrder(root->right);
//    cout << endl;
//}
//
//void postOrder(Node *root) {
//    if (root == NULL) return;
//    postOrder(root->left);
//    postOrder(root->right);
//    cout << root->data << " ";
//    cout << endl;
//}
//
//// Fungsi Search
//bool cari(Node *root, int data) {
//    if (root == NULL)
//        return false;
//    else if (data < root->data)
//        return cari(root->left, data);
//    else if (data > root->data)
//        return cari(root->right, data);
//    else
//        return true;
//}
//
//// Mencari Node Minimum
//Node *cariMin(Node *root) {
//    if (root == NULL)
//        return NULL;
//    while (root->left != NULL)
//        root = root->left;
//    return root;
//}
//
//// Fungsi Delete
//void hapus(Node *&root, int data) {
//    if (root == NULL)
//        return;
//    else if (data < root->data)
//        hapus(root->left, data);
//    else if (data > root->data)
//        hapus(root->right, data);
//    else {
//        if (root->left == NULL && root->right == NULL) {
//            delete root;
//            root = NULL;
//        } else if (root->left == NULL) {
//            Node *temp = root;
//            root = root->right;
//            delete temp;
//        } else if (root->right == NULL) {
//            Node *temp = root;
//            root = root->left;
//            delete temp;
//        } else {
//            Node *temp = cariMin(root->right);
//            root->data = temp->data;
//            hapus(root->right, root->data);
//        }
//    }
//}
//
//void tampilkanMenu() {
//    cout << "Menu:\n";
//    cout << "1. Buat Node Awal\n";
//    cout << "2. Tambah Node\n";
//    cout << "3. Hapus Node\n";
//    cout << "4. Tampil Data\n";
//    cout << "5. Keluar\n";
//}
//
//void tampilkanTraversal() {
//    cout << "Pilihan Traversal:\n";
//    cout << "1. Level Order\n";
//    cout << "2. Preorder\n";
//    cout << "3. Inorder\n";
//    cout << "4. Postorder\n";
//}
//
//int main() {
//    int pilihan, nilai;
//    do {
//        tampilkanMenu();
//        cout << "Masukkan pilihan [1..5]: ";
//        cin >> pilihan;
//        switch (pilihan) {
//            case 1:
//                cout << "Masukkan nilai: ";
//                cin >> nilai;
//                root = createNode(nilai);
//                cout << "Nilai " << nilai << " berhasil dimasukkan di node awal.\n";
//                break;
//            case 2:
//                cout << "Masukkan nilai: ";
//                cin >> nilai;
//                insert(root, nilai);
//                cout << "Nilai " << nilai << " berhasil ditambahkan.\n";
//                break;
//            case 3:
//                cout << "Masukkan nilai untuk dihapus: ";
//                cin >> nilai;
//                hapus(root, nilai);
//                cout << "Nilai " << nilai << " berhasil dihapus.\n";
//                break;
//            case 4:
//                tampilkanTraversal();
//                int traversal;
//                cout << "Masukkan pilihan [1..4]: ";
//                cin >> traversal;
//                if (traversal == 1) levelOrder(root);
//                else if (traversal == 2) preOrder(root);
//                else if (traversal == 3) inOrder(root);
//                else if (traversal == 4) postOrder(root);
//                break;
//            case 5:
//                cout << "Keluar dari program.\n";
//                break;
//            default:
//                cout << "Pilihan tidak valid.\n";
//        }
//    } while (pilihan != 5);
//
//    return 0;
//}

#include <iostream>
#include <queue>
using namespace std;

// Struktur Node untuk Binary Search Tree
struct Node {
    int data;
    Node *left;
    Node *right;
};

// Deklarasi node root, temp, dan lainnya
Node *root = NULL, *n = NULL, *temp = NULL;

// Fungsi untuk membuat node baru
Node *createNode(int data) {
    n = new Node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Fungsi untuk menambahkan node ke dalam BST
void insert(Node *&root, int data) {
    if (root == NULL)
        root = createNode(data);
    else if (data <= root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

// Fungsi untuk mencari nilai minimum di tree
Node *cariMin(Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Fungsi untuk menghapus node di BST
void hapus(Node *&root, int data) {
    if (root == NULL)
        return;
    else if (data < root->data)
        hapus(root->left, data);
    else if (data > root->data)
        hapus(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL) { // Kasus 1: Node tanpa anak
            delete root;
            root = NULL;
        } else if (root->left == NULL) { // Kasus 2: Node hanya punya anak kanan
            temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) { // Kasus 2: Node hanya punya anak kiri
            temp = root;
            root = root->left;
            delete temp;
        } else { // Kasus 3: Node punya dua anak
            temp = cariMin(root->right);
            root->data = temp->data;
            hapus(root->right, temp->data);
        }
    }
}

// Fungsi traversal Inorder
void inOrder(Node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Fungsi traversal Preorder
void preOrder(Node *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Fungsi traversal Postorder
void postOrder(Node *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Fungsi traversal Level Order
void levelOrder(Node *root) {
    if (root == NULL) return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        cout << q.front()->data << " ";
        if (q.front()->left != NULL)
            q.push(q.front()->left);
        if (q.front()->right != NULL)
            q.push(q.front()->right);
        q.pop();
    }
}

// Fungsi untuk mencari data di BST
bool cari(Node *root, int data) {
    if (root == NULL)
        return false;
    else if (data < root->data)
        return cari(root->left, data);
    else if (data > root->data)
        return cari(root->right, data);
    else
        return true;
}

// Fungsi utama (main)
int main() {
    int pilihan, nilai;
    do {
        cout << "\n=================================\n";
        cout << "       Menu Binary Search Tree\n";
        cout << "=================================\n";
        cout << "1. Tambahkan Node\n";
        cout << "2. Cari Node\n";
        cout << "3. Hapus Node\n";
        cout << "4. Tampilkan Tree (Inorder)\n";
        cout << "5. Tampilkan Tree (Preorder)\n";
        cout << "6. Tampilkan Tree (Postorder)\n";
        cout << "7. Tampilkan Tree (Level Order)\n";
        cout << "8. Keluar\n";
        cout << "=================================\n";
        cout << "Masukkan pilihan Anda [1-8]: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nMasukkan nilai yang ingin ditambahkan: ";
                cin >> nilai;
                insert(root, nilai);
                cout << "-> Node dengan nilai " << nilai << " berhasil ditambahkan.\n";
                break;
            case 2:
                cout << "\nMasukkan nilai yang ingin dicari: ";
                cin >> nilai;
                if (cari(root, nilai))
                    cout << "-> Node dengan nilai " << nilai << " ditemukan di tree.\n";
                else
                    cout << "-> Node dengan nilai " << nilai << " tidak ditemukan di tree.\n";
                break;
            case 3:
                cout << "\nMasukkan nilai yang ingin dihapus: ";
                cin >> nilai;
                hapus(root, nilai);
                cout << "-> Node dengan nilai " << nilai << " berhasil dihapus.\n";
                break;
            case 4:
                cout << "\nTraversal Inorder: ";
                inOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "\nTraversal Preorder: ";
                preOrder(root);
                cout << endl;
                break;
            case 6:
                cout << "\nTraversal Postorder: ";
                postOrder(root);
                cout << endl;
                break;
            case 7:
                cout << "\nTraversal Level Order: ";
                levelOrder(root);
                cout << endl;
                break;
            case 8:
                cout << "\n-> Keluar dari program. Terima kasih!\n";
                break;
            default:
                cout << "\n-> Pilihan tidak valid! Silakan coba lagi.\n";
        }
    } while (pilihan != 8);

    return 0;
}

