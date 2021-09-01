#pragma once..
#include "BitacoraP.h";
#include<vector>;
#include<fstream>;
#include<iostream>;
#include<iomanip>;
#include<stdlib.h>;
#include<cstring>;
#include<istream>;
#include<string>;

#include <iterator>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class AlmacenDatos
{
public:
	ifstream l, car1;
	ofstream in, car;
	vector<BitacoraP> almacen;
	vector<BitacoraP> ContenedorTXT;
	
public:
	AlmacenDatos() {

	};

	void agregarProceso(BitacoraP bitacora) {
		almacen.push_back(bitacora);
	}

	void agregarProcesoaContenedorTXT(BitacoraP bitacora) {
		ContenedorTXT.push_back(bitacora);
	}

	void mostrarProcesos() {
		cout << "No. Proceso\t | Tema\t\t | Paternidad\t | Tiempo Ejecucion";
		cout << endl;
		for (int i = 0; i < almacen.size(); i++) {
			cout << almacen[i].toString();
			cout << endl;
		}
	}

	void mostrarProcesosContenedroTXT() {
		cout << "No. Proceso\t | Tema\t\t\t | Paternidad\t | Tiempo Ejecucion";
		cout << endl;
		for (int i = 0; i < ContenedorTXT.size(); i++) {
			cout << ContenedorTXT[i].toString();
			cout << endl;
		}
	}


	void LeerFichero() {// Procedimiento para imprimir el inventario en pantalla.
			string temp;
			string temNoProceso, tempTema, tempEstado,tempPaternidad,tempTiempo;
			PrioridadProceso pp = PrioridadProceso();
			string leer; // se declaran 2 variables una para abrir el fichero y otra para almacenar la información que se encuentra en el fichero
			int cont = 0;
			l.open("Inventario.txt", ios::in);//se abre el fichero
			if (l.fail()) {// muestra error en caso el fichero este dañado o no exista
				cout << "El archivo no se pudo abrir, puede que este dañado";
				exit(1);
			}// fin de error
			system("cls");
			cout << "No. Proceso\tTema\tPrioridadProceso\tPaternidad\tTiempo de Ejecución";
			cout << "*********************************************************************";
			while (!l.eof()) {//lectura del fichero
				cont = 0;
				
				getline(l, leer);// almacena la información del fichero en la variable leer 
				cout << leer << "\n";// se imprime en pantalla, guarda el formato exacto de como se encuentra en el fichero.


				stringstream input_stringstream(leer);

				while (getline(input_stringstream,temp,'|')) {
					if (cont == 0) {
						temNoProceso = temp;
					}if (cont == 1) {
						tempTema = temp;
					}/*if (cont == 2) {
						pp = PrioridadProceso::LISTO;
					}*/if (cont == 3) {
						tempPaternidad = temp;
					}if (cont == 4) {
						tempTiempo = temp;
					}

					cont++;
				}
				agregarProcesoaContenedorTXT(BitacoraP::BitacoraP(temNoProceso, tempTema, PrioridadProceso::NUEVO, tempPaternidad, tempTiempo));
			}l.close();	// fin de la lectura del fichero	

			mostrarProcesosContenedroTXT(); 
		}
};

