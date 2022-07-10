#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;


struct Property{

    string type;
    double sqrfoot;
    string pool;
    int stories;
    int bathrooms;
    string view;



};

void setHouseType(Property houses[]);
void setSqrFoot(Property houses[]);
void setPool(Property houses[]);
void setStories(Property houses[]);
void setBathrooms(Property houses[]);
void setView(Property houses[]);

int main()
{

    srand(time(0));
    ///declaring our array of 500 houses
    Property houses[500];

    ///calling our functions
    setHouseType(houses);
    setSqrFoot(houses);
    setPool(houses);
    setStories(houses);
    setBathrooms(houses);
    setView(houses);


    ///declaring output stream variable and opening output file
    ofstream outFile;
    outFile.open("listings.txt");

    ///output array to file
    for(int i = 0; i < 500; i++)
    {
        outFile << setw(3) << setfill('0') << i + 1 << "   " << houses[i].type << "   " << houses[i].sqrfoot << "   "
                << houses[i].pool << "   " << houses[i].stories << "   "
                << houses[i].bathrooms << "   " << houses[i].view << "   " << endl;
    }




    return 0;
}

void setHouseType(Property houses[])
{

    int randNum;


    for(int i = 0; i < 500; i++)
    {
        ///generating a random number between 1-3
        ///probability factor
        randNum = (rand() % 3) + 1;


        ///house types have the same probability
        if(randNum == 1)
            houses[i].type = "Condo";
        else if(randNum == 2)
            houses[i].type = "Apartment";
        else if(randNum == 3)
            houses[i].type = "Detached";

    }

}

void setSqrFoot(Property houses[])
{

    double randNum = 0;

    for(int i = 0; i < 500; i++)
    {
        if(houses[i].type == "Condo")
        {
            ///generating a random number between 1000-1300
            randNum = rand()%(1300 - 1000 + 1) + 1000;
            houses[i].sqrfoot = randNum;
        }
        else if(houses[i].type == "Apartment")
        {
            ///generating a random number between 1100-800
            randNum = rand()%(1100 - 800 + 1) + 800;
            houses[i].sqrfoot = randNum;
        }
        else if(houses[i].type == "Detached")
        {
            ///generating a random number between 2400-1400
            randNum = rand()%(2400 - 1400 + 1) + 1400;
            houses[i].sqrfoot = randNum;
        }
    }
}

void setPool(Property houses[])
{

    int randNum;

    for(int i = 0; i < 500; i++)
    {
        if(houses[i].type == "Condo" || houses[i].type == "Apartment")
        {
            houses[i].pool = "No";
        }
        else if(houses[i].type == "Detached")
        {
            ///probability factor
            randNum = rand()%(2 - 1 + 1) + 1;

            if(randNum == 1)
            {
                houses[i].pool = "Yes";
            }
            else if(randNum == 2)
            {
                houses[i].pool = "No";
            }
        }
    }
}

void setStories(Property houses[])
{

    int randNum;

    for(int i = 0; i < 500; i++)
    {
        if(houses[i].type == "Condo" || houses[i].type == "Detached")
        {
            ///probability factor
            randNum = rand()%(2 - 1 + 1) + 1;
            houses[i].stories = randNum;
        }
        else if(houses[i].type == "Apartment")
        {

            ///generating a random number between 1-3
            ///probability factor
            randNum = (rand() % 3) + 1;
            houses[i].stories = randNum;
        }
    }
}

void setBathrooms(Property houses[])
{
    int randNum;

    for (int i = 0; i < 500; i++)
    {
        if(houses[i].type == "Condo" || houses[i].type == "Apartment")
        {
            ///probability factor
            randNum = rand()%(2 - 1 + 1) + 1;
            houses[i].bathrooms = randNum;
        }
        else if(houses[i].type == "Detached")
        {
            randNum = rand()%(4 - 2 + 1) + 2;
            houses[i].bathrooms = randNum;
        }
    }
}

void setView(Property houses[])
{
    int randNum;

    for(int i = 0; i < 500; i++)
    {
        ///probability factor
        randNum = rand()%(4 - 1 + 1) + 1;

        if(randNum == 1)
            houses[i].view = "Sea";
        else if (randNum == 2)
            houses[i].view = "Lake";
        else if(randNum == 3)
            houses[i].view = "Neighborhood";
        else if(randNum == 4)
            houses[i].view = "Forest";
    }
}













