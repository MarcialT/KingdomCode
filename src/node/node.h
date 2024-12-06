#ifndef NODE_H
#define NODE_H
#pragma once

template<class T>
class Node {
private:
    T data;
    int fe = 0;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
    int autoHeight ();
public:
        Node(T,Node<T>*,Node<T>*);
        ~Node();
        void setData(T);
        T getData();
        void setChildren(Node<T>*,Node<T>*);//Establece el hijo de un nodo
        Node<T>* getChildren(int);//facilita el hijo de un nodo
        void setFe(int);//permite establecer el factor de equilibrio
        int getFe();//obtiene el factor de equilibrio
        void setHeigth(int);//establece la altura del arbol
        int calculate_Heigth(Node<T>*);//calcula la altura del arbol
        int getHeigth();//obtiene la atura del arbol
        bool isLeaf();//verifica si el nodo no tiene hijos
        void setRight(Node<T>*);//establece el hijo derecho
        void setLeft(Node<T>*);//establece el hijo izquierdo
};
#endif