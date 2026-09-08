#include<iostream>
using namespace std;

int main() {
    int arr [3][3][4];
    int n = 2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 4; k++){
                arr [i][j][k] = n;
                n += 2;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 4; k++){
                cout << arr [i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
