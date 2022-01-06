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
};

void PERSON::setPerson(string last_name, string first_name, string city, double debt, int weight)
{
    this->last_name = last_name;
    this->first_name = first_name;
    this->city = city;
    this->debt = debt;
    this->weight = weight;
}

// void PERSON::setUsed (int used)
// {
//     this->used = used;
// }

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

// int PERSON::getUsed()
// {
//     return this->used;
// }

void PERSON::displayPerson()
{
    cout << "Last name: " << this->getLastName() << endl;
    cout << "First name: " << this->getFirstName() << endl;
    cout << "City: " << this->getCity() << endl;
    cout << "Debt: " << this->getDebt() << endl;
    cout << "Weight: " << this->getWeight() << endl;
}

// ----------------- PLAYER CLASS -----------------------

class PLAYER : public PERSON
{
private:
    int game_number;

public:
    void setGameNumber(int game_number);
    int getGameNumber();
    void displayPlayer();
};

void PLAYER::setGameNumber(int game_number)
{
    this->game_number = game_number;
}

int PLAYER::getGameNumber()
{
    return this->game_number;
}

void PLAYER::displayPlayer()
{
    displayPerson();
    cout << "Game number: " << this->getGameNumber() << endl;
    cout << endl;
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

void openFile(string nameFile, string array[])
{
    fstream file;
    int i = 0;
    file.open(nameFile, ios::in);
    if (!file)
    {
        cout << "No such file" << endl;
    }
    else
    {
        string line;
        while (getline(file, line))
        {
            array[++i] = line;
        }
    }
    file.close();
}

template <typename X>
X minim (X a, X b)
{
    if (a == b)
        return NULL;
    return (a < b) ? a : b;
}

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
        else{
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
        else {
            (*nb_triangles)++;
            return "triangle";
        }
    }

    return "nothing";
}

void shuffle(int *arr, size_t n)
{
    if (n > 1) 
    {
        int i;
        srand(time(NULL));
        for (i = 0; i < n - 1; i++) 
        {
          int j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = arr[j];
          arr[j] = arr[i];
          arr[i] = t;
        }
    }
}

int main()
{
    srand(time(NULL));
    PERSON person1;
    PERSON persons[109];
    person1.setPerson("iordache", "ana", "pitesti", 10000, 50);
    //person1.displayPerson();

    PLAYER player1;
    PLAYER players[100];
    player1.setPerson("iordache", "alexa", "pitesti", 10000, 54);
    player1.setGameNumber(1);
    //player1.displayPlayer();

    SUPERVISOR supervisor1;
    SUPERVISOR supervisors[10];
    supervisor1.setPerson("popa", "ioana", "bucuresti", 100000, 65);
    supervisor1.setMaskForm("patrat");
    //supervisor1.displaySupervisor();

    string firstNamesArray[109] = {};
    string lastNamesArray[109] = {};
    string citiesArray[109] = {};
    int gameNumbersArray[100];

    openFile("NAMES.txt", firstNamesArray);
    openFile("LASTNAMES.txt", lastNamesArray);
    openFile("CITIES.txt", citiesArray);

    fstream personsFile;
    fstream playersFile;
    fstream supervisorsFile;


    // ----------- a file with all the persons in the game ----------------

    personsFile.open("PERSONS.txt", ios::out);
    if (!personsFile)
    {
        cout << "No such file" << endl;
    }
    else
    {
        //srand(time(NULL));
        for (int i = 1; i <= 108; i++)
        {
            // we have 3 different nr in order to avoid dublicates (two persons with the same last name, first name and city)
            int nr = 1 + rand() % 108;
            int nr2 = 1 + rand() % 108;
            int nr3 = 1 + rand() % 108;

            double debt = 10000 + rand() % 90001;
            int weight = 50 + rand() % 51;
            //cout << i <<": " <<  firstNamesArray[nr] << " " << lastNamesArray[nr] << " " << citiesArray[nr] << " " << money<< " " << greutate << endl;
            persons[i].setPerson(firstNamesArray[nr], lastNamesArray[nr2], citiesArray[nr3], debt, weight);
            personsFile << firstNamesArray[nr] << " " << lastNamesArray[nr2] << " " << citiesArray[nr3] << " " << debt << " " << weight << " " << endl;
        }
    }
    personsFile.close();

    // ------------- a file with 99 players -----------------

    playersFile.open("PLAYERS.txt", ios::out);
    if (!playersFile)
    {
        cout << "No such file" << endl;
    }
    else
    {
        //srand(time(NULL));
        for (int i = 1; i <= 99; i++)
        {
            int nr = 1 + rand() % 99;
            playersFile << persons[nr].getLastName() << " " << persons[nr].getFirstName() << " " << persons[nr].getCity() << " " << persons[nr].getDebt() << " " << persons[nr].getWeight() << " " << nr << endl;
            players[i].setPerson(persons[nr].getLastName(), persons[nr].getFirstName(), persons[nr].getCity(), persons[nr].getDebt(), persons[nr].getWeight());
            gameNumbersArray[i] = nr;
            players[i].setGameNumber(nr);
        }
    }
    playersFile.close();

    for (int i = 1; i <= 99; i++)
    {
        cout << gameNumbersArray[i] << " ";
    }

    // ------------------- a file with 9 supervisors --------------------------

    int nb_circles = 0;
    int nb_triangles = 0;
    int nb_squares = 0;

    supervisorsFile.open("SUPERVISORS.txt", ios::out);
    if (!supervisorsFile)
    {
        cout << "No such file" << endl;
    }
    else
    {
        ///srand(time(NULL));
        for (int i = 1; i <= 9; i++)
        {
            int nr = 1 + rand() % 9;

            int nb2 = 1 + rand() % 3;
            string form = randomMaskForm(nb2, &nb_circles, &nb_triangles, &nb_squares);
            // cout << nb2 << " " << form << " " << nb_circles << " " << nb_triangles << " " << nb_squares << endl;
            supervisors[i].setMaskForm(form);

            supervisors[i].setPerson(persons[nr].getLastName(), persons[nr].getFirstName(), persons[nr].getCity(), persons[nr].getDebt(), persons[nr].getWeight());
            supervisorsFile << persons[nr].getLastName() << " " << persons[nr].getFirstName() << " " << persons[nr].getCity() << " " << persons[nr].getDebt() << " " << persons[nr].getWeight() << " " << supervisors[i].getMaskForm() << endl;
        }
    }
    supervisorsFile.close();

    fstream teamsFile;
    teamsFile.open("TEAMS.txt", ios::out);
    if (!teamsFile)
    {
        cout << "No such file" << endl;
    }
    else{
        supervisorsFile.open("SUPERVISORS.txt", ios::in);
        if(!supervisorsFile)
        {
            cout << "No such file" << endl;
        }
        else{
            for (int i = 1; i <=9; i++)
            {
                if(supervisors[i].getMaskForm() == "circle")
                {
                    teamsFile << supervisors[i].getLastName() << " " << supervisors[i].getFirstName() << " " << supervisors[i].getCity() << " " << supervisors[i].getDebt() << " " << supervisors[i].getWeight() << " " << supervisors[i].getMaskForm() << endl;
                }
            }
            teamsFile << endl;
            for (int i = 1; i <= 9; i++)
            {
                if(supervisors[i].getMaskForm() == "triangle")
                {
                    teamsFile << supervisors[i].getLastName() << " " << supervisors[i].getFirstName() << " " << supervisors[i].getCity() << " " << supervisors[i].getDebt() << " " << supervisors[i].getWeight() << " " << supervisors[i].getMaskForm() << endl;
                }
            }
            teamsFile << endl;
            for (int i = 1; i <= 9; i++)
            {
                if(supervisors[i].getMaskForm() == "square")
                {
                    teamsFile << supervisors[i].getLastName() << " " << supervisors[i].getFirstName() << " " << supervisors[i].getCity() << " " << supervisors[i].getDebt() << " " << supervisors[i].getWeight() << " " << supervisors[i].getMaskForm() << endl;
                }
            }
        }
    }

    
    // srand(time(NULL));
    // for (int i = 1; i <= 99; i++)
    // {
    //     int number = 1 + rand() % 99;
    //     gameNumbersArray[i] = number;
    //     //cout << number << endl;
    // }
    // random_shuffle(gameNumbersArray, gameNumbersArray + 99);
    // for (int i = 1; i <= 99; i++)
    // {
    //     cout << i << ". " << gameNumbersArray[i] << endl;
    // }

    int i;
    int arr[10];
    for (i = 0; i < 10; i++){
        arr[i] = i;
    }
    shuffle(arr, 10);
    for (i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
