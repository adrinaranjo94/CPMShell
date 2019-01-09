#!/bin/bash

echo Introduce tu nombre
read nombre
echo Introduce numero al azar
read num
echo Perfecto, tu nombre y numero han sido guardados al final del fichero

echo -e "$nombre $num\n" >> historial.txt
echo Adios
