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
#include<deque>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::deque;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

enum class Shift {
    UP_LEFT, UP_RIGHT,
    LEFT_UP, LEFT_DOWN,
    RIGHT_UP, RIGHT_LEFT,
    DOWN_LEFT, DOWN_RIGHT
};

struct Point {
    short letter;
    short number;

    Point(string point): letter((short)point[0] - 97), number((short)point[1] - 49) {};

    Point getShift(Point point, Shift shift) {
        switch shift {
            case UP_LEFT -> Point(point.)
        }
    }
};

vector<string> findMoveToAttack(Point pawn, Point horse) {

}

int main() {
    ifstream inFile("in.txt");
    ofstream outFile("out.txt");

    string pawnPoint, horsePoint;
    inFile >> pawnPoint;
    inFile >> horsePoint;

    vector<string> attacked = findMoveToAttack(Point(pawnPoint), Point(horsePoint));

    for (string move : attacked) {
        outFile << move << endl;
    }

    return 0;
}