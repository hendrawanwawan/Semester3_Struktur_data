#include <iostream>
#include <queue>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *root = NULL, *n = NULL, *temp = NULL;

// Pembuatan Node Baru
Node *createNode(int data) {
    n = new Node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Proses Insert node pada BST
void insert(Node *&root, int data) {
    if (root == NULL)
        root = createNode(data);
    else if (data <= root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

// Binary Tree Traversal menggunakan Level Order
void levelOrder(Node *root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        cout << q.front()->data << " ";
        if (q.front()->left != NULL)
            q.push(q.front()->left);
        if (q.front()->right != NULL)
            q.push(q.front()->right);
        q.pop();
    }
    cout << endl;
}

// Binary Tree Traversal menggunakan Preorder
void preOrder(Node *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Binary Tree Traversal menggunakan Inorder
void inOrder(Node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Binary Tree Traversal menggunakan Postorder
void postOrder(Node *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Pencarian data pada BST
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

// Mencari alamat memori node yang memiliki nilai minimum
Node *cariMin(Node *root) {
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Penghapusan node pada BST
void hapus(Node *&root, int data) {
    if (root == NULL)
        return;
    else if (data < root->data)
        hapus(root->left, data);
    else if (data > root->data)
        hapus(root->right, data);
    else {
        // Kasus I: Node tanpa anak
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
            // Kasus II: Node dengan satu anak
        else if (root->left == NULL) {
            temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            temp = root;
            root = root->left;
            delete temp;
        }
            // Kasus III: Node dengan dua anak
        else {
            temp = cariMin(root->right);
            root->data = temp->data;
            hapus(root->right, root->data);
        }
    }
}

// Fungsi untuk menampilkan menu
void menu() {
    int pilihan, nilai;
    do {
        cout << "\nMenu:\n";
        cout << "1. Buat Node Awal\n";
        cout << "2. Tambah Node\n";
        cout << "3. Hapus Node\n";
        cout << "4. Tampil Data\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan [1..5] : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                root = createNode(nilai);
                cout << "Nilai " << nilai << " berhasil dimasukkan di node awal.\n";
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insert(root, nilai);
                cout << "Nilai " << nilai << " berhasil ditambahkan.\n";
                break;
            case 3:
                cout << "Masukkan nilai yang akan dihapus: ";
                cin >> nilai;
                hapus(root, nilai);
                cout << "Nilai " << nilai << " berhasil dihapus.\n";
                break;
            case 4:
                cout << "Traversal Level Order: ";
                levelOrder(root);
                cout << "Traversal Preorder: ";
                preOrder(root);
                cout << "\nTraversal Inorder: ";
                inOrder(root);
                cout << "\nTraversal Postorder: ";
                postOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (pilihan != 5);
}

int main() {
    menu();
    return 0;
}

