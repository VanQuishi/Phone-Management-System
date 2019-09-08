#include "BusinessContact.h"
#include <string.h>

BusinessContact::BusinessContact() : GenericContact(), bName(""), city("")
{
}

BusinessContact::BusinessContact(const string &_bName, const string &_city, const string &_email, const string &_phoneNumber) : GenericContact("B", _email, _phoneNumber), bName(_bName), city(_city)
{
}

string BusinessContact::getBName()
{
    return bName;
}

string BusinessContact::getCity()
{
    return city;
}

void BusinessContact::setBName(const string &_bName)
{
    bName = _bName;
}

void BusinessContact::setCity(const string &_city)
{
    city = _city;
}

void BusinessContact::print() const
{
    cout << "Name: " << bName << ", City: " << city << " ";
    GenericContact::print();
}

// Write the implementation of the overloaded operator != here
bool BusinessContact::operator!=(const GenericContact &contact) {
    if (bName != ((BusinessContact&)contact).getBName() || city != ((BusinessContact&)contact).getCity() || this->getType() != ((BusinessContact&)contact).getType() || this->getEmail() != ((BusinessContact&)contact).getEmail() || this->getPhoneNumber() != ((BusinessContact&)contact).getPhoneNumber()) {
        return true;
    }

    else {
        return false;
    }
}