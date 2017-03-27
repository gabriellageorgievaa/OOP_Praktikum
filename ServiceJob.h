#pragma once
#include <iostream>
#include <cstring>


enum Repair
{
    None=0,
    Maintenance=10,
    Engine=50,
    Suspension=20
};

struct ServiceJob
{
double Time;
Repair RepairType;

ServiceJob();
ServiceJob( double Time,Repair RepairType );

double GetServiceJobPrice(const ServiceJob& );

double getTime();
void setTime(double Time);


Repair getRepairType();
void setRepairType(Repair RepairType);

};
