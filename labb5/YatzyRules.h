#ifndef YATZYRULES_H
#define YATZYRULES_H

#include <vector>
#include "Die.h"
#include "YatzyRowRule.h"

using std::vector;

/**
 * Handles the rules for the game yatzy, also see http://sv.wikibooks.org/wiki/Yatzy
 *
 * Works with the rows (1 - 15) in yatzy as follows
 * 1 - One
 * 2 - Two
 * 3 - Tree
 * 4 - Four
 * 5 - Five
 * 6 - Six
 * 7 - Pair
 * 8 - Two pair
 * 9 - Three Equal
 * 10 - Four Equal
 * 11 - Small Straight
 * 12 - Large Straight
 * 13 - Full House
 * 14 - Chanse
 * 15 - Yatzy
 */
class YatzyRules
{
  public:   
	/**
	 * Contructs the yatzy rules
	 */
	YatzyRules();
    YatzyRules(const YatzyRules&);
	/**
	 * Release allocated resources
	 */
	virtual ~YatzyRules();

	/**
	 * Checks if it is legal to place the dice in the row and calculates the score if it was legal
	 * 
	 * @param dice the five dice that we want to place
	 * @param row the row we want to place the dice at (1 - 15)	  
	 * @return int the score, -1 if it is not legal to place the dice in the row
	 */
	const int placeDice(vector<Die> dice, int row);
	/**
	 * Return all valid rows for the dice. Note that it is for example valid to put five
	 * fours on the row for ones even if it will give zero points.
	 *
	 * @param dice the five dice we want to check valid rows for
	 * @return vector<int> all valid rows
	 */
	const vector<int> getValidRows(vector<Die> dice);
  private:
	vector<YatzyRowRule*> mRows;
};

#endif
