/* Daniel Lännström */
/* danlan01         */

#ifndef HIGHSCOREPOST_H
#define HGIHSCOREPOST_H

#include <string>

#include "IOutputer.h"

using namespace std;

/**
 * A post in a high score list
 * @author Daniel Lannstrom
**/ 
class HighScorePost
{
    public:
        /**
          * Constructs a HighScorePost
        **/ 
        HighScorePost(const string& name, int score);
        /**
          * Clean-up
        **/ 
        virtual ~HighScorePost();

        /**
          * Compares only the score
        **/ 
        bool operator<(const HighScorePost& hsp) const;
        /**
          * Compares only the score
        **/ 
        bool operator>(const HighScorePost& hsp) const;
        /**
          * Compares only the score
        **/ 
        bool operator==(const HighScorePost& hsp) const;

        /**
          *  Print post 
          *  @param ioutputer object used for I/O
        **/ 
        void printPost(const IOutputer& ioutputer) const;

        /**
          *  returns score
        **/ 
        int getScore() const;

        /**
          *  returns name
        **/ 
        const string getName() const;

    private:
        string m_name;
        int m_score;
};

#endif
