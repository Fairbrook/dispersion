#include "Menu.h"

using namespace std;

Menu::Menu() {}
void Menu::startMenu()
{
    int opc = 0;
    while (opc != 4)
    {
        cout << "1- Ejecutar la función de dispersión" << endl;
        cout << "2- Mostrar los resultados de la función" << endl;
        cout << "3- Mostrar el número de frecuencias" << endl;
        cout << "4- Salir" << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            fileManager.readFile(INPUT_FILE);
            fileManager.applyDispersion();
            break;

        case 2:
            break;

        case 3:
            break;

        default:
            break;
        }
    }
}