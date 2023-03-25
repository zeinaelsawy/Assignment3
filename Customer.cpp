#include "Customer.hpp"
using namespace std;

void Customer::setMechanicID(int id) 
{
    mechanicID = id;
}

void Customer::setAppointment(int hour, int minute) 
{
    appointmentSlot.hours = hour;
    appointmentSlot.minute = minute;
}

int Customer::getMechanicID() 
{
    return mechanicID;
}

int Customer::getAppointmentHour() 
{
    return appointmentSlot.hours;
}

int Customer::getAppointmentMinute() 
{
    return appointmentSlot.minute;
}

bool Customer::operator==(Customer& other) 
{
    if (appointmentSlot.hours == other.getAppointmentHour() || appointmentSlot.minute == other.getAppointmentMinute()) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool Customer::operator>(Customer& other) 
{
    if (appointmentSlot.hours > other.getAppointmentHour() || appointmentSlot.minute > other.getAppointmentMinute()) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool Customer::operator<(Customer& other) 
{
    if (appointmentSlot.hours < other.getAppointmentHour() || appointmentSlot.minute < other.getAppointmentMinute()) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}
