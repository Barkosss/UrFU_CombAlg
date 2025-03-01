// Lab2: https://contest.yandex.ru/contest/46568/problems/B/

/*
 * Определить, является ли данный граф ацикличным.
 *
 * Метод решения: Поиск в ширину.
 */

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

template<typename Type>
struct ArrayNode {
    unsigned index;
    Type element;

    ArrayNode* nextElement;

    ArrayNode(Type element): index(0), element(element), nextElement(nullptr) {}
    ArrayNode(unsigned index, Type element): index(index), element(element), nextElement(nullptr) {}
};

template<typename ArrayType>
class Array {
private:
    ArrayNode<ArrayType>* headNode;
    ArrayNode<ArrayType>* tailNode;

public:
    Array<ArrayType>(nullptr_t pVoid) : headNode(nullptr), tailNode(nullptr) {}

    ArrayType operator()(unsigned index) {
        ArrayNode<ArrayType>* node = headNode;
        while (node->index != index) {
            node = node->nextElement;
        }
        return node->element;
    }

    ArrayType get(unsigned index) {
        return this(index);
    }

    bool isEmpty() {
        return headNode == nullptr;
    }

    void push(ArrayType element) {
        if (this->isEmpty()) {
            headNode = new ArrayNode(element);
            tailNode = headNode;
            return;
        }

        tailNode->nextElement = new ArrayNode(tailNode->index + 1, element);
        tailNode = tailNode->nextElement;
    }
};

template<typename MatrixType>
class Matrix {
private:
    Array<MatrixType> array;

public:
    Matrix<MatrixType>(): array(nullptr) {}

};

int main() {
    Array<bool> columns = Array<bool>(nullptr);
    Matrix<bool> matrix = Matrix<bool>();


    columns.push(true);
    matrix;

    return 0;
}