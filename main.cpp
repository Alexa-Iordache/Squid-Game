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
    int hasTeam; //ne ajutam de acest atribut pentru a forma echipele
    int eliminated;
    int random_number;
    int genken_number;

public:
    void setGameNumber(int game_number);
    void setHasTeam(int hasTeam);
    void setEliminated(int eliminated);
    void setRandomNumber(int random_number);
    void setGenkenNumber(int genken_numer);
    int getGameNumber();
    int getHasTeam();
    int getEliminated();
    int getRandomNumber();
    int getGenkenNumber();
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

void PLAYER::setEliminated(int eliminated)
{
    this->eliminated = eliminated;
}

void PLAYER::setRandomNumber(int random_number)
{
    this->random_number = random_number;
}

void PLAYER::setGenkenNumber(int genken_number)
{
    this->genken_number = genken_number;
}

int PLAYER::getGameNumber()
{
    return this->game_number;
}

int PLAYER::getHasTeam()
{
    return this->hasTeam;
}

int PLAYER::getEliminated()
{
    return this->eliminated;
}

int PLAYER::getRandomNumber()
{
    return this->random_number;
}

int PLAYER::getGenkenNumber()
{
    return this->genken_number;
}

void PLAYER::displayPlayer()
{
    displayPerson();
    cout << "Game number: " << this->getGameNumber() << endl;
    //cout << "Has team? " << this->getHasTeam() << endl;
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
    // file << "Has team? " << players[i].getHasTeam() << endl;
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

void makeGroups(SUPERVISOR supervisors[], PLAYER players[], fstream &file, string maskForm)
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

void RED_LIGHT_GREEN_LIGHT(PLAYER players[], fstream &file)
{
    int contor = 1;
    for (int i = 1; i <= 99; i++)
    {
        if (players[i].getGameNumber() % 2 != 0)
        {
            file << players[i].getLastName() << " " << players[i].getFirstName() << " " << players[i].getGameNumber() << endl;
            contor++;
        }
        else
        {
            players[i].setEliminated(1);
        }
    }
}

void makeGroupsForSecondGame(PLAYER players[], fstream &file, int m[5][13])
{
    for (int i = 1; i <= 99; i++)
    {
        players[i].setHasTeam(0);
    }
    for (int i = 1; i <= 4; i++)
    {
        file << " Echipa " << i << endl;
        int col = 0;

        for (int j = 1; j <= 12; j++)
        {
            int nr = 1 + rand() % 99;
            if (players[nr].getHasTeam() == 0 && players[nr].getGameNumber() % 2 != 0)
            {
                file << players[nr].getLastName() << " " << players[nr].getFirstName() << " " << players[nr].getGameNumber() << endl;
                players[nr].setHasTeam(1);
                m[i][++col] = players[nr].getGameNumber();
            }
            else
                j--;
        }
        file << endl;
    }
}

void TUG_OF_WAR(PLAYER players[], fstream &file, int m[5][13])
{
    int sum[5];
    for (int i = 1; i <= 4; i++)
    {
        sum[i] = 0;
        for (int j = 1; j <= 12; j++)
        {
            sum[i] = sum[i] + players[m[i][j]].getWeight();
        }
    }

    cout << "Greutatile echipelor sunt: " << endl;
    cout << "Echipa 1: " << sum[1] << endl;
    cout << "Echipa 2: " << sum[2] << endl;
    cout << "Echipa 3: " << sum[3] << endl;
    cout << "Echipa 4: " << sum[4] << endl;

    int maxWeightRound1 = 0, maxWeightRound2 = 0, maxWeight = 0;
    int winner1, winner2, winner;

    //se dueleaza prima echipa cu a doua
    if (sum[1] > sum[2])
    {
        maxWeightRound1 = sum[1];
        winner1 = 1;
    }
    else
    {
        maxWeightRound1 = sum[2];
        winner1 = 2;
    }

    //se dueleaza a treia echipa cu a patra
    if (sum[3] > sum[4])
    {
        maxWeightRound2 = sum[3];
        winner2 = 3;
    }
    else
    {
        maxWeightRound2 = sum[4];
        winner2 = 4;
    }

    //se dueleaza echipele castigatoare de la meciurile anterioare
    if (sum[winner1] > sum[winner2])
    {
        maxWeight = sum[winner1];
        winner = winner1;
    }
    else
    {
        maxWeight = sum[winner2];
        winner = winner2;
    }

    cout << "Greutatea maxima este: " << maxWeight << " si este a echipei " << winner << endl;

    for (int i = 1; i <= 4; i++)
    {
        if (i != winner)
        {
            for (int j = 1; j <= 12; j++)
            {
                players[m[i][j]].setEliminated(1);
            }
        }
    }

    int j = 0;
    for (int i = 1; i <= 99; i++)
    {
        if (players[i].getEliminated() == 0)
        {
            file << players[i].getLastName() << " " << players[i].getFirstName() << " " << players[i].getGameNumber() << " " << endl;
        }
    }
}

void makeGroupsForThirdGame(PLAYER players[], fstream &file, int m[8][3])
{
    //daca nu sunt eliminati setam atributul de echipa in 0 (sa figureze ca nu are echipa)
    for (int i = 1; i <= 99; i++)
    {
        if (players[i].getEliminated() == 0)
            players[i].setHasTeam(0);
    }

    file << "Last name"
         << "  "
         << "First name"
         << "  "
         << "Game number"
         << "  "
         << "Random number" << endl;
    file << endl;

    for (int i = 1; i <= 7; i++)
    {
        file << " Echipa " << i << endl;

        for (int j = 1; j <= 2; j++)
        {
            int nr = 1 + rand() % 99;

            if (players[nr].getHasTeam() == 0 && players[nr].getEliminated() == 0)
            {
                // dam un numar radom (intre 1 si 99) fiecarui jucator ramas
                int n = 1 + rand() % 99;
                players[nr].setRandomNumber(n);

                file << players[nr].getLastName() << " " << players[nr].getFirstName() << " " << players[nr].getGameNumber() << " " << players[nr].getRandomNumber() << endl;
                players[nr].setHasTeam(1);

                //adaugam in matricea m numarul de concurs al jucatorilor astfel: pe fiecare linie se
                //afla numerele de concurs al jucatorilor dintr-o echipe (deci matricea m are in total
                //7 linii pentru ca sunt 7 echipe)
                m[i][j] = players[nr].getGameNumber();
            }
            else
                j--;
        }
        file << endl;
    }
}

void MARBLES(PLAYER players[], fstream &file, int m[8][3])
{
    for (int i = 1; i <= 7; i++)
    {
        if (players[m[i][1]].getRandomNumber() > players[m[i][2]].getRandomNumber())
            players[m[i][2]].setEliminated(1);
        else
            players[m[i][1]].setEliminated(1);
    }

    for (int i = 99; i >= 1; i--)
    {
        if (players[i].getEliminated() == 0)
            file << players[i].getLastName() << " " << players[i].getFirstName() << " " << players[i].getGameNumber() << endl;
    }
}

int RulesOfGenken(int a, int b)
{
    // 1 = piatra; 2 = hartie; 3 = foarfece
    if ((a == 1 && b == 2) || (b == 1 && a == 2))
        return 2; //castiga hartia
    if ((a == 1 && b == 3) || (b == 1 && a == 3))
        return 1; // castiga piatra
    if ((a == 2 && b == 3) || (b == 2 && a == 3))
        return 3; //castiga foarfeca
    return 0;     //este egalitate
}

void GENKEN(PLAYER players[], fstream &file, int finalPlayers[], int *nbFinalPlayers)
{
    for (int j = 99; j >= 1; j--)
    {
        if (players[j].getEliminated() == 0)
        {
            int n = 1 + rand() % 3; //le acordam un numar random intre 1 si 3 inclusiv
            players[j].setGenkenNumber(n);
            file << players[j].getLastName() << " " << players[j].getFirstName() << " " << players[j].getGameNumber() << " " << players[j].getGenkenNumber() << endl;

            //adaugam in vectorul finalPlayers numerele de concurs ale celor 7 finalisti
            finalPlayers[++(*nbFinalPlayers)] = players[j].getGameNumber();
        }
    }
    file << endl;
    file << endl;

    for (int i = 1; i < 7; i++)
    {
        for (int j = i + 1; j <= 7; j++)
        {
            if (RulesOfGenken(players[finalPlayers[i]].getGenkenNumber(), players[finalPlayers[j]].getGenkenNumber()) == players[finalPlayers[i]].getGenkenNumber() && players[finalPlayers[i]].getEliminated() == 0 && players[finalPlayers[j]].getEliminated() == 0)
            {
                //cout << players[finalPlayers[i]].getGameNumber() << " castiga" << endl;
                players[finalPlayers[j]].setEliminated(1);
                (*nbFinalPlayers)--;
            }
            else
            {
                if (RulesOfGenken(players[finalPlayers[i]].getGenkenNumber(), players[finalPlayers[j]].getGenkenNumber()) == players[finalPlayers[j]].getGenkenNumber() && players[finalPlayers[i]].getEliminated() == 0 && players[finalPlayers[j]].getEliminated() == 0)
                {
                    //cout << players[finalPlayers[j]].getGameNumber() << " castiga" << endl;
                    players[finalPlayers[i]].setEliminated(1);
                    (*nbFinalPlayers)--;
                }
            }
        }
    }

    (*nbFinalPlayers) = 0;
    for (int i = 1; i <= 99; i++)
        if (players[i].getEliminated() == 0)
        {
            (*nbFinalPlayers)++;
        }

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
            players[i].setEliminated(0);

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
            makeGroups(supervisors, players, teamsFile, "circle");
            makeGroups(supervisors, players, teamsFile, "triangle");
            makeGroups(supervisors, players, teamsFile, "square");
        }
    }

    // -------------------------------- RED LIGHT GREEN LIGHT---------------------------------

    fstream afterFirstGameFile; //fisier in care stocam jucatorii ramasi dupa primul joc
    afterFirstGameFile.open("FIRSTGame.txt", ios::out);
    if (verifyFileExists("FIRSTGame.txt") == 1)
    {
        RED_LIGHT_GREEN_LIGHT(players, afterFirstGameFile);
    }

    int m[5][13] = {0};
    fstream groupsForSecongGame;
    groupsForSecongGame.open("beforeSECONDGame.txt", ios::out);
    if (verifyFileExists("beforeSECONDGame.txt") == 1)
    {
        makeGroupsForSecondGame(players, groupsForSecongGame, m);
    }

    // for (int i = 1; i <= 4; i++)
    // {
    //     for (int j = 1; j <= 12; j++)
    //     {
    //         cout << m[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // -------------------------------- TUG OF WAR ---------------------------------

    fstream afterSecondGameFile;
    afterSecondGameFile.open("SECONDGame.txt", ios::out);
    if (verifyFileExists("SECONDGame.txt") == 1)
    {
        TUG_OF_WAR(players, afterSecondGameFile, m);
    }

    // -------------------------------- MARBLES ---------------------------------

    int m2[8][3] = {0};
    fstream groupsForThirdGameFile;
    groupsForThirdGameFile.open("beforeTHIRDGame.txt", ios::out);
    if (verifyFileExists("beforeTHIRDGame.txt") == 1)
    {
        makeGroupsForThirdGame(players, groupsForThirdGameFile, m2);
    }

    // for (int i = 1; i <= 7; i++)B
    // {
    //     for (int j = 1; j <= 2; j++)
    //     {
    //         cout << m2[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    fstream afterThirdGameFile;
    afterThirdGameFile.open("THIRDGame.txt", ios::out);
    if (verifyFileExists("THIRDGame.txt") == 1)
    {
        MARBLES(players, afterThirdGameFile, m2);
    }

    // -------------------------------- GENKEN ---------------------------------

    int finalPlayers[8];
    int nbFinalPlayers = 0;
    fstream FourthGameFile;
    FourthGameFile.open("FOURTHGame.txt", ios::out);
    if (verifyFileExists("FOURTHGame.txt") == 1)
    {
        GENKEN(players, FourthGameFile, finalPlayers, &nbFinalPlayers);
    }

    if (nbFinalPlayers > 1)
    {
        while (nbFinalPlayers > 1)
        {
            GENKEN(players, FourthGameFile, finalPlayers, &nbFinalPlayers);
        }
    }

    cout << " ----------------- " << endl;
    cout << endl;
    cout << "THE FINAL WINNER: " << endl;
    for (int i = 1; i <= 99; i++)
    {
        if (players[i].getEliminated() == 0)
            cout << players[i].getLastName() << " " << players[i].getFirstName() << " " << players[i].getGameNumber() << endl;
    }


    // -------------------------------- FINAL PART ---------------------------------
    return 0;
}