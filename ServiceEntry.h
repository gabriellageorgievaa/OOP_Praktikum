#pragma once
#include<string>
#include<iostream>
#include "ServiceJob.h"
#include "String.h"

using namespace std;

enum  Make
{
    Subaru,
    Volkswagen,
    Renault,
    Nissan,
    BMW,
    Type_1
};
enum  ClientType
{
    Private=2,
    Firm=2,
    Pref=3,
    Type_2
};

class ServiceEntry
{
private:
    String Name;
	int ID;
	String CarPlates;
	Make CarMake;
	ClientType Client;
	ServiceJob Repairs;
public:
    ServiceEntry();
	~ServiceEntry();
	ServiceEntry(String Name,int ID,String CarPlates,Make CarMake,ClientType Client,ServiceJob* serviceJobs);

	String getName();
	void setName(String newName);

	int getID();
	void setID(int newID);

	String getCarPlates();
	void setCarPlates(String newCarPlates);

	Make getCarMake();
	void setCarMake(Make newCarMake);

	ClientType getClientType();
	void setClientType(ClientType newClient);

    double GetTotalPrice();
	void Info();

};
