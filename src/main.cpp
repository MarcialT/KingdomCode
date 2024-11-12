#include<iostream>
#include<fstream>

 using namespace std;

template<class T>
class Node{
    private:
    T data;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
    public:
    Node(T,Node<T>*,Node<T>*);
    ~Node();
    T getData();
    void setData(Node<T>*);
    Node<T>* getNext();
    void setNext(Node<T>*);
    Node<T>* getPrev();
    void setPrev(Node<T>*);
    void print();
};

void Menu(int option);



int main(){
    int option = 0;
        Menu(option);
}

void Menu(int option){
    cout<<"Bienvenido al reino!!!\nQue desea hacer hoy?"<<endl;
    while(option!=5){
        cout<<"1.-Convertir los datos en un arbol binario"<<endl
        <<"2.-Mostrar la linea de sucesion actual"<<endl
        <<"3.-Asignar un nodo como rey de manera automatica en caso de morir el rey actual"<<endl
        <<"4.-Cambiar los datos de cualquier nodo del arbol"<<endl
        <<"5.-Salir"<<endl;
        cin>>option;
    switch (option)
        {
        case 1:
            cout<<"Se han convertido los datos en un arbol binario"<<endl;
            break;
        
        case 2:
            cout<<"La linea de sucesion actual es:\n"<<endl;
            break;

        case 3:
            cout<<"rey asignado"<<endl;
            break;

        case 4:
            cout<<"Se han cambiado los datos de manera exitosa"<<endl;
            break;
        
        case 5:
            cout<<"Gracias por ejecutar el codigo del reino"<<endl;
            break;

        default:
            cout<<"Por favor ingrese un numero dentro del rango\n"<<endl;
            break;
        }
        }
}

template<class T>
Node<T>::Node(T data,Node<T>* left,Node<T>* rigth){
    if(left != NULL){
        this->left = left;
    }
    if(right != NULL){
        this->right = rigth;
    }
}

template<class T>
Node<T>::~Node(){
    this->left = nullptr;
    this->right = nullptr;
}

template<class T>
T Node<T>::getData(){
    return this->data;
}
