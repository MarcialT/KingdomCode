#include<iostream>
#include"./people.h"
using namespace std;

Persona::Persona(int _id, string _first_name, string _last_name, string _gender, int _age, int _id_father, bool _is_dead, bool _was_king, bool _is_king){
    this->id = _id;
    this->first_name = _first_name;
    this->last_name = _last_name;
    this->gender = _gender;
    this->age = _age;
    this->id_father = _id_father;
    this->is_dead = _is_dead;
    this->was_king = _was_king;
    this->is_king = _is_king;
    primogenito = nullptr;
    segundoHijo = nullptr;
    Siguiente = nullptr;
}