#include "FileManager.hpp"

using namespace std;

//Construccion de file manager
FileManager::FileManager() : directions()
{
    //Ciclo que recorre todas las posiciones del arreglo de direcciones y frecuencias
    for (int i = 0; i < 100; i++)
    {
        //Asigna nulo a la dirección i
        directions[i] = nullptr;
        //Asigna 0 a la frecuencia de la dirección i
        frequency[i] = 0;
    }
}

/**
 * Función para leer el archivo y guardar los registros
 * 
 * Entradas:
 *  @filename: Cadena con el nombre del archivo a leer
 * 
 * Salidas:
 * Devuelve true en caso de leer exitosamente el archivo, 
 * false en caso contrario
 *
 * **/
bool FileManager::readFile(const string &filename)
{
    //Declara el objeto file y lo inicializa, abriendo así el archivo
    ifstream file(filename);
    //Comprueba que el archivo se haya abierto
    if (!file.is_open())
    {
        //Retorna falso si el archivo no se abrió
        return false;
    }
    //Ciclo hasta que el puntero de lectura detecte el final del archivo
    while (file.peek() != EOF)
    {
        //cadena para leer el registro completo
        string registry;
        //lee una linea del archivo y la pone en una cadena
        getline(file, registry);
        //crea un objeto de tipo propietario y lo añade al arreglo de registros leidos
        registries.push_back(propietario(registry));
    }
    //Cierra el archivo
    file.close();
    //Devuelve verdadero en caso de éxito
    return true;
}

/**
 * Función para aplicar la disperción de folk a una placa
 * 
 * Parametros:
 * @placa: Array de caracteres que contienen la placa
 * 
 * Devuleve:
 * La dirección calculada
*/
int FileManager::dispersionFolk(char *placa)
{
    //Inicializa la dirección resultante en 0
    int res(0);
    //Iteración por todos los elementos de la placa
    for (int i = 0; i < 12; i += 2)
    {
        /**
         * Paso 1 del algoritmo de folk
         * Se hace una conversión implicita de char a entero
         * por lo que este paso no se hace explicitamente
         * 
         * Paso 2 del algoritmo de folk
         * 
         * Desglosar:
         *  placa[i] * 100 + placa[i+1]
         * 
         * Sumar:
         * (res + Desglosar) % 20000
        */
        res = (res + placa[i] * 100 + placa[i + 1]) % 20000;
    }

    /**
    * Paso 3 del algoritmo de folk
    * Apliar operacion modulo de 101
    */
    res %= 101;
    //Asegura que la dirección calculada esté dentro del rango de 100 direcciones
    res %= 100;
    return res;
}

//Función para aplicar el algoritmo de dispersion a todos los registros
bool FileManager::applyDispersion()
{
    //Iteración por cada registro
    for (propietario registry : registries)
    {
        //Llamada a la función que devuelve la dirección
        int index = dispersionFolk(registry.getCharPlaca());
        //Determina si la dirección ya esta ocupada
        if (directions[index] == nullptr)
        {
            //Si la dirección está libre, asigna el registro a la dirección
            directions[index] = new propietario(registry);
        }
        //aumenta la frecuencia de esa dirección en uno
        frequency[index] += 1;
    }
    //Devuelve verdadero en caso de éxito
    return true;
}

/**
 * Función para almacenar los registros en un archivo de texto
 * 
 * Entrada:
 * @filename: El nombre del archivo en el que se guardará la infromación
 * 
 * Salida:
 * bool: Verdadero en caso de éxito
*/
bool FileManager::saveFile(const std::string &filename)
{
    //Abre el archivo correspondiente
    ofstream file(filename);
    //Inicializa el indice
    int i(0);
    //Itera entre todas las direcciones
    for (propietario *registry : directions)
    {
        //Guarda el número de direccion en el archivo
        file << i << " ";
        //Comprueba si hay un registro en esa posicion 
        if (registry != nullptr)
        {
            //Guarda la placa en el archivo
            file << registry->getPlaca() << '|';
            //Guarda el nombre en el archivo
            file << registry->getNombre() << '|';
            //Guarda el domicilio en el archivo
            file << registry->getDomicilio() << '|';
            //Guarda la provincia en el archivo
            file << registry->getProvincia() << "|";
        }
        //Añade un enter en el archivo
        file << '\n';
        //incrementa el indice en uno
        i++;
    }
    //cierra el archivo
    file.close();
    //Devuelve verdadero en caso de exito
    return true;
}

/**
 * Guarda la frecuencia en un archivo de texto
 * 
 * Entrada:
 * @filename: Cadena con el nombre del archivo en donde se 
 * almacenarán las frecuencias
 * 
 * Salida:
 * bool: Verdadero en caso de éxito
*/
bool FileManager::saveFrequencyToFile(const string &filename)
{
    //Se abre el archivo correspondiente
    ofstream file(filename);
    //Se inicializa el inidice de direcciones en 0
    int i(0);
    //Iteració por todas las frecuencias almacenadas
    for (short f : frequency)
    {
        //Guarda la frecuencia en el archivo
        file << i << " (" << f << ")\n";
        //Aumentar el indice en uno
        i++;
    }
    //Cierra el archivo
    file.close();
    //Deuvelve verdadero en caso de éxito
    return true;
}