/* Daniel Lännström */
/* danlan01         */

#include "HighScorePost.h"

HighScorePost::~HighScorePost()
{
}

HighScorePost::HighScorePost(const string& name, int score)
{
    m_name = name;
    m_score = score;
}

bool HighScorePost::operator<(const HighScorePost& hsp) const
{
    return m_score < hsp.m_score;
}

bool HighScorePost::operator>(const HighScorePost& hsp) const
{
    return m_score > hsp.m_score;
}

bool HighScorePost::operator==(const HighScorePost& hsp) const
{
    return m_score == hsp.m_score;
}

int HighScorePost::getScore() const
{
    return m_score;
}

const string HighScorePost::getName() const
{
    return m_name;
}

void HighScorePost::printPost(const IOutputer& ioutputer) const
{
    ioutputer.printString(m_name);
    ioutputer.printString("\t");
    ioutputer.printInt(m_score);
    ioutputer.printString("\n");
}
