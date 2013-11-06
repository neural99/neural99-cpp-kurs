/* Daniel Lännström */
/* danlan01         */

#ifndef YATSYHAND_H
#define YATSYHAND_H

#include <vector>
using namespace std;

#include "Die.h"
#include "IOutputer.h"

/**
  * Class responsible for a hand of dies
  * @author Daniel Lannstrom
**/ 
class YatsyHand
{
    public:
        /**
          * Constructs a DieHand with 5 dices
        **/ 
        YatsyHand();
        
        /**
          * Clean-up
        **/ 
        virtual ~YatsyHand();

        /**
          * Interactive re-roll
          * @param ioutputer IOutputer used for I/O
          * @return returns true if user wants to continue rolling
        **/ 
        bool reroll(const IOutputer& ioutputer);

        /**
          * Print hand using IOutputer
          * @param ioutputer IOutputer used for I/O
        **/ 
        void printHand(const IOutputer& ioutputer) const;

        vector<Die> getDies() const;

        /**
          * Reroll all dices
        **/ 
        void rerollAll();

    private:

        /** 
         * Prompts the user until a valid number has been read
         * @return index to m_dices
        **/
        int readDieNumber(const IOutputer& ioutputer, const vector<int>& rerolls) const;

        /** 
         * Returns dices still valid for selection by user
        **/
        vector<int> getAllowedValues(const vector<int>& rerolls) const; 

            
        /**
          * Reroll dices whose indices are in rerolls
          * @param rerolls indices to m_dices
        **/ 
        void reroll(const vector<int>& rerolls);

        /**
          * Static helper function
        **/
        static void printVec(const vector<int>& vec);

        const static int NR_DICES = 5;

        /**
          * vector with the dices
        **/
        vector<Die> m_dices;

};

#endif
