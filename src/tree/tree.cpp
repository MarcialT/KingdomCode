#include<iostream>
#include"./tree.h"
using namespace std;

Tree::Tree(){
    this->head = nullptr;
    this->last = nullptr;
}

void Tree::addPerson(Persona* newPerson) {
        if (head == nullptr) {
            head = newPerson;
            last = newPerson;
        } else {
            last->Siguiente = newPerson;
            last = newPerson;
        }
    }

    Persona* Tree::findPersonById(int id) {
        Persona* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                return temp;
            }
            temp = temp->Siguiente;
        }
        return nullptr;
    }

    bool Tree::isFirstborn(int childId, int& fatherId) {
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