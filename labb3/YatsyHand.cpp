#include <vector>
#include <algorithm>
/*#include <iostream>*/

#include "YatsyHand.h"

/* Local helper-methods */
static bool isValueInVector(const vector<int>& vec, int value);
static int readDieNumber(const IOutputer& ioutputer, const vector<int>& rerolls);
/*static void printVec(const vector<int>& vec);*/

/** 
 * Is the value present in the vector?
 */
static bool isValueInVector(const vector<int>& vec, int value)
{
    return find(vec.begin(), vec.end(), value) != vec.end();
}

/** 
 * Prompts the user until a valid number has been read
 * @return index to m_dices
 */
static int readDieNumber(const IOutputer& ioutputer, const vector<int>& rerolls)
{
    /* Loop until a valid number has been read */
    while (true)  
    {
        int die = ioutputer.readNumber("Ange tärning att slå om (1 - 5): ", 1, 5);

        /* Index starts at 0 */
        int index = die - 1;

        if (isValueInVector(rerolls, index))
        {
            ioutputer.printString("Ogilltigt val. Du har redan valt denna tärning.\n");
        }
        else
        {
            return index;
        }
    }
}

/*
static void printVec(const vector<int>& vec)
{
    vector<int>::const_iterator it;
    for (it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}
*/

YatsyHand::YatsyHand()
{
    /* Create 5 dices */
    for (int i = 0; i < YatsyHand::NR_DICES; i++) 
    {
        m_dices.push_back(Die());
    } 
}

YatsyHand::~YatsyHand()
{
}

void YatsyHand::rerollAll()
{
    vector<int> rerolls;
    for (int i = 0; i < YatsyHand::NR_DICES; i++) 
    {
        rerolls.push_back(i);
    }
    reroll(rerolls);
}

void YatsyHand::reroll(const vector<int>& rerolls)
{
    vector<int>::const_iterator iter;
    /* Threat the integers as indices */
    for (iter = rerolls.begin(); iter != rerolls.end(); ++iter)
    {
        m_dices.at(*iter).rollDie();
    }
}


void YatsyHand::reroll(const IOutputer& ioutputer)
{
    int nr = ioutputer.readNumber("Hur många tärningar vill du slå om? ", 1, 5);

    vector<int> rerolls;

    /* Do we need to ask which dices to reroll */
    if (nr == YatsyHand::NR_DICES) 
    {
        rerollAll();
    } 
    else 
    {
        for (int i = 0; i < nr; i++) 
        {
            rerolls.push_back(readDieNumber(ioutputer, rerolls));
        }

        /*printVec(rerolls);*/

        reroll(rerolls);
    }
}

void YatsyHand::printHand(const IOutputer& ioutputer) const
{
    ioutputer.printDieHand(m_dices);
}


