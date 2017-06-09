#include "Package.h"
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Package::Package(Person _sender, Person _receiver, typePackage _ePackage) : identity(rand()%1000000000)
{
    setSender(_sender);
    setReceiver(_receiver);
    setTypePackage(_ePackage);
    srand(time(NULL));
}

Package::Package(const Package& other)
{
    setSender(other.sender);
    setReceiver(other.receiver);
    setTypePackage(other.ePackage);
}

Package& Package::operator=(const Package& other)
{
    if (this == &other)
        return *this;

    setSender(other.sender);
    setReceiver(other.receiver);
    setTypePackage(other.ePackage);
    return *this;
}

Package::~Package()
{}

void Package::setSender(const Person& _sender)
{
    sender.name = _sender.name;
    sender.address = _sender.address;
    sender.telNumber = _sender.telNumber;
}

void Package::setReceiver(const Person& _receiver)
{
    receiver.name = _receiver.name;
    receiver.address = _receiver.address;
    receiver.telNumber = _receiver.telNumber;
}

void Package::setTypePackage(typePackage _ePackage)
{
    ePackage = _ePackage;
}

void Package::getSender()
{
    cout << "Sender Info:" << endl;
    cout << endl;

    cout << sender;
}

void Package::getReceiver()
{
    cout << "Receiver Info: " << endl;
    cout << endl;

    cout << receiver;
}

typePackage Package::getTypePackageIdx() const
{
    return ePackage;
}

void Package::getTypePackage() const
{
    switch(ePackage)
    {
    case typePackage::None:
        cout << "None" << endl;
        break;
    case typePackage::Normal:
        cout << "Normal" << endl;
        break;
    case typePackage::Fast:
        cout << "Fast" << endl;
        break;
    case typePackage::Express:
        cout << "Express" << endl;
        break;
    default:
        cout << "Error" << endl;
    }
}

int Package::getIdentity() const
{
    return identity;
}

void Package::printPackageInfo()
{
    cout << "ID: " << getIdentity() << endl;
    this->getSender();
    this->getReceiver();
    cout << "Package type: ";
    this->getTypePackage();
}
