#include <stdio.h>
#include <windows.h>
#pragma warning(disable : 4996)
#pragma warning(disable : 6054)

struct Morros {

	char Alumno[50];
	int telefono;

	int estatus;

};

void mostrarlista();
void MeterMorro();
char menu();
void buscador();
//void bucarMorro();

int main() {
	char opc;

	do
	{
		opc = menu();
		switch (opc)
		{
		case 'a':
			MeterMorro();
			break;

		case 'f':
			mostrarlista();
			break;

		default:
			break;
		}
	} while (opc != 'h');

	//system("pause");
}

char menu() {
	char op;
	int z;

	FILE* MENU = fopen("MENU.txt", "r");
	while ((z = fgetc(MENU)) != EOF) { printf("%c", z); }        //sirve para escribir una variable en la consola

	scanf_s(" %c", &op, sizeof(op)); //  soluciona problemas en visual 
	fclose(MENU);
	return op;
}

void MeterMorro() {
	Morros datos; // llamar la estrura en  funciones 
	system("cls");
	printf("�Como se llama la persona que quieres a�adir a la agenda?\n\n");
	scanf_s(" %[^\n]s", &datos.Alumno, sizeof(datos.Alumno));
	printf("�Cual es el telefono \n");
	scanf_s(" %i", &datos.telefono);
	datos.estatus = 1; // bandera en verde  =1

	FILE* lista = fopen("Lista de contactos.alv", "ab");
	fwrite(&datos, sizeof(Morros), 1, lista);
	fclose(lista);
	system("pause");
}

void mostrarlista() {
	system("cls");
	printf("\n\n\t\tContactos guardados\n\n");
	Morros chamacos[20];
	FILE* lalista = fopen("Lista de contactos.alv", "rb");
	int tama�o;
	// printf(" \n nombre : %c \n, direccion: %c \n , edad :%i\n ,movil : %i \n, email : %c\n ",*dato[30].nombre,*dato[30].direccion,dato[30].edad,dato[30].movil,*dato[30].email);
	fseek(lalista, 0, SEEK_END); // e l numero consta la cantidad de datos que nos vamos a mover 
	tama�o = ftell(lalista); // dar tama�o de lista 
	tama�o = tama�o / sizeof(Morros); // dividir cantidad total de carcateres ente el tama�o del arreglo 
	rewind(lalista); // regresar al inicio del archivo 

	printf("%-30s %-30s\n", "Nombre", "Telefono"); //  imprime un espaciado  entre   la cadena y el tex

	for (int i = 0; i < tama�o; i++)
	{
		fread(&chamacos[i], 1, sizeof(Morros), lalista);
		if (chamacos[i].estatus == 1) {
			printf("%-30s", chamacos[i].Alumno);
			printf("%-30i", chamacos[i].telefono);
			printf("\n");
		}

	}
	system("pause");
	system("cls");
	fclose(lalista);
} 

void cambiarStatus() { // bloquear 
	int cuchao = 0;
	char  a[50];
	FILE* lalista = fopen("Lista de contactos.alv", "rb");
	Morros status;

	printf("�que alumno va a bloquear?");
	scanf_s(" %[^\n]s", a, sizeof(a));

	while (!feof(lalista)) {
		fread(&status, sizeof(Morros), 1, lalista);
		if (!strcmp(status.Alumno, a) && status.estatus == 1) {
			printf("%-30s%-30s\n", "Nombre", "Telefono");
			printf("%-30s", status.Alumno);
			printf("%-30i", status.telefono);
			status.estatus = 0;

			int ontoi = ftell(lalista) - sizeof(status);
			fseek(lalista, ontoi, SEEK_SET); //
			fwrite(&status, sizeof(Morros), 1, lalista);

			cuchao++;
			break;
			//123466789
		}
	}
	if (cuchao == 0) {
		printf("\n\nMorro no encontrado\n\n");
	}
	else
	{
		printf("\n\nContacto bloqueado\n\n");
	}

	system("pause");
	system("cls");
	fclose(lalista);
} void buscador() {


	// el se la come 
}

