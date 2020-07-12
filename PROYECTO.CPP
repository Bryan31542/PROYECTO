#include <iostream>
#include <string>
#include <string.h> 

using namespace std;

const int longCad = 20;

struct costoPorArticulo
{
    char nombreArticulo[longCad+1];
    int cantidad;
    float precio;
    float CostoArticulo;
};

//funcion que lea datos (nombre, cantidad, precio unitario y los incorpore en el arreglo)
void leerdatos(int n, string nombre, costoPorArticulo listado[]){

    cout << "\nProceda a ingresar el nombre del articulo, cantidad y el precio unitario" << endl;
    int cont = 1;

    for (int i = 0; i < n; i++){

        cout << "\nNombre del articulo numero " << cont << ": ";
        getline(cin, nombre, '\n');
        strncpy(listado[i].nombreArticulo, nombre.c_str(), longCad);
        listado[i].nombreArticulo[longCad]= '\0';

        cout << "Cantidad comprada del articulo numero " << cont << ": ";
        cin >>listado[i].cantidad;

        cout << "Precio unitario del articulo numero " << cont << ": ";
        cin >> listado[i].precio;

        cin.ignore(100, '\n'); //Limpiar teclado 
        cont++;
    }
}
//funcion que calcule el costo por articulo e incorpore este valor en el campo correspondiente de cada articulo
void Costo(int n, costoPorArticulo listado[]){

    int costo = 0;
    for (int i = 0; i < n; i++){

        listado[i].CostoArticulo = listado[i].cantidad * listado[i].precio; //Se multiplica la cantidad por el precio y se almacena
        
    }
}

//funcion que despliegue el contenido del arreglo, mostrando los cuatro datos de las estructura para cada articulo
void desplegarContenido(int n, costoPorArticulo listado[]){

    cout << "\nLos datos de su factura son: " << endl;
    //costoPorArticulo listado[n];

    int cont1 = 1;
    for (int i = 0; i < n; i++){

        cout << "\nArticulo numero: " << cont1 << endl;
        cout << "Nombre del Articulo: " << listado[i].nombreArticulo << endl;
        cout << "Cantidad comprada: " << listado[i].cantidad << endl;
        cout << "Precio unitario: " << listado[i].precio << endl;
        cout << "Costo total por articulo: " << listado[i].CostoArticulo << endl;
        cont1++;
    }
}
//funcion que retorne el costo total de la compra, suma de los costos de cada articulo, se desplegara en main
float costototal(int n, costoPorArticulo listado[]){

    float total = 0;
    for (int i = 0; i < n; i++){

        total += listado[i].CostoArticulo;

    }
    return total;
}

//Funcion principal
int main(){

    int n;
    string nombre;
    char nombreArticulo[longCad+1];
    float total;

    cout << "\nPROCESE UNA FACTURA DE COMPRA" << endl << endl;

    cout << "Ingrese la cantidad de articulos: ";
    cin >> n;

    cin.ignore(100,'\n');

    costoPorArticulo listado[n]; //Se declara el arreglo

    leerdatos(n, nombre, listado); //Se manda a llamar a la funcion que lee los datos

    Costo(n, listado); //Se manda a llamar a la funcion que calcula el costo por articulo

    desplegarContenido(n, listado); //Se manda a llamar a la funcion que despliega el contenido de la estructura

    cout << "\nEl costo total de su compra es de: " << costototal(n, listado); //Se manda a llamar a la funcion que calcula el costo total de la compra
    
    return 0;
}