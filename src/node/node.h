#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
private:
    T data;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
public:
    Node(T, Node<T>*, Node<T>*);
    ~Node();
    T getData();
    void setData(T);
};
#endif