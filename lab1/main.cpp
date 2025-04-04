// Lab1: https://contest.yandex.ru/contest/46568/problems/A/
/*
 * На шахматной доске стоят белый конь и черная пешка.
 * Напечатать маршрут коня, позволяющий уничтожить пешку.
 * Примечание: пешка - неподвижная, конь не должен попадать под удар пешки.
 *
 * Метод решения: Поиск в глубину.
 */

#include<iostream>
#include<fstream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

struct Point {
    char letter;
    short number;

    Point(string point): letter(point[0]), number((short)point[1]) {};
};

pair<bool, vector<string>> canAttack(Point pawn, Point horse) {


    return make_pair(false, vector<string>{});
}

int main() {
    ifstream inFile("in.txt");
    ofstream outFile("out.txt");

    string pawnPoint, horsePoint;
    inFile >> pawnPoint;
    inFile >> horsePoint;

    pair<bool, vector<string>> isAttacked = canAttack(Point(pawnPoint), Point(horsePoint));

    if (isAttacked.first) {
        outFile << "" << endl;
    } else {
        outFile << "" << endl;
    }

    cout << "" << endl;

    return 0;
}