#include<iostream>
#include "ServiceEntry.h"

using namespace std;



ServiceEntry::ServiceEntry()
{
	Name=String();
	CarPlates=String();
	ID=0;
	CarMake=Type_1;
	Client=Type_2;
}

ServiceEntry::ServiceEntry
(String newName,int newID,String newCarPlates,Make newCarMake,ClientType newClient,ServiceJob* serviceJob)
{
	Name = newName;
	ID = newID;
	CarPlates = newCarPlates;
	CarMake = newCarMake;
	Client = newClient;
}

char* PrintCarBrand(Make Brand)
{
	switch (Brand)
	{
    case Subaru:
	    return "Subaru";
	    break;
	case Volkswagen:
	    return "Volkswagen";
        break;
	case Renault:
	    return "Renault";
        break;
	case Nissan:
	    return "Nissan";
        break;
    case BMW:
       return "BMW";
       break;
	default:
	    return "Ни се знае";
        break;
	}
}

char* PrintClient(ClientType client)
{
	switch(client)
	{
	case Firm:
	    return "Firm client";
	    break;
	case Pref:
	    return "Preferential client";
	    break;
	case Private:
	    return "Private client";
        break;
	default:
	    return "Ни нам";
        break;
	}
}


String ServiceEntry::getName()
{return Name;}
void ServiceEntry::setName(String newName)
{Name = newName;}


int ServiceEntry::getID()
{return ID;}
void ServiceEntry::setID(int newID)
{ID = newID;}


String ServiceEntry::getCarPlates()
{return CarPlates;}
void ServiceEntry::setCarPlates(String newCarPlates)
{CarPlates = newCarPlates;}


Make ServiceEntry::getCarMake()
{return CarMake;}
void ServiceEntry::setCarMake(Make newCarMake)
{CarMake = newCarMake;}


ClientType ServiceEntry::getClientType()
{return Client;}

void ServiceEntry::setClientType(ClientType newClient)
{Client = newClient;}

void ServiceEntry::Info()
{
    cout <<"Name: "<<Name.getStr()<<endl;
    cout << "ID: "<<ID<<endl;
	cout << "Plates: " <<CarPlates.getStr()<<endl;
	cout << "Brand: " << this -> getCarMake()<<endl;
	cout << "Type of client: "<< this -> getClientType()<<endl;
}
