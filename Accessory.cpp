#include "Accessory.h"

Accessory::Accessory(std::string name, float coeffSpeed,float coeffRes,float hidingCapacity)
{
    this->name = name;
    this->coeffSpeed = coeffSpeed;
    this->coeffRes = coeffRes;
    this->hidingCapacity = hidingCapacity;
}

Accessory::Accessory(const Accessory & accessory)
{
    this->name = accessory.name;
    this->coeffSpeed = accessory.coeffSpeed;
    this->coeffRes = accessory.coeffRes;
    this->hidingCapacity = accessory.hidingCapacity;
}

Accessory::~Accessory()
{
}
