#include <iostream>
#include <string.h>
using namespace std;
const char *nombre_archivo = "archivo.dat";
	int opc;
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
	char eliminar[50];
};
void menu();
void crear();
void leer();
void actualizar();
 void eliminar_estudiante();
main(){
	menu();
	leer();
	crear();
	actualizar();
    eliminar_estudiante();
}
void menu(){
	system("cls");

cout<<"1. Insertar estudiante"<<endl;
cout<<"2. ver estudiantes"<<endl;
cout<<"3. Actualizar estudiante"<<endl;
cout<<"4. eliminar estudiante"<<endl;
cout<<"5. Salir"<<endl<<endl;
cout<<"Digite su opcion: ";
cin>>opc; 

	system("cls");

	switch(opc)
	{
		case 1: crear();		 		;break;
 		case 2: leer();					;break;
 		case 3: actualizar();	 		;break;
 		case 4: eliminar_estudiante();	 		;break;
 		case 5: exit(-1);				;break;  
		default:cout<<"Opcion no valida";  
	}	
}
void leer(){
		system("cls");
		FILE* archivo = fopen(nombre_archivo,"rb");	
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");	
		}
		Estudiante estudiante;
		int id=0;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"____________________________________________"<<endl;
		cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Telefono"<<endl;
		do{
		cout<<"____________________________________________"<<endl;
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;	
		}while(feof(archivo)==0);
		fclose(archivo);
		cout<<endl;
		system("pause");
		menu();
}
void actualizar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	Estudiante estudiante;
	string nombre,apellido;
	cout<<"Ingres el ID que desa Modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
	
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	leer();
}
void crear(){
	char continuar;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	string nombre,apellido;
	do{
		fflush(stdin);
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Dese Agregar otro Estudiante (s/n):";
		cin>>continuar;
	} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);
	leer();
}void eliminar_estudiante(){
	
	FILE* archivo = fopen(nombre_archivo, "r+b");
		char auxi;
		int id;
		string nombre,apellido, nada;	
    	Estudiante estudiante;
    
		cout << "Ingrese el estudiante a eliminar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Estudiante), SEEK_SET );  // esto es lo que permite modificar en la pocision	
	
		cout<<"Ingrese el Codigo:";
		cin>>nada
		;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombres, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos, apellido.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
	fclose(archivo);
		system("PAUSE");
}
