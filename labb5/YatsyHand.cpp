/* Daniel Lännström */
/* danlan01         */

#include <vector>
#include <algorithm>
#include <iostream>

#include "YatsyHand.h"

vector<int> YatsyHand::getAllowedValues(const vector<int>& rerolls) const
{
    vector<int> full;
    for (int i = 1; i <= YatsyHand::NR_DICES; i++)
    {
        full.push_back(i);
    }

    /* Delete dices already chosen */
    vector<int>::const_iterator it;
    for (it = rerolls.begin(); it != rerolls.end(); ++it) 
    {
        remove(full.begin(), full.end(), *it + 1);
    }

    return full;
}

int YatsyHand::readDieNumber(const IOutputer& ioutputer, const vector<int>& rerolls) const
{
    int die = ioutputer.readNumber("Ange tärning att slå om (1 - 5): ", "Ogilltigt val. Du har redan valt denna tärning.\n", getAllowedValues(rerolls));
    /* Index start at 0 */
    return die - 1;
}

void YatsyHand::printVec(const vector<int>& vec)
{
    vector<int>::const_iterator it;
    for (it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

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

bool YatsyHand::reroll(const IOutputer& ioutputer)
{
    int nr = ioutputer.readNumber("Hur många tärningar vill du slå om? ", 0, 5);

    vector<int> rerolls;

    /* Do we need to ask which dices to reroll */
    if (nr == YatsyHand::NR_DICES) 
    {
        rerollAll();
        return true;
    } 
    else if (nr == 0)  /* Aborting */
    {
        return false;
    }
    else 
    {
        for (int i = 0; i < nr; i++) 
        {
            rerolls.push_back(readDieNumber(ioutputer, rerolls));
        }

        //printVec(rerolls);

        reroll(rerolls);
    }

    return true;
}

void YatsyHand::printHand(const IOutputer& ioutputer) const
{
    ioutputer.printDieHand(m_dices);
}

vector<Die> YatsyHand::getDies() const
{
    return m_dices;
}
