#include <vector>

#include "YatsyHand.h"

YatsyHand::YatsyHand()
{
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

void YatsyHand::reroll(const vector<int> rerolls)
{
    vector<int>::const_iterator iter;
    for (iter = rerolls.begin(); iter != rerolls.end(); ++iter)
    {
        m_dices.at(*iter).rollDie();
    }
}

void YatsyHand::reroll(const IOutputer& ioutputer)
{
    int nr = ioutputer.readNumber("Hur många tärningar vill du slå om? ", 1, 5);

    vector<int> rerolls(nr);

    /* Do we need to ask which dices to reroll */
    if (nr == YatsyHand::NR_DICES) 
    {
        rerollAll();
    } 
    else 
    {
        for (int i = 0; i < nr; i++) 
        {
            int die = ioutputer.readNumber("Ange tärning att slå om (1 - 5): ", 1, 5);
            
            /* Index start at 0 */
            rerolls.push_back(die-1);
        }

        reroll(rerolls);
    }
}

void YatsyHand::printHand(const IOutputer& ioutputer) const
{
    ioutputer.printDieHand(m_dices);
}


