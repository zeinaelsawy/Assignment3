#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <stdio.h>
#include <iostream>
#include "Person.hpp"

using namespace std;

class Customer : public Person 
{
    private:
    int mechanicID;
    Appointment appointmentSlot;
    
    public:
    void setMechanicID(int id);
    void setAppointment(int hour, int minute);
    int getMechanicID();
    int getAppointmentHour();
    int getAppointmentMinute();
    bool operator==(Customer& other);
    bool operator>(Customer& other);
    bool operator<(Customer& other);
};

#endif /* CUSTOMER_HPP */
