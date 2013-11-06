/* Daniel Lännström */
/* danlan01         */

#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

#include "HighScore.h"

HighScore::HighScore()
{
}

HighScore::~HighScore()
{
}

void HighScore::loadNamesScores(const vector<string> names, const vector<int> scores) 
{
    vector<string>::const_iterator it1;
    vector<int>::const_iterator it2;
    for (it1 = names.begin(), it2 = scores.begin(); it1 != names.end(); ++it1, ++it2)
    {
/*        cout << *it1 << "\t" << *it2 << endl; */
        insertScore(HighScorePost(*it1, *it2));
    }
}

void HighScore::loadFromFile(const string& path)
{
    vector<string> names;
    vector<int> scores;

    string str; 

    string name;
    int score;

    ifstream ifs(path.c_str());

    while (true)
    {
        getline(ifs, str);
        if (!ifs.good()) /* EOF */
        {
            break;
        }
        stringstream ss(str);
        ss >> name;
        ss >> score;

        names.push_back(name);
        scores.push_back(score);
    }
    
    loadNamesScores(names, scores);
}

void HighScore::saveToFile(const string& path)
{
    ofstream ofs(path.c_str());

    vector<HighScorePost>::const_reverse_iterator it;
    for (it = m_posts.rbegin(); it != m_posts.rend(); ++it)
    {
        ofs << it->getName() << "\t" << it->getScore() << endl;
    }
}

bool HighScore::scoreGoodEnough(int score) const
{
    if ((m_posts.size() < HighScore::MAX_POSTS) || (m_posts.begin()->getScore() < score)) 
    {
        return true;
    }
    return false;
}

void HighScore::addPlayerIfGoodEnough(const Player& player, const IOutputer& ioutputer)
{
    int score = player.finalScore();
    if (scoreGoodEnough(score)) 
    {
        ioutputer.printString("Grattis spelare ");
        ioutputer.printInt(player.getNr());
        ioutputer.printString("! Du har hamnat på highscore-listan!\n");

        string name = ioutputer.readString("Skriv in ditt namn: ");
        insertScore(HighScorePost(name, score));
    }
}


void HighScore::insertScore(const HighScorePost& hsp)
{
    if ((m_posts.size() < HighScore::MAX_POSTS) || (*m_posts.begin() < hsp)) 
    {
        m_posts.push_back(hsp);    
        sort(m_posts.begin(), m_posts.end());
        removeExtras();
    }
}

void HighScore::removeExtras()
{
    /* Erase until length is acceptable */
    while (m_posts.size() > HighScore::MAX_POSTS)
    {
        m_posts.erase(m_posts.begin());
    }
}

void HighScore::printHighScores(const IOutputer& ioutputer) const
{
    /* Iterate from back to fron */
    vector<HighScorePost>::const_reverse_iterator it;
    for (it = m_posts.rbegin(); it != m_posts.rend(); ++it)
    {
        it->printPost(ioutputer);
    }
}
