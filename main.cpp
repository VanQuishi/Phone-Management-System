#include "Phonebook.h"

int main()
{
    string phoneNum = "777-777-7770";
    string type = "B";
    string info = "Business2 City2 bemail2@email.com 777-777-7770";
    Phonebook myPhonebook(10);
    myPhonebook.readFromFile("input.txt");
    //myPhonebook.print();
    
    //myPhonebook.addContact(type, info);
    //myPhonebook.deleteContact(phoneNum);
    myPhonebook.print();

    Phonebook myOtherPhonebook = myPhonebook;
    myOtherPhonebook.print();

    Phonebook my2Phonebook(9);
    my2Phonebook = myPhonebook;
    my2Phonebook.print();
    return 0;
}