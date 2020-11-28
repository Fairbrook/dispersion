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
    const int len(all.length());
    char *str;
    strncpy(str, all.c_str(), len);
    char *token = strtok(str, "|");

    int opc(0);
    while (token != NULL)
    {
        string helper(token);
        switch (opc)
        {
        case 0:
            setPlaca(helper);
            break;
        case 1:
            setNombre(helper);
            break;
        case 2:
            setDomicilio(helper);
            break;
        case 3:
            setProvincia(helper);
            break;
        default:
            break;
        }
        token = strtok(NULL, "|");
        opc++;
    }
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