#include <iostream>
#include <fstream>
#include <unistd.h>
#include<sys/wait.h>

using namespace std;

void AbrirYLeerArchivo(){

	string textoDeArchivo;
	ifstream archivo;

	archivo.open("ArchivoDePrueba.txt");

	if(archivo.fail()){
		cout<<"No se pudo abrir,"<<endl;
	}

	while(!archivo.eof()){
		getline(archivo, textoDeArchivo);
		cout<<textoDeArchivo<<endl;
	}

}

void GuardarMensaje(string mensaje){

	ofstream archivo;

	archivo.open("ArchivoDePrueba.txt", ios::app);

	if(archivo.fail()){
		cout<<"No se pudo abrir,"<<endl;
	}

	archivo<<"El proceso con PID: "<<getpid()<<" escribio el mensaje: "<<mensaje<<endl;

	archivo.close();
}

void MostrarMenu(){

	cout<<"Ingrese un numero para elejir una opcion"<<endl;
	cout<<"1.- crear un proceso nuevo"<<endl;
	cout<<"2.- Guardar un mensaje"<<endl;
	cout<<"3.- Ver mensajes guardados"<<endl;
	cout<<"4.- Salir"<<endl;

}


void BifurcarProceso(){

	cout<<"Proceso hijo"<<endl;

	int valorDeRetorno = fork();

}


int main() {

	cout<<"Proceso padre"<<endl;

	int opcion;

			do{
				MostrarMenu();
				cin>>opcion;

				switch(opcion){

				case 1:
					BifurcarProceso();
					wait(NULL);
					break;
				case 2:{
					string mensaje;
					cout<<"Escriba el mensaje que desea guardar: "<<endl;
					getline(std::cin >> std::ws, mensaje);
					GuardarMensaje(mensaje);
					break;
				}
				case 3:
					AbrirYLeerArchivo();
					break;
				case 4:
					exit(0);
					break;
				default:
					cout<<"Opcion incorrecta"<<endl;

				}

			}while(true);

	return 0;
}
