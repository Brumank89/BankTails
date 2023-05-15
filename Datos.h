#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <unistd.h>


using namespace std;

#ifndef DATOS_H
#define DATOS_H

class Datos {

	private:

	public:
		string Nombres() {
			string nombre [] = {"Alexis", "Juan", "Esteban", "Vanessa", "Sebastian", "Valeria"};
			string apellido[] = {" Hernandez", " Sanchez", " Huerta", " Lopez", " Martinez"};
				for(int i=0; i<120; i++){
					int numero = rand()%(6-0+1)+0;
					int numero2 = rand()%(5-0+1)+0;
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
		
		int TiempoLlegada(){
			int tiempoL;
			srand(time(NULL));
			for(int i=0; i<20; i++) {
				tiempoL = rand()%(4-2+1)+2;
				return tiempoL;
			}
		}
		
};

#endif
