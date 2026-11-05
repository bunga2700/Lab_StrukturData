#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjMatrix;

    int hurufKeAngka(char c) { return c - 'A'; }
    char angkaKeHuruf(int i) { return 'A' + i; }

public:
    Graph(int jumlahVertex) {
        V = jumlahVertex;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void dijkstra(int source) {
        vector<int> distance(V, INT_MAX);
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        distance[source] = 0; 

        for (int i = 0; i < V; i++) {
            int u = -1;
            
            for (int j = 0; j < V; j++) {
                if (!visited[j] && (u == -1 || distance[j] < distance[u])) {
                    u = j;
                }
            }

            if (u == -1 || distance[u] == INT_MAX)
                break;

            visited[u] = true;

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != 0 && !visited[v]) {
                    int newDistance = distance[u] + adjMatrix[u][v];

                    if (newDistance < distance[v]) {
                        distance[v] = newDistance;
                        parent[v] = u;
                    }
                }
            }
        }

        cout << "Rute terpendek dari vertex " << angkaKeHuruf(source) << " ke semua lokasi:" << endl;

        for (int i = 0; i < V; i++) {
            if (i == source) continue;
            cout << angkaKeHuruf(source) << " -> " << angkaKeHuruf(i) << " (Jarak: " << distance[i] << " km) Rute: ";
            if (distance[i] == INT_MAX) {
                cout << "Tidak terjangkau" << endl;
            } else {
                vector<int> rute;
                int curr = i;
                while (curr != -1) {
                    rute.push_back(curr);
                    curr = parent[curr];
                }
                for (int j = rute.size() - 1; j >= 0; j--) {
                    cout << angkaKeHuruf(rute[j]);
                    if (j > 0) cout << " -> ";
                }
            }
            cout << endl;
        }
    }

    void rekomendasiRute(char asal, char tujuan) {
        int source = hurufKeAngka(asal);
        int dest = hurufKeAngka(tujuan);

        vector<int> distance(V, INT_MAX);
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        distance[source] = 0;

        for (int i = 0; i < V; i++) {
            int u = -1;
            for (int j = 0; j < V; j++) {
                if (!visited[j] && (u == -1 || distance[j] < distance[u])) {
                    u = j;
                }
            }
            if (u == -1 || distance[u] == INT_MAX) break;
            visited[u] = true;

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != 0 && !visited[v]) {
                    int newDistance = distance[u] + adjMatrix[u][v];
                    if (newDistance < distance[v]) {
                        distance[v] = newDistance;
                        parent[v] = u;
                    }
                }
            }
        }
        cout << endl;

        cout << "Rekomendasi rute tercepat dari " << asal << " ke " << tujuan << ":" << endl;
        if (distance[dest] == INT_MAX) {
            cout << "Tidak ada rute yang tersedia." << endl;
        } else {
            cout << "Total jarak: " << distance[dest] << " km" << endl;
            cout << "Rute: ";
            vector<int> rute;
            int curr = dest;
            while (curr != -1) {
                rute.push_back(curr);
                curr = parent[curr];
            }
            for (int j = rute.size() - 1; j >= 0; j--) {
                cout << angkaKeHuruf(rute[j]);
                if (j > 0) cout << " -> ";
            }
            cout << endl;
        }
    }
};

int main() {
    char dari, tujuan;
    Graph graph(6);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 5);
    graph.addEdge(1, 4, 3);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 6);
    graph.addEdge(3, 4, 2);
    graph.addEdge(3, 5, 4);
    graph.addEdge(4, 5, 3);

    graph.dijkstra(0);

    cout << endl;
    cout << "Masukkan lokasi asal (A-F): ";
    cin >> dari;
    cout << "Masukkan lokasi tujuan (A-F): ";
    cin >> tujuan;

    graph.rekomendasiRute(dari, tujuan);

    return 0;
}