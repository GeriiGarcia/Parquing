#include "Plazas.h"

class Parquing
{
public:
    Parquing();
    time_t getTiempo() {return tiempo;}

    Plazas getPlaza(int num) {return plazas->at(num);}
    void ocuparPlaza();
    

private:
    vector<Plazas> plazas[1000];
    time_t tiempo;   

};



