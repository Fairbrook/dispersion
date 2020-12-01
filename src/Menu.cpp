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
#include "Menu.h"

using namespace std;

Menu::Menu() {}
void Menu::startMenu()
{
    fileManager.readFile(INPUT_FILE); // lee el archivo de AUTOS_PRO
    std::array<propietario*, 100> resultado; // array de tipo propietario
    std::array<short, 100> frecuencias; // array del tipo short
    int opc = 0; // variable de control de menu
    while (opc != 4) // while sale cuando opc = 4
    {
        cout << "1- Ejecutar la función de dispersion" << endl; // esto es un cout
        cout << "2- Mostrar los resultados de la función" << endl; // esto es un cout
        cout << "3- Mostrar el numero de frecuencias" << endl; // esto es un cout
        cout << "4- Salir" << endl;
        cin >> opc; // lee opc
        switch (opc) // switch de opc
        {
        case 1:
            fileManager.applyDispersion(); // corre la funcion de dispersion
            break;

        case 2:
            resultado = fileManager.getDirections(); // obtiene los objetos de dispersion
           for (int i = 0; i < resultado.size(); i++) // for para mostrar los objetos de dispersion
           { 
                cout<< i << " " << endl; // esto es un cout
               if(resultado[i] != nullptr){ // si el resultado no es null mostrara la informacion
                    cout<< resultado[i]->getPlaca() << endl; // muestra placa
                    cout<< resultado[i]->getNombre() << endl; // muestra nombre
                    cout<< resultado[i]->getDomicilio() << endl; // muestra domicilio
                    cout<< resultado[i]->getProvincia() << endl; // mustra provincia
               }
                cout<< "-----------------------"<< endl; // separador
           }
           fileManager.saveFile(DISPERSION_FILE); // guarda los datos de dispersion en DISPERSION_PRO.txt
            break;

        case 3:
            frecuencias = fileManager.getFrequency(); // corre la funcion de frecuencias
            for (int i = 0; i < frecuencias.size(); i++) // for para mostrar las frecuencias
           { 
                cout<< i << " (" << frecuencias[i]<< ")" <<endl; // Mustra el id y la frecuencia
           }
            fileManager.saveFrequencyToFile(FREQUENCIES_FILE); // guarda los datos de frecuencia en FREQUENCIES_PRO.txt
            break;

        default:
            break;
        }
    }
}