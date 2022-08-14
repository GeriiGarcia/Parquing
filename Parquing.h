#include "Plazas.h"

class Parquing
{
public:
    Parquing();
    time_t getTiempo() {return tiempo;}

    Plazas getPlaza(int num) {return plazas->at(num);}
    bool ocuparPlaza(TipoV ve, string mat);
    void setTime() {tiempo = time(NULL);}
    bool desocuparPlaza(string mat, int &tiempoTotal);
   

private:
    vector<Plazas> plazas[1000];
    time_t tiempo;   

};

 


