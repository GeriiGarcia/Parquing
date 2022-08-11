#include "Parquing.h"

int main()
{

    


    return 0;
}


/* 

Es un programa para controlar quien entra y sale del parquing y si se puede entrar o no.
Si el parquing esta lleno, no se puede entrar.

El parquing dipsone de 1000 plazas, 700 para Turismos, 100 para motos, 50 para vehiculos de familias numerosas, 100 para vehiculos grandes y 50 Son reservados para personal.

Un Vehiculo de familia numerosa (VFN) puede entrar en las plazas para turismos, pero al contrario no.
Los Vehiculos Grandes solo pueden entrar en sus plazas.
Los Vechiculos reservados tienen un codigo de acceso que se le preguntara para dejarlo entrar, son plazas exclusivas, no tiene coste.

El parquing tiene un coste de 0,50€/h para las plazas que no esten reservadas y un coste fijo de entrada de 1€. 
Al entrar se pondra la matricula (o codigo en caso de ser reservado), a partir de la hora de entrada a la salida se cobrará con la hora de salida.
Al entrar se pondrá qué tipo de vehiculo eres y se responderá si hay plazas libres para ti y cuantas.

Al salir se pondra la matricula y se respondera con el precio a pagar en relacion al tiempo aparcado.

-----------------------------------------------------------------------------------------------------------------------------------------------------

Qué necesito?

Class Parquing
{
    tiempo
    vector Plazas[1000];
}

Class Plazas
{
    Vehiculo
    Tipo de Plaza  (hacer type def)
    
    //puedo saber si esta ocupado si el tipo de vehiculo es NULL
}

Class Vehiculo
{
    Tipo   (hacer type def)
    Matricula
}










*/ 