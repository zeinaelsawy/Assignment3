#include <iostream>
#include <cstring>
#include "Person.hpp"
#include "Customer.hpp"
#include "Mechanic.hpp"
#include "Queue.h"
#include <fstream>
using namespace std;

int main()
{
    Mechanic mechanics[3];
    string name;
    int age;
    int id;
    ifstream file;
    
    file.open("Mechanic.txt");
    while(!file.eof())
    {
        for(int i=0;i<3;i++)
        {
            file >> name;
            file >> age;
            file >> id;
            mechanics[i].setName(name);
            mechanics[i].setAge(age);
            mechanics[i].setID(id);   
        }
    }
    file.close();
    
    Customer customers[5];
    string name2;
    int age2;
    int hour;
    int min;
    ifstream file2;
    
    file2.open("Customer.txt");
    while(!file2.eof())
    {
        for(int r=0;r<5;r++)
        {
            file2 >> name2;
            file2 >> age2;
            file2 >> hour;
            file2 >> min;
            customers[r].setName(name2);
            customers[r].setAge(age2);
            customers[r].setAppointment(hour,min);
        }
    }
    file2.close();
    
    int z=0;
    for(int j=0;j<5;j++)
    {
        if(j>=3)
        {
            if(mechanics[z].isAvailable(customers[j].getAppointmentHour(), customers[j].getAppointmentMinute())==1)
            {
                mechanics[z].setAppointment(customers[j].getAppointmentHour(), customers[j].getAppointmentMinute());
                customers[j].setMechanicID(z);
                z++;
            }
            else
            {
                if(mechanics[z+1].isAvailable(customers[j].getAppointmentHour(), customers[j].getAppointmentMinute())==1)
                {
                    mechanics[z].setAppointment(customers[j].getAppointmentHour(), customers[j].getAppointmentMinute());
                    customers[j].setMechanicID(z+1);
                    z++;
                }
            }       
        }
        else
        {
            if(mechanics[j].isAvailable(customers[j].getAppointmentHour(), customers[j].getAppointmentMinute())==1)
            {
                mechanics[j].setAppointment(customers[j].getAppointmentHour(), customers[j].getAppointmentMinute());
                customers[j].setMechanicID(j);
            }
            else
            {
                cout << "Error- no mechanic available" << customers[j].getName() << endl;
            }
        }
    }
    
    Queue<Customer> customerQueue;
    for(int k=0;k<5;k++)
    {
        Customer temp;
        for(int u=0;u<5;u++)
        {
            if(customers[k] < customers[u])
            {
                temp = customers[k];
                customers[k] = customers[u];
                customers[u] = temp;
            }
        }   
    }
    
    for(int i=0;i<5;i++)
    {
        customerQueue.enqueue(customers[i]);
    }
    
    for(int a=0;a<5;a++)
    {
        Customer temp[5];
        temp[a] = customerQueue.dequeue();
        cout << "Name- " << temp[a].getName() << endl;
        cout<< "Appointment Time- " << temp[a].getAppointmentHour() << ":" << temp[a].getAppointmentMinute() << endl;
        cout<< "Mechanic-" << mechanics[temp[a].getMechanicID()].getName() << endl;
    }
}

    

