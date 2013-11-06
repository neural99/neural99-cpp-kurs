/* Daniel Lännström */
/* danlan01         */

#ifndef OUTPUTER_H
#define OUTPUTER_H

#include <vector>
#include <string>
using namespace std;

#include "Die.h"

/**
  * Class responsible for outputing 
  * @author Daniel Lannstrom
**/ 
class IOutputer 
{
    public:

      /** 
        * prints an integer
        * @param d integer to print
      **/
      void printInt(int d) const;

      /**
        * prints a string
        * @param s string to print
      **/
      void printString(string s) const;
    
      /**
        * prints dice ascii art 
        * @param d die object to print
      **/
      void printDice(const Die& d) const;

      /** 
        * prints dice ascii art for 5 dices 
        * @param hand vector with die objects to print
      **/
      void printDieHand(const vector<Die>& hand) const;

      /** 
        * reads an integer from stdin
      **/
      int readInt() const;

    private:

      /**
        * Holds ascii art for dices
      **/
      static string msDices[6][5];

      /**
        * Number of lines in ascii art
      **/
      const static int ASCII_LINES = 5;
};

#endif  
