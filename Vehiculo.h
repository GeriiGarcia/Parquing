#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include "unistd.h"

using namespace std;

enum TipoV
{
    Vacio,
    Turismo,
    Moto,
    VFN,
    VG,
    RP,
};

class Vehiculo
{
public:
    Vehiculo(string m, TipoV t) {matricula = m; tipo = t;};
    Vehiculo() {matricula=""; tipo=Vacio;};

    string getMatricula() {return matricula;}
    TipoV getTipoV() {return tipo;}

    void setMatricula(string m) {matricula = m;}
    void setTipoV(TipoV t) {tipo = t;}

private:
    string matricula;
    TipoV tipo;
};




