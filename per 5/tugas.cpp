#include <iostream>
using namespace std;

// membuat fungsi
int binarySearch(int data[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // menghitung indeks tengah

        if (data[mid] == target) {
            return mid; // target di tengah
        } else if (target < data[mid]) {
            right = mid - 1; // target di kiri
        } else {
            left = mid + 1; // target di kanan
        }
    }
    return -1;
}

int main() {
    int n, target;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    int* data = new int[n];

    cout << "Masukkan data mahasiswa secara terurut:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i+1 << " : ";
        cin >> data[i];
    }

    cout << "Masukkan nilai yang dicari: ";
    cin >> target;

    int hasil = binarySearch(data, n, target);

    if (hasil != -1) {
        cout << "Data ditemukan pada indeks : "
             << hasil << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    delete[] data;
    return 0;
}
