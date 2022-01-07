//
//  main.cpp
//  squid_game
//
//  Created by Alexa Iordache on 06.01.2022.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

//folosim INCAPSULAREA - declara private atributele si metodele public (folosim getters
// si setters)
//este o clasa pe care o vom mosteni pentru jucatori si supraveghetori
class PERSON
{
private:
    string last_name;  //nume
    string first_name; //prenume
    string city;
    double debt; //datorie
    int weight;

public:
    void setPerson(string last_name, string first_name, string city, double debt, int weight);

    //getters
    string getLastName();
    string getFirstName();
    string getCity();
    double getDebt();
    int getWeight();

    void displayPerson();
    void displayInFile(fstream &file, int i, int nr, int nr2, int nr3, double debt, int weight, string firstNamesArray[], string lastNamesArray[], string citiesArray[]);
};

void PERSON::setPerson(string last_name, string first_name, string city, double debt, int weight)
{
    this->last_name = last_name;
    this->first_name = first_name;
    this->city = city;
    this->debt = debt;
    this->weight = weight;
}

string PERSON::getLastName()
{
    return this->last_name;
}

string PERSON::getFirstName()
{
    return this->first_name;
}

string PERSON::getCity()
{
    return this->city;
}

double PERSON::getDebt()
{
    return this->debt;
}

int PERSON::getWeight()
{
    return this->weight;
}

void PERSON::displayPerson()
{
    cout << "Last name: " << this->getLastName() << endl;
    cout << "First name: " << this->getFirstName() << endl;
    cout << "City: " << this->getCity() << endl;
    cout << "Debt: " << this->getDebt() << endl;
    cout << "Weight: " << this->getWeight() << endl;
}

void displayInFile(fstream &file, int i, int nr, int nr2, int nr3, double debt, int weight, string firstNamesArray[], string lastNamesArray[], string citiesArray[])
{
    file << i << ". First name: " << firstNamesArray[nr] << endl;
    file << "Last name: " << lastNamesArray[nr2] << endl;
    file << "City: " << citiesArray[nr3] << endl;
    file << "Debt: " << debt << endl;
    file << "Weight: " << weight << endl;
    file << endl;
}

// ----------------- PLAYER CLASS -----------------------

class PLAYER : public PERSON
{
private:
    int game_number;
    int hasTeam;

public:
    void setGameNumber(int game_number);
    void setHasTeam(int hasTeam);
    int getGameNumber();
    int getHasTeam();
    void displayPlayer();
    void displayInFile(fstream &file, int i, int nr, PERSON persons[], PLAYER players[]);
};

void PLAYER::setGameNumber(int game_number)
{
    this->game_number = game_number;
}

void PLAYER::setHasTeam(int hasTeam)
{
    this->hasTeam = hasTeam;
}

int PLAYER::getGameNumber()
{
    return this->game_number;
}

int PLAYER::getHasTeam()
{
    return this->hasTeam;
}

void PLAYER::displayPlayer()
{
    displayPerson();
    cout << "Game number: " << this->getGameNumber() << endl;
    cout << "Has team? " << this->getHasTeam() << endl;
    cout << endl;
}

// function to display players in file
void displayInFile(fstream &file, int i, int nr, PERSON persons[], PLAYER players[])
{
    file << "First name: " << persons[nr].getLastName() << endl;
    file << "Last name: " << persons[nr].getFirstName() << endl;
    file << "City: " << persons[nr].getCity() << endl;
    file << "Debt: " << persons[nr].getDebt() << endl;
    file << "Weight: " << persons[nr].getWeight() << endl;
    file << "Game number: " << i << endl;
    file << "Has team? " << players[i].getHasTeam() << endl;
    file << endl;
}

// ------------ SUPERVISOR CLASS -------------

class SUPERVISOR : public PERSON
{
private:
    string mask_form;

public:
    void setMaskForm(string mask_form);
    string getMaskForm();
    void displaySupervisor();
    void displayInFile(fstream &file, int i, int nr, PERSON persons[], SUPERVISOR supervisors[]);
};

void SUPERVISOR::setMaskForm(string mask_form)
{
    this->mask_form = mask_form;
}

string SUPERVISOR::getMaskForm()
{
    return this->mask_form;
}

void SUPERVISOR::displaySupervisor()
{
    displayPerson();
    cout << "Mask form: " << getMaskForm() << endl;
    cout << endl;
}

void displayInFile(fstream &file, int i, int nr, PERSON persons[], SUPERVISOR supervisors[])
{
    file << i << ". First name: " << persons[nr].getLastName() << endl;
    file << "Last name: " << persons[nr].getFirstName() << endl;
    file << "City: " << persons[nr].getCity() << endl;
    file << "Debt: " << persons[nr].getDebt() << endl;
    file << "Weight: " << persons[nr].getWeight() << endl;
    file << "Mask form: " << supervisors[i].getMaskForm() << endl;
    file << endl;
}

// ---------------------------------------------------------------------------------------

int verifyFileExists(string fileName)
{
    fstream file;
    if (!file)
    {
        cout << fileName << " does not exist." << endl;
        return 0;
    }
    return 1;
}

void openFile(string nameFile, string array[])
{
    fstream file;
    int i = 0;
    file.open(nameFile, ios::in);
    if (verifyFileExists(nameFile) == 1)
    {
        string line;
        while (getline(file, line))
        {
            array[++i] = line;
        }
    }
    file.close();
}

// template <typename X>
// X minim(X a, X b)
// {
//     if (a == b)
//         return NULL;
//     return (a < b) ? a : b;
// }

// bool verifyDuplicity (int arr[])
// {
//     int sizeArray = sizeof(arr)/sizeof(arr[0]);
//     bool var = true;
//     for (int i = 1; i <= sizeArray; i++)
//     {
//         for (int j = i; j <= sizeArray; j++)
//         {
//             if(arr[i] == arr[j])
//             {
//                 var = false;
//             }
//         }
//     }
//     return var;
// }

string randomMaskForm(int nb2, int *nb_circles, int *nb_triangles, int *nb_squares)
{
    if (nb2 == 1 && (*nb_circles) < 3)
    {
        (*nb_circles)++;
        return "circle";
    }

    if (nb2 == 2 && (*nb_triangles) < 3)
    {
        (*nb_triangles)++;
        return "triangle";
    }

    if (nb2 == 3 && (*nb_squares) < 3)
    {
        (*nb_squares)++;
        return "square";
    }

    if (nb2 == 1 && (*nb_circles) == 3)
    {
        if ((*nb_triangles) == 3)
        {
            (*nb_squares)++;
            return "square";
        }
        else
        {
            (*nb_triangles)++;
            return "triangle";
        }
    }

    if (nb2 == 2 && (*nb_triangles) == 3)
    {
        if ((*nb_circles) == 3)
        {
            (*nb_squares)++;
            return "square";
        }
        else
        {
            (*nb_circles)++;
            return "circle";
        }
    }

    if (nb2 == 3 && (*nb_squares) == 3)
    {
        if ((*nb_triangles) == 3)
        {
            (*nb_circles)++;
            return "circle";
        }
        else
        {
            (*nb_triangles)++;
            return "triangle";
        }
    }

    return "nothing";
}

void makeGroups (SUPERVISOR supervisors[], PLAYER players[], fstream &file, string maskForm)
{
    for (int i = 1; i <= 9; i++)
    {
        if (supervisors[i].getMaskForm() == maskForm)
        {
            file << supervisors[i].getLastName() << " " << supervisors[i].getFirstName() << " " << supervisors[i].getCity() << " " << supervisors[i].getDebt() << " " << supervisors[i].getWeight() << " " << supervisors[i].getMaskForm() << endl;
            for (int j = 1; j <= 11; j++)
            {
                int nr = 1 + rand() % 99;
                if (players[nr].getHasTeam() == 0)
                {
                    file << players[nr].getLastName() << " " << players[nr].getFirstName() << " " << players[nr].getCity() << " " << players[nr].getDebt() << " " << players[nr].getWeight() << " " << players[nr].getGameNumber() << endl;
                    players[nr].setHasTeam(1);
                }
                else
                {
                    j--;
                }
            }
            file << endl;
        }
    }
    file << endl;
}

int main()
{
    srand(time(NULL));
    PERSON persons[109];
    PLAYER players[100];
    SUPERVISOR supervisors[10];

    string firstNamesArray[109] = {};
    string lastNamesArray[109] = {};
    string citiesArray[109] = {};
    //int gameNumbersArray[100];

    openFile("NAMES.txt", firstNamesArray);
    openFile("LASTNAMES.txt", lastNamesArray);
    openFile("CITIES.txt", citiesArray);

    fstream personsFile;
    fstream playersFile;
    fstream supervisorsFile;

    // ----------- a file with all the persons in the game ----------------

    personsFile.open("PERSONS.txt", ios::out);
    if (verifyFileExists("PERSONS.txt") == 1)
    {
        for (int i = 1; i <= 108; i++)
        {
            // we have 3 different nr in order to avoid dublicates (two persons with the same last name, first name and city)
            int nr = 1 + rand() % 108;
            int nr2 = 1 + rand() % 108;
            int nr3 = 1 + rand() % 108;

            double debt = 10000 + rand() % 90001;
            int weight = 50 + rand() % 51;

            persons[i].setPerson(firstNamesArray[nr], lastNamesArray[nr2], citiesArray[nr3], debt, weight);
            displayInFile(personsFile, i, nr, nr2, nr3, debt, weight, firstNamesArray, lastNamesArray, citiesArray);
        }
    }
    personsFile.close();

    // ------------- a file with 99 players -----------------

    playersFile.open("PLAYERS.txt", ios::out);
    if (verifyFileExists("PLAYERS.txt") == 1)
    {
        for (int i = 1; i <= 99; i++)
        {
            int nr = 1 + rand() % 99;
            players[i].setPerson(persons[nr].getLastName(), persons[nr].getFirstName(), persons[nr].getCity(), persons[nr].getDebt(), persons[nr].getWeight());
            players[i].setHasTeam(0);

            players[i].setGameNumber(i);
            displayInFile(playersFile, i, nr, persons, players);
        }
    }
    playersFile.close();

    // ------------------- a file with 9 supervisors --------------------------

    int nb_circles = 0;
    int nb_triangles = 0;
    int nb_squares = 0;

    supervisorsFile.open("SUPERVISORS.txt", ios::out);
    if (verifyFileExists("SUPERVISORS.txt") == 1)
    {
        for (int i = 1; i <= 9; i++)
        {
            int nr = 1 + rand() % 9;
            int nb2 = 1 + rand() % 3;
            string form = randomMaskForm(nb2, &nb_circles, &nb_triangles, &nb_squares);
            supervisors[i].setMaskForm(form);
            supervisors[i].setPerson(persons[nr].getLastName(), persons[nr].getFirstName(), persons[nr].getCity(), persons[nr].getDebt(), persons[nr].getWeight());

            displayInFile(supervisorsFile, i, nr, persons, supervisors);
        }
    }
    supervisorsFile.close();

    fstream teamsFile;
    teamsFile.open("TEAMS.txt", ios::out);
    if (verifyFileExists("TEAMS.txt") == 1)
    {
        supervisorsFile.open("SUPERVISORS.txt", ios::in);
        if (verifyFileExists("SUPERVISORS.txt") == 1)
        {
            makeGroups (supervisors, players, teamsFile, "circle");
            makeGroups (supervisors, players, teamsFile, "triangle");
            makeGroups (supervisors, players, teamsFile, "square");
        }
    }

    return 0;
}
