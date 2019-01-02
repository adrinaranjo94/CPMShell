/* pipe.c - Tubería sin nombre entre procesos padre e hijo */
#include <stdlib.h>
#include <unistd.h>

#define LEER		0
#define ESCRIBIR	1

int main ()
    {
    int descr[2];	/* Descriptores de E y S de la turbería */
    int  bytesleidos;
    char mensaje[100],
	*frase="Veremos si la transferecia es buena.";

    printf ("Ejemplo de tuberÍa entre padre e hijo.\n");
    pipe (descr);
    if (fork () == 0)
       {
            printf("1:     %d\n", getpid()); 
            close (descr[LEER]);
            write (descr[ESCRIBIR], frase, strlen(frase));
            close (descr[ESCRIBIR]);
       }
    else
       {
            printf("1:     %d\n", getpid()); 
            close (descr[ESCRIBIR]);
            bytesleidos = read (descr[LEER], mensaje, 100);
            printf ("Bytes leidos: %d\n");
            printf ("Mensaje: %s\n", bytesleidos, mensaje);
            close (descr[LEER]);
       }
    }