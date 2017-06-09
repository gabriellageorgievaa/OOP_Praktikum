#pragma once
#include "String.h"
#include <iostream>

using namespace std;

struct Person
{
    String name;
    String address;
    String telNumber;

    friend ostream& operator<<(ostream& os, Person& obj)
    {
        os << "Name: " << obj.name << endl;
        os << "Address: " << obj.address << endl;
        os << "Tel. Number: " << obj.telNumber << endl;
        os << endl;
        return os;
    }
};

enum class typePackage
{
    None,
    Normal,
    Fast,
    Express,
};


class Package
{
private:
    Person sender;
    Person receiver;
    typePackage ePackage;
    int identity;

public:
    Package(Person _sender, Person _receiver, typePackage _ePackage);
    Package(const Package& other);
    Package& operator=(const Package& other);
    ~Package();

    void setSender(const Person& _sender);
    void setReceiver(const Person& _receiver);
    void setTypePackage(typePackage _ePackage);

    void getSender();
    void getReceiver();
    typePackage getTypePackageIdx() const;
    void getTypePackage() const;
    int getIdentity() const;

    virtual void printPackageInfo();

    virtual double getPrice() {}

};
