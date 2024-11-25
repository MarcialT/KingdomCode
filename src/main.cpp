#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Persona {
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

    Persona(int _id, string _first_name, string _last_name, string _gender, int _age, int _id_father, bool _is_dead, bool _was_king, bool _is_king) {
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
void leerCSV(string KingDom);
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