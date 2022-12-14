#include "Parquing.h"

string capitalizeString(string s)
{
    transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return toupper(c); });
    return s;
}

bool matriculaReal(string m)
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

TipoV intoV(int o)
{
    switch (o)
    {
    case 1:
        return Turismo;
        break;
    case 2: return Moto;
        break;
    case 3: return VFN;
        break;
    case 4: return VG;
        break;
    case 5: return RP;
        break;
    }
    return Vacio;
}

void pago(int tiempo)
{
    int deuda;

    if(tiempo == 0)
        deuda = 0;
    else
    {
        deuda = 1;
        tiempo = tiempo / 3600;
        deuda = deuda + 0.5 * tiempo;
        cout << "Total ha pagar: " << deuda << "." << endl;
    }
        
}

int main()
{

    Parquing P;
    int opcion;
    string matric;
    int tiempoTotal = 0;

    do
    {
        cout << "Hola, Bienvenido al Parquing de Gerard, que quieres hacer?" << endl;
        cout << "1- Entrar al parquing" << endl << "2- Salir del parquing"<<endl << "3- Plazas Libres" << endl << "4- Exit" << endl;

        cin >> opcion;



        while (opcion != 1 && opcion !=2 && opcion !=3 && opcion !=4 && opcion != 5)
        {
            cout << "Opcion no valida" << endl;
            cin >>opcion;
        }

        switch(opcion)
        {
        case 1: 
            cout << "¿Qué tipo de coche eres?" << endl << "1- Turismo" << endl << "2- Motocicleta" << endl;
            cout << "3- Vehiculo Familia Numerosa" << endl << "4- Vehiculo Grande" << endl << "5- Reservado a Personal" << endl;

            int opcionVehiculo;

            cin >> opcionVehiculo;

            while (opcionVehiculo != 1 && opcionVehiculo !=2 && opcionVehiculo !=3 && opcionVehiculo !=4 && opcionVehiculo != 5)
            {
                cout << "Opcion no valida" << endl;
                cin >>opcionVehiculo;
            }

            if(opcionVehiculo == 5)
            {
                cout <<  "Introduce tu codigo de personal: ";
                
                do
                {
                    cin >> matric;
                } while (!P.personal(matric));

            }
            else
            {
                cout << "Perfecto, introduce tu matricula: "; 

                do
                {
                    cin >> matric;
                } while (!matriculaReal(matric));

                matric= capitalizeString(matric);
                
                if(P.ocuparPlaza(intoV(opcionVehiculo),matric))
                    cout << "Hay plazas para ti, adelante." << endl;
                else
                    cout << "No quedan plazas para ti, intentelo de nuevo mas tarde. Gracias." <<endl;
            }

            break;

        case 2:
            cout << "Perfecto, introduce tu matricula: ";
            
            do
            {
                cin >> matric;
            } while (!matriculaReal(matric));

            matric= capitalizeString(matric);

            if(P.desocuparPlaza(matric, tiempoTotal)) 
            {
                pago(tiempoTotal);
                cout << "Muchas gracias por confiar en nosotros, hasta pronto." << endl << endl;
            }
            else
                cout << "Parece que la matricula que has introducido no coincide con ninguna registrada, intentelo de nuevo: ";

            break;

        case 3:
            P.imprimirPlazas();
            break;
        case 5:
            P.anadirQuitarPersonal();

            break;

        }

    } while (opcion !=4);
    
    return 0;
}


/* 

Es un programa para controlar quien entra y sale del parquing y si se puede entrar o no.
Si el parquing esta lleno, no se puede entrar.

El parquing dipsone de 1000 plazas, 700 para Turismos, 100 para motos, 50 para vehiculos de familias numerosas, 100 para vehiculos grandes y 50 Son reservados para personal.

Un Vehiculo de familia numerosa (VFN) puede entrar en las plazas para turismos, pero al contrario no.
Los Vehiculos Grandes solo pueden entrar en sus plazas.
Los Vechiculos reservados tienen un codigo de acceso que se le preguntara para dejarlo entrar, son plazas exclusivas, no tiene coste.

El parquing tiene un coste de 0,50€/h para las plazas que no esten reservadas y un coste fijo de entrada de 1€. 
Al entrar se pondra la matricula (o codigo en caso de ser reservado), a partir de la hora de entrada a la salida se cobrará con la hora de salida.
Al entrar se pondrá qué tipo de vehiculo eres y se responderá si hay plazas libres para ti y cuantas.

Al salir se pondra la matricula y se respondera con el precio a pagar en relacion al tiempo aparcado.

-----------------------------------------------------------------------------------------------------------------------------------------------------

Qué necesito?

Class Parquing
{
    tiempo
    vector Plazas[1000];
}

Class Plazas
{
    Vehiculo
    Tipo de Plaza  (hacer type def)
    
    //puedo saber si esta ocupado si el tipo de vehiculo es NULL
}

Class Vehiculo
{
    Tipo   (hacer type def)
    Matricula
}










*/ 