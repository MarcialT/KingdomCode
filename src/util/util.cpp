#include<iostream>
#include<fstream>
#include"sstream"
#include<string>
#include"util.h"
#include"../tree/tree.cpp"
#include"../people/people.cpp"
using namespace std;

void Menu(int option) {
    cout << "\nBienvenido al reino!!!\nQue desea hacer hoy?" << endl;
    while (option != 5) {
        cout << "1.-Convertir los datos en un arbol binario" << endl
             << "2.-Mostrar la linea de sucesion actual" << endl
             << "3.-Asignar un nodo como rey de manera automatica en caso de morir el rey actual" << endl
             << "4.-Cambiar los datos de cualquier nodo del arbol" << endl
             << "5.-Salir" << endl;
        cin >> option;
        switch (option) {
            case 1:
                leerCSV("../bin/KingDom.csv");
                cout << "Se han convertido los datos en un arbol binario" << endl;
                break;

            case 2:
                int parentId;
                cout << "Ingrese el ID del padre: ";
                cin >> parentId;
                findChildrenById("../bin/KingDom.csv", parentId);
                cout << "La linea de sucesion actual es:\n" << endl;
                break;

            case 3:
                cout << "rey asignado" << endl;
                break;

            case 4:
                cout << "Se han cambiado los datos de manera exitosa" << endl;
                break;

            case 5:
                cout << "Gracias por ejecutar el codigo del reino" << endl;
                break;

            default:
                cout << "Por favor ingrese un numero dentro del rango\n" << endl;
                break;
        }
    }
}

void leerCSV(string KingDom) {
    Tree tree;

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

void findChildrenById(string csvFile, int parentId) {
    ifstream file(csvFile);
    if (!file.is_open()) {
        cout << "Error al abrir el archivo " << csvFile << endl;
        return;
    }

    Tree tree;
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