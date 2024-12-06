#include<iostream>
#include<fstream>
#include<string>
#include"./tree.h"
using namespace std;

template<class T>
Tree<T>::Tree(){
    
}

template<class T>
void Tree<T>::TreeInsert(T data){
    
    if(root==NULL){

        root=new Node<T>(data,NULL,NULL);

    }
    else{
        Node<T>* actual = root;
        Node<T>* father = NULL;

        while(actual != NULL && data != actual->data){
            father = actual;
            if(actual->getData() > data){
                actual = actual->getChild(IZQ);
            }
            else{
                actual = actual->getChild(DER);
            }
        }

        if(actual != NULL) return;
        
        if(father->getData()> data){
            father->setLeft = new Node(data, NULL, NULL);
        }
        else{
            father->setRight = new Node(data, NULL, NULL);
        }
    }
}