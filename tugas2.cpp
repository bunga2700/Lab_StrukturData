#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main () {
    // membuat node 1
    Node* node1 = new Node();
    node1->data = 100;
    node1->next = nullptr;

    // membuat node 2
    Node* node2 = new Node();
    node2->data = 92;
    node2->next = nullptr;

    // membuat node 3
    Node* node3 = new Node();
    node3->data = 45;
    node3->next = nullptr;

    // membuat node 4
    Node* node4 = new Node();
    node4->data = 87;
    node4->next = nullptr;

    // membuat node 5
    Node* node5 = new Node();
    node5->data = 71;
    node5->next = nullptr;

    // membuat node 6
    Node* node6 = new Node();
    node6->data = 99;
    node6->next = nullptr;

    // membuat node 7
    Node* node7 = new Node();
    node7->data = 95;
    node7->next = nullptr;

    // membuat node 8
    Node* node8 = new Node();
    node8->data = 60;
    node8->next = nullptr;

    // membuat node 9
    Node* node9 = new Node();
    node9->data = 55;
    node9->next = nullptr;

    // membuat node 10
    Node* node10 = new Node();
    node10->data = 88;
    node10->next = nullptr;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;

    // head and tail
    Node* head = node1;
    Node* tail = node10;

    cout << "Isi linked list awal: ";
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    // menambahkan node baru didepan
    Node* node11 = new Node();
    node11->data = 70;
    node11->next = head;
    head = node11;

    cout << "Setelah ditambah node di depan : " ;
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    // menambahkan node baru diakhir
    Node* node12 = new Node();
    node12->data = 50;
    node12->next = nullptr;
    tail->next = node12;
    tail = node12;

    cout << "Setelah ditambah node diakhir : " ;
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    // menambahkan node baru ditengah setelah node nilai 45
    Node* node13 = new Node();
    node13->data = 0;
    node13->next = node4; 
    node3->next = node13;

    cout << "Setelah ditambah node di tengah setelah node nilai 45 : " ;
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    // mengahapus node dengan nilai 99
    temp = head;

    while (temp->next->data != 99) {
        temp = temp->next;
    }
        
    Node* hapus = temp->next; 
    temp->next = hapus->next; 
    delete hapus;

    cout << "Setelah node nilai 99 dihapus : " ;
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    // mengahapus node dengan nilai 60
    temp = head;

    while (temp->next->data != 60) {
        temp = temp->next;
    }
        
    hapus = temp->next; 
    temp->next = hapus->next; 
    delete hapus;

    cout << "Setelah node nilai 60 dihapus : " ;
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}