/**
 * Maestro:
 * Gracela Lara Lopez
 * 
 * Materia:
 * Estructura de DatosII D03
 * 
 * Participantes:
 * Arturo Carrillo Solórzano 218744333
 * Josué Yizreel Jauregui Rodríguez 219293556
 * Kevin Alan Martínez Virgen 219294382
 */

#include "Propietario.h"

using namespace std;

propietario::propietario() {} //constructor vacio

propietario::propietario(string pl, string n, string dom, string pr) //constructor que recibe cadenas para asignar a sus atributos
{
    setPlaca(pl);      //llama a funcion set placa
    setNombre(n);      //llama a funcion set nombre
    setDomicilio(dom); //llama a funcion set domicilio
    setProvincia(pr);  //llama a funcion set provincia
}

propietario::propietario(const std::string &all) //constructor que recibe una cadena que incluye todos los atributos de propietario dividido por un delimitador
{
    int i(all.find('|', 0)); //almacena la locacion en la cadena del primer delimitador
    int j(0);                //variable auxiliar

    string pl = all.substr(j, i - j); //pl es igual a la porsion de la cadena "all" delimitada por 'j' e 'i'
    j = i + 1;                        //actualizamos el valor de j
    i = (all.find('|', j));           //i almacena la locacion en la cadena del segundo delimitador
    string n = all.substr(j, i - j);
    j = i + 1;              //actualizamos el valor de j
    i = (all.find('|', j)); //i almacena la locacion en la cadena del tercer delimitador
    string dom = all.substr(j, i - j);
    j = i + 1;              //actualizamos el valor de j
    i = (all.find('|', j)); //i almacena la locacion en la cadena del cuarto delimitador
    string pr = all.substr(j, i - j);

    setPlaca(pl);      //Esta linea llama la funcion set place
    setNombre(n);      //Esta linea llama la funcion set nombre
    setDomicilio(dom); //Esta linea llama la funcion set domicilio
    setProvincia(pr);  //Esta linea llama la funcion set provincia
}

propietario::~propietario() {}

void propietario::setPlaca(string pl) //asigna el valor de pl a el atributo placa
{
    int len(pl.length()); //len almacena la longitud de la cadena pl
    int i(0);             //inicializa la variable 'i' como 0
    while (i < 11)        //Ciclo se ejecutara hasta que 'i' sea igual o mayor a 11
    {
        if (i >= len) // si i es mayor o igual a la len se ejecutara el siguiente codigo
        {
            this->placa[i] = ' '; //placa en la posicion i sera igual a un espacio
        }
        else //si i es menor a len se ejecutara lo siguient
        {
            this->placa[i] = pl[i]; //placa en la posicion i es igual a pl en la posicion i
        }

        i++; //se incrementa el valor de i en uno
    }
    placa[i] = '\0'; //placa en la posicion 12 sera igual al caracter \0
}

void propietario::setNombre(string n) //Funcion que asigna el valor de de la cadena n  a nombre
{
    int len(n.length());      //len almacena la longitud de la cadena n
    int i;                    //se delcara la variable 'i'
    for (i = 0; i < len; i++) //cicla mientras que 'i' sea menor a len
    {
        this->nombre[i] = n[i]; //asigna el valor de n en la posicion 'i' a nombre en la posicion 'i'
    }
    nombre[i] = '\0'; //nombre en la posicion 12 sera igual al caracter \0
}

//las funciones setDomicilio y setProvincia funcionan de la misma manera que setNombre

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

//Todas las funciones 'get' retornan cadenas de los valores correspondientes

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