#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *root = NULL;

Node *createNode(int data) {
    Node *n = new Node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function insert
void insert(Node *&root, int data) {
    if (root == NULL)
        root = createNode(data);
    else if (data <= root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

// Fungsi Traversal
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

void preOrder(Node *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
    cout << endl;
}

void inOrder(Node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
    cout << endl;
}

void postOrder(Node *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
    cout << endl;
}

// Fungsi Search
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

// Mencari Node Minimum
Node *cariMin(Node *root) {
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Fungsi Delete
void hapus(Node *&root, int data) {
    if (root == NULL)
        return;
    else if (data < root->data)
        hapus(root->left, data);
    else if (data > root->data)
        hapus(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } else if (root->left == NULL) {
            Node *temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            Node *temp = root;
            root = root->left;
            delete temp;
        } else {
            Node *temp = cariMin(root->right);
            root->data = temp->data;
            hapus(root->right, root->data);
        }
    }
}

void tampilkanMenu() {
    cout << "Menu:\n";
    cout << "1. Buat Node Awal\n";
    cout << "2. Tambah Node\n";
    cout << "3. Hapus Node\n";
    cout << "4. Tampil Data\n";
    cout << "5. Keluar\n";
}

void tampilkanTraversal() {
    cout << "Pilihan Traversal:\n";
    cout << "1. Level Order\n";
    cout << "2. Preorder\n";
    cout << "3. Inorder\n";
    cout << "4. Postorder\n";
}

int main() {
    int pilihan, nilai;
    do {
        tampilkanMenu();
        cout << "Masukkan pilihan [1..5]: ";
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
                cout << "Masukkan nilai untuk dihapus: ";
                cin >> nilai;
                hapus(root, nilai);
                cout << "Nilai " << nilai << " berhasil dihapus.\n";
                break;
            case 4:
                tampilkanTraversal();
                int traversal;
                cout << "Masukkan pilihan [1..4]: ";
                cin >> traversal;
                if (traversal == 1) levelOrder(root);
                else if (traversal == 2) preOrder(root);
                else if (traversal == 3) inOrder(root);
                else if (traversal == 4) postOrder(root);
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}
