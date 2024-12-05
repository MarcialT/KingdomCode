#ifndef TREE_H
#define TREE_H
#include"../people/people.cpp"
#include"../node/node.cpp"
template<class T>
class Tree {
    public:
    Persona* head = nullptr;
    Persona* last = nullptr;
    Tree();
    void addPerson(Persona* newPerson);
    Persona* findPersonById(int id);
    bool isFirstborn(int childId, int& fatherId);
};

#endif