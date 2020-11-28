#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <array>
#include "FileManager.hpp"
#include "Propietario.h"
#define INPUT_FILE "AUTOS_PRO.txt"
#define DISPERSION_FILE "DISPERSION_PRO.txt"
class Menu
{
private:
    FileManager fileManager;
    propietario propietarioObj;

public:
    Menu();
    void startMenu();
};

#endif