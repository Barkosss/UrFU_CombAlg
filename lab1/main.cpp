// Lab1: https://contest.yandex.ru/contest/46568/problems/A/
/*
 * На шахматной доске стоят белый конь и черная пешка.
 * Напечатать маршрут коня, позволяющий уничтожить пешку.
 * Примечание: пешка - неподвижная, конь не должен попадать под удар пешки.
 *
 * Метод решения: Поиск в глубину.
 */

#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Node {
    string coordination;

    Node* nextMove;

    Node(string coordination): coordination(coordination), nextMove(nullptr);
};

class Grath {
private:
    Node* root

public:
    Grath(): root(nullptr);

    bool isEmpty() {
        return root == nullptr;
    }

    void push(string coordination) {

        if (isEmpty()) {
            root = new Node(coordination);
            return;
        }


    }
};


void main() {


}