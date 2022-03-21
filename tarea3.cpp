#include <iostream>
#include <iostream>
#include <stdio.h>  
#include <string.h> 

using namespace std;
const char *nombre_archivo="archivo.dat";

struct Estudiante{
	int	 codigo;
	char nombre[25];
	char apellido[25];
	char direccion[35];
	int	 grado;
	int	 telefono;
};

void crear();
void leer();

main(){
	
	system("PAUSE");
	crear();
	leer();
	return 0;
	
}

void leer(){
	system("cls");
	FILE* archivo=fopen(nombre_archivo,"rb");
	if(!archivo){
		archivo=fopen(nombre_archivo,"w+b");
	}
	Estudiante estudiante;
	int id;
	do{
		cout<<"______________________________________"<<endl;
		cout<<id<<" | "<<estudiante.codigo<<" | "<<estudiante.nombre<<" | "<<estudiante.apellido<<" | "<<estudiante.direccion<<" | "<<estudiante.grado<<" | "<<estudiante.telefono<<endl;
		fread(&estudiante,sizeof(Estudiante),1,archivo);	
	}while(feof(archivo)==0);
	fclose(archivo);
}

void crear(){
	FILE* archivo=fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	char continuar;
	string nombre,apellido,direccion;
	int grado,telefono;
	int id;
	do{
		
		fflush(stdin);
		cout<<"Ingrese Codigo: ";cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese Nombres: ";cin>>estudiante.nombre;
		getline(cin,nombre);
		strcpy(estudiante.nombre,nombre.c_str());
		
		cout<<"Ingrese Apellidos: ";cin>>estudiante.apellido;
		getline(cin,apellido);
		strcpy(estudiante.apellido,apellido.c_str());
		
		cout<<"Ingrese Direccion: ";cin>>estudiante.direccion;
		getline(cin,direccion);
		strcpy(estudiante.direccion,direccion.c_str());
		
		cout<<"Ingrese Grado: ";cin>>estudiante.grado;
		cin.ignore();
		
		cout<<"Ingrese Telefono: ";cin>>estudiante.telefono;
		cin.ignore();
		
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;
		
		cout<<"Desea Ingresar Otro Registro (s/n):";cin>>continuar;
		
	
	}while(continuar=='s');
	fclose(archivo);
}

