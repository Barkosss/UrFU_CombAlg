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

using std::cout;
using std::endl;
using std::vector;
using std::ofstream;
using std::ifstream;

const int INF = -32768;

vector<int> longestPath() {
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

    vector<int> result = longestPath();

    if (result[target] == INF) {
        outFile << "N" << endl;
    } else {
        outFile << "Y" << endl;
        /// ...
    }

    return 0;
}