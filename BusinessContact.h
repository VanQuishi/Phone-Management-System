#ifndef BUSCONTACT_H
#define BUSCONTACT_H

#include <iostream>
#include <string>
#include "GenericContact.h"

using namespace std;

class BusinessContact : public GenericContact
{
private:
    string bName;
    string city;

public:
    BusinessContact();
    BusinessContact(const string &_name, const string &_city, const string &_email, const string &_phoneNumber);
    string getBName();
    string getCity();
    void setBName(const string &_bName);
    void setCity(const string &_city);
    void print() const;
    bool operator!=(const GenericContact &contact);    //create a new variable of this class, do the casting from generic contact to this class onto this new variable, then compare data members
};

#endif