#include "GenericContact.h"
#include <string.h>

GenericContact::GenericContact() : type(""), email(""), phoneNumber("")
{
}

GenericContact::GenericContact(const string &_type, const string &_email, const string &_phoneNumber) : type(_type), email(_email), phoneNumber(_phoneNumber)
{
}

string GenericContact::getEmail() const
{
    return email;
}

string GenericContact::getPhoneNumber() const
{
    return phoneNumber;
}

string GenericContact::getType() const
{
    return type;
}

void GenericContact::setType(const string &_type)
{
    type = _type;
}

void GenericContact::setEmail(const string &_email)
{
    email = _email;
}

void GenericContact::setPhoneNumber(const string &_phoneNumber)
{
    phoneNumber = _phoneNumber;
}

void GenericContact::print() const
{
    cout << "Email: " << email << ", Phone number: " << phoneNumber << endl;
}

// Write the implementation of the overloaded operator != here

bool GenericContact::operator!=(const GenericContact &contact) {
    if (this->type != contact.type || this->email != contact.email || this->phoneNumber != contact.phoneNumber) {
        return true;
    }
    else {
        return false;
    }
}

//strcmp(this->type, contact.type) != 0 || strcmp(this->email, contact.email) != 0 || strcmp(this->phoneNumber, contact.phoneNumber) != 0)