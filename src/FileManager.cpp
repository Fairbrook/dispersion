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