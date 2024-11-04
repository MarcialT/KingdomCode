#include<iostream>
#include<fstream>

 using namespace std;

int main(){
    int option = 0;

    while(option!=5){
        cout<<"Bienvenido al reino!!!\nQue desea hacer hoy?"<<endl
        <<"1.-Convertir los datos en un arbol binario"<<endl
        <<"2.-Mostrar la linea de ssucesion actual"<<endl
        <<"3.-Asignar un nodo como rey de manera automática en caso de morir el rey actual"<<endl
        <<"4.-Cambiar los datos de cualquier nodo del árbol"<<endl
        <<"5.-Salir"<<endl;
        cin>>option;

        if(option==5){
            cout<<"Gracias por ejecutar el codigo del reino"<<endl;
        }
    }
}