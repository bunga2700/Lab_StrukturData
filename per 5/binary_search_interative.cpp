#include <iostream>
using namespace std;

//  membuat fungsi
int binarySearch(int data[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // menghitung indeks tengah

        if (data[mid] == target) {
            return mid; // target tengah
        } else if (target < data[mid]) {
            right = mid - 1; // target kiri
        } else {
            left = mid + 1; // target kanan
        }
    }
    return -1;
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int target = 6;

    int hasil = binarySearch (data, n, target);

    if (hasil != -1) {
        cout << "Data ditemukan pada indeks : " << hasil << endl;
    }
    else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}