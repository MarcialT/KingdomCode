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
    void setData(T);
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

class FamilyTree {
public:
    Persona* head;
    Persona* last;

    FamilyTree() : head(nullptr), last(nullptr) {}

    void addPerson(Persona* newPerson) {
        if (head == nullptr) {
            head = newPerson;
            last = newPerson;
        } else {
            last->Siguiente = newPerson;
            last = newPerson;
        }
    }

    Persona* findPersonById(int id) {
        Persona* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                return temp;
            }
            temp = temp->Siguiente;
        }
        return nullptr;
    }

    bool isFirstborn(int childId, int& fatherId) {
        Persona* child = findPersonById(childId);
        if (child == nullptr) {
            return false;
        }

        fatherId = child->id_father;
        if (fatherId == 0) {
            return false;
        }

        Persona* temp = head;
        while (temp != nullptr) {
            if (temp->id_father == fatherId && temp->id != childId) {
                if (temp->age > child->age) {
                    return false;
                }
            }
            temp = temp->Siguiente;
        }
        return true;
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
        leerCSV("KingDom.csv");
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

template<class T>
void Node<T>::setData(T data){
    this->data = data;
}
void leerCSV(string KingDom) {
    FamilyTree tree;

    ifstream archivo(KingDom);
    string linea;
    getline(archivo, linea); // Saltar la primera línea (encabezados)
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string campo[9];
        for (int i = 0; i < 9; ++i) {
            getline(ss, campo[i], ',');
        }

        Persona* nuevaPersona = new Persona(
            stoi(campo[0]),
            campo[1],
            campo[2],
            campo[3],
            stoi(campo[4]),
            stoi(campo[5]),
            stoi(campo[6]),
            stoi(campo[7]),
            stoi(campo[8])
        );

        tree.addPerson(nuevaPersona);
    }

    archivo.close();

    int id;
    cout << "Ingrese el ID de la persona: ";
    cin >> id;

    int fatherId;
    if (tree.isFirstborn(id, fatherId)) {
        Persona* father = tree.findPersonById(fatherId);
        cout << "La persona con ID " << id << " es el primogénito de " << father->first_name << " " << father->last_name << "." << endl;
    } else {
        cout << "La persona con ID " << id << " no es el primogénito de nadie o no tiene padre registrado." << endl;
    }
}