/* Daniel Lännström */
/* danlan01         */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "IOutputer.h"

using namespace std;

/* The dices */
string IOutputer::msDices[6][5] = { 
                         {  "-------",
                            "|     |",
                            "|  *  |",
                            "|     |",
                            "-------" }
                            ,
                         {  "-------",
                            "|  *  |", 
                            "|     |",
                            "|  *  |",
                            "-------" }
                            ,
                         {  "-------",
                            "| *   |",
                            "|  *  |",
                            "|   * |",
                            "-------" }
                            ,
                         {  "-------",
                            "| * * |",
                            "|     |",
                            "| * * |",
                            "-------" }
                            ,
                         {  "-------",
                            "| * * |",
                            "|  *  |",
                            "| * * |",
                            "-------" }
                            ,
                         {  "-------",
                            "| * * |",
                            "| * * |",
                            "| * * |",
                            "-------" }};

void IOutputer::printInt(int d) const
{
     cout << d;
}

void IOutputer::printString(const string& s) const
{
     cout << s;
}

void IOutputer::printDieHand(const vector<Die>& hand) const
{
    stringstream ss;
    vector<Die>::const_iterator iter;
    int i;

    /* Loop over the lines */
    for (i = 0; i < IOutputer::ASCII_LINES; i++) 
    {
        /* Loop over the dices */
        for (iter = hand.begin(); iter != hand.end(); ++iter)
        {
            int dieValue = (*iter).getDieValue();
            /* Add a space between to make it look better */
            ss << IOutputer::msDices[dieValue-1][i] << " "; 
        }
        ss << endl;
    }
    cout << ss.str() << endl;
}

/* I modified Die to make it possible to a const Die reference */
void IOutputer::printDice(const Die& d) const
{
    /* We just assume the die has 6 sides. No way of finding out. */
    int dieValue = d.getDieValue();
    for (int i = 0; i < 5; i++)
    {
        cout << IOutputer::msDices[dieValue-1][i] << endl;
    }
}

bool IOutputer::readInt(int& outInt) const
{
    /* Eat a line */
    string str;
    getline(cin, str);
    
    int i = 0;
    stringstream ss(str);
    ss >> i;

    if (ss.fail()) 
    {
        return false;
    }
    else 
    {
        outInt = i;
        return true;
    }
}

bool IOutputer::readChar(char& outChar) const
{
    /* Eat a line */
    string str;
    getline(cin, str);
    
    char ch = '\0';
    stringstream ss(str);
    ss >> ch;

    if (ss.fail()) 
    {
        return false;
    }
    else 
    {
        outChar = ch;
        return true;
    }
}

bool IOutputer::readStr(string& outString) const
{
    /* Eat a line */
    string str;
    getline(cin, str);
    
    outString = str;
    return true;
}

char IOutputer::readCharacter(const string& prompt) const
{
    char ch = '\0';
    
    printString(prompt);

    while (!readChar(ch)) 
    {
        printString("Ogilltig inmatning. Försök igen.\n");
        printString(prompt);
    }
    return ch;
}

int IOutputer::readNumber(const string& prompt, int lowerBound, int upperBound) const
{
    int i = lowerBound-1;

    printString(prompt);

    /* Until a valid number has been read */
    while (! (readInt(i) &&  i >= lowerBound && i <= upperBound))
    {
        printString("Ogilltig inmatning. Försök igen.\n");
        printString(prompt);
    }
    return i;
}

static bool isValueInVector(const vector<int>& vec, int value)
{
    return find(vec.begin(), vec.end(), value) != vec.end();
}

int IOutputer::readNumber(const string& prompt, const string& errorPrompt, const vector<int>& allowedValues) const
{
    /* Copy the vector and sort it */
    vector<int> tmp; 
    tmp.resize(allowedValues.size());
    copy(allowedValues.begin(), allowedValues.end(), tmp.begin());
    sort(tmp.begin(), tmp.end());

    int lower = *tmp.begin();
    int upper = *(tmp.end() - 1);

    /* Loop until a valid number has been read */
    while (true) 
    {
        int integer = readNumber(prompt, lower, upper);
        if (isValueInVector(tmp, integer))
        {
            return integer;
        }
        else
        {
            printString(errorPrompt);
        }
    }
}

string IOutputer::readString(const string& prompt) const
{
    string str = "";

    printString(prompt);

    while (!readStr(str))
    {
        printString("Ogilltig inmatning. Försök igen.\n");
        printString(prompt);
    }
    return str;
}
