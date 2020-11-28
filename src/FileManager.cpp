#include "FileManager.hpp"

using namespace std;

bool FileManager::readFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        return false;
    }
    while (file.peek() != EOF)
    {
        string registry;
        getline(file, registry);
        registries.push_back(propietario(registry));
    }
    file.close();
    return true;
}

int FileManager::dispersionFolk(const string &placa)
{
    int res(0);
    for (int i = 0; i < 12; i += 2)
    {
        res = (res + placa.at(i) * 0x100 + placa.at(i + 1)) % 20000;
    }
    res %= 101;
    res %= 100;
}

bool FileManager::applyDispersion()
{
    for (propietario registry : registries)
    {
        directions[dispersionFolk(registry.getPlaca())] = new propietario(registry);
    }
}

bool FileManager::saveFile(const std::string &filename)
{
    ofstream file(filename);
    for (int i{0}; propietario * registry : directions)
    {
        file << i << " ";
        file << registry->getPlaca() << '|';
        file << registry->getNombre() << '|';
        file << registry->getDomicilio() << '|';
        file << registry->getProvincia() << '|\n';
    }
    file.close();
}