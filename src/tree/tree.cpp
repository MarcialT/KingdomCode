#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"./tree.h"
#include"./node/node.cpp"
#include"./people/people.cpp"
enum ramas{IZQ,DER};
using namespace std;

template<class T>
Tree<T>::Tree(){
    this->root = nullptr;
}
template<class T>
Node<T>* Tree<T>::getRoot(){
    return this->root;
}
template<class T>
void Tree<T>::Insert(Persona* node, Persona* new_person) {
    if (node == nullptr) {
        return;
    }

    if (node->id == new_person->id_father) {
        if (node->left_child == nullptr) {
            node->left_child = new_person;
        } else if (node->right_child == nullptr) {
            node->right_child = new_person;
        }
    } else {
        insert(node->left_child, new_person);
        insert(node->right_child, new_person);
    }
}

template<class T>
void Tree<T>::showSuccession(Persona* Node) {
    if (Node == nullptr) return;

    if (!Node->is_dead && Node->is_king) {
        cout << "Rey actual: " << Node->first_name << " " << Node->last_name << endl;
    }

    if (Node->segundoHijo != nullptr && !Node->segundoHijo->is_dead) {
        showSuccession(Node->segundoHijo);
    }
    if (Node->primogenito != nullptr && !Node->primogenito->is_dead) {
        showSuccession(Node->primogenito);
    }
}

template<class T>
Persona* Tree<T>::assignNewKing(Persona* currentKing) {
    if (currentKing == nullptr || !currentKing->is_dead) {
        return currentKing;
    }

    if (currentKing->left_child && !currentKing->left_child->is_dead) {
        return currentKing->left_child;
    }
    if (currentKing->right_child && !currentKing->right_child->is_dead) {
        return currentKing->right_child;
    }

    if (currentKing->id_father != 0) {
        Persona* father = findPersonById(root, currentKing->id_father);
        if (father != nullptr) {
            if (father->left_child && father->left_child != currentKing && !father->left_child->is_dead) {
                return father->left_child;
            }
            if (father->right_child && father->right_child != currentKing && !father->right_child->is_dead) {
                return father->right_child;
            }
        }
    }

    return nullptr;
}
template<class T>
Persona* Tree<T>::findPersonById(Persona* node, int id) {
    if (node == nullptr) return nullptr;
    if (node->id == id) return node;
    Persona* found = findPersonById(node->left_child, id);
    if (found != nullptr) return found;
    return findPersonById(node->right_child, id);
}

template<class T>
void Tree<T>::readCSV(const string& filename) {
    ifstream file(filename);
    string line;

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

        Persona* new_person = new Person(id, name, last_name, gender, age, id_father, is_dead, was_king, is_king);

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
        cout << "Nuevo rey asignado: " << new_king->name << " " << new_king->last_name << endl;
    } else {
        cout << "No se pudo asignar un nuevo rey." << endl;
    }
}
template<class T>
void Tree<T>::updatePersonData(int id, const string& new_name, const string& new_last_name, int new_age) {
    Persona* person = findPersonById(root, id);
    if (person != nullptr) {
        person->name = new_name;
        person->last_name = new_last_name;
        person->age = new_age;
    }
}
template<class T>
Tree<T>::~Tree() {
    // Se debe liberar la memoria del árbol, si se desea
}