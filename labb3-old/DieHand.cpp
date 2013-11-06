#include <vector>

#include "DieHand.h"

DieHand::DieHand()
{
    for (int i = 0; i < 5; i++) 
    {
        m_dices.push_back(Die());
    } 
}

DieHand::~DieHand()
{
}

void DieHand::rerollAll()
{
    vector<int> rerolls;
    for (int i = 0; i < 5; i++) 
    {
        rerolls.push_back(i);
    }
    reroll(rerolls);
}

void DieHand::reroll(const vector<int> rerolls)
{
    vector<int>::const_iterator iter;
    for (iter = rerolls.begin(); iter != rerolls.end(); ++iter)
    {
        m_dices[*iter].rollDie();
    }
}

void DieHand::reroll(const IOutputer& ioutputer)
{
    ioutputer.printString("Hur många tärningar vill du slå om? ");
    int nr = ioutputer.readInt(); 

    vector<int> rerolls(nr);

    if (nr == 5) 
    {
        rerollAll();
    } 
    else 
    {
        for (int i = 0; i < nr; i++) 
        {
            ioutputer.printString("Ange tärning att slå om (1 - 5): ");
            int die = ioutputer.readInt();
            
            rerolls.push_back(die-1);
        }

        reroll(rerolls);
    }
}

void DieHand::printHand(const IOutputer& ioutputer) const
{
    ioutputer.printDieHand(m_dices);
}


