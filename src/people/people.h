#ifndef PEOPLE_H
#define PEOPLE_H
#include<string>
#pragma once
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
    Persona(int _id, string _first_name, string _last_name, string _gender, int _age, int _id_father, bool _is_dead, bool _was_king, bool _is_king);
};

#endif