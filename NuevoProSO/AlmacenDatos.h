#pragma once..
#include "BitacoraP.h";
#include<vector>;
using namespace std;

class AlmacenDatos
{
	public:
		vector<BitacoraP> almacen;
	public:
		AlmacenDatos() {

		};

			void agregarProceso(BitacoraP bitacora) {
			almacen.push_back(bitacora);
		}

		void mostrarProcesos() {
			cout << "No. Proceso\t | Tema\t\t | Paternidad\t | Tiempo Ejecucion"; 
			cout << endl;
			for (int i = 0; i < almacen.size(); i++) {
				cout << almacen[i].toString();
				cout << endl;
			}
		}
};

