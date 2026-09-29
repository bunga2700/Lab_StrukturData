#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

void tambah(Node*& root, int data) {
    if (root == NULL) {
        root = new Node();
        root->data = data;
        root->kiri = NULL;
        root->kanan = NULL;

        return;
    }

    if (data < root->data) {
        tambah(root->kiri, data);
    }

    if (data > root->data) {
        tambah(root->kanan, data);
    }

    return;
}

// PRE-ORDER
void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

// IN-ORDER
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

// POST-ORDER
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = NULL;
    int angka;

    cout << "Masukkan angka (0 = stop) : " << endl;
    cin >> angka;

    while (angka != 0) {
        tambah(root, angka);
        cin >> angka;
    }

    // Menampilkan tree traversal
    cout << endl;

    cout << "Pre Order  : ";
    preOrder(root);

    cout << endl;

    cout << "In Order   : ";
    inOrder(root);

    cout << endl;

    cout << "Post Order : ";
    postOrder(root);

    cout << endl;

    return 0;
}