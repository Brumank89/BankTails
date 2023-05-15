#include <iostream>
#include <string>
#ifndef COLA_H
#define COLA_H
using namespace std;

class Cola{
	private:
		string cola[50];
		int fondo = 0, tope, cima = 0, indice = 0;
		
		bool ColaLlena() {
			if(cima > tope)
				return true;
			else 
				return false;
		}
		
		
		void Reorganizar(int indice) {
			//caso base
			if(indice == cima) {
				cola[cima] = -1;
				indice = 0;
				return;
			} else { //Caso general
				cola[indice] = cola[indice+1]; 
				Reorganizar(indice+1);
			}
		}
	public:  
	
		bool ColaVacia() {
			if(cima==fondo)
				return true;
			else 
				return false;
		}
		
		void Inicializar() {
			cima = 0;
			fondo = 0;
			indice = 0;
			int longitud = sizeof(cola)/sizeof(*cola);
			tope = longitud - 1;
		}
		
		int Push(string dato) {
			if(ColaLlena() != true){
				cola[cima] = dato;
				cima++;
				return 0;
			}else{
				return -1;
			}
		}
		
		int Pop() {
			if(ColaVacia()!=true) {
				string dato;
				dato = cola[fondo];
				cima--;
				Reorganizar(indice);
			}else{
				return -1;
			}
		}
		
		
		void Vaciar(int pos){
			if(!ColaVacia()){
				if(pos==tope){
					return;
				}else{
					Pop();
					cout<<"Eliminado dato..."<<endl;
					Vaciar(pos+1);
				}
			}
		}
		
		void MostrarCola(int cont){
			if(cont == cima){
				return;
			}else{
				cout<<cola[cont]<<" ";
				MostrarCola(cont+1);
			}	
		}
		
		string Atendiendo(int num){
			return cola[num];
		}
		
		int Cima(){
			return cima;
		}
		
		string Fondo(){
			return cola[Cima()-1];
		}
};

#endif
