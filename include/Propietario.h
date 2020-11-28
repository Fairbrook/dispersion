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

#include <string> //incluyo la libreria string

class propietario //clase propietario
{
public:
    propietario();                                                   //declaracion de construnctor
    propietario(const std::string &);                                //constructor toma una cadena y la divide de manera que se asigne informacion a cada dato de propietario
    propietario(std::string, std::string, std::string, std::string); //recibe una cadena por cada dato de propietario para ser asignado
    ~propietario();                                                  //destructor

    void setPlaca(std::string);     //asigna valor al atributo placa
    void setNombre(std::string);    //asigna valor al atributo nombre
    void setDomicilio(std::string); //asigna valor al atributo domicilio
    void setProvincia(std::string); //asigna valor al atributo provincia

    std::string getPlaca();     //retorna valor de atributo placa como una cadena
    std::string getNombre();    //retorna valor de atributo nombre
    std::string getDomicilio(); //retorna valor de atributo domicilio
    std::string getProvincia(); //retorna valor de atributo provincia
    char *getCharPlaca();       //retorna valor de atributo placa como un arreglo de caracteres

private:
    char placa[12];     //atributo que almacena el valor de place
    char nombre[30];    //atributro que almcacen a el nombre del propietario
    char domicilio[20]; //atributo que almacena el domicilio del propietario
    char provincia[20]; //atributo que almacena la provincia del propietario
};

#endif