#include<iostream>
#include"./node.h"
using namespace std;

template<class T>
Node<T>::Node(T data, Node<T>* left,Node<T>* right){
    this->data = data;
    this->left = left;
    this->right = right
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