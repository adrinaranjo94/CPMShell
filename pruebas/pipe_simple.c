#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int tuberia[2];	//Descriptor de la tubería
	//tuberia[0] descriptor de lectura
	//tuberia[1] descriptor de escritura
	int bytesleidos;

	char mensaje1[101] = "Mensaje a transmitir";
	int mensaje2 = 17;

	pipe(tuberia);//Crea la tuberia

	if (fork() == 0) {
		//Soy el proceso hijo
		close(tuberia[0]); //Cierro tubería de lectura
        write(tuberia[1], mensaje1, sizeof(mensaje1));
		write(tuberia[1], &mensaje2, sizeof(mensaje2));
		close(tuberia[1]);
	} else {
		//Soy el proceso padre
		close(tuberia[1]);
		bytesleidos = read (tuberia[0], &mensaje1, sizeof(mensaje1));
		printf ("Bytes leidos: %d\n", bytesleidos);
		printf ("Mensaje: %s\n", mensaje1);
		bytesleidos = read (tuberia[0], &mensaje2, sizeof(mensaje2));
		printf ("Bytes leidos: %d\n", bytesleidos);
		printf ("Mensaje: %d\n", mensaje2);
		close (tuberia[0]);
	}
}
