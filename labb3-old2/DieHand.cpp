#include <vector>

#include "DieHand.h"

DieHand::DieHand()
{
    for (int i = 0; i < DieHand::NR_DICES; i++) 
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
    for (int i = 0; i < DieHand::NR_DICES; i++) 
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
        m_dices.at(*iter).rollDie();
    }
}

void DieHand::reroll(const IOutputer& ioutputer)
{
    int nr = ioutputer.readNumber("Hur många tärningar vill du slå om? ", 1, 5);

    vector<int> rerolls(nr);

    if (nr == DieHand::NR_DICES) 
    {
        rerollAll();
    } 
    else 
    {
        for (int i = 0; i < nr; i++) 
        {
            int die = ioutputer.readNumber("Ange tärning att slå om (1 - 5): ", 1, 5);
            
            rerolls.push_back(die-1);
        }

        reroll(rerolls);
    }
}

void DieHand::printHand(const IOutputer& ioutputer) const
{
    ioutputer.printDieHand(m_dices);
}


