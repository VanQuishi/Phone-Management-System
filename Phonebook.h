#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <fstream>
#include <sstream>
#include "BusinessContact.h"
#include "PersonalContact.h"

class Phonebook
{
private:
    GenericContact **contacts = nullptr;     //doublr pointer: a pointer to pointer
    int numContacts;
    int size;
    int findAvailablePosition();
    int findContactPosition(const string &_phoneNumber);

public:
    Phonebook(const int _size);
    Phonebook(const Phonebook &origOBJ);
    const Phonebook &operator=(const Phonebook &ObjToCopy);
    bool addContact(const string &type, const string &contactInformation);      //check the type, then use overloaded of either class to assign the data
    bool deleteContact(const string &_phoneNumber);
    void print() const;
    bool readFromFile(const string &filename);
    bool operator==(const Phonebook &RHS);
    ~Phonebook();
};

#endif