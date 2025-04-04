// Lab2: https://contest.yandex.ru/contest/46568/problems/B/

/*
 * Определить, является ли данный граф ацикличным.
 *
 * Метод решения: Поиск в ширину.
 */

#include<algorithm>
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<set>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::queue;
using std::pair;
using std::set;

vector<int> findCycle(const vector<vector<int>> &matrix, int indexVert) {
    unsigned int matrixLen = matrix.size();
    vector<int> parent(matrixLen, -1);
    vector<bool> visited(matrixLen, false);
    queue<int> q;

    q.push(indexVert);
    visited[indexVert] = true;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        for (int neighbour = 0; neighbour < matrixLen; neighbour++) {
            if (matrix[vertex][neighbour]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    parent[neighbour] = vertex;
                    q.push(neighbour);
                } else if (parent[vertex] != neighbour) {
                    vector<int> cycle;
                    cycle.push_back(vertex);
                    cycle.push_back(neighbour);

                    while (true) {
                        vertex = parent[vertex];
                        if (std::find(cycle.begin(), cycle.end(), vertex) != cycle.end()) break;
                        cycle.push_back(vertex);

                        neighbour = parent[neighbour];
                        if (std::find(cycle.begin(), cycle.end(), neighbour) != cycle.end()) break;
                        cycle.push_back(neighbour);
                    }

                    std::sort(cycle.begin(), cycle.end());
                    return cycle;
                }
            }
        }
    }

    return {};
}


void isAcyclic(const vector<vector<int>> &matrix) {
    ofstream outFile("out.txt");

    if (!outFile.is_open()) {
        cout << "Error opening output file" << endl;
        return;
    }

    unsigned int matrixLen = matrix.size();

    for (int indexVert = 0; indexVert < matrixLen; indexVert++) {
        vector<int> cycle = findCycle(matrix, indexVert);
        if (!cycle.empty()) {
            outFile << "N" << endl;
            for (int elem: cycle) outFile << elem + 1 << " ";
            return;
        }
    }

    outFile << "A" << endl;
}


int main() {
    ifstream inFile("in.txt");

    if (!inFile.is_open()) {
        cout << "File is not open" << endl;
        return 404;
    }

    int count;
    inFile >> count;
    vector<vector<int>> matrix(count, vector<int>(count));
    for (int index = 0; index < count; index++) {
        for (int jndex = 0; jndex < count; jndex++) {
            inFile >> matrix[index][jndex];
        }
    }

    isAcyclic(matrix);

    cout << "Program is complete" << endl;
    return 0;
}