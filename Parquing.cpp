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

bool Parquing::ocuparPlaza(TipoV ve, string mat)
{
    bool encontrado = false;
    
    int i = 0;

    while (encontrado == false)
    {
        if(plazas->at(i).esIgual(ve) == true)
        {
            if(plazas->at(i).getVehiculo().getMatricula()=="")
            {
                //ocupamos la plaza
                encontrado = true;
                Vehiculo v(mat,ve);
                plazas->at(i).setVehiculo(v);

                //actualizamos el tiempo y se lo asignamos a la plaza
                setTime();
                plazas->at(i).setTiempo(tiempo);
            }
        }
        i++;
    }
    return encontrado;   
}


bool Parquing::desocuparPlaza(string mat, int &tiempoTotal)
{
    bool desocupado = false;
    int i=0;

    while (desocupado == false)
    {
        if(plazas->at(i).getVehiculo().getMatricula() == mat)
        {
            //desocupamos plaza
            desocupado = true;
            plazas->at(i).getVehiculo().setMatricula("");
            plazas->at(i).getVehiculo().setTipoV(Vacio);

            //cogemos el tiempo actual y se lo restamos al tiempo de entrada de la plaza y lo devolvemos por referencia
            time_t salida = time(NULL);
            setTime();
            tiempoTotal = salida - plazas->at(i).getTiempoP();
            
        }
        i++;
    }

    return desocupado;
}
