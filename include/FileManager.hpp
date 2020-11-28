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
#ifndef FILE_MANAGER_INCLUDE_H
#define FILE_MANAGER_INCLUDE_H

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <fstream>
#include "Propietario.h"
//Declaración de la clase para el manejo de los archivos
class FileManager
{
private:
    // Declaracion del array para guardar las direcciones
    std::array<propietario*, 100> directions;
    // Declaracion del array para guardar los registro obtenidos del archivo
    std::vector<propietario> registries;
    // Declaracion del array para guardar la frecuencia de las direcciones
    std::array<short, 100> frequency;
    // Declaración de la función para realizar las dipersion de folk
    int dispersionFolk(char *);

public:
    //Constructor
    FileManager();
    //Funcion para leer el archivo y almacenar sus registros
    bool readFile(const std::string &);
    //Aplica la función de dispersion a todos los registros leidos
    bool applyDispersion();
    //Guarda el arreglo de direcciones en el archivo
    bool saveFile(const std::string &);
    //Guarda el arreglo de frecuencia en el archivo
    bool saveFrequencyToFile(const std::string &);
    //devuelve el arreglo de direcciones
    std::array<propietario*, 100> getDirections() const { return directions; }
    //devuelve el arreglo de registros
    std::vector<propietario> getResgistries() const { return registries; }
    //devuelve el arreglo de frecuencias
    std::array<short, 100> getFrequency() const { return frequency; }
};

#endif