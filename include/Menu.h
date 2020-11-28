#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include "FileManager.hpp"
#define INPUT_FILE "AUTOS_PRO.txt"
class Menu
{
private:
    FileManager fileManager;

public:
    Menu();
    void startMenu();
};

#endif