#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

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

class Persona{
public:
    int id;
    string first_name;
    string last_name;
    string gender;
    int age;
    int id_father;
    bool is_dead;
    bool was_king;
    bool is_king;

    Persona* primogenito;
    Persona* segundoHijo;
    Persona* Siguiente;

    Persona(int _id, string _first_name, string _last_name, string _gender, int _age, int _id_father, bool _is_dead, bool _was_king, bool _is_king){
        id = _id;
        first_name = _first_name;
        last_name = _last_name;
        gender = _gender;
        age = _age;
        id_father = _id_father;
        is_dead = _is_dead;
        was_king = _was_king;
        is_king = _is_king;
        primogenito = nullptr;
        segundoHijo = nullptr;
        Siguiente = nullptr;
    }
};

Persona* head = nullptr;
void Menu(int option);
void leerCSV (string KingDom);



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

void leerCsv (string KingDom){
    ifstream archivo("KingDom.csv");
    if (!archivo.is_open()){
        cout<<"No se pudo abrir el archivo"<<endl;
        return;
    }
    string linea;
    getline(archivo, linea);

    Persona* ultimo = nullptr;
    while(getline(archivo, linea)){
        stringstream ss(linea);
        string dato;
        string campo[9];
        int i= 0;

        while(getline(ss, dato, ',')){
            campo[i++] = dato;
        }

        if (campo[3] == "Male"){
            campo[3] == "H";
        } 
        else if(campo[3] == "Female"){
            campo[3] == "M";
        }

        Persona* nuevaPersona = new Persona{
            stoi(campo[0]),
            campo[1],
            campo[2],
            campo[3],
            stoi(campo[4]),
            stoi(campo[5]),
            stoi (campo[6]),
            stoi (campo[7]),
            stoi (campo[8]),
    };

    if (head == nullptr){
        head = nuevaPersona;
        ultimo = nuevaPersona;
    }
    else {
        ultimo->Siguiente = nuevaPersona;
        ultimo = nuevaPersona;
    }
    }

    archivo.close();
           
    
}
