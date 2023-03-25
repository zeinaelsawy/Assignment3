#ifndef MECHANIC_HPP
#define MECHANIC_HPP

#include <iostream>
#include "Person.hpp"
using namespace std;

class Mechanic : public Person 
{
    private:
    int counter = 0;
    Appointment array[5];
    
    public:
    bool isAvailable(int hour, int min);
    void incrementCounter();
    void setAppointment(int hour, int min);
    int getCounter();
    int getHours(int index);
    int getMins(int index);
};

#endif /* MECHANIC_HPP */