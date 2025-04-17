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
#include<limits>
#include<deque>

using std::cout;
using std::endl;
using std::deque;
using std::vector;
using std::ofstream;
using std::ifstream;

const int NO_EDGE = -32768;

vector<int> longestPath(vector<vector<int>> matrix, int start, int target) {
    // ...
    // ...
    // ...
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

    vector<vector<int>> matrix = vector<vector<int>>(matrixSize, vector<int>(matrixSize));
    for (unsigned int index = 0; index < matrixSize; index++) {
        for (unsigned int jndex = 0; jndex < matrixSize; jndex++) {
            inFile >> matrix[index][jndex];
        }
    }

    unsigned int start, target;
    inFile >> start >> target;

    vector<int> path = longestPath(matrix, start, target);

    if (path.empty()) {
        cout << "N" << endl;
        return 0;
    }

    cout << "Y" << endl;
    for (int node: path) {
        cout << node << " ";
    }
    cout << endl;

    int totalWeight = 0;
    for (int index = 0; index < path.size(); index++) {
        totalWeight += matrix[path[index]][path[index + 1]];
    }
    cout << totalWeight << endl;

    return 0;
}