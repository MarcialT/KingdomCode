#ifndef TREE_H
#define TREE_H
#include"../people/people.h"
#include"../node/node.h"
template<class T>
class Tree {
    private:
    Persona* root;
    void showSuccession(Persona* node);
    Persona* assignNewKing(Persona* currentKing);
    Persona* findPersonById(Persona* node, int id);
    public:
    Tree();
    void readCSV();
    void showSuccession();
    void assignKing();
    void updatePersonData(int id, const string& new_name, const string& new_last_name, int new_age);
    ~Tree();
    void insert(Persona* node, Persona* new_person);
};
#endif