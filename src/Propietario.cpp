#include "Propietario.h"

using namespace std;

propietario::propietario() {}
propietario::propietario(string pl, string n, string dom, string pr)
{
    setPlaca(pl);
    setNombre(n);
    setDomicilio(dom);
}
propietario::~propietario() {}

void propietario::setPlaca(string pl)
{
    int len(pl.length());
    int i(0);
    while (i < 12)
    {
        if (i >= len)
        {
            this->placa[i] = ' ';
        }
        else
        {
            this->placa[i] = pl[i];
        }

        i++;
    }
}

void propietario::setNombre(string n)
{
    int len(n.length());
    for (int i = 0; i < len; i++)
    {
        this->nombre[i] = n[i];
    }
}

void propietario::setDomicilio(string dom)
{
    int len(dom.length());
    for (int i = 0; i < len; i++)
    {
        this->domicilio[i] = dom[i];
    }
}

void propietario::setProvincia(string pr)
{
    int len(pr.length());
    for (int i = 0; i < len; i++)
    {
        this->provincia[i] = pr[i];
    }
}

string propietario::getNombre()
{
    string helper(nombre);
    return helper;
}

string propietario::getPlaca()
{
    string helper(placa);
    return helper;
}

string propietario::getDomicilio()
{
    string helper(domicilio);
    return helper;
}

string propietario::getProvincia()
{
    string helper(provincia);
    return helper;
}