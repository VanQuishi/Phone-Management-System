#ifndef GENCONTACT_H
#define GENCONTACT_H
#include <iostream>
#include <string>
using namespace std;

class GenericContact
{
private:
    string type;
    string email;
    string phoneNumber;

public:
    GenericContact();
    GenericContact(const string &_type, const string &_email, const string &_phoneNumber);
    string getType() const;
    string getEmail() const;
    string getPhoneNumber() const;
    void setType(const string &_type);
    void setEmail(const string &_email);
    void setPhoneNumber(const string &_phoneNumber);
    void print() const;
    virtual bool operator!=(const GenericContact &contact);
};

#endif