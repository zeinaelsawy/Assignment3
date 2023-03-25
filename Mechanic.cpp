#include "Mechanic.hpp"
using namespace std;

bool Mechanic::isAvailable(int hour, int min)
{
    int available = 1;
    for (int i = 0; i < counter && available == 1; i++) 
    {
        if (array[i].hours == hour && array[i].minute == min) 
        {
            available = 0;
        }
    }
    return available;
}

void Mechanic::incrementCounter()
{
    counter++;
}

void Mechanic::setAppointment(int hour, int min)
{
    array[counter].hours = hour;
    array[counter].minute = min;
    counter++;
}

int Mechanic::getCounter()
{
    return counter;
}

int Mechanic::getHours(int index)
{
    return array[index].hours;
}

int Mechanic::getMins(int index)
{
    return array[index].minute;
}

