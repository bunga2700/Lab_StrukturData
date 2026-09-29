#include <iostream>
using namespace std;

char stack[100];
int top = -1;

void push(char data) {
    if (top == 99) {
        cout << "Stack penuh!" << endl;
        return;
    }
    top++;
    stack[top] = data;
}

void pop() {
    if (top == -1) {
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << stack[top];
    top--;
}

int main() {
    string kata;

    cout << "Masukkan kata: ";
    cin >> kata;

    for (int i = 0; i < kata.length(); i++) {
        push(kata[i]);
    }

    cout << "Kata setelah dibalik: ";

    while (top != -1) {
        pop();
    }

    cout << endl;

    return 0;
}