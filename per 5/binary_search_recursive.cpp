#include <iostream>
using namespace std;

//  membuat fungsi
int binarySearch(int data[], int left, int right, int target) {

    while (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2; // menghitung indeks tengah

    if (data[mid] == target) {
        return mid; // target tengah
    } else if (target < data[mid]) {
        return binarySearch(data, left, mid - 1, target); // target kiri
    } else {
       return binarySearch(data, mid + 1, right, target) ; // target kanan
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int target = 7;

    int hasil = binarySearch (data, 0, n - 1, target);

    if (hasil != -1) {
        cout << "Data ditemukan pada indeks : " << hasil << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}