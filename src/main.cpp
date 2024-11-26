#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"./node/node.cpp"
#include"./people/people.cpp"
#include"./util/util.cpp"
using namespace std;

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
void findChildrenById(string csvFile, int parentId);

int main() {
    int option = 0;
    Menu(option);

    int parentId;
    cout << "Ingrese el ID del padre para buscar sus hijos: ";
    cin >> parentId;
    findChildrenById("../bin/KingDom.csv", parentId);

    return 0;
}

void findChildrenById(string csvFile, int parentId) {
    ifstream file(csvFile);
    if (!file.is_open()) {
        cout << "Error al abrir el archivo " << csvFile << endl;
        return;
    }

    FamilyTree tree;
    string line;
    getline(file, line); // Saltar la primera línea (encabezados)

    while (getline(file, line)) {
        stringstream ss(line);
        string field[9];
        for (int i = 0; i < 9; ++i) {
            getline(ss, field[i], ',');
        }

        Persona* nuevaPersona = new Persona(
            stoi(field[0]),
            field[1],
            field[2],
            field[3],
            stoi(field[4]),
            stoi(field[5]),
            stoi(field[6]),
            stoi(field[7]),
            stoi(field[8])
        );

        tree.addPerson(nuevaPersona);
    }

    file.close();

    Persona* parent = tree.findPersonById(parentId);
    if (parent == nullptr) {
        cout << "No se encontró a la persona con ID " << parentId << endl;
        return;
    }

    cout << "Buscando hijos de: " << parent->first_name << " " << parent->last_name << endl;

    Persona* oldestChild = nullptr;
    bool hasChildren = false;

    Persona* temp = tree.head;
    while (temp != nullptr) {
        if (temp->id_father == parentId) {
            hasChildren = true;
            cout << "Hijo: " << temp->first_name << " " << temp->last_name << endl;
            if (oldestChild == nullptr || temp->age > oldestChild->age) {
                oldestChild = temp;
            }
        }
        temp = temp->Siguiente;
    }

    if (!hasChildren) {
        cout << "La persona con ID " << parentId << " no tiene hijos registrados." << endl;
    } else if (oldestChild != nullptr) {
        cout << "El hijo de mayor edad es: " << oldestChild->first_name << " " << oldestChild->last_name << " con " << oldestChild->age << " años." << endl;
    }
}