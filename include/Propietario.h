#ifndef PROPIETARIO_H
#define PROPIETARIO_H

#include <string>;

class propietario
{
public:
    propietario();
    propietario(std::string, std::string, std::string, std::string);
    ~propietario();

    void setPlaca(std::string);
    void setNombre(std::string);
    void setDomicilio(std::string);
    void setProvincia(std::string);

    std::string getPlaca();
    std::string getNombre();
    std::string getDomicilio();
    std::string getProvincia();

private:
    char placa[12];
    char nombre[30];
    char domicilio[20];
    char provincia[20];
};

#endif