#include "Parquing.h"

string capitalizeString2(string s)
{
    transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c){ return toupper(c); });
    return s;
}
bool matriculaReal2(string m)
{
     bool real = false;

    string n = m;
    n.pop_back();
    n.pop_back();
    n.pop_back();

    char c = m.back();
    char b = m.back();
    char a = m.back();

    if(m.size() == 7)
    {
        if(isdigit(n.at(0)) && isdigit(n.at(1)) && isdigit(n.at(2)) && isdigit(n.at(3)) && !isdigit(c) && !isdigit(b) && !isdigit(a))
            real = true;
    }

    if(real == false)
        cout << "Matricula no Válida." << endl;

    return real;
}

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
            if(plazas->at(i).getTipoP() == RPP)
            {
                //desocupamos plaza
                desocupado = true;
                Vehiculo v("", Vacio);
                plazas->at(i).setVehiculo(v);
                tiempoTotal = 0;
            }
            else
            {
                //desocupamos plaza
                desocupado = true;
                Vehiculo v("", Vacio);
                plazas->at(i).setVehiculo(v);

                //cogemos el tiempo actual y se lo restamos al tiempo de entrada de la plaza y lo devolvemos por referencia
                time_t salida = time(NULL);
                setTime();
                tiempoTotal = salida - plazas->at(i).getTiempoP();
            }
   
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
        } while (!matriculaReal2(antigua));
        
        antigua = capitalizeString2(antigua);

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
    } while (!matriculaReal2(actual));
    
    actual = capitalizeString2(actual);

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

bool Parquing::personal(string p)
{
    bool trobat = false;
    int i = 0;

    if(matriculaReal2(p))
    {
        p = capitalizeString2(p);
        while(trobat == false && i < 50)
        {
            if(matriculasPersonal[i] == p)
                trobat = true;

            i++;
        }

        if(trobat == false)
            cout << "Vehiculo de Personal no encontrado. Vuelva a intentarlo." << endl;
        else
        {
            ocuparPlaza(RP, p);
        }
    }
    
    return trobat;
}

void Parquing::imprimirPlazas()
{
    int turismo = 0, moto = 0, vfn = 0, vg = 0, rp = 0;

    for (int i = 0; i < 1000; i++)
    {
        if(plazas->at(i).getVehiculo().getTipoV() == Turismo && plazas->at(i).getVehiculo().getMatricula() != "")
            turismo++;
        else if(plazas->at(i).getVehiculo().getTipoV() == Moto && plazas->at(i).getVehiculo().getMatricula() != "")
            moto++;
        else if(plazas->at(i).getVehiculo().getTipoV() == VFN && plazas->at(i).getVehiculo().getMatricula() != "")
            vfn++;
        else if(plazas->at(i).getVehiculo().getTipoV() == VG && plazas->at(i).getVehiculo().getMatricula() != "")
            vg++;
        else if(plazas->at(i).getVehiculo().getTipoV() == RP && plazas->at(i).getVehiculo().getMatricula() != "")
            rp++;

    }

        cout << endl << "Plazas libres:" << endl << "Turismos: " << 700 - turismo << endl;
        cout << "Motocicletas: " << 100 - moto << endl << "Vehiculos Para Familias Numerosas: " << 50 - vfn << endl;
        cout << "Vehiculos Grandes: " <<100 - vg << endl << "Vehiculos Reservados: " << 50 - rp << endl;

    cout << endl;

}
