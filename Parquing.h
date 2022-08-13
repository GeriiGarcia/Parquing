#include "Plazas.h"

class Parquing
{
public:
    Parquing();
    time_t getTiempo() {return tiempo;}

    Plazas getPlaza(int num) {return plazas->at(num);}
    void ocuparPlaza(TipoV ve, string mat);
    void setTime() {tiempo = time(NULL);}
   

private:
    vector<Plazas> plazas[1000];
    time_t tiempo;   

};

 bool operator == (TipoP p, TipoV v);



