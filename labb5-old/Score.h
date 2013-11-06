/* Daniel Lännström */
/* danlan01         */

#ifndef SCORE_H
#define SCORE_H

#include <string>
#include <vector>

#include "YatzyRules.h"
#include "IOutputer.h"
#include "ScorePost.h"
#include "YatsyHand.h"

using namespace std;

/**
 * Manages score for a player
 * @author Daniel Lannstrom
**/ 
class Score 
{
    public:
        /**
          * Constructs a Score with 15 score posts
        **/ 
        Score();

        /**
          * Clean-up
        **/ 
        virtual ~Score();

        /**
          * Print all posts 
          * @param ioutputer IOutputer used for I/O
        **/ 
        void printPosts(const IOutputer& ioutputer) const;

        /**
          * Calculate score for lower posts
        **/ 
        int calcLowerSum() const;

        /**
          * Calculate score for upper posts
        **/ 
        int calcUpperSum() const;

        /**
          * Calculate total score
        **/ 
        int calcSum() const;

        /**
          * Calculate bonus score for upper posts
        **/ 
        int calcBonus() const;

        /**
          * Interactive placement of hand 
          * @param ioutputer IOutputer used for I/O
          * @param hand YatsyHand to place
        **/ 
        void placeHand(const IOutputer& ioutputer, const YatsyHand& hand);

        /**
          * Checks if scoreboard is full (i.e. game is over)
        **/ 
        bool isScoreFull() const;

    private:
        /**
          * Get const iterator in to the right vector based on index
        **/ 
        vector<ScorePost>::const_iterator getConstIterator(int index) const;

        /**
          * Get iterator in to the right vector based on index
        **/ 
        vector<ScorePost>::iterator getIterator(int index);

        /**
          * Checks if a post on a certain index is empty
        **/ 
        bool isEmpty(int index) const;        

        /**
          * Writes the value to corresponding ScorePost
        **/ 
        void placeValue(int index, int value);

        /**
          * Determines if we need to zero out a post
        **/ 
        bool needToZeroBox(const vector<int>& allowed) const;

        /**
          * Returns a vector of empty posts
        **/ 
        const vector<int> getEmptyPostNr() const;

        /**
          * Interactive zeroing of a post
        **/ 
        void zeroBox(const IOutputer& ioutpuer); 

        /**
          * Interactively place a real score post (not zeroing) 
        **/ 
        void placeRealScore(const IOutputer& ioutputer, const YatsyHand& yh, const vector<int>& allowed);

        YatzyRules m_rules;

        vector<ScorePost> m_upper;
        vector<ScorePost> m_lower;

        /**
          * Names used for printing purposes
        **/ 
        static string ms_postNames[15];
};

#endif
