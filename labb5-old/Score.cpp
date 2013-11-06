/* Daniel Lännström */
/* danlan01         */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "IOutputer.h"
#include "ScorePost.h"
#include "Score.h"

using namespace std;

string Score::ms_postNames[15] = { "Ettor", "Tvåor", "Treor", "Fyror", "Femmor", "Sexor", "1 par", "2 par", 
                            "Triss", "Fyrtal", "Liten stege", "Stor stege", "Kåk   ", "Chans", "Yatsy" };

Score::Score()
{
    /* Create upper and lower ScorePosts */
    for (int i = 0; i < 6; i++) 
    {
        m_upper.push_back(ScorePost(i + 1, Score::ms_postNames[i]));
    }
    for (int i = 6; i < 15; i++) 
    {
        m_lower.push_back(ScorePost(i + 1, Score::ms_postNames[i]));
    }
}

Score::~Score()
{
}

int Score::calcUpperSum() const
{
    int sum = 0;
    vector<ScorePost>::const_iterator it;
    for (it = m_upper.begin(); it != m_upper.end(); ++it)
    {
        if (!it->isEmpty()) 
        {
            sum += it->getValue();
        } 
    }
    return sum;
}

int Score::calcLowerSum() const
{
    int sum = 0;
    vector<ScorePost>::const_iterator it;
    for (it = m_lower.begin(); it != m_lower.end(); ++it)
    {
        if (!it->isEmpty()) 
        {
            sum += it->getValue();
        } 
    }
    return sum;
}

int Score::calcSum() const
{
    return calcLowerSum() + calcBonus() + calcUpperSum();
}

int Score::calcBonus() const
{
    int sum = calcUpperSum();
    if (sum >= 63) 
    {
        /* Swedish version uses 50 */
        return 50;
    }
    return 0;
}

void Score::printPosts(const IOutputer& ioutputer) const
{
    vector<ScorePost>::const_iterator it;

    /* Header */
    ioutputer.printString("RESULTAT\n");

    /* Upper posts */
    for (it = m_upper.begin(); it != m_upper.end(); ++it) 
    {
        it->printPost(ioutputer);
    }

    /* Summary and bonus */
    int upperSum = calcUpperSum();
    ioutputer.printString("   Summa\t");
    ioutputer.printInt(upperSum);
    ioutputer.printString("\n");
    int bonus = calcBonus();
    ioutputer.printString("   Bonus\t");
    ioutputer.printInt(bonus);
    ioutputer.printString("\n");

    /* Lower posts */
    for (it = m_lower.begin(); it != m_lower.end(); ++it) 
    {
        it->printPost(ioutputer);
    }

    /* Total sum */
    int sum = calcSum(); 
    ioutputer.printString("   Summa\t");
    ioutputer.printInt(sum);
    ioutputer.printString("\n");
}

bool Score::isScoreFull() const
{
    return getEmptyPostNr().size() == 0;
}

vector<ScorePost>::iterator Score::getIterator(int index)
{
    if (index < 6) 
    {
        return (m_upper.begin() + index);
    } 
    else
    {
        return (m_lower.begin() + (index - 6));
    }
}

vector<ScorePost>::const_iterator Score::getConstIterator(int index) const
{
    if (index < 6) 
    {
        return (m_upper.begin() + index);
    } 
    else
    {
        return (m_lower.begin() + (index - 6));
    }
}

bool Score::isEmpty(int index) const
{
    return getConstIterator(index)->isEmpty();
}

void Score::placeValue(int index, int value)
{
    getIterator(index)->setValue(value);
}

bool Score::needToZeroBox(const vector<int>& allowed) const
{
    /* Is there an empty postition that is also valid? */
    vector<int>::const_iterator it;
    for (it = allowed.begin(); it != allowed.end(); ++it) 
    {
        if (isEmpty(*it - 1))
        {
            return false;
        }
    }
    return true;
}

const vector<int> Score::getEmptyPostNr() const
{
    /* Iterate and accumulate empty posts */
    vector<int> empty;
    for (int i = 1; i <= 15; i++) 
    {
        if (isEmpty(i - 1)) 
        {
            empty.push_back(i);
        } 
    }
    return empty;
}

void Score::zeroBox(const IOutputer& ioutputer)
{
    ioutputer.printString("Du måste strycka en post.\n");
    int post = ioutputer.readNumber("Välj post att strycka (1 - 15): ",
                         "Ogilltig post.\n",
                         getEmptyPostNr());
    int index = post - 1;
    placeValue(index, 0);
}
    
static void printVector(const vector<int>& vec)
{
    vector<int>::const_iterator it;
    for (it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << " ";
    }
}

void Score::placeHand(const IOutputer& ioutputer, const YatsyHand& yh)
{
    const vector<int> allowed = m_rules.getValidRows(yh.getDies());

    printVector(allowed); 

    if (needToZeroBox(allowed))
    {
        zeroBox(ioutputer);
    }
    else 
    {
        placeRealScore(ioutputer, yh, allowed);
    }
}

void Score::placeRealScore(const IOutputer& ioutputer, const YatsyHand& yh, const vector<int>& allowed)
{
    /* Until a valid choice has been read */
    while (true) 
    {
        int post = ioutputer.readNumber("Vart vill du placera slager? (1 - 15): ", 
                             "Ogilltig placering engligt Yatsy reglerna\n",
                             allowed);
        int index = post - 1;

        if (isEmpty(index))
        {
            placeValue(index, m_rules.placeDice(yh.getDies(), post));
            return;
        }
        else
        {
            ioutputer.printString("Ogilltig placering. Redan använd.\n");
        }
    }
}

