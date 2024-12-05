#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"./node/node.cpp"
#include"./people/people.cpp"
#include"./util/util.cpp"
#include"./tree/tree.cpp"
using namespace std;

int main() {
    int option = 0;
    Menu(option);

    int parentId;
    cout << "Ingrese el ID del padre para buscar sus hijos: ";
    cin >> parentId;
    findChildrenById("../bin/KingDom.csv", parentId);

    return 0;
}
