#include <iostream>
#include <queue>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node *left;
    Node *right;
};

// Deklarasi pointer global
Node *root = NULL, *n = NULL, *temp = NULL;

// Fungsi untuk membuat node baru
Node *createNode(int data) {
    n = new Node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Fungsi untuk insert data ke BST
void insert(Node *&root, int data) {
    if (root == NULL)
        root = createNode(data);
    else if (data <= root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

// Fungsi untuk melakukan traversal Level Order
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

// Fungsi untuk traversal Preorder
void preOrder(Node *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Fungsi untuk traversal Inorder
void inOrderAsc(Node *root) {
    if (root == NULL) return;
    inOrderAsc(root->left);
    cout << root->data << " ";
    inOrderAsc(root->right);
}

void inOrderDesc(Node *root) {
    if (root == NULL) return;
    inOrderDesc(root->right); // Subtree kanan
    cout << root->data << " "; // Root
    inOrderDesc(root->left); // Subtree kiri
}

// Fungsi untuk traversal Postorder
void postOrder(Node *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Fungsi untuk mencari data
bool search(Node *root, int data) {
    if (root == NULL)
        return false;
    else if (data < root->data)
        return search(root->left, data);
    else if (data > root->data)
        return search(root->right, data);
    else
        return true;
}

// Fungsi untuk mencari node dengan nilai minimum
Node *findMin(Node *root) {
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Fungsi untuk menghapus node pada BST dengan output sesuai permintaan
void deleteNode(Node *&root, int data) {
    if (root == NULL) {
        cout << "Data " << data << " tidak ditemukan...\n";
        return;
    } else if (data < root->data) {
        deleteNode(root->left, data);
    } else if (data > root->data) {
        deleteNode(root->right, data);
    } else {
        // Data ditemukan
        // Kasus 1: Node tanpa anak
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
            // Kasus 2: Node dengan satu anak
        else if (root->left == NULL) {
            temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            temp = root;
            root = root->left;
            delete temp;
        }
            // Kasus 3: Node dengan dua anak
        else {
            temp = findMin(root->right);
            root->data = temp->data;
            deleteNode(root->right, temp->data);
        }
        cout << "Data " << data << " berhasil dihapus...\n";
    }
}

void displaytree(Node *root) {
    cout << "\nTree (inorder Ascending) : ";
    if(root==NULL) {
        cout <<"Tree kosong\n";
    } else {
        inOrderAsc(root);
        cout<<endl;
    }
}

// Fungsi untuk menampilkan menu traversal
void traversalMenu(Node *root) {
    int choice;
    do {
        cout << "\nBinary Tree Traversal\n======================\n";
        cout << "1. Level Order\n";
        cout << "2. Preorder\n";
        cout << "3. Inorder (ASC)\n";
        cout << "4. Inorder (DESC)\n";
        cout << "5. Postorder\n";
        cout << "6. Batal\n";
        cout << "Masukkan pilihan [1..6]: ";
        cin >> choice;

        switch (choice) {
            case 1:
                levelOrder(root);
                cout << endl;
                break;
            case 2:
                preOrder(root);
                cout << endl;
                break;
            case 3:
                inOrderAsc(root);
                cout << endl;
                break;
            case 4:
                inOrderDesc(root);
                cout << endl;
                break;
            case 5:
                postOrder(root);
                cout << endl;
                break;
            case 6:
                cout << "Kembali ke menu utama.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 6);
}

// Fungsi utama
int main() {
    int choice, data;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Pencarian Data\n";
        cout << "3. Hapus Node\n";
        cout << "4. Binary Tree Traversal\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan [1..5]: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                insert(root, data);
                cout << "Data " << data << " berhasil dimasukkan.\n";
                displaytree(root);
                break;
            case 2:
                cout << "Masukkan data yang ingin dicari: ";
                cin >> data;
                if (search(root, data))
                    cout << "Data " << data << " ditemukan di tree.\n";
                else
                    cout << "Data " << data << " tidak ditemukan di tree.\n";
                break;
            case 3:
                cout << "Masukkan data yang ingin dihapus: ";
                cin >> data;
                deleteNode(root, data);
                displaytree(root);
                break;
            case 4:
                traversalMenu(root);
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 5);

    return 0;
}
