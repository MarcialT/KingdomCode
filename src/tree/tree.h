#ifndef TREE_H
#define TREE_H
#include"../people/people.h"
#include"../node/node.h"
template<class T>
class Tree {
    private:
    Node<T>* root = nullptr;
    public:
    Tree();
    Node<T>* getRoot();
    void Insert(Persona*,Persona*);
    void showSuccession(Persona* Node);
    Persona* assignNewKing(Persona* currentKing);
    Persona* findPersonById(Persona* node, int id);
    void readCSV(const string& filename);
    void showSuccession();
    void assignKing(); 
    void updatePersonData(int id, const string& new_name, const string& new_last_name, int new_age);
    ~Tree();
};

#endif