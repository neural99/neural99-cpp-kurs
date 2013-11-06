/* Daniel Lännström */
/* danlan01         */

#include <vector>
#include <iostream>

#include "YatsyProgram.h"

const string YatsyProgram::HIGHSCORE_FILENAME = "highscore.txt";

void YatsyProgram::createPlayers(const IOutputer& ioutputer)
{
    int players = ioutputer.readNumber("Hur många spelare (1+)? ", 1, YatsyProgram::MAX_PLAYERS);

    for (int i = 0; i < players; i++) 
    {
        m_players.push_back(Player(i + 1));
    }
}

void YatsyProgram::printFinalScores(const IOutputer& ioutputer) const
{
    vector<Player>::const_iterator it;
    for (it = m_players.begin(); it != m_players.end(); ++it) 
    {
        it->printFinalScore(ioutputer);
    }
}

void YatsyProgram::doHighscore(const IOutputer& ioutputer)
{
    vector<Player>::const_iterator it;
    for (it = m_players.begin(); it != m_players.end(); ++it) 
    {
        m_highscore.addPlayerIfGoodEnough(*it, ioutputer);
    }
}

bool YatsyProgram::rollOrQuit(const IOutputer& ioutputer)
{
    /* Until a valid alternative has been chosen */
    while (true) 
    {
        char c = ioutputer.readCharacter("Vill du slå tärningar (s) eller avsluta (a)? ");
        if (c == 'a')
        {
            return false; 
        } 
        else if (c == 's')
        {
            return true;
        }
    }
}

void YatsyProgram::run()
{
    IOutputer ioutputer;

    ioutputer.printString("Välkommen till Yatsy!\n\n");

    /* Load and display highscore */
    m_highscore.loadFromFile(YatsyProgram::HIGHSCORE_FILENAME);
    ioutputer.printString("Highscore:\n");
    m_highscore.printHighScores(ioutputer);

    createPlayers(ioutputer);

    /* Until Game Over */
    while (!m_players.begin()->isGameOver()) 
    {
        if (!rollOrQuit(ioutputer))
        {
            break;
        }
        else
        {
            vector<Player>::iterator it;
            for (it = m_players.begin(); it != m_players.end(); ++it) 
            {
                it->doTurn(ioutputer);
            }
        }
    }

    ioutputer.printString("----------------------\n");
    ioutputer.printString("Spel slut\n");
    ioutputer.printString("----------------------\n");

    printFinalScores(ioutputer);

    /* Adds players to highscore list and save it to disk */
    doHighscore(ioutputer);
    m_highscore.saveToFile(YatsyProgram::HIGHSCORE_FILENAME);
}
