#include <iostream>
#include "ServiceJob.h"

using namespace std;

ServiceJob::ServiceJob()
{
    this -> Time = 0;
    this -> RepairType = None;
}

ServiceJob::ServiceJob ( double newTime, Repair newRepairType )
{
    Time = newTime;
    RepairType = newRepairType;
}

double ServiceJob::GetServiceJobPrice(const ServiceJob& object)
{
	return
	this -> getRepairType() * this -> getTime();
}


char* returnRepairType (Repair RepairT)
{
	switch(RepairT)
	{
	case Engine:
	    return "Engine";
	    break;
	case Maintenance:
	     return "Maintenance";
	     break;
	case Suspension:
	     return "Suspension";
	     break;
	default:
    return "Ни нам, не е дадено :)))";
    break;
	}
}



double ServiceJob::getTime()
{
    return Time;
}
void ServiceJob::setTime(double newTime)
{
    Time = newTime;
}


Repair ServiceJob::getRepairType()
{
    return RepairType;
}
void ServiceJob::setRepairType(Repair newRepairType)
{
    RepairType=newRepairType;
}



