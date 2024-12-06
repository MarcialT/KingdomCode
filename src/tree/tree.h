#ifndef TREE_H
#define TREE_H
#include"../people/people.cpp"
#include"../node/node.cpp"
template<class T>
class Tree {
    private:
    Node<T>* root = nullptr;
    public:
    Tree();
    void TreeInsert(T);
};

#endif