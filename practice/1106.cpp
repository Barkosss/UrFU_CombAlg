// https://acm.timus.ru/problem.aspx?num=1106&locale=ru&ysclid=m9imi0bfpo208897328

#include<iostream>
#include<fstream>
#include<vector>

using std::pair;
using std::endl;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::vector;

pair<int, vector<int>> getBipartiteGraph(int count, vector<vector<int>> friends) {
    // ...
}

int main() {
    ifstream inFile("in.txt");

    int count;
    vector<vector<int>> friends(count, vector<int>());

    int num;
    for (int index = 0; index < count; index++) {
        inFile >> num;
        while (num) {
            friends[index].push_back(num);
        }
    }

    return 0;
}