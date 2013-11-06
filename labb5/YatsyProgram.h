/* Daniel Lännström */
/* danlan01         */

#ifndef YATSYPROGRAM_H
#define YATSYPROGRAM_H

#include <vector>

#include "IOutputer.h"
#include "YatsyHand.h"
#include "Score.h"
#include "Player.h"
#include "HighScore.h"

using namespace std;

/**
  * Main class. Manages Players and Highscore
  * @author Daniel Lannstrom
**/ 
class YatsyProgram
{
    public:
        /**
          * Run the program
        **/ 
        void run();

    private:
        /**
          * Prints the resulting scores for all players
          * @param ioutputer object used for I/O
        **/ 
        void printFinalScores(const IOutputer& ioutputer) const;

        /**
          * Ask the user how many players should be created and create so many
          * @param ioutputer object used for I/O
        **/ 
        void createPlayers(const IOutputer& ioutputer);

        /**
          * Adds the players scores to the highscore list if good enough
          * @param ioutputer object used for I/O
        **/ 
        void doHighscore(const IOutputer& ioutputer);

        /**
          * Ask the user if we should roll dice or quit the program
          * @param ioutputer object used for I/O
          * @return true if the user wants to continue
        **/ 
        bool rollOrQuit(const IOutputer& ioutputer);

        vector<Player> m_players;

        HighScore m_highscore;

        /**
          * Maximum players, used as a safeguard 
        **/ 
        const static int MAX_PLAYERS = 99;

        /**
          * Filename used for highscore file
        **/ 
        const static string HIGHSCORE_FILENAME;
};

#endif
