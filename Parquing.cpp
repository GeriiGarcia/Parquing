#include "Parquing.h"

Parquing::Parquing()
{
    tiempo = time(NULL);
    Vehiculo v;
    Plazas p(v, MotoP);

    for (int i = 0; i < 1000; i++)
    {
        plazas->push_back(p);
    }
    
    for (int i = 0; i < 1000; i++)
    {
        if(i >= 0 && i <=699 )
            plazas->at(i).setTipoP(TurismoP);
        else if(i>=700 && i <= 799)
            plazas->at(i).setTipoP(MotoP);
        else if(i >= 800 && i <= 849)
            plazas->at(i).setTipoP(VFNP);
        else if( i >= 850 && i<= 949)
            plazas->at(i).setTipoP(VGP);
        else
            plazas->at(i).setTipoP(RPP);
    }
    
}

void Parquing::ocuparPlaza(TipoV ve, string mat)
{
    bool encontrado = false;
    
    int i =0;

    while (encontrado == false)
    {
        if(plazas->at(i).esIgual(ve) == true)
        {
            if(plazas->at(i).getVehiculo().getMatricula()=="")
            {
                encontrado = true;
                Vehiculo v(mat,ve);
                plazas->at(i).setVehiculo(v);
                
                //actualizamos el tiempo
                setTime();
                plazas->at(i).setTiempo(tiempo);
            }
            else
            {
                
            }
        }
        i++;
    }
    
}
