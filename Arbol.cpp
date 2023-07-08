#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct nodo{
	string dato;
	nodo *der;
	nodo *izq;
};

void Menu();
nodo *crearNodo(string);
void agregarNodo(nodo *&, string);
void MostrarArbol(nodo *, int);
nodo *arbol = NULL;

int main(){
	Menu();
	getch();
	return 0;
}

void Menu(){
	string dato;
	int	opcion, contador = 0;
	do{
		cout<<"1. Agregar nombres al Arbol Genealogico "<<endl;
		cout<<"2. Mostrar Arbol Genealogico "<<endl;
		cout<<"3. Salir "<<endl;
		cout<<"\nOpcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:	cout<<"Nombre a agregar: ";
					cin>>dato;
					agregarNodo(arbol,dato);
					break;
			case 2:	cout<<"\n.:Mostrando Arbol:."<<endl;
					MostrarArbol(arbol,contador);
					break;
		}
		system("pause");
		system("cls");
	}while(opcion != 3);
}

nodo *crearNodo(string n){
	nodo *NuevoNodo = new nodo();
	NuevoNodo->dato = n;
	NuevoNodo->der = NULL;
	NuevoNodo->izq = NULL;	
	return NuevoNodo;
}

void agregarNodo(nodo *&arbol, string n){
	if(arbol == NULL){
		nodo *nuevoNodo = crearNodo(n);
		arbol = nuevoNodo;
		cout<<("Nodo raiz creado")<<endl;
	}else{
		string ValorDeRaiz = arbol->dato;
		if(n < ValorDeRaiz){
			agregarNodo(arbol->izq,n);
			cout<<("Nodo izquierdo creado")<<endl;
		}else{
			agregarNodo(arbol->der,n);
			cout<<("Nodo derecho creado")<<endl;
		}
	}
}

void MostrarArbol(nodo *arbol, int cont){
	if(arbol == NULL){
		return;
	}else{
		MostrarArbol(arbol->der,cont+1);
		for(int i=0 ; i<cont ; i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		MostrarArbol(arbol->izq,cont+1);
	}
}


