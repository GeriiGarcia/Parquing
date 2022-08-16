#include "Plazas.h"

class Parquing
{
public:
    Parquing();
    time_t getTiempo() {return tiempo;}
    Plazas getPlaza(int num) {return plazas->at(num);}

    void setTime() {tiempo = time(NULL);}

    bool ocuparPlaza(TipoV ve, string mat);
    bool desocuparPlaza(string mat, int &tiempoTotal);
    void anadirQuitarPersonal();

    void imprimirPersonal();

   

private:
    vector<Plazas> plazas[1000];
    time_t tiempo;
    string matriculasPersonal[50] = {"1234ABC", "1234AAA", };

};

 


