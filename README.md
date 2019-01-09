# CPM Shell
Proyecto de creación de un terminal en C basandose en CPMShell

PROYECTO REALIZADO POR:

- Adrian Naranjo https://github.com/adrinaranjo94
- Sergio Redondo https://github.com/SergioRedondoMontes
- Carlos Rodriguez https://github.com/carlosRodriguezGonzalez
- Eduardo Lafoz https://github.com/LAFGOD
- Jorge Lopez https://github.com/jlfpg

# Estructuración del proyecto

```
 - A           Directorio A
 - B           Directorio B
 - lib         Directorio de librerias
 - test        Directorio de test y archivos que se han utilizado para pruebas
 - cpmshell    Ejecutable de terminal
```

# Inicialización del proyecto 
* Abrimos un terminal y nos vamos a la carpeta raíz del proyecto.

* Compilamos las librerías con los siguientes comandos
```
gcc -c lib/copy.c -o lib/copy.o
gcc -c lib/dir.c -o lib/dir.o
gcc -c lib/era.c -o lib/era.o
gcc -c lib/ren.c -o lib/ren.o
gcc -c lib/run.c -o lib/run.o
gcc -c lib/type.c -o lib/type.o
```

* Compilamos el terminal
```
gcc -c cpmshell.c -o cpmshell.o
```

* Compilamos el terminal con todas las librerías para obtener el ejecutable
```
gcc cpmshell.o lib/dir.o lib/type.o lib/era.o lib/copy.o lib/ren.o lib/run.o -o cpmshell
```

* Ejecutamos el terminal
```
./cpmshell
```

* Para poder ejecutar un .bat con nuestro terminal
```
./cpmshell archivo.bat
```
