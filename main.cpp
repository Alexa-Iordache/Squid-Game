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
#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

// a class for every single person in the game
class PERSON
{
private:
    string last_name;  
    string first_name; 
    string city;
    double debt; 
    int weight;
    int isTaken; // attribute that will help us check if the person is already an existing player/ supervisor

public:
    //setters
    void setPerson(string last_name, string first_name, string city, double debt, int weight);
    void setIsTaken(int isTaken);

    //getters
    string getLastName();
    string getFirstName();
    string getCity();
    double getDebt();
    int getWeight();
    int getIsTaken();

    // methods to display the info about a person in terminal and in the file as well 
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

void PERSON::setIsTaken(int isTaken)
{
    this->isTaken = isTaken;
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

int PERSON::getIsTaken()
{
    return this->isTaken;
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

// a class for every single player in the game
// this class inherits the 'Person' class
class PLAYER : public PERSON
{
private:
    int game_number;
    int hasTeam; // it will help us check if the player is already in a team or not (1 = he has a team; 0 = he has not a team)
    int eliminated; // it will help us check if the player has been eliminated or not (1 = he has been eliminated 0 = he has not benn eliminated)
    int random_number; 
    int genken_number; // attribute for a random number used in the last game

public:
    // setters
    void setGameNumber(int game_number);
    void setHasTeam(int hasTeam);
    void setEliminated(int eliminated);
    void setRandomNumber(int random_number);
    void setGenkenNumber(int genken_numer);

    // getters
    int getGameNumber();
    int getHasTeam();
    int getEliminated();
    int getRandomNumber();
    int getGenkenNumber();

    // methods to display the info about a player in terminal and in the file as well 
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
    file << i << ". First name: " << persons[nr].getLastName() << endl;
    file << "Last name: " << persons[nr].getFirstName() << endl;
    file << "City: " << persons[nr].getCity() << endl;
    file << "Debt: " << persons[nr].getDebt() << endl;
    file << "Weight: " << persons[nr].getWeight() << endl;
    file << "Game number: " << i << endl;
    // file << "Has team? " << players[i].getHasTeam() << endl;
    file << endl;
}


// ------------ SUPERVISOR CLASS -------------

// a class for every single supervisor in the game
// this class inherits the 'Person' class
class SUPERVISOR : public PERSON
{
private:
    string mask_form;
    double finalSum;

public:
    // setters
    void setMaskForm(string mask_form);
    void setFinalSum(double finalSum);

    // getters
    string getMaskForm();
    int getFinalSum();

    // methods to display the info about a supervisor in terminal and in the file as wel
    void displaySupervisor();
    void displayInFile(fstream &file, int i, int nr, PERSON persons[], SUPERVISOR supervisors[]);
};

void SUPERVISOR::setMaskForm(string mask_form)
{
    this->mask_form = mask_form;
}

void SUPERVISOR::setFinalSum(double finalSum)
{
    this->finalSum = finalSum;
}

string SUPERVISOR::getMaskForm()
{
    return this->mask_form;
}

int SUPERVISOR::getFinalSum()
{
    return this->finalSum;
}

void SUPERVISOR::displaySupervisor()
{
    displayPerson();
    cout << "Mask form: " << getMaskForm() << endl;
    cout << endl;
}

void displayInFile(fstream &file, int i, int nr, PERSON persons[], SUPERVISOR supervisors[])
{
    file << "First name: " << persons[nr].getLastName() << endl;
    file << "Last name: " << persons[nr].getFirstName() << endl;
    file << "City: " << persons[nr].getCity() << endl;
    file << "Debt: " << persons[nr].getDebt() << endl;
    file << "Weight: " << persons[nr].getWeight() << endl;
    file << "Mask form: " << supervisors[i].getMaskForm() << endl;
    file << endl;
}


// ---------------------------------------------------------------------------------------

// function that checks if a file exists or not 
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

// reads line by line from a file and stores the info in an array
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

// function that randomly returns a mask form 
string randomMaskForm(int nb2, int *nb_circles, int *nb_triangles, int *nb_squares)
{
    // if the 'circle' has been picked and there aren't already 3 supervisors with this mask form
    if (nb2 == 1 && (*nb_circles) < 3)
    {
        (*nb_circles)++;
        return "circle";
    }

    // if the 'triangle' has been picked and there aren't already 3 supervisors with this mask form
    if (nb2 == 2 && (*nb_triangles) < 3)
    {
        (*nb_triangles)++;
        return "triangle";
    }

    // if the 'square' has been picked and there aren't already 3 supervisors with this mask form
    if (nb2 == 3 && (*nb_squares) < 3)
    {
        (*nb_squares)++;
        return "square";
    }

    // if the 'circle' has been picked and there are already 3 supervisors with this mask form
    if (nb2 == 1 && (*nb_circles) == 3)
    {
        // we check if there are already 3 supervisors with triangle masks
        if ((*nb_triangles) == 3)
        {
            // if there are, we give that supervisor a square mask
            (*nb_squares)++;
            return "square";
        }
        else
        {
            // if there are not, we give that supervisor a trinagle mask
            (*nb_triangles)++;
            return "triangle";
        }
    }

    // we proceed in the same way for the other two cases
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

// function that forms the initial teams - every supervisor with his 11 players
void makeGroups(SUPERVISOR supervisors[], PLAYER players[], fstream &file, string maskForm, int teams[10][12], int *nbTeams, string supervisorsTeams[10][3])
{
    for (int i = 1; i <= 9; i++) // for each supervisor
    {
        if (supervisors[i].getMaskForm() == maskForm)
        {
            file << supervisors[i].getLastName() << " " << supervisors[i].getFirstName() << " " << supervisors[i].getCity() << " " << supervisors[i].getDebt() << " " << supervisors[i].getWeight() << " " << supervisors[i].getMaskForm() << endl;
            ++(*nbTeams); 
            // we also form the matrix with the last name, first name and form mask of each supervisor
            supervisorsTeams[(*nbTeams)][0] = supervisors[i].getLastName();
            supervisorsTeams[(*nbTeams)][1] = supervisors[i].getFirstName();
            supervisorsTeams[(*nbTeams)][2] = supervisors[i].getMaskForm();

            for (int j = 1; j <= 11; j++)
            {
                int nr = 1 + rand() % 99;
                if (players[nr].getHasTeam() == 0) // if the player doesn't already have a team 
                {
                    file << players[nr].getLastName() << " " << players[nr].getFirstName() << " " << players[nr].getCity() << " " << players[nr].getDebt() << " " << players[nr].getWeight() << " " << players[nr].getGameNumber() << endl;
                    teams[(*nbTeams)][j] = players[nr].getGameNumber(); // we put him in a team
                    players[nr].setHasTeam(1); // and note that he was added to a team
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

// function for the first game
void RED_LIGHT_GREEN_LIGHT(PLAYER players[], fstream &file)
{
    int contor = 1;
    for (int i = 1; i <= 99; i++) 
    {
        if (players[i].getGameNumber() % 2 != 0) // if the game number of the player is an odd number
        {
            // the player moves on to the next game
            file << players[i].getLastName() << " " << players[i].getFirstName() << " " << players[i].getGameNumber() << endl;
            contor++;
        }
        else // if the game number of the player is an even number
        {
            players[i].setEliminated(1); // the player is eliminated
        }
    }
}

// function to make groups for the second game
void makeGroupsForSecondGame(PLAYER players[], fstream &file, int m[5][13])
{
    // no player has a team for the second game
    for (int i = 1; i <= 99; i++)
    {
        players[i].setHasTeam(0);
    }

    for (int i = 1; i <= 4; i++)    // there must be 4 teams with 12 players each
    {
        file << " Echipa " << i << endl;
        int col = 0;

        for (int j = 1; j <= 12; j++)
        {
            int nr = 1 + rand() % 99; // we select randomly the player
            if (players[nr].getHasTeam() == 0 && players[nr].getGameNumber() % 2 != 0) // if he doesn't already have a team and he is not eliminated
            {
                file << players[nr].getLastName() << " " << players[nr].getFirstName() << " " << players[nr].getGameNumber() << endl; // we display him in the file
                players[nr].setHasTeam(1); // we note that he is in a team
                m[i][++col] = players[nr].getGameNumber(); // we put his game number on the line in the 'm' matrix whose number corresponds to the team number to which he was assigned
            }
            else
                j--;
        }
        file << endl;
    }
}

// function for the second game
void TUG_OF_WAR(PLAYER players[], fstream &file, int m[5][13])
{
    int sum[5];

    // for each team we calculate the sum of the weights of all the players and put the values in the 'sum' array
    for (int i = 1; i <= 4; i++) 
    {
        sum[i] = 0;
        for (int j = 1; j <= 12; j++)
        {
            sum[i] = sum[i] + players[m[i][j]].getWeight();
        }
    }

    cout << " ---------- TUG OF WAR -------- " << endl;
    cout << "The weights of the teams are: " << endl;
    cout << "Team 1: " << sum[1] << endl;
    cout << "Team 2: " << sum[2] << endl;
    cout << "Team 3: " << sum[3] << endl;
    cout << "Team 4: " << sum[4] << endl;

    int maxWeightRound1 = 0, maxWeightRound2 = 0, maxWeight = 0;
    int winner1, winner2, winner;

    // the first team duels with the second one
    // maxWeightRound1 = the weight of the winning team from the first duel
    // winner1 = number of the winning team from the first duel
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

    // the third team duels with the fouth one
    // maxWeightRound2 = the weight of the winning team from the second duel
    // winner2 = number of the winning team from the second duel
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

    // the duel of the winning teams from the previous matches
    // maxWeight = the weight of the winning team after the whole game
    // winner = number of the winning team after the whole game
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

    cout << "The max weight is: " << maxWeight << " and it belongs to team number " << winner << endl;

    // all players from the losing teams are eliminated
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

    // displaying in the file the remaining players after the third game
    int j = 0;
    for (int i = 1; i <= 99; i++)
    {
        if (players[i].getEliminated() == 0)
        {
            file << players[i].getLastName() << " " << players[i].getFirstName() << " " << players[i].getGameNumber() << " " << endl;
        }
    }
}

// function ehich makes groups for the third game
void makeGroupsForThirdGame(PLAYER players[], fstream &file, int m[8][3])
{
    // if the player is not removed we set the team attribute to 0 (figure that he doesn't have a team)
    for (int i = 1; i <= 99; i++)
    {
        if (players[i].getEliminated() == 0)
            players[i].setHasTeam(0);
    }

    file << "Last name  First name  Game number  Random number" << endl;
    file << endl;

    // we form 7 teams with 2 players each
    for (int i = 1; i <= 7; i++)
    {
        file << " Echipa " << i << endl;

        for (int j = 1; j <= 2; j++)
        {
            int nr = 1 + rand() % 99;

            if (players[nr].getHasTeam() == 0 && players[nr].getEliminated() == 0) // if the player doesn't already have a team and he isn't eliminated
            {
                // we give him a random number (between 1 and 99)
                int n = 1 + rand() % 99;
                players[nr].setRandomNumber(n);

                // we display the info about the player in the specific file and set the attribute for having a team to 1
                file << players[nr].getLastName() << " " << players[nr].getFirstName() << " " << players[nr].getGameNumber() << " " << players[nr].getRandomNumber() << endl;
                players[nr].setHasTeam(1);

                // we add in the matrix m the competition number of the players as follows: on each line there are the 
                // competition numbers of the players from a team (so the 'm' matrix has a total of 7 lines because there 
                // are 7 teams)
                m[i][j] = players[nr].getGameNumber();
            }
            else
                j--;
        }
        file << endl;
    }
}


// function for the third game
void MARBLES(PLAYER players[], fstream &file, int m[8][3])
{
    for (int i = 1; i <= 7; i++)
    {
        // player 1, player 2 = the two players of a tea,
        // if the random number of the player 1 is bigger than the random number of the player 2
        if (players[m[i][1]].getRandomNumber() > players[m[i][2]].getRandomNumber())
            players[m[i][2]].setEliminated(1); // the player 2 is eliminated
        else
            players[m[i][1]].setEliminated(1); // if not, the player 1 is eliminated
    }

    // displaying in the file the remaining players after the third game
    for (int i = 99; i >= 1; i--)
    {
        if (players[i].getEliminated() == 0)
            file << players[i].getLastName() << " " << players[i].getFirstName() << " " << players[i].getGameNumber() << endl;
    }
}

// function with the rules of 'paper scissors stone' game
int RulesOfGenken(int a, int b)
{
    // 1 = stone; 2 = paper; 3 = scissors
    if ((a == 1 && b == 2) || (b == 1 && a == 2))
        return 2; // paper wins
    if ((a == 1 && b == 3) || (b == 1 && a == 3))
        return 1; // stone wins
    if ((a == 2 && b == 3) || (b == 2 && a == 3))
        return 3; // scissors wins
    return 0;  // it is tie
}

// function for the fourth game
void GENKEN(PLAYER players[], fstream &file, int finalPlayers[], int *nbFinalPlayers)
{
    for (int j = 99; j >= 1; j--)
    {
        if (players[j].getEliminated() == 0)
        {
            int n = 1 + rand() % 3; // the player is given a random number between 1 and 3
            players[j].setGenkenNumber(n);
            file << players[j].getLastName() << " " << players[j].getFirstName() << " " << players[j].getGameNumber() << " " << players[j].getGenkenNumber() << endl;

            // we add in the 'finalPlayers' array the game numbers of the 7 finalists
            finalPlayers[++(*nbFinalPlayers)] = players[j].getGameNumber();
        }
    }
    file << endl;
    file << endl;

    // the players play two by two
    for (int i = 1; i < 7; i++)
    {
        for (int j = i + 1; j <= 7; j++)
        {
            // if the first player wins and none of them is eliminated
            if (RulesOfGenken(players[finalPlayers[i]].getGenkenNumber(), players[finalPlayers[j]].getGenkenNumber()) == players[finalPlayers[i]].getGenkenNumber() && players[finalPlayers[i]].getEliminated() == 0 && players[finalPlayers[j]].getEliminated() == 0)
            {
                // then, the second player is eliminated and the number of finalists decreases by one
                players[finalPlayers[j]].setEliminated(1); 
                (*nbFinalPlayers)--;
            }
            else
            {
                 // if the second player wins and none of them is eliminated
                if (RulesOfGenken(players[finalPlayers[i]].getGenkenNumber(), players[finalPlayers[j]].getGenkenNumber()) == players[finalPlayers[j]].getGenkenNumber() && players[finalPlayers[i]].getEliminated() == 0 && players[finalPlayers[j]].getEliminated() == 0)
                {
                    // then, the first player is eliminated and the number of finalists decreases by one
                    players[finalPlayers[i]].setEliminated(1);
                    (*nbFinalPlayers)--;
                }
            }
        }
    }

    // we calculate the number of players after the first round (there is a chance to be more than one winner)
    (*nbFinalPlayers) = 0;
    for (int i = 1; i <= 99; i++)
        if (players[i].getEliminated() == 0)
        {
            (*nbFinalPlayers)++;
        }
}

// function that displays the winner in the terminal
void displayWinner (PLAYER players[])
{
    for (int i = 1; i <= 99; i++)
    {
        if (players[i].getEliminated() == 0)
            cout << players[i].getLastName() << " " << players[i].getFirstName() << " " << players[i].getGameNumber() << endl;
    }
}

// function that displays the winner in the file
void displayWinnerInFile (PLAYER players[], fstream &file)
{
    long long int sumWinner;  // the amount of money won by the winner
    int indexWinner;

    for (int i = 1; i <= 99; i++)
        {
            if (players[i].getEliminated() == 1)
                sumWinner = sumWinner + players[i].getDebt(); // the winner receives the sum of all eliminated players
            else
                indexWinner = i;
        }
        file << players[indexWinner].getLastName() << " " << players[indexWinner].getFirstName() << " a castigat jocul. Acesta a primit un premiu in valoare de " << sumWinner << endl;
}

// function that calculates the amount of money received by each supervisor
void calculateSupervisorsSum (PLAYER players[], SUPERVISOR supervisors[], int teams[10][12], string supervisorsTeams[10][3], double arrayOfSums[10], int *nbOfSums)
{
    for (int i = 1; i <= 9; i++) // for each supervisor
    {
        double sum = 0;
        int n = 0;
        double finalSum;
        for (int j = 1; j <= 11; j++)
        {
            if (players[teams[i][j]].getEliminated() == 1)
            {
                // the supervisor receives the amount of the eliminated players' debts
                sum += players[teams[i][j]].getDebt(); 
                n++;
            }
        }

        // if the supervisor has the winner in his team, he receives his debt multiplied by 10 
        if (n != 11) 
        {
            for (int k = 1; k <= 9; k++)
            {
                if (supervisorsTeams[i][0] == supervisors[k].getLastName() && supervisorsTeams[i][1] == supervisors[k].getFirstName() && supervisorsTeams[i][2] == supervisors[k].getMaskForm())
                {
                    finalSum = supervisors[k].getDebt() * 10;

                    // we add in the 'arrayOfSums' array the final amount of money 
                    arrayOfSums[++(*nbOfSums)] = finalSum;

                    supervisors[k].setFinalSum(finalSum);
                }
            }
        }

        // if the supervisor doesn't have the winner in his team
        else
        {
            for (int k = 1; k <= 9; k++)
            {
                if (supervisorsTeams[i][0] == supervisors[k].getLastName() && supervisorsTeams[i][1] == supervisors[k].getFirstName() && supervisorsTeams[i][2] == supervisors[k].getMaskForm())
                {
                    // from the amount of money received, his initial debt is deducted 
                    finalSum = sum - supervisors[k].getDebt();

                    // we add in the 'arrayOfSums' array the final amount of money 
                    arrayOfSums[++(*nbOfSums)] = finalSum;

                    supervisors[k].setFinalSum(finalSum);
                }
            }
        }
    }
}

// function that displays an array with double elements
void displayArray (double array[])
{
    for (int i = 1; i <= 9; i++)
        cout << array[i] << " ";
    cout << endl;
}

// sorting method
void sortDescending ( double array[])
{
    for (int i = 1; i < 9; i++)
    {
        for (int j = i; j <= 9; j++)
        {
            if (array[i] < array[j])
            {
                swap(array[i], array[j]);
            }
        }
    }
}

// function that displays the amount of money earned by each supervisor in the file
void displaySupersvisorsSum (SUPERVISOR supervisors[], double array[], fstream &file)
{
    for (int i = 1; i <= 9; i++)
    {
        for (int k = 1; k <= 9; k++)
        {
            if ( array[i] == supervisors[k].getFinalSum())
            {
                file << supervisors[k].getLastName() << " " << supervisors[k].getFirstName() << " a castigat suma: " << supervisors[k].getFinalSum() << endl;
            }
        }
    }
    file << endl;
}

// function that calculates and displays which team of supervisors raised the most money
void displayTeamWithBiggestSum (SUPERVISOR supervisors[], fstream &file)
{
    long long int sumCircle, sumTriangle, sumSquare;
    sumCircle = 0; sumTriangle = 0; sumSquare = 0; 

    for (int i = 1; i <= 9; i++)
    {
        if (supervisors[i].getMaskForm() == "circle")
        {
            sumCircle += supervisors[i].getFinalSum();
        }

        if (supervisors[i].getMaskForm() == "triangle")
        {
            sumTriangle += supervisors[i].getFinalSum();
        }

        if (supervisors[i].getMaskForm() == "square")
        {
            sumSquare += supervisors[i].getFinalSum();
        }
    }

    if (sumCircle >= sumTriangle && sumCircle >= sumSquare)
    {
        file << "The 'circle' team won the most money: " << sumCircle << endl;
    }

    if (sumTriangle >= sumCircle && sumTriangle >= sumSquare)
    {
        file << "The 'triangle' team won the most money: " << sumTriangle << endl;
    }

    if (sumSquare >= sumTriangle && sumSquare >= sumCircle)
    {
        file << "The 'square' team won the most money: " << sumSquare << endl;
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

    openFile("NAMES.txt", firstNamesArray); // file with 108 first names
    openFile("LASTNAMES.txt", lastNamesArray); // file with 108 last names
    openFile("CITIES.txt", citiesArray); // file with 108 cities

    fstream personsFile; // file with info about the 108 persons
    fstream playersFile; // file with info about the 99 players
    fstream supervisorsFile; // file with info about the 9 supervisors


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
            persons[i].setIsTaken(0);
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
            if (persons[nr].getIsTaken() == 0)
            {
                players[i].setPerson(persons[nr].getLastName(), persons[nr].getFirstName(), persons[nr].getCity(), persons[nr].getDebt(), persons[nr].getWeight());
                players[i].setHasTeam(0);
                players[i].setEliminated(0);

                players[i].setGameNumber(i);
                displayInFile(playersFile, i, nr, persons, players);
                persons[nr].setIsTaken(1);
            }
            else
            {
                i--;
            }
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
        int j = 0;
        for (int i = 1; i <= 108; i++)
        {
            if (persons[i].getIsTaken() == 0)
            {
                int nb2 = 1 + rand() % 3;
                string form = randomMaskForm(nb2, &nb_circles, &nb_triangles, &nb_squares);
                ++j;
                supervisors[j].setMaskForm(form);
                supervisors[j].setPerson(persons[i].getLastName(), persons[i].getFirstName(), persons[i].getCity(), persons[i].getDebt(), persons[i].getWeight());

                displayInFile(supervisorsFile, j, i, persons, supervisors);
                persons[i].setIsTaken(1);
            }
        }
    }
    supervisorsFile.close();
    

    // --------------------------------------------------


    int teams[10][12] = {0}; // matrix with the game numbers of each player (1 line = 11 players of a team)
                             // the first 3 lines -> circle; the next 3 lines -> triangle; the last 3 lines -> square
    int nbTeams = 0; // number of teams
    string supervisorsTeams[10][3]; // matrix with the first name, last name and mask form for each supervisor (1 line = 1 supervisor)
    
    fstream teamsFile; // file with each supervisor and the 11 assigned players
    teamsFile.open("TEAMS.txt", ios::out);
    if (verifyFileExists("TEAMS.txt") == 1)
    {
        supervisorsFile.open("SUPERVISORS.txt", ios::in);
        if (verifyFileExists("SUPERVISORS.txt") == 1)
        {
            makeGroups(supervisors, players, teamsFile, "circle", teams, &nbTeams, supervisorsTeams);
            makeGroups(supervisors, players, teamsFile, "triangle", teams, &nbTeams, supervisorsTeams);
            makeGroups(supervisors, players, teamsFile, "square", teams, &nbTeams, supervisorsTeams);
        }
    }


    // -------------------------------- RED LIGHT GREEN LIGHT---------------------------------

    fstream afterFirstGameFile; //file with the remaining players after the first game
    afterFirstGameFile.open("FIRSTGame.txt", ios::out);
    if (verifyFileExists("FIRSTGame.txt") == 1)
    {
        RED_LIGHT_GREEN_LIGHT(players, afterFirstGameFile);
    }

    int m[5][13] = {0}; // matrix containing the game numbers of the players from the initial teams - second game
    fstream groupsForSecongGame; //file with the teams for the second game
    groupsForSecongGame.open("beforeSECONDGame.txt", ios::out);
    if (verifyFileExists("beforeSECONDGame.txt") == 1)
    {
        // forming the teams for the second game
        makeGroupsForSecondGame(players, groupsForSecongGame, m);
    }
    afterFirstGameFile.close();

    // -------------------------------- TUG OF WAR ---------------------------------

    fstream afterSecondGameFile; // file with the remaining players after the second game
    afterSecondGameFile.open("SECONDGame.txt", ios::out);
    if (verifyFileExists("SECONDGame.txt") == 1)
    {
        TUG_OF_WAR(players, afterSecondGameFile, m);
    }
    afterSecondGameFile.close();

    // -------------------------------- MARBLES ---------------------------------

    int m2[8][3] = {0}; // matrix containing the game numbers of the players from the initial teams - third game
    fstream groupsForThirdGameFile; // file with the teams for the third game
    groupsForThirdGameFile.open("beforeTHIRDGame.txt", ios::out);
    if (verifyFileExists("beforeTHIRDGame.txt") == 1)
    {
        // forming the teams for the third game
        makeGroupsForThirdGame(players, groupsForThirdGameFile, m2);
    }

    fstream afterThirdGameFile; // filw with the remaining players after the third game
    afterThirdGameFile.open("THIRDGame.txt", ios::out);
    if (verifyFileExists("THIRDGame.txt") == 1)
    {
        MARBLES(players, afterThirdGameFile, m2);
    }
    groupsForSecongGame.close();
    afterThirdGameFile.close();

    // -------------------------------- GENKEN ---------------------------------

    int finalPlayers[8]; // array with the game numbers of the final players (7)
    int nbFinalPlayers = 0; // number of final players 
    
    fstream FourthGameFile; // file with the players during the fourth game
    FourthGameFile.open("FOURTHGame.txt", ios::out);
    if (verifyFileExists("FOURTHGame.txt") == 1)
    {
        GENKEN(players, FourthGameFile, finalPlayers, &nbFinalPlayers);
    }

    // if there is more than one winner, they play until there is one winner left
    if (nbFinalPlayers > 1)
    {
        while (nbFinalPlayers > 1)
        {
            GENKEN(players, FourthGameFile, finalPlayers, &nbFinalPlayers);
        }
    }

    // we display in terminal the winner of the game
    cout << " ----------------- " << endl;
    cout << endl;
    cout << "THE FINAL WINNER: " << endl;
    displayWinner(players);
    FourthGameFile.close();

    // -------------------------------- FINAL PART ---------------------------------

    int sumWinner = 0; // the amount of money won by the winning player
    int indexWinner; 
    double arrayOfSums[10]; // array with the amounts of money won by each supervisor
    int nbOfSums = 0; // the number of 

    fstream final;
    final.open("FINAL.txt", ios::out); // file with the final results

    if (verifyFileExists("FINAL.txt") == 1)
    {
       // displaying the winner in the final file
       displayWinnerInFile(players, final);

       // calculating the amount of money earned by each supervisor
       calculateSupervisorsSum (players, supervisors, teams, supervisorsTeams, arrayOfSums, &nbOfSums);

       displayArray (arrayOfSums);
       sortDescending (arrayOfSums);
       displayArray (arrayOfSums);

       // displaying the amount of money of each supervisor in descending order
       displaySupersvisorsSum (supervisors, arrayOfSums, final);

       // displaying the team of supervisors who earned the most money in total
       displayTeamWithBiggestSum (supervisors, final);
    }
    final.close();

return 0;
}