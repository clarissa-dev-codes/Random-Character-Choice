//Pulls from the character text list and gives a random name
// Have a place to delete names
// Have a place to add names

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const string fileName = "characterlist.txt";

vector<string> loadNames()
{
    vector<string> names;
    ifstream inFile(fileName);
    string name;

    if(inFile.is_open())
    {
        while(getline(inFile, name))
        {
            if(!name.empty())
            {
                names.push_back(name);
            }
        }
        inFile.close();
    }
    return names;
}//end of loadNames

void saveNames(const vector<string>& names)
{
    ofstream outFile(fileName);
    if (outFile.is_open())
    {
        for(const string& name:names)
        {
            outFile << name << endl;
        }
        outFile.close();
    }
    else
    {
        cout << "Error saving names to file!" << endl;
    }
}//end of saveNames

string chosenOne()
{
    vector<string> names = loadNames();

    if (names.empty())
    {
        return "No names available. Add some first!";
    }

    int randomIndex = rand() % names.size();
    return names[randomIndex];
}//end of chosenOne

void addName()
{
    string newName;
    cout << "Enter the name to add: ";
    cin.ignore();
    getline(cin, newName);

    if(!newName.empty())
    {
        vector<string> names = loadNames();
        names.push_back(newName);
        saveNames(names);
        cout << newName << " has been added successfully!\n";
    }
}//end of addName

void deleteName()
{
    string targetName;
    cout << "Enter name to delete: ";
    cin.ignore();
    getline(cin, targetName);

    vector<string> names = loadNames();
    bool found = false;

    for (auto it = names.begin(); it != names.end(); ++it)
    {
        if(*it == targetName)
        {
            names.erase(it);
            found = true;
            break;
        }
    }

    if(found)
    {
        saveNames(names);
        cout << targetName << " has been deleted successfully!\n";
    }
    else
    {
        cout << "Name not found in the list.\n";
    }
}//end of deleteName

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int choice;

    do
    {
        cout << "\n=== Character List Menu ===\n";
        cout << "1. Pick a Random Name\n";
        cout << "2. Add a Name\n";
        cout << "3. Delete a Name\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\n Name Chosen: " << chosenOne() << endl;
                break;
            case 2:
                addName();
                break;
            case 3:
                deleteName();
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }

    }while (choice != 4);

    return 0;
}