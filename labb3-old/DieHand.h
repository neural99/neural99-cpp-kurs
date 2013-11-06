/* Daniel Lännström */
/* danlan01         */

#ifndef DIEHAND_H
#define DIEHAND_H

#include <vector>
using namespace std;

#include "Die.h"
#include "IOutputer.h"

/**
  * Class responsible for a hand of dies
  * @author Daniel Lannstrom
**/ 
class DieHand
{
    public:
        /**
          * Constructs a DieHand with 5 dices
        **/ 
        DieHand();
        
        /**
          * Clean-up
        **/ 
        virtual ~DieHand();

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

        /**
          * Reroll all dices
        **/ 
        void rerollAll();
            
        /**
          * Reroll dices whose indices are in rerolls
          * @param rerolls indices to m_dices
        **/ 
        void reroll(const vector<int> rerolls);
    
    private:
        /**
          * vector with the dices
        **/
        vector<Die> m_dices;
};

#endif
