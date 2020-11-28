#ifndef FILE_MANAGER_INCLUDE_H
#define FILE_MANAGER_INCLUDE_H

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <fstream>
#include "Propietario.h"

class FileManager
{
private:
    std::array<propietario*, 100> directions;
    std::vector<propietario> registries;
    std::array<short, 100> frequency;
    int dispersionFolk(const std::string &);

public:
    FileManager();
    bool readFile(const std::string &);
    bool applyDispersion();
    bool saveFile(const std::string &);
    bool saveFrequencyToFile(const std::string &);
    std::array<propietario*, 100> getDirections() const { return directions; }
    std::vector<propietario> getResgistries() const { return registries; }
    std::array<short, 100> getFrequency() const { return frequency; }
};

#endif