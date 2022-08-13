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
    Plazas();
    Plazas(Vehiculo v, TipoP t) {ve = v; tipo = t;};
    

    void setVehiculo(Vehiculo v) {ve = v;}
    void setTipoP(TipoP t) {tipo = t;}

    Vehiculo getVehiculo() {return ve;}
    TipoP getTipoP() {return tipo;}

private:
    Vehiculo ve;
    TipoP tipo;
};


