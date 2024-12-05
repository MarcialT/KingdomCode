#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"./node/node.h"
#include"./people/people.h"
#include"./util/util.h"
#include"./tree/tree.h"
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
