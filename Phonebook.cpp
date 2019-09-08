#include "Phonebook.h"
#include <sstream>
#include <fstream>

Phonebook::Phonebook(const int _size) : size(_size), numContacts(0)
{
    contacts = new GenericContact *[size];                           //an array of pointers
    for (int i = 0; i < size; i++)
        contacts[i] = nullptr;
}

Phonebook::Phonebook(const Phonebook &origOBJ) : size(origOBJ.size), numContacts(origOBJ.numContacts)
{

    contacts = new GenericContact *[size];
    for (int i = 0; i < size; i++)
        contacts[i] = nullptr;
    for (int i = 0; i < size; i++)
    {
        if (origOBJ.contacts[i] != nullptr)
        {
            if (origOBJ.contacts[i]->getType() == "B")
            {
                BusinessContact temp = *((BusinessContact *)origOBJ.contacts[i]);    //assign RHS obj's content to the temporary obj
                contacts[i] = new BusinessContact;                                   //allocate new momory for the pointer contacts[i]
                *((BusinessContact *)contacts[i]) = temp;                            //assign temporary obj's content to the new memory
            }
            else
            {
                PersonalContact temp = *((PersonalContact *)origOBJ.contacts[i]);
                contacts[i] = new PersonalContact;
                *((PersonalContact *)contacts[i]) = temp;
            }
        }
    }
}

const Phonebook &Phonebook::operator=(const Phonebook &ObjToCopy)
{
    if (this != &ObjToCopy)
    {
        for (int i = 0; i < size; i++)
        {
            if (contacts[i] != nullptr)
            {
                delete contacts[i];
                contacts[i] = nullptr;
            }
        }
        delete[] contacts;
        contacts = nullptr;
        size = ObjToCopy.size;
        numContacts = ObjToCopy.numContacts;
        contacts = new GenericContact *[size];
        for (int i = 0; i < size; i++)
            contacts[i] = nullptr;
        for (int i = 0; i < size; i++)
        {
            if (ObjToCopy.contacts[i] != nullptr)
            {
                if (ObjToCopy.contacts[i]->getType() == "B")
                {
                    BusinessContact temp = *((BusinessContact *)ObjToCopy.contacts[i]);
                    contacts[i] = new BusinessContact;
                    *((BusinessContact *)contacts[i]) = temp;
                }
                else
                {
                    PersonalContact temp = *((PersonalContact *)ObjToCopy.contacts[i]);
                    contacts[i] = new PersonalContact;
                    *((PersonalContact *)contacts[i]) = temp;
                }
            }
        }
    }
    return *this;
}


// Write the implementation of the finAvailable Position helper function here
int Phonebook::findAvailablePosition() {
    int count = 0;
    int value = 0;

    for (int i = 0; i < size; i++) {
        if (contacts[i] == nullptr) {
            value = i;
            break;
        }
        else {
            count++;
        } 
    }

    if (count == size) {
        value = -1;
    }

    return value;
}



// Write the implementation of the finContactPosition helper function here
int Phonebook::findContactPosition(const string &_phoneNumber) {
    int count = 0;
    int value = 0;

    for (int i = 0; i < size; i++) {
        if (contacts[i] != nullptr && contacts[i]->getPhoneNumber() == _phoneNumber) {
            value = i;
            break;
        }
        else if (contacts[i] == nullptr || contacts[i]->getPhoneNumber() != _phoneNumber) {
            count++;
        }
    }

    if (count == size) {
        value = -1;
    }

    return value;
    
}

bool Phonebook::addContact(const string &type, const string &contactInformation) {
// Write the implementation of the addContact method here
// print the following message if the phonebook is full
// cout << "Cannot add the personal contact. The phonebook is full" << endl;
// Hint: use the findAvailablePosition helper function

    string bname, city, fname, lname, dob, email, phoneNum;
    bool value;
    int idx = findAvailablePosition(); 

    if (type == "P") {

        if (idx == -1) {
            cout << "Cannot add the personal contact. The phonebook is full" << endl;
            value = false;
        }

        else {
            stringstream mySStream(contactInformation);
            mySStream >> fname >> lname >> dob >> email >> phoneNum;
            PersonalContact temp(fname, lname, dob, email, phoneNum);
            contacts[idx] = new PersonalContact;
            *((PersonalContact *)contacts[idx]) = temp;
            numContacts++;
            value = true;
        }

    }

    else if (type == "B") {

        if (idx == -1) {
            cout << "Cannot add the business contact. The phonebook is full" << endl;
            value = false;
        }

        else {
            stringstream mySStream(contactInformation);
            mySStream >> bname >> city >> email >> phoneNum;
            BusinessContact temp(bname, city, email, phoneNum);
            contacts[idx] = new BusinessContact;
            *((BusinessContact *)contacts[idx]) = temp;
            numContacts++;
            value = true;
        }
    }

    return value;
   
}

bool Phonebook::deleteContact(const string &_phoneNumber) {
    // Write the implementation of the deleteContact method here
    // print the following message if no contact was found
    // cout << "Cannot find the phone number in the phonebook" << endl;
    // Hint: use the findContactPosition helper function

    bool value;
    int idx = findContactPosition(_phoneNumber);

    if (idx != -1) {
        value = true; 
        contacts[idx] = nullptr;
        numContacts--;
        
    }

    else {
        cout << "Cannot find the phone number in the phonebook" << endl;
        value = false;
    }

    
    return value;
}

void Phonebook::print() const {
    // Write the implementation of the print method here
    // Show the following message before printing the contacts' information
    cout << "Contacts: " << endl;

    for (int i = 0; i < size; i++) {

        if(contacts[i] != nullptr && contacts[i]->getType() == "B") {
            cout << "Name: " << ((BusinessContact *)contacts[i])->getBName() << ", City: " << ((BusinessContact *)contacts[i])->getCity() << ", Email: " << ((BusinessContact *)contacts[i])->getEmail() << ", Phone number: " << ((BusinessContact *)contacts[i])->getPhoneNumber() << endl;
        }

        else if (contacts[i] != nullptr && contacts[i]->getType() == "P") {
            cout << "Firstname: " << ((PersonalContact *)contacts[i])->getFName() << ", Lastname: " << ((PersonalContact *)contacts[i])->getLName() << ", DOB: " << ((PersonalContact *)contacts[i])->getDOB() << ", Email: " << ((PersonalContact *)contacts[i])->getEmail() << ", Phone number: " << ((PersonalContact *)contacts[i])->getPhoneNumber() << endl;
        }
    }

}

bool Phonebook::readFromFile(const string &filename) {
    // Write the implementation of the readFromFile method here

    string initial, bname, city, fname, lname, dob, email, phoneNum;
    bool value;
    int idx = 0;

    ifstream inFile;

    inFile.open(filename);

    if (!inFile.is_open()) {
        value = false;
    }

    else {
        value = true;

        do {
            idx = findAvailablePosition(); 

            inFile >> initial;

            if (initial == "P") {
                if (idx != -1) {
                    inFile >> fname >> lname >> dob >> email >> phoneNum;
                    PersonalContact temp(fname, lname, dob, email, phoneNum);
                    contacts[idx] = new PersonalContact;
                    *((PersonalContact *)contacts[idx]) = temp;
                    numContacts++;
                }
            }

            else {
                if (idx != -1) {
                    inFile >> bname >> city >> email >> phoneNum;
                    BusinessContact temp(bname, city, email, phoneNum);
                    contacts[idx] = new BusinessContact;
                    *((BusinessContact *)contacts[idx]) = temp;
                    numContacts++;
                }
            }

        }while(!inFile.eof());
    }

    inFile.close();

    return value;
}

bool Phonebook::operator==(const Phonebook &RHS) {
    // Write the implementation of the overloaded == operator here
    bool value;

    if (this->size == RHS.size && this->numContacts == RHS.numContacts) {

        for (int i = 0; i < numContacts; i++) {

            if (this->contacts[i]->getType() == RHS.contacts[i]->getType()) {

                if (this->contacts[i]->getType() == "B") {

                    if (*((BusinessContact *)contacts[i]) != *((BusinessContact *)RHS.contacts[i])) {
                        value = false;
                        break;
                    }
                    else {
                        value = true;
                    }
                }

                else if (this->contacts[i]->getType() == "P") {

                    if (*((PersonalContact *)contacts[i]) != *((PersonalContact *)RHS.contacts[i])) {
                        value = false;
                        break;
                    }
                    else {
                        value = true;
                    }
                }

            }

            else {
                value = false;
                break;
            }
        }
    }

    else {
        value = false;
    }
   

   return value;
}

Phonebook::~Phonebook() {
    // Write the implementation of the destructor here

    delete[] contacts;

}