// NuevoProSO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "BitacoraP.h";
#include "AlmacenDatos.h";
#include "PrioridadProceso.h";
#define limite 5
using namespace std;
AlmacenDatos procesos = AlmacenDatos();

void insertar(char datos[], int tiempo[], int numero) {
    for (int i = 0; i < (numero); i++) {
        cout << "inserte el tiempo en el proceso [" << datos[i] << "]: ";
        cin >> tiempo[i];
    }
}

int quantum(int tiempo[], int numero) {
    int resultado = 20;
   
    /*for (int i = 0; i < numero; ++i)
        resultado += tiempo[i];
    resultado /= numero;*/
    return resultado;
}

void RoundRobin(char datos[], int tiempo[], int numero) {

    PrioridadProceso pp =  PrioridadProceso();
    insertar(datos, tiempo, numero);
    int Quantum = quantum(tiempo, numero);// saca el promedio de tiempo de los procesos
    cout << "El quantum es: " << Quantum << endl;
    int tiempoFinal = 0;
    float sumatoria = 0.0f;
    int metalera = 0;
    int i = 0;
    do {
        tiempo[i] != 0 ? tiempo[i] -= Quantum : ++i;
        if (tiempo[i] > 0){
            tiempoFinal += Quantum;
            cout << "el tiempo de nuevo de " << datos[i] << ": "
                << tiempoFinal << endl;
            procesos.agregarProceso(BitacoraP::BitacoraP("1", "hola", PrioridadProceso::LISTO, "1", "25"));

        }
        else {
            tiempoFinal += Quantum + tiempo[i];
            sumatoria += tiempoFinal;
            cout << "el tiempo de proceso de " << datos[i] << ": "
                << tiempoFinal << endl;
            metalera++;
        }
        i < (numero - 1) ? i++ : i = 0;
    } while (metalera < numero);
    sumatoria /= numero;
    cout << "Tiempo promedio de los procesos es: "
        << sumatoria << endl;
}


int main() {
  

    char datos[limite] = { 'a','b','c','d','e' };
    int tiempo[limite];
    RoundRobin(datos, tiempo, limite);
    cin.get();
    cin.get();

    procesos.mostrarProcesos();

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
