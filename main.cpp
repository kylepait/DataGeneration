#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct Property{

    int ID;
    string type;
    double sqrfoot;
    bool pool;
    int stories;
    int bathrooms;
    string view;



};
///function to populate array
int readInArray(Property houses[]);
///search functions
void houseTypeSearch(Property houses[], int userSelectionType, int numOfEntries);
void houseBathroomSearch(Property houses[], int userSelectionBathrooms, int numOfEntries);
void housePoolSearch(Property houses[], int userSelectionPool, int numOfEntries);
void houseStorySearch(Property houses[], int userSelectionNumStories, int numOfEntries);

int main()
{

    int numOfEntries;

    ///array to hold houses
    Property houses[500];

    ///call function to read input into array and return number of houses
    numOfEntries = readInArray(houses);

    ///variables to hold user inputs
    int userSelection;
    int userSelectionType;
    int userSelectionBathrooms;
    int userSelectionPool;
    int userSelectionNumStories;


    cout << "Select Search Parameter: type(1), baths(2), pool(3), stories(4), exit(0)";
    cin  >> userSelection;
    cout << endl;

    if(userSelection == 1)
    {
        cout << "Select house type: condo(1), apartment(2), detached(3): ";
        cin  >> userSelectionType;
        cout << endl;

        houseTypeSearch(houses, userSelectionType, numOfEntries);
    }
    else if(userSelection == 2)
    {
        cout << "Enter number criterium: ";
        cin  >> userSelectionBathrooms;
        cout << endl;

        houseBathroomSearch(houses, userSelectionBathrooms, numOfEntries);


    }
    else if(userSelection == 3)
    {
        cout << "Enter Search Criterium: Houses with pool(1), without pool(2)";
        cin  >> userSelectionPool;
        cout << endl;

        housePoolSearch(houses, userSelectionPool, numOfEntries);


    }
    else if (userSelection == 4)
    {
        cout << "Enter Number Criterium: ";
        cin  >> userSelectionNumStories;
        cout << endl;

        houseStorySearch(houses, userSelectionNumStories, numOfEntries);


    }

    return 0;
}


int readInArray(Property houses[])
{
    int numOfEntries = 0;



    ifstream inFile;
    inFile.open("listings.txt");

    inFile >> numOfEntries;

    for(int i = 0; i < numOfEntries; i++)
    {
        inFile >> houses[i].ID >> houses[i].type >> houses[i].sqrfoot >> houses[i].stories >> houses[i].bathrooms
               >> houses[i].view >> houses[i].pool;
    }

    return numOfEntries;

}

void houseTypeSearch(Property houses[], int userSelectionType, int numOfEntries)
{

    ///variables used to hold count
    int condoCounter = 0;
    int apartmentCounter = 0;
    int detachedCounter = 0;

    if(userSelectionType == 1)
    {
        for(int i = 0; i < numOfEntries; i++)
        {
            if(houses[i].type == "condo")
                    condoCounter++;
        }

        cout << condoCounter;
    }

    else if(userSelectionType == 2)
    {
        for(int i = 0; i < numOfEntries; i++)
        {
            if(houses[i].type == "apartment")
                    apartmentCounter++;
        }

        cout << apartmentCounter;
    }

    else if(userSelectionType == 3)
    {
        for(int i = 0; i < numOfEntries; i++)
        {
            if(houses[i].type == "detached")
                    detachedCounter++;
        }
        cout << detachedCounter;
    }
}

void houseBathroomSearch(Property houses[], int userSelectionBathrooms, int numOfEntries)
{
    ///variables used to hold count
    int bathroomCounter = 0;

    for(int i = 0; i < numOfEntries; i++)
    {
        if(houses[i].bathrooms == userSelectionBathrooms)
                bathroomCounter++;
    }

        cout << bathroomCounter;
}

void housePoolSearch(Property houses[], int userSelectionPool, int numOfEntries)
{
    ///variables used to hold count
    int poolCounter = 0;

    if(userSelectionPool == 1)
        {
            for(int i = 0; i < numOfEntries; i++)
            {
                if(houses[i].pool == 1)
                    poolCounter++;
            }

            cout << poolCounter;
        }

        else if(userSelectionPool == 2)
        {

            for(int i = 0; i < numOfEntries; i++)
            {
                if(houses[i].pool == 0)
                    poolCounter++;
            }

            cout << poolCounter - 1;

        }
}

void houseStorySearch(Property houses[], int userSelectionNumStories, int numOfEntries)
{

    ///variables used to hold count
    int oneStoryHouses = 0;
    int twoStoryHouses = 0;
    int threeStoryHouses = 0;

    if(userSelectionNumStories == 1)
    {
        for(int i = 0; i < numOfEntries; i++)
        {
            if(houses[i].stories == 1)
                oneStoryHouses++;
        }

        cout << "Houses with one story: " << oneStoryHouses;
    }

    if(userSelectionNumStories == 2)
    {
        for(int i = 0; i < numOfEntries; i++)
        {
            if(houses[i].stories == 2)
                twoStoryHouses++;
        }

        cout << "Houses with two stories: " << twoStoryHouses;
    }

    if(userSelectionNumStories == 3)
    {
        for(int i = 0; i < numOfEntries; i++)
        {
            if(houses[i].stories == 3)
                threeStoryHouses++;
        }

        cout << "Houses with three stories: " << threeStoryHouses;
    }
}
