#include "Menu.h"

using namespace std;

Menu::Menu() {}
void Menu::startMenu()
{
    fileManager.readFile(INPUT_FILE);
    std::array<propietario*, 100> resultado;
    int opc = 0;
    while (opc != 4)
    {
        cout << "1- Ejecutar la función de dispersion" << endl;
        cout << "2- Mostrar los resultados de la función" << endl;
        cout << "3- Mostrar el numero de frecuencias" << endl;
        cout << "4- Salir" << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            fileManager.applyDispersion();
            break;

        case 2:
            resultado = fileManager.getDirections();
           for (int i = 0; i < resultado.size(); i++)
           {
                cout<< i << " " << endl;
               if(resultado[i] != nullptr){
                    cout<< resultado[i]->getPlaca() << endl;
                    cout<< resultado[i]->getNombre() << endl;
                    cout<< resultado[i]->getDomicilio() << endl;
                    cout<< resultado[i]->getProvincia() << endl;
               }
           }
           //fileManager.saveFile(DISPERSION_FILE);
            break;

        case 3:
            fileManager.getFrequency();
            break;

        default:
            break;
        }
    }
}