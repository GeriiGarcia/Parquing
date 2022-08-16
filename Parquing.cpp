#include "Parquing.h"

string capitalizeString(string s);
bool matriculaReal(string m);

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

    for (int i = 0; i < 50; i++)
    {
        matriculasPersonal[i] = "123";
    }
    

    int l = 65;
    char a = l;
    for (int i = 0; i < 50; i++)
    {
        if(i<25)
        {
            a=l;
            matriculasPersonal[i].push_back('4');
            matriculasPersonal[i].push_back(a);
            matriculasPersonal[i].push_back(a);
            matriculasPersonal[i].push_back(a);
            l++;
        }
        else
        {
            a=l;
            if(i==25)
                l =65;
            matriculasPersonal[i].push_back('5');
            matriculasPersonal[i].push_back(a);
            matriculasPersonal[i].push_back(a);
            matriculasPersonal[i].push_back(a);
            l++;
        }
            
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

    while (desocupado == false && i<999)
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


void Parquing::anadirQuitarPersonal()
{
    string antigua, actual;
    bool buscar = false;
    int i = 0;

    do
    {
        i = 0;

        do
        {
            cout << "Introduce matricula a quitar: ";
            cin >> antigua;
        } while (!matriculaReal(antigua));
        
        antigua = capitalizeString(antigua);

        while (buscar == false && i < 50)
        {
            if(antigua == matriculasPersonal[i])
                buscar = true;

            i++;
        }

        if(buscar == false)
            cout << "Error en encontrar la matricula, inténtelo de nuevo." << endl;

    } while (buscar == false);
    
    do
    {
        cout << "Perfecto. Introduce matricula actual: ";
        cin >> actual;
    } while (!matriculaReal(actual));
    

    matriculasPersonal[i-1] = actual;

    cout << "Perfecto. Cambio realizado." << endl;
    
}

void Parquing::imprimirPersonal()
{
    for (int i = 0; i < 50; i++)
    {
        cout << i << " " <<matriculasPersonal[i]<< endl;
    }
    
}
