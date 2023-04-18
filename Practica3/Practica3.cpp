#include <cstdio>
#include <cstdlib>
#include "Utils.h"
#include "MemoryManager.h"
#include"CHora.h"
using namespace std;

int main() {
	{
		const char* menu[3]{ "Introducir hora","Visualizar hora","Terminar" };
		int funcion = 0;
		int nHoras = 0;
		int nMinutos = 0;
		int nSegundos = 0;
		bool aux;
		string pszFormato;
		CHora hora;	
		while (funcion != 3) {
			CrearMenu(menu, 3);
			funcion = LeerInt();
			switch (funcion) {
			case 1:
			{
				do {
					hora.Iniciar();
					cout << "Introduzca el Formato horario (AM/PM o 24 HORAS): " << endl;
					pszFormato = LeerCadena(); // defenir funcion de lectura string
					cout << "Introduzca la Hora: ";
					nHoras = LeerInt();
					cout << endl;
					cout << "Introduzca los Minutos: ";
					nMinutos = LeerInt();
					cout << endl;
					cout << "Introduzca los Segundos: ";
					nSegundos = LeerInt();
					cout << endl;
					aux = hora.AsignarHora(nHoras, nMinutos, nSegundos, pszFormato);
					if (aux == false)
						cout << "Valores introduccidos incorrectos";
				} while (aux != true);
				break;
			}
			case 2:
			{
				VisualizarHora(hora);
				break;
			}
			case 3:
			{
				hora.Destruir();
				hora.~CHora();
			}
			}
		}
	}
	MemoryManager::dumpMemoryLeaks();
}
