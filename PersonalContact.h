#ifndef PERCONTACT_H
#define PERCONTACT_H

#include <iostream>
#include <string>
#include "GenericContact.h"

using namespace std;

class PersonalContact : public GenericContact
{
private:
    string fname;
    string lname;
    string dob;

public:
    PersonalContact();
    PersonalContact(const string &_fname, const string &_lname, const string &_dob, const string &_email, const string &_phoneNumber);
    string getFName();
    string getLName();
    string getDOB();
    void setFName(const string &_fname);
    void setLName(const string &_lname);
    void setDOB(const string &_dob);
    void print() const;
    bool operator!=(const GenericContact &contact);  
};

#endif