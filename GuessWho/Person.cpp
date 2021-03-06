//
//  PersonData.cpp
//  GuessWho
//
//  Created by Kory Brown on 9/26/14.
//  Copyright (c) 2014 AlphA. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <stdlib.h>
#include "Person.h"
#include "LnkdLst.h"

using namespace std;

string name [] = {"Elena", "Sephiroth", "Haytham", "Peach", "Xion", "Dante", "Ocelot", "Lara",
                   "Luigi", "Rikku", "Adam", "Link", "Samus", "Geralt", "Waluigi", "Shiek",
                   "Connor", "Aerith", "Chloe", "Little Mac", "Lee", "Snake", "Faith",
                   "Dr. Mario"};
string hairColor [] = {"blonde", "white", "brown", "black"};
string eyeColor [] = {"brown", "green" , "blue"};
string facialHairType[] = {"mustache", "beard"};
string gender [] = {"male", "female"};


void CreatePeople(); // creates a txt file that contains specifed list of people from the person class
void DisplayPeople(); // read from text file the list of people and output to console
void AddDataToPerson(); // allows you to select which person you want edit and updates the changes to file
void Prompt(); // Allows to display or add data to a person continuously

Person person;
LnkdLst<Person> people;
const string file = "Person Data";
const int NUM_PEOPLE = 24;

int main()
{
    
//    CreatePeople();
    //DisplayPeople();
    //AddDataToPerson();
    Prompt();
    
    return 0;
}

void Prompt()
{
    //    DisplayPeople();
    bool quit = false;
    int choice = 0;
    while(!quit)
    {
        cout << "1) Add data to a person\n"
        << "2) Display People\n"
        << "3) Quit\n"
        << "choice: ";
        cin  >> choice;
        cout << endl;
        
        switch(choice)
        {
            case 1:
                //system("clear"); // doesnt work in Xcode
                AddDataToPerson();
                break;
            case 2:
                //system("clear"); // doesnt work in Xcode
                DisplayPeople();
                break;
            case 3:
                quit = true;
                break;
        }
    }
    cout << endl;
    exit(1);
}

void GetPeopleData()
{
    fstream personData(file, ios::in | ios::binary); // stream to read data from file.
    if (personData.fail())
    {
        cout << "File failed....\n";
        exit(1);
    }
    personData.read(reinterpret_cast<char *>(&person), // data is read into person class.
                    sizeof(person));
    
    while(!personData.eof())
    {
        people.Append(person);
        
        personData.read(reinterpret_cast<char *>(&person),sizeof(person));
    }
    personData.close();
}
void DisplayPeople()
{
    fstream personData(file, ios::in | ios::binary); // stream to read data from file.
    if (personData.fail())
    {
        cout << "File failed....\n";
        exit(1);
    }
    personData.read(reinterpret_cast<char *>(&person), // data is read into person class.
                    sizeof(person));
    int personCount = 0;
    while(!personData.eof())
    {
        personCount++;
        cout << "Person " << personCount << endl
        << setw(15) << "\n" << person.getName() << ":" << endl;
        cout << setw(20) << "Gender: " << person.getGender() << endl;
        cout << setw(20) << "Eye Color: " << person.getEyeColor() << endl;
        cout << setw(20) << "Hair Color: " << person.getHairColor() << endl;
        cout << setw(20) << "Facial Hair: ";
        if (person.hasFacialHair())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
        cout << setw(20) << "Facial Hair Type: " << person.getFacialHairType() << endl;
        cout << setw(20) << "Hat: ";
        if (person.hasHat())
            cout << "yes" << endl << endl;
        else
            cout << "no" << endl << endl;
        
        personData.read(reinterpret_cast<char *>(&person),sizeof(person));
    }
    personData.close();
}


void CreatePeople()
{
    // creating space in each memeber of the structs.
    person.setName("");
    person.setGender("");
    person.setEyeColor("");
    person.setHairColor("");
    person.setFacialHair(false);
    person.setFacialHairType("");
    person.setHat(false);
    
    fstream personData(file, ios::out | ios::binary); // stream to write data to a file.
    if (personData.fail())
    {
        cout << "File failed....\n";
        exit(1);
    }
    
    for (int i=1; i<=NUM_PEOPLE; i++) // NUM_PEOPLE - can be changed to the desired amount of people we want to describe.
    {
        cout << "Now writing person " << i << endl;
        personData.write(reinterpret_cast<char *>(&person),sizeof(person));
        
    }
    cout << endl;
    personData.close();
}

// Can go through one by one giving a Person's decription by inputting the diesired person you want to provide data with.
void AddDataToPerson()
{
    int i;
    bool correctInput = false;
    
    // Open the file in binary mode for input and output
    fstream personData(file, ios::in | ios::out | ios::binary); // stream to read and write to file.
    if (personData.fail())
    {
        cout << "File failed....\n";
        exit(1);
    }
    do {
        // Get the person number of the desired record.
        cout << "Which person do you want to edit <1-" << NUM_PEOPLE <<">: ";
        cin >> i;
        if (i > 0 && i <= NUM_PEOPLE)
            correctInput = true;
    }while(!correctInput);
    cout << endl;
    
    if (i > 0)
        i--;
//    else if (i == NUM_PEOPLE)
//        i--;
    // Move to the person selected and read it.
    personData.seekg(i * sizeof(person), ios::beg);
    personData.read(reinterpret_cast<char *>(&person),
                    sizeof(person));
    
    // Display the person contents.
    cout << "\nName: " << person.getName() << ":" << endl
    << "Gender: " << person.getGender() << endl
    << "Eye Color: " << person.getEyeColor() << endl
    << "Hair Color: " << person.getHairColor() << endl
    << "Facial Hair: " << person.hasFacialHair() << endl
    << "Facial Hair Type: " << person.getFacialHairType() << endl
    << "Hat: " << person.hasHat() << endl << endl;
    
    
    int selection = 0;
    // Get the new person data.
    char answer = NULL;
    do
    {
        cout << "\nName: " << person.getName() << " Rename<Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y') // change exisiting
        {
            cout << "Person Name: ";
            cin >> selection;
            
            switch (selection)
            {
                case 0:
                    person.setName(name[0]);
                    break;
                case 1:
                     person.setName(name[1]);
                    break;
                case 2:
                    person.setName(name[2]);
                    break;
                case 3:
                    person.setName(name[3]);
                    break;
                case 4:
                    person.setName(name[4]);
                    break;
                case 5:
                    person.setName(name[5]);
                    break;
                case 6:
                    person.setName(name[6]);
                    break;
                case 7:
                    person.setName(name[7]);
                    break;
                case 8:
                    person.setName(name[8]);
                    break;
                case 9:
                    person.setName(name[9]);
                    break;
                case 10:
                    person.setName(name[10]);
                    break;
                case 11:
                    person.setName(name[11]);
                    break;
                case 12:
                    person.setName(name[12]);
                    break;
                case 13:
                    person.setName(name[13]);
                    break;
                case 14:
                    person.setName(name[14]);
                    break;
                case 15:
                    person.setName(name[15]);
                    break;
                case 16:
                    person.setName(name[16]);
                    break;
                case 17:
                    person.setName(name[17]);
                    break;
                case 18:
                    person.setName(name[18]);
                    break;
                case 19:
                    person.setName(name[19]);
                    break;
                case 20:
                    person.setName(name[20]);
                    break;
                case 21:
                    person.setName(name[21]);
                    break;
                case 22:
                    person.setName(name[22]);
                    break;
                case 23:
                    person.setName(name[23]);
                    break;
                    
                default:
                    break;
            }
            correctInput = true;
           
        }
        else if (tolower(answer) == 'n') // leave alone
        {
            correctInput = true;
        }
        else
            correctInput = false;
    }while(!correctInput);
    
    do
    {
        cout << "Gender: " << person.getGender() << " Rename<Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y') // change exisiting
        {
            cout << "Gender: ";
            cin >> selection;
            
            switch (selection)
            {
                case 0:
                    person.setGender(gender[0]);
                    break;
                case 1:
                    person.setGender(gender[1]);
                    break;
                default:
                    break;
            }
            correctInput = true;
        }
        else if (tolower(answer) == 'n') // leave alone
        {
            correctInput = true;
        }
        else
            correctInput = false;
    }while(!correctInput);
    
    do
    {
        cout  << "Hair Color: " << person.getHairColor()  << " Rename<Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y') // change exisiting
        {
            cout << "Hair Color: ";
            cin >> selection;
            
            switch (selection)
            {
                case 0:
                    person.setHairColor(hairColor[0]);
                    break;
                case 1:
                    person.setHairColor(hairColor[1]);
                    break;
                case 2:
                    person.setHairColor(hairColor[2]);
                    break;
                case 3:
                    person.setHairColor(hairColor[3]);
                    break;
                default:
                    break;
            }
            correctInput = true;
        }
        else if (tolower(answer) == 'n') // leave alone
        {
            correctInput = true;
        }
        else
            correctInput = false;
    }while(!correctInput);
    
    do
    {
        cout  << "Eye Color: " << person.getEyeColor()  << " Rename<Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y') // change exisiting
        {
            cout << "Eye Color: ";
            cin >> selection;
            
            switch (selection)
            {
                case 0:
                    person.setEyeColor(eyeColor[0]);
                    break;
                case 1:
                    person.setEyeColor(eyeColor[1]);
                    break;
                case 2:
                    person.setEyeColor(eyeColor[2]);
                    break;

                default:
                    break;
            }
            correctInput = true;
        }
        else if (tolower(answer) == 'n') // leave alone
        {
            correctInput = true;
        }
        else
            correctInput = false;
    }while(!correctInput);
    
    do
    {
        cout << "Facial Hair: " << person.hasFacialHair() << " Change<Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y') // change exisiting
        {
            do
            {
                cout << "Facial Hair <Y or N>: ";
                cin >> answer;
                if ( tolower(answer)== 'y')
                {
                    correctInput = true;
                    person.setFacialHair(true);
                    
                    cout << "Facial Hair Type: ";
                    cin >> selection;
                    
                    switch (selection)
                    {
                        case 0:
                            person.setFacialHairType(facialHairType[0]);
                            break;
                        case 1:
                            person.setFacialHairType(facialHairType[1]);
                            break;
                        default:
                            break;
                    }
                    correctInput = true;
                }
                else if (tolower(answer) == 'n')
                {
                    correctInput = true;
                    person.setFacialHair(false);
                    person.setFacialHairType("none");
                }
                else
                    correctInput = false;
            }while(!correctInput);
        }
        else if (tolower(answer) == 'n') // leave alone
        {
            correctInput = true;
        }
        else
            correctInput = false;
    }while(!correctInput);
    
    do
    {
        cout  << "Hat: " << person.hasHat()  << " Change<Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y') // change exisiting
        {
            do
            {
                cout << "Hat <Y or N>: ";
                cin >> answer;
                if ( tolower(answer)== 'y')
                {
                    correctInput = true;
                    person.setHat(true);
                }
                else if(tolower(answer) == 'n')
                {
                    correctInput = true;
                    person.setHat(false);
                }
                else
                    correctInput = false;
            }while(!correctInput);
        }
        else if (tolower(answer) == 'n') // leave alone
        {
            correctInput = true;
        }
        else
            correctInput = false;
    }while(!correctInput);
    
    cout << endl;
    
    
    
    //     Move back to the beginning of this person's position.
    personData.seekp(i * sizeof(person), ios::beg);
    
    // Write the new person over the current person.
    personData.write(reinterpret_cast<char *>(&person),
                     sizeof(person));
    personData.close();
}

