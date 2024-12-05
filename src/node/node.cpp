#include<iostream>
#include"./node.h"
using namespace std;

template<class T>
Node<T>::Node(T data, Node<T>* left,Node<T>* right){
    this->data = data;
    this->left = left;
    this->right = right;
}

template<class T>
Node<T>::~Node() {
    this->left = nullptr;
    this->right = nullptr;
}

template<class T>
T Node<T>::getData() {
    return this->data;
}

template<class T>
void Node<T>::setData(T data) {
    this->data = data;
}

template<class T>
void Node<T>::setChildren(Node<T>* left, Node<T>* right){
    this->left = left;
    this->right = right;
}

template<class T>
void Node<T>::setLeft(Node<T>* left){
    this->left = left;
}

template<class T>
void Node<T>::setRight(Node<T>* right){
    this->right = right;
}

template<class T>
void Node<T>::setFe(int fe){
    this->fe = fe;
}

template<class T>
int Node<T>::getFe(){
    return this->fe;
}

template<class T>
Node<T>* Node<T>::getChildren(int children){
    switch (children)
    {
    case 0:
        return this->left;
        break;
    
    case 1:
        return this->right;
        break;
    }
}

template<class T>
bool Node<T>::isLeaf(){
    return right==NULL && left==NULL;
}

