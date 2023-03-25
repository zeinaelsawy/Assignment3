#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>
using namespace std;

class Person 
{
    private:
    string name;
    int id;
    int age;
    
    public:
    Person();
    void setName(string name);
    void setID(int id);
    void setAge(int age);
    string getName();
    int getID();
    int getAge();
    
    struct Appointment 
    {
        int hours;
        int minute;
    };
    
    virtual void printInfo(); 
};

#endif /* PERSON_HPP */