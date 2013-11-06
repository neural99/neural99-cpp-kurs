/* Daniel Lännström */
/* danlan01         */

#ifndef PLAYER_H
#define PLAYER_H

#include "IOutputer.h"
#include "Score.h"
#include "YatsyHand.h"

/**
 * A player with score and dies and a unique number
 * @author Daniel Lannstrom
**/ 
class Player
{
    public:
        /**
          * Constructs a player
          * @param nr the number of this player
        **/ 
        Player(int nr);

        /**
          * Clean-up
        **/ 
        virtual ~Player();

        /**
          * Interactive turn in which the player rolls the dies upto 3 times
          * and places the score according to the rules
          * @param ioutputer IOutputer used for I/O
        **/ 
        void doTurn(const IOutputer& ioutputer);

        /**
          * Returns total score
        **/ 
        int finalScore() const;

        /**
          * Prints final score
          * @param ioutputer object used for I/O
        **/ 
        void printFinalScore(const IOutputer& ioutputer) const;

        /**
          * Returns true if the game is over i.e the score board is full
        **/ 
        bool isGameOver() const;

        /**
          * Returns the player's number
        **/ 
        int getNr() const;

    private:
        Score m_score;
        YatsyHand m_hand;
        int m_nr;
};

#endif
