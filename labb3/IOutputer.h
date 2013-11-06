/* Daniel Lännström */
/* danlan01         */

#ifndef IOUTPUTER_H
#define IOUTPUTER_H

#include <vector>
#include <string>
using namespace std;

#include "Die.h"

/**
  * Class responsible for inputing and outputing 
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
        * prints dice ascii art for 5 dices side by side
        * @param hand vector with die objects to print
      **/
      void printDieHand(const vector<Die>& hand) const;

      /** 
        * reads an integer from stdin
        * @param outInt this variable is set to the result
        * @return whatever the operation was successful
      **/
      bool readInt(int& outInt) const;

      /** 
        * reads an integer from stdin with constraints
        * @param prompt printed before input
        * @param lowerBound make sure input is greater or equal to this
        * @param uppserBound make sure input is less or equal to this
        * @return read integer
      **/
      int readNumber(string prompt, int lowerBound, int upperBound) const;

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
