#include "Plazas.h"

class Parquing
{
public:
    Parquing();
    time_t getTiempo() {return tiempo;}
    

private:
    vector<Plazas> plazas[1000];
    time_t tiempo;   

};



