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
    Plazas() {tiempoEntrada = 0;};
    Plazas(Vehiculo v, TipoP t) {ve = v; tipo = t;};
    
    void setVehiculo(Vehiculo v) {ve = v;}
    void setTipoP(TipoP t) {tipo = t;}
    void setTiempo(time_t t) {tiempoEntrada = t;}

    Vehiculo getVehiculo() {return ve;}
    TipoP getTipoP() {return tipo;}
    int getTiempoP() {return tiempoEntrada;}

    bool esIgual(const TipoV &v)
    {
        if((tipo == TurismoP && v == Turismo) || (tipo == MotoP && v == Moto) || (tipo == VFNP && v==VFN) || (tipo == VGP && v ==VG) || (tipo == RPP && v == RP) || (tipo == TurismoP && v == VFN))
            return true;
        else 
            return false;
    }

private:
    Vehiculo ve;
    TipoP tipo;
    int tiempoEntrada;
};


