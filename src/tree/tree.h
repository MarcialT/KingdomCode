#ifndef TREE_H
#define TREE_H
#include"../people/people.h"
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