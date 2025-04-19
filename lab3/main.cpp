// Lab3: https://contest.yandex.ru/contest/46568/problems/C/
/*
 * Найти v-w путь в сети с неотрицательными весами,
 * решающий задачу о пути наибольшего веса,
 * где вес пути равен сумме весов дуг.
 *
 * Метод решения: алгоритм построения пути в бесконтурной сети.
 *
 * Число -32768 означает, что данная дуга отсутствует.
 */

#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<deque>

using std::cout;
using std::endl;
using std::deque;
using std::stack;
using std::vector;
using std::ofstream;
using std::ifstream;

const int NO_EDGE = -32768;
vector<vector<int>> matrix;
vector<bool> visited;
stack<int> topPath;
vector<int> newIndexPath;
vector<int> parent;
vector<int> weight;

// TODO: А что если не отсортированная сеть?
// TODO: Присвоение новых номеров
void topSort(int v) {
    visited[v] = true;
    for (int node = 0; node < matrix.size(); node++) {
        if (matrix[v][node] != NO_EDGE && !visited[node]) {
            topSort(node);
        }
    }

    topPath.push(v);
}

// Назначение новых индексов
void newIndexes() {
    newIndexPath = vector<int>(topPath.size(), NO_EDGE);
    int index, newIndex = 1;
    while (!topPath.empty()) {
        index = topPath.top(); topPath.pop();
        newIndexPath[index] = newIndex++;
    }
}


/*
 * Изменение индексов у вершин после топологической сортировки
 * Посчитать количество истоков
 * Задача:
 *  1. Найти вернишу с нулевым истоком, и приравнять её максимальному номеру
 *
 */
void longestPath(int start) {
    weight[start] = 0;

    for (int index = 0; index < newIndexPath.size(); index++) {
        int u = newIndexPath[index];
        //int u = topPath.top();
        //topPath.pop();

        if (weight[u] == NO_EDGE) continue;

        for (int column = 0; column < matrix.size(); column++) {
            if (matrix[u][column] != NO_EDGE) {
                if (weight[u] + matrix[u][column] > weight[column]) {
                    weight[column] = weight[u] + matrix[u][column];
                    parent[column] = u;
                }
            }
        }
    }
}

int main() {
    ifstream inFile("in.txt");
    ofstream outFile("out.txt");

    if (!inFile.is_open() || inFile.eof()) {
        cout << "File is not found or is empty!" << endl;
        return 404;
    }

    unsigned int matrixSize;
    inFile >> matrixSize;

    matrix = vector<vector<int>>(matrixSize, vector<int>(matrixSize));
    visited = vector<bool>(matrixSize, false);
    weight = vector<int>(matrixSize, NO_EDGE);
    parent = vector<int>(matrixSize, -1);

    for (unsigned int index = 0; index < matrixSize; index++) {
        for (unsigned int jndex = 0; jndex < matrixSize; jndex++) {
            inFile >> matrix[index][jndex];
        }
    }

    unsigned int start, target;
    inFile >> start >> target;
    start--;
    target--;

    for (int node = 0; node < matrixSize; node++) {
        if (!visited[node]) {
            topSort(node);
        }
    }

    newIndexes();

    longestPath(start);

    if (weight[target] == NO_EDGE) {
        outFile << "N" << endl;
        return 0;
    }

    outFile << "Y" << endl;
    deque<int> path;
    for (int cur = target; cur != -1; cur = parent[cur])
        path.push_front(cur + 1);

    for (int index = 0; index < path.size(); index++)
        outFile << path[index] << " ";
    outFile << endl;

    outFile << weight[target] << endl;

    return 0;
}