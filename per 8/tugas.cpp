#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    vector<pair<int, string>> table;
    vector<int> status;

    int hash1(int key) {
        return key % TABLE_SIZE;
    }

    int hash2(int key) {
        return 7 - (key % 7);
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
        status.resize(TABLE_SIZE, 0);
    }

    void insert(int key, string value) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;
        int deletedIndex = -1;

        while (true) {
            if (status[index] == 1 && table[index].first == key) {
                table[index].second = value;
                return;
            }
            if (status[index] == 2 && deletedIndex == -1) {
                deletedIndex = index;
            }
            if (status[index] == 0) {
                if (deletedIndex != -1) {
                    index = deletedIndex;
                }
                table[index] = make_pair(key, value);
                status[index] = 1;
                return;
            }
            index = (index + step) % TABLE_SIZE;
            if (index == initialIndex) {
                break;
            }
        }

        if (deletedIndex != -1) {
            table[deletedIndex] = make_pair(key, value);
            status[deletedIndex] = 1;
        } else {
            cout << "Table penuh" << endl;
        }
    }

    void search(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;

        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == key) {
                cout << "Data ditemukan : " << table[index].second << endl;
                return;
            }
            index = (index + step) % TABLE_SIZE;
            if (index == initialIndex) {
                break;
            }
        }
        cout << "Data tidak ditemukan" << endl;
    }

    void remove(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;

        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == key) {
                status[index] = 2;
                cout << "Data berhasil dihapus" << endl;
                return;
            }
            index = (index + step) % TABLE_SIZE;
            if (index == initialIndex) {
                break;
            }
        }
        cout << "Data tidak ditemukan" << endl;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (status[i] == 1) {
                cout << table[i].first << " - " << table[i].second;
            } else if (status[i] == 2) {
                cout << "DELETED";
            } else {
                cout << "EMPTY";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;

    // insert
    ht.insert(251401011, "friska");
    ht.insert(251401014, "meisrik");
    ht.insert(251401023, "bunga");
    ht.insert(251401041, "baktiar");
    ht.insert(251401083, "sri");

    cout << "Tampilan awal Hash Table:" << endl;
    ht.display();

    // search
    cout << "Mencari NIM 251401014:" << endl;
    ht.search(251401023);

    // remove
    cout << "Menghapus NIM 251401023:" << endl;
    ht.remove(251401041);

    // menampilkan tabel setelah remove
    cout << "Hash Table setelah penghapusan:" << endl;
    ht.display();

    return 0;
}