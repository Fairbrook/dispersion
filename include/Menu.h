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
#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <array>
#include "FileManager.hpp"
#include "Propietario.h"
#define INPUT_FILE "AUTOS_PRO.txt"
#define DISPERSION_FILE "DISPERSION_PRO.txt"
#define FREQUENCIES_FILE "FREQUENCIES_PRO.txt"
class Menu
{
private:
    FileManager fileManager; // objeto de file manager
    propietario propietarioObj; // objeto de propietario

public:
    Menu();
    void startMenu(); // Funcion de menu
};

#endif