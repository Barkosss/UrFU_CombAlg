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

using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

int main() {
    ifstream inFile("in.txt");
    ofstream outFile("out.txt");

    if (!inFile.is_open() || inFile.eof()) {
        cout << "File is not found or is empty!" << endl;
        return 404;
    }

    // ...
}