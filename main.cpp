#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <time.h>

#include "Datos.h"
#include "Cola.h"

using namespace std;

string Nombres();
int TiempoCajero();
int TiempoLlegada();


int main() {
	Cola c;
	int contA=0, contE=0, Tllegada=0, TCajero=0;
	string nombre;
	c.Inicializar();

	for(int i=0; i<=120; i++) { //Tiempo de ejecucion

		if(c.ColaVacia()) {
			nombre = Nombres();
			c.Push(nombre);
			/*	Tllegada = TiempoLlegada();
				TCajero = TiempoCajero();	*/
		} else {
			if(Tllegada == 0) { //Si el cajero esta vacio
				Tllegada = TiempoLlegada();
				c.Push(Nombres());
				contE++; //Personas que entraron
			} else {
				Tllegada--; //Se decrementa el valor de llegada que es el tiempo en que sale
			}
		}

		if(TCajero == 0) { //Verficar que el tiempo de ser atendido sea cero para que el otro entre
			nombre = c.Atendiendo(0); //Guarda en la variable la posicion 0 de la cadena, la persona antendida
			c.Pop(); //Se borra quien esta en el cajero
			TCajero = TiempoCajero();
			contA++; //Aumento el contador de personas atendidas
		} else {
			TCajero--; //Se decrementa el valor de atencion que es el tiempo en que sale
		}


		system("cls");
		system("color 06");

		cout<<"                         *                *                   *     "<<endl;
		cout<<"             *                                     *                "<<endl;
		cout<<"     *              |           *             *        *         *  "<<endl;
		cout<<"          *        -+-                 *                            "<<endl;
		cout<<"       __           |      *             *          *        *      "<<endl;
		cout<<"   ___|  |   *     _|_              *    ____    ____               "<<endl;
		cout<<"   [_]|같|__      _| |_        *    |   |....|  |....|    *     *   "<<endl;
		cout<<"      |     |   _|[] []|_    ___    |   |....|  | ___|__            "<<endl;
		cout<<"   [_]|  같 |__|_  ______|  |   |  |_|  |....|  || -- - |   *     * "<<endl;
		cout<<"      |________  |__     |  |# #|  |_|  |....|  || - -- |  _____    "<<endl;
		cout<<"   [_]| _____ |     |__[]|  |   |  |_|  |....|__|| -- - | |* * *|   "<<endl;
		cout<<"      | [___] |        |__  |# #|  |_|  |....|__|| -- -_|_|* * *|   "<<endl;
		cout<<"   [_]|       | 같        | |   |__| |__|....|  || ___|* *|* * *|   "<<endl;
		cout<<"      | _____ |           |__  #|_______|....|  | |* *|* *|* * *|   "<<endl;
		cout<<"   [_]| [___] |       같     |__|_______|__  |  | |* *|* *|* * *|   "<<endl;
		cout<<"      |       |            __|_____________|__    |* *|* *|* * *|   "<<endl;
		cout<<"   [_]| _____ |  같      _|___________________|_  |* *|* *|* * *|   "<<endl;
		cout<<"      | [___] |         |_______________________|  ______________   "<<endl;
		cout<<"    __|_______|_________|_______________________| _________________ "<<endl;
		cout<<"   |_______________________________________________________________|"<<endl;
		cout<<"   |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"   ||||||||||||||||||||||||||||||BANCO||||||||||||||||||||||||||||||"<<endl;
		cout<<"   ||||||||||||||||||||||||||||||COLAS||||||||||||||||||||||||||||||"<<endl;
		cout<<"   |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<endl;
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* Operando *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<endl;
		cout<<"\t\t 	Tiempo trasncurrido: "<<i<<endl;
		cout<<">	Entraron: "<<contE<<endl;
		cout<<">	"<<nombre<<", esta siendo atendido, sale en: "<<TCajero<<endl; //Mostrar nombre
		cout<<">	La siguiente persona llega en: "<<Tllegada<<endl;
		cout<<">	Clientes en cola: "<<endl;
		cout<<"> 	";
		c.MostrarCola(0);
		cout<<endl;
		sleep(1);
	}
	
	cout<<endl;
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-	Reporte		-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
	cout<<endl;
	cout<<">	Numero total de clientes atendidos: "<<contA<<endl;
	cout<<">	Numero de clientes que se quedaron en cola: "<<c.Cima()<<endl;
	cout<<">	El cliente siendo atendido fue: "<<nombre<<endl;
	cout<<">	El cliente que iba a pasar es: "<<c.Atendiendo(0)<<endl;
	cout<<">	El ultimo cliente en llegar fue: ";
	cout<<c.Fondo()<<endl;




	return 0;
}

string Nombres() {
	string nombre [] = {"Alexis", "Juan", "Esteban", "Vanessa", "Sebastian", "Valeria"};
	srand(time(NULL));
	for(int i=0; i<120; i++) {
		int numero = rand()%(5-0+1)+0;
		return nombre[numero];
	}
}

int TiempoCajero() {
	int tiempoA;
	srand(time(NULL));
	for(int i=0; i<20; i++) {
		tiempoA = rand()%(5-3+1)+3;
		return tiempoA;
	}
}

int TiempoLlegada() {
	int tiempoL;
	srand(time(NULL));
	for(int i=0; i<20; i++) {
		tiempoL = rand()%(4-2+1)+2;
		return tiempoL;
	}
}
