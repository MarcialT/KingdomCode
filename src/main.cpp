#include<iostream>
#include<fstream>

 using namespace std;

int main(){
    int option = 0;

    while(option!=5){
        cout<<"Bienvenido al reino!!!\nQue desea hacer hoy?"<<endl
        <<"1.-Convertir los datos en un arbol binario"<<endl
        <<"2.-Mostrar la linea de sucesion actual"<<endl
        <<"3.-Asignar un nodo como rey de manera automática en caso de morir el rey actual"<<endl
        <<"4.-Cambiar los datos de cualquier nodo del árbol"<<endl
        <<"5.-Salir"<<endl;
        cin>>option;

        switch (option)
        {
        case 1:
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
            cout<<"Por favor ingrese un numero dentro del rango"<<endl;
            break;
        }
    }
}