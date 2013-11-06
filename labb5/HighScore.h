/* Daniel Lännström */
/* danlan01         */

#ifndef HIGHSCORE_H
#define HGIHSCORE_H

#include <string>
#include <vector>

#include "HighScorePost.h"
#include "IOutputer.h"
#include "Player.h"

using namespace std;

/**
 * Manages high score list and reading it from disk
 * @author Daniel Lannstrom
**/ 
class HighScore
{
    public:
        /**
          * Constructs a HighScore
        **/ 
        HighScore();

        /**
          * Clean-up
        **/ 
        virtual ~HighScore(); 

        /**
          * load data from file
          * @param path path to file 
        **/ 
        void loadFromFile(const string& path);

        /**
          * save data to file
          * @param path path to file 
        **/ 
        void saveToFile(const string& path);

        /**
          * add player interactively to highscore list if the players score is good enough
          * @param player player to add
          * @param ioutputer object used for I/O
        **/ 
        void addPlayerIfGoodEnough(const Player& player, const IOutputer& ioutputer);

        /**
          * prints entire high score list
          * @param ioutputer object used for I/O
        **/ 
        void printHighScores(const IOutputer& ioutputer) const;

    private:
        /**
          * inserts object into list if greater than the smallest object in vector
          * @param hsp object to insert
        **/ 
        void insertScore(const HighScorePost& hsp);

        /**
          * Helper function for loadFromFile. Inserts data from vectors.
          * @param names vector of names
          * @param scores vector of scores
        **/ 
        void loadNamesScores(const vector<string> names, const vector<int> scores);

        /**
          * returns whatever the score is good enough to be placed into the highscore list
        **/ 
        bool scoreGoodEnough(int score) const;

        /**
          * removes extra elemements from m_posts so it is max MAX_POSTS in size
        **/ 
        void removeExtras();

        const static unsigned int MAX_POSTS = 3;

        vector<HighScorePost> m_posts;
};

#endif
