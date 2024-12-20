#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"./tree.h"
#include"../node/node.cpp"
#include"../people/people.cpp"
enum ramas{IZQ,DER};
using namespace std;

template<class T>
Tree<T>::Tree(){
    this->root = nullptr;
}
template<class T>
void Tree<T>::showSuccession(Persona* node) {
    if (node == nullptr) return;

    // Mostrar el rey actual
    if (!node->is_dead && node->is_king) {
        cout << "Rey actual: " << node->id << " " << node->first_name << " " << node->last_name << ", Edad: " << node->age << endl;
    }

    // Función auxiliar para mostrar los herederos
    mostrarHerederos(node);
}

template<class T>
void Tree<T>::mostrarHerederos(Persona* node) {
    if (node == nullptr) return;

    // Mostrar el primogénito si está vivo y es menor de 70 años
    if (node->primogenito != nullptr && !node->primogenito->is_dead && node->primogenito->age < 70) {
        cout << "Heredero: " << node->primogenito->id << " " << node->primogenito->first_name << " " << node->primogenito->last_name << ", Edad: " << node->primogenito->age << endl;
        mostrarHerederos(node->primogenito); // Llamada recursiva para el primogénito
    }

    // Mostrar el hijo del primogénito si está vivo y es menor de 70 años
    if (node->primogenito != nullptr && node->primogenito->primogenito != nullptr && !node->primogenito->primogenito->is_dead && node->primogenito->primogenito->age < 70) {
        cout << "Heredero: " << node->primogenito->primogenito->id << " " << node->primogenito->primogenito->first_name << " " << node->primogenito->primogenito->last_name << ", Edad: " << node->primogenito->primogenito->age << endl;
        mostrarHerederos(node->primogenito->primogenito); // Llamada recursiva para el hijo del primogénito
    }

    // Mostrar el primer hijo del segundo hijo del rey actual si está vivo y es menor de 70 años
    if (node->segundoHijo != nullptr && node->segundoHijo->primogenito != nullptr && !node->segundoHijo->primogenito->is_dead && node->segundoHijo->primogenito->age < 70) {
        cout << "Heredero: " << node->segundoHijo->primogenito->id << " " << node->segundoHijo->primogenito->first_name << " " << node->segundoHijo->primogenito->last_name << ", Edad: " << node->segundoHijo->primogenito->age << endl;
        mostrarHerederos(node->segundoHijo->primogenito); // Llamada recursiva para el primer hijo del segundo hijo
    }

    // Mostrar el segundo hijo si está vivo y es menor de 70 años
    if (node->segundoHijo != nullptr && !node->segundoHijo->is_dead && node->segundoHijo->age < 70) {
        cout << "Heredero: " << node->segundoHijo->id << " " << node->segundoHijo->first_name << " " << node->segundoHijo->last_name << ", Edad: " << node->segundoHijo->age << endl;
        mostrarHerederos(node->segundoHijo); // Llamada recursiva para el segundo hijo
    }
}
template<class T>
Persona* Tree<T>::assignNewKing(Persona* currentKing) {
    if (currentKing == nullptr || !currentKing->is_dead) {
        return currentKing;
    }

    if (currentKing->segundoHijo && !currentKing->segundoHijo->is_dead) {
        return currentKing->segundoHijo;
    }
    if (currentKing->primogenito && !currentKing->primogenito->is_dead) {
        return currentKing->primogenito;
    }

    if (currentKing->id_father != 0) {
        Persona* father = findPersonById(root, currentKing->id_father);
        if (father != nullptr) {
            if (father->segundoHijo && father->segundoHijo != currentKing && !father->segundoHijo->is_dead) {
                return father->segundoHijo;
            }
            if (father->primogenito && father->primogenito != currentKing && !father->primogenito->is_dead) {
                return father->primogenito;
            }
        }
    }

    return nullptr;
}
template<class T>
Persona* Tree<T>::findPersonById(Persona* node, int id) {
    if (node == nullptr) return nullptr;
    if (node->id == id) return node;
    Persona* found = findPersonById(node->segundoHijo, id);
    if (found != nullptr) return found;
    return findPersonById(node->primogenito, id);
}

template<class T>
void Tree<T>::readCSV() {
    ifstream file("../bin/KingDom.csv");
    string line;

    getline(file, line); // Leer la línea de encabezado
    while (getline(file, line)) {
        stringstream ss(line);
        string id_str, name, last_name, gender_str, age_str, id_father_str, is_dead_str, was_king_str, is_king_str;
        getline(ss, id_str, ',');
        getline(ss, name, ',');
        getline(ss, last_name, ',');
        getline(ss, gender_str, ',');
        getline(ss, age_str, ',');
        getline(ss, id_father_str, ',');
        getline(ss, is_dead_str, ',');
        getline(ss, was_king_str, ',');
        getline(ss, is_king_str, ',');

        int id = stoi(id_str);
        int age = stoi(age_str);
        int id_father = stoi(id_father_str);
        bool is_dead = stoi(is_dead_str);
        bool was_king = stoi(was_king_str);
        bool is_king = stoi(is_king_str);
        char gender = gender_str[0];

        Persona* new_person = new Persona(id, name, last_name, gender, age, id_father, is_dead, was_king, is_king);

        if (id_father == 0) {
            root = new_person;
        } else {
            insert(root, new_person);
        }
    }
}

template<class T>
void Tree<T>::showSuccession() {
    showSuccession(root);
}
template<class T>
void Tree<T>::assignKing() {
    if (root == nullptr) return;
    Persona* new_king = assignNewKing(root);
    if (new_king != nullptr) {
        cout << "Nuevo rey asignado: " << new_king->first_name << " " << new_king->last_name << endl;
    } else {
        cout << "No se pudo asignar un nuevo rey." << endl;
    }
}
template<class T>
void Tree<T>::updatePersonData(int id, const string& new_name, const string& new_last_name, int new_age) {
    Persona* person = findPersonById(root, id);
    if (person != nullptr) {
        person->first_name = new_name;
        person->last_name = new_last_name;
        person->age = new_age;
    }
}

template<class T>
void Tree<T>::insert(Persona* node, Persona* new_person) {
    if (node == nullptr) {
        return;
    }

    if (node->id == new_person->id_father) {
        if (node->segundoHijo == nullptr) {
            node->segundoHijo = new_person;
        } else if (node->primogenito == nullptr) {
            node->primogenito = new_person;
        }
    } else {
        insert(node->segundoHijo, new_person);
        insert(node->primogenito, new_person);
    }
}
