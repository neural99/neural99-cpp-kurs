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
        **/ 
        void reroll(const IOutputer& ioutputer);

        /**
          * Print hand using IOutputer
          * @param ioutputer IOutputer used for I/O
        **/ 
        void printHand(const IOutputer& ioutputer) const;

    private:

        const static int NR_DICES = 5;

        /**
          * Reroll all dices
        **/ 
        void rerollAll();
            
        /**
          * Reroll dices whose indices are in rerolls
          * @param rerolls indices to m_dices
        **/ 
        void reroll(const vector<int>& rerolls);

        /**
          * vector with the dices
        **/
        vector<Die> m_dices;
};

#endif
