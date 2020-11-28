#include "FileManager.hpp"

using namespace std;

FileManager::FileManager() : directions()
{
    for (int i = 0; i < 100; i++)
    {
        directions[i] = nullptr;
        frequency[i] = 0;
    }
}

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

int FileManager::dispersionFolk(char *placa)
{
    int res(0);
    for (int i = 0; i < 12; i += 2)
    {
        res = (res + placa[i] * 0x100 + placa[i + 1]) % 20000;
    }
    res %= 101;
    res %= 100;
    return res;
}

bool FileManager::applyDispersion()
{
    for (propietario registry : registries)
    {
        int index = dispersionFolk(registry.getCharPlaca());
        if (directions[index] == nullptr)
        {
            directions[index] = new propietario(registry);
        }
        frequency[index] += 1;
    }
    return true;
}

bool FileManager::saveFile(const std::string &filename)
{
    ofstream file(filename);
    int i(0);
    for (propietario *registry : directions)
    {
        file << i << " ";
        if (registry != nullptr)
        {
            file << registry->getPlaca() << '|';
            file << registry->getNombre() << '|';
            file << registry->getDomicilio() << '|';
            file << registry->getProvincia() << "|";
        }
        file << '\n';
        i++;
    }
    file.close();
    return true;
}

bool FileManager::saveFrequencyToFile(const string &filename)
{
    ofstream file(filename);
    int i(0);
    for (short f : frequency)
    {
        file << i << " (" << f << ")\n";
    }
    file.close();
    return true;
}