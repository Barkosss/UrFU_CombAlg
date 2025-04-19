// https://acm.timus.ru/problem.aspx?space=1&num=1399
#include<iostream>
#include<fstream>
#include<vector>

using std::endl;
using std::vector;
using std::ifstream;
using std::ofstream;

struct Node {
    unsigned int id;

    vector<Node *> neighbors;

    Node(unsigned int id) : id(id) {};
};

class Graph {
private:
    Node *root;

public:
    Graph(const vector<vector<unsigned int>> matrix) {
        int matrixSize = matrix.size();
    }

    ~Graph() {
        delete root;
    }
};

int main() {
    ifstream inFile("in.txt");
    ofstream outFile("in.txt");

    int countClient, countItems, truckLoad;
    inFile >> countClient >> countItems >> truckLoad;
    vector<vector<unsigned int>> matrix = vector(countClient + 1, vector<unsigned int>(countClient + 1));

    for (int index = 0; index < countClient + 1; index++) {
        for (int jndex = 0; jndex < countClient + 1; jndex++) {
            inFile >> matrix[index][jndex];
        }
    }

    Graph graph = Graph(matrix);

    return 0;
}