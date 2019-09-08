#include "PersonalContact.h"
#include <string.h>

PersonalContact::PersonalContact() : GenericContact(), fname(""), lname(""), dob("")
{
}

PersonalContact::PersonalContact(const string &_fname, const string &_lname, const string &_dob, const string &_email, const string &_phoneNumber) : GenericContact("P", _email, _phoneNumber), fname(_fname), lname(_lname), dob(_dob)
{
}

string PersonalContact::getFName()
{
    return fname;
}

string PersonalContact::getLName()
{
    return lname;
}

string PersonalContact::getDOB()
{
    return dob;
}

void PersonalContact::setFName(const string &_fname)
{
    fname = _fname;
}

void PersonalContact::setLName(const string &_lname)
{
    lname = _lname;
}

void PersonalContact::setDOB(const string &_dob)
{
    dob = _dob;
}

void PersonalContact::print() const
{
    cout << "Firstname: " << fname << ", Lastname: " << lname << ", DOB: " << dob << " ";
    GenericContact::print();
}

// Write the implementation of the overloaded operator != here

bool PersonalContact::operator!=(const GenericContact &contact) { 
      
    if (fname != ((PersonalContact&)contact).getFName() || lname != ((PersonalContact&)contact).getLName() || dob != ((PersonalContact&)contact).getDOB() || this->getType() != ((PersonalContact&)contact).getType() || this->getEmail() != ((PersonalContact&)contact).getEmail() || this->getPhoneNumber() != ((PersonalContact&)contact).getPhoneNumber()) {
        return true;
    }

    else {
        return false;
    }
}
//fname != ((PersonalContact&)contact).getFname()