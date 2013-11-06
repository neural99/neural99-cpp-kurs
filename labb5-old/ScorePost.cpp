/* Daniel Lännström */
/* danlan01         */

#include <iostream>
#include <string>

#include "ScorePost.h"

using namespace std;

ScorePost::ScorePost(int nr, const string& name)
{
    m_nr = nr;
    m_name = name;
    m_value = -1;
}   

ScorePost::~ScorePost()
{
}

bool ScorePost::isEmpty() const
{
    return m_value == -1;
}

void ScorePost::setValue(int newValue)
{
    m_value = newValue;
}

const int ScorePost::getValue() const
{
    return m_value;
}

const int ScorePost::getNr() const
{
    return m_nr;
}

const string ScorePost::getName() const
{
    return m_name;
}

void ScorePost::printPost(const IOutputer& ioutputer) const
{
    int nr = getNr();
    /* Align the numbers */
    if (nr < 10)
    {
        ioutputer.printString(" ");
    }

    ioutputer.printInt(nr);
    ioutputer.printString(" ");
    ioutputer.printString(getName());

    /* Do we want to print the value? */
    if (!isEmpty()) 
    {
        ioutputer.printString("\t");
        ioutputer.printInt(getValue());
    }

    ioutputer.printString("\n");
}
