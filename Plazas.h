#include "Vehiculo.h"


enum TipoP
{
    TurismoP,
    MotoP,
    VFNP,
    VGP,
    RPP,
};

class Plazas
{

public:
    Plazas(Vehiculo v, TipoP t);
    /* ~Plazas();*/

    void setVehiculo(Vehiculo v) {ve = v;}
    void setTipo(TipoP t) {tipo = t;}

    Vehiculo getVehiculo() {return ve;}
    TipoP getTipoP() {return tipo;}

private:
    Vehiculo ve;
    TipoP tipo;
};


