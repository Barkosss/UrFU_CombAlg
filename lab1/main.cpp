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
#include<map>

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
    RIGHT_UP, RIGHT_DOWN,
    DOWN_RIGHT, DOWN_LEFT,
    LEFT_DOWN, LEFT_UP
};

const std::map<Shift, pair<int, int>> shiftMap = {
        {Shift::UP_LEFT,    {-1, 2}},
        {Shift::UP_RIGHT,   {1,  2}},
        {Shift::RIGHT_UP,   {2,  1}},
        {Shift::RIGHT_DOWN, {2,  -1}},
        {Shift::DOWN_RIGHT, {1,  -2}},
        {Shift::DOWN_LEFT,  {-1, -2}},
        {Shift::LEFT_DOWN,  {-2, -1}},
        {Shift::LEFT_UP,    {-2, 1}}
};

vector<Shift> moves = {
        Shift::UP_LEFT, Shift::UP_RIGHT,
        Shift::RIGHT_UP, Shift::RIGHT_DOWN,
        Shift::DOWN_RIGHT, Shift::DOWN_LEFT,
        Shift::LEFT_DOWN, Shift::LEFT_UP
};

struct Point {
    short letter;
    short number;

    Point(string point) : letter((short) point[0] - 97), number((short) point[1] - 49) {};

    Point(short letter, short number) : letter(letter), number(number) {};

    bool operator==(Point &point) {
        return this->letter == point.letter && this->number == point.number;
    }

    Point getShift(Shift shift) {
        pair<int, int> move = shiftMap.at(shift);
        return Point(letter + move.first, number + move.second);
    }

    bool isValid() const {
        bool isValidVertically = (number >= 0 && number <= 7);
        bool isValidHorizontally = (letter >= 0 && letter <= 7);

        return isValidVertically && isValidHorizontally;
    }

    bool isAttack(Point targetPoint) {
        // Attack down-left
        if (targetPoint.letter - 1 == this->letter && targetPoint.number - 1 == this->number) {
            cout << "Was attack" << endl;
            return true;
        }

        // Attack down-rights
        if (targetPoint.letter + 1== this->letter && targetPoint.number - 1 == this->number) {
            return true;
        }

        return false;
    }

    string toString() const {
        return string(1, (char) (letter + 'a')) + std::to_string(number + 1);
    }
};

bool dfs(Point currentPoint, Point targetPoint, vector<vector<bool>> &visited, vector<string> &path) {
    // Если вышли за пределы доски или начали ходить по кругу
    if (!currentPoint.isValid() || visited[currentPoint.letter][currentPoint.number]) {
        return false;
    }

    // Если следующий (current) ход попадёт под удар пешки
    if (currentPoint.isAttack(targetPoint)) {
        return false;
    }

    visited[currentPoint.letter][currentPoint.number] = true;
    path.push_back(currentPoint.toString());

    // Если следующий (current) шаг бъёт по пешке
    if (currentPoint == targetPoint) {
        return true;
    }

    // Перебираем все возможные ходы коня
    for (Shift move: moves) {
        if (dfs(Point(currentPoint.getShift(move)), targetPoint, visited, path)) {
            return true;
        }
    }

    path.pop_back();
    visited[currentPoint.letter][currentPoint.number] = false;
    return false;
}


vector<string> findMoveToAttack(Point horse, Point pawn) {
    vector<string> path;
    vector<vector<bool>> visited(8, vector<bool>(8, false));

    if (dfs(horse, pawn, visited, path)) {
        return path;
    }

    // Если путь не найден
    return {};
}

int main() {
    ifstream inFile("in.txt");
    ofstream outFile("out.txt");

    string horsePoint, pawnPoint;
    inFile >> horsePoint >> pawnPoint;

    vector<string> attacked = findMoveToAttack(Point(horsePoint), Point(pawnPoint));

    for (string move: attacked) {
        outFile << move << endl;
    }

    return 0;
}