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
    vector<Node *> nodes;

public:
    unsigned int size;

    Graph(const vector<vector<unsigned int>> matrix) {
        int matrixSize = matrix.size();

        for (int index = 0; index < matrixSize; index++) {
            nodes.push_back(new Node(index));
        }

        for (int index = 0; index < matrixSize; index++) {
            for (int jndex = 0; jndex < matrixSize; jndex++) {
                if (matrix[index][jndex]) {
                    nodes[index]->neighbors.push_back(nodes[jndex]);
                }
            }
        }
    }

    ~Graph() {
        for (Node *node: nodes) {
            delete node;
        }
    }

    void setSize(unsigned int size_) {
        this->size = size_;
    }

    void show() const {
        for (const auto &node: nodes) {
            std::cout << "Node #" << node->id << " connect with: ";
            for (const auto &neighbor: node->neighbors) {
                std::cout << neighbor->id << " ";
            }
            std::cout << std::endl;
        }
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

    graph.show();

    return 0;
}