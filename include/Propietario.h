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
#ifndef PROPIETARIO_H
#define PROPIETARIO_H

#include <string>

class propietario
{
public:
    propietario();
    propietario(const std::string &);
    propietario(std::string, std::string, std::string, std::string);
    ~propietario();

    void setPlaca(std::string);
    void setNombre(std::string);
    void setDomicilio(std::string);
    void setProvincia(std::string);

    std::string getPlaca();
    std::string getNombre();
    std::string getDomicilio();
    std::string getProvincia();
    char *getCharPlaca();

private:
    char placa[12];
    char nombre[30];
    char domicilio[20];
    char provincia[20];
};

#endif