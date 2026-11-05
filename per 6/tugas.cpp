#include <iostream>
#include <string>
using namespace std;

int main() {
    string data[100];
    int n;

    cout << "Masukkan jumlah kata: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Kata ke-" << i + 1 << ": ";
        cin >> data[i];
    }

    for (int i = 1; i < n; i++) {
        string key = data[i];
        int j = i - 1;

        cout << "Putaran " << i << endl;

        for (int k = 0; k < n; k++) {
            cout << data[k] << " ";
        }
        cout << endl;

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;

            for (int k = 0; k < n; k++) {
                if (k == j + 1) {
                    cout << key << " ";
                } else {
                    cout << data[k] << " ";
                }
            }
            cout << endl;
        }
        data[j + 1] = key;
    }

    cout << "Hasil Insertion Sort : ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
