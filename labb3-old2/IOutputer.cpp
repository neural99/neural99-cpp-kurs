/* Daniel Lännström */
/* danlan01         */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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

void IOutputer::printString(string s) const
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

/* FIXME: Make this handle EOF so the user can abort with Ctrl-D */
int IOutputer::readNumber(string prompt, int lowerBound, int upperBound) const
{
    int i = lowerBound-1;

    printString(prompt);

    while (! (readInt(i) &&  i >= lowerBound && i <= upperBound))
    {
        printString("Ogilltig inmatning. Försök igen.\n");
        printString(prompt);
    }
    return i;
}
