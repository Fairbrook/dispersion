#include "Propietario.h"

using namespace std;

propietario::propietario() {}

propietario::propietario(string pl, string n, string dom, string pr)
{
    setPlaca(pl);
    setNombre(n);
    setDomicilio(dom);
}

propietario::propietario(const std::string &all)
{
    int i(all.find('|', 0));
    int j(0);

    string pl = all.substr(j, i - j);
    j = i + 1;
    i = (all.find('|', i));
    string n = all.substr(j, i - j);
    j = i + 1;
    i = (all.find('|', i));
    string dom = all.substr(j, i - j);
    j = i + 1;
    i = (all.find('|', i));
    string pr = all.substr(j, i - j);

    setPlaca(pl);
    setNombre(n);
    setDomicilio(dom);
    setProvincia(pr);
}

propietario::~propietario() {}

void propietario::setPlaca(string pl)
{
    int len(pl.length());
    int i(0);
    while (i < 10)
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
    placa[i] = '\0';
}

void propietario::setNombre(string n)
{
    int len(n.length());
    int i;
    for (i = 0; i < len; i++)
    {
        this->nombre[i] = n[i];
    }
    nombre[i] = '\0';
}

void propietario::setDomicilio(string dom)
{
    int len(dom.length());
    int i;
    for (i = 0; i < len; i++)
    {
        this->domicilio[i] = dom[i];
    }
    domicilio[i] = '\0';
}

void propietario::setProvincia(string pr)
{
    int len(pr.length());
    int i;
    for (i = 0; i < len; i++)
    {
        this->provincia[i] = pr[i];
    }
    provincia[i] = '\0';
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

char *propietario::getCharPlaca()
{
    return this->placa;
}