#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    private:
        int numberVertex;
        vector<vector<int>> adjMatrix;

        int hurufKeAngka(char c) { return c - 'A'; }
        char angkaKeHuruf(int i) { return 'A' + i; }

    public:
        Graph(int banyakTitik) {
            numberVertex = banyakTitik;
            adjMatrix.resize(numberVertex, vector<int>(numberVertex, 0));
        }

    void addEdge(char i, char j) {
        int u = hurufKeAngka(i);
        int v = hurufKeAngka(j);
        if (u >= 0 && u < numberVertex && v >= 0 && v < numberVertex) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        } else {
            cout << "Index nonvalid" << endl;
        }
    }

    void printAdjMatrix() {
        for (int i = 0; i < numberVertex; i++) {
            for (int j = 0; j < numberVertex; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bfs(char start) {
        int awal = hurufKeAngka(start);
        vector<bool> visited(numberVertex, false);
        queue<int> titikVisit;
        
        visited[awal] = true;
        titikVisit.push(awal);

        cout << "Urutan vertex yang dikunjungi: ";
        while (!titikVisit.empty()) {
            int u = titikVisit.front();
            titikVisit.pop();
            cout << angkaKeHuruf(u) << " ";

            for (int v = 0; v < numberVertex; v++) {
                if (adjMatrix[u][v] == 1 && !visited[v]) {
                    visited[v] = true;
                    titikVisit.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int jumlahEdge;
    char u, v, mulai;

    Graph graphh(6);
    
    cout << "Masukkan jumlah edge: ";
    cin >> jumlahEdge;

    cout << "Masukkan edge (contoh: A B):" << endl;
    for (int i = 0; i < jumlahEdge; i++) {
        cin >> u >> v;
        graphh.addEdge(u, v);
    }

    cout << endl;
    cout << "Adjacency Matrix:" << endl;
    graphh.printAdjMatrix();

    cout << endl;

    cout << "Masukkan vertex awal (A-F): ";
    cin >> mulai;

    graphh.bfs(mulai);

    return 0;
}