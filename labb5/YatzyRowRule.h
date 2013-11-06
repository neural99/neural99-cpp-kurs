#ifndef YATZYROWRULE_H
#define YATZYROWRULE_H

#include <vector>
#include <algorithm>
#include "Die.h"

using std::vector;

/**
 * An interface for classes that can determine the score for a set of dice on a specific
 * yatzy row (full house, straight etc). 
 */
class YatzyRowRule
{
  public:
	YatzyRowRule() {};
	virtual ~YatzyRowRule() {};
	/**
	 * Calculates the score for the dice if they were placed in the row
	 *
	 * @param dice the five dice we want to place in the row
	 * @return int the score or -1 if the dice are not valid for the row
	 */
	virtual int calculateResult(vector<Die> Dice) = 0;
};

/**
 * Can calculates the score for a row (1 - 6)
 */
class OnesToSixes : public YatzyRowRule
{
  public:
	/**
	 * Construct a class to calculate score for a row (1 - 6)
	 *
	 * @param dieValue the die value that the class should check against (1 - 6)
	 */
	OnesToSixes(int dieValue): mDieValue(dieValue) {};
	/**
	 * Cleans up allocated resources
	 */
	~OnesToSixes() {};
	/*
     * @see YatzyRowRule#calculateResult(vector<Die> dice)
     */
	int calculateResult(vector<Die> dice)
	{
		int score = 0;

		for(int i = 0; i < 5; i ++)
		{
			if(dice[i].getDieValue() == mDieValue)
			{
				score += dice[i].getDieValue();
			}
		}
		return score;
	};
  private:
	int mDieValue;
};
/**
 * Can calculates the score for a row (one pair, three of a kind, four of a kind and yatzy)
 */
class Equal : public YatzyRowRule
{
  public:
	/**
	 * Construct a class to calculate score for a row (one pair, three of a kind, four of a kind and yatzy)
	 *
	 * @param numberOfEqual how many equal the class should look for
	 */
	Equal(int numberOfEqual) : mNumberOfEqual(numberOfEqual) {}
	/**
	 * Cleans up allocated resources
	 */
	~Equal() {}
	/*
     * @see YatzyRowRule#calculateResult(vector<Die> dice)
     */
	int calculateResult(vector<Die> dice)
	{
		int value = 0;
		int score = -1;
		
		sort(dice.begin(), dice.end());
		reverse(dice.begin(), dice.end());

		for(int i = 0; i < 4; i ++)
		{
			for(int j = i + 1; j < 5 && dice[i] == dice[j]; j ++)
			{
				if(j - i  + 1 == mNumberOfEqual)
				{
					value = dice[i].getDieValue();
					i = j = 5;
				}				
			}
		}		
		if(value > 0 && mNumberOfEqual == 5)
		{
			score = 50;
		}
		else if(value > 0)
		{
			score = value * mNumberOfEqual;
		}
		return score;
	}
  private:
	int mNumberOfEqual;
};
/**
 * Can calculates the score for the row two pairs
 */
class TwoPair : public YatzyRowRule
{
  public:
  	/**
	 * Construct a class to calculate score for the row two pairs	 
	 */
	TwoPair() {}
	/**
	 * Cleans up allocated resources
	 */
	~TwoPair() {}
	/*
     * @see YatzyRowRule#calculateResult(vector<Die> dice)
     */
	int calculateResult(vector<Die> dice)
	{
		int score = -1;
		int value1 = 0, value2 = 0;

		sort(dice.begin(), dice.end());

		for(int i = 0; i < 4; i ++)
		{
			for(int j = i + 1; j < 5 && dice[i].getDieValue() == dice[j].getDieValue(); j ++)
			{
				if(j - i  + 1 == 2)
				{
					value1 = dice[i].getDieValue();
					i = j = 5;
				}				
			}
		}

		sort(dice.begin(), dice.end());
		reverse(dice.begin(), dice.end());

		for(int i = 0; i < 4; i ++)
		{
			for(int j = i + 1; j < 5 && dice[i].getDieValue() == dice[j].getDieValue(); j ++)
			{
				if(j - i  + 1 == 2)
				{
					value2 = dice[i].getDieValue();
					i = j = 5;
				}				
			}
		}	
		if(value1 != 0 && value2 != 0 && value1 != value2)
		{
			score = value1 * 2 + value2 * 2;
		}
		return score;
	}
};
/**
 * Can calculates the score for the rows big and small straight
 */
class Straight : public YatzyRowRule
{
  public:
	/**
	 * Construct a class to calculate score for the rows big and small straight
	 *
	 * @param startValue the start value for the straight (1 for small or 2 for big)
	 */
	Straight(int startValue) : mStartValue(startValue) {}
	/**
	 * Cleans up allocated resources
	 */	
	~Straight() {}
	/*
     * @see YatzyRowRule#calculateResult(vector<Die> dice)
     */
	int calculateResult(vector<Die> dice)
	{
		int numberOfEqual = 0;
		int score = -1;
		
		sort(dice.begin(), dice.end());

		for(int j = 0, i = mStartValue; i < mStartValue + 5; i ++)
		{
			if(i == dice[j ++].getDieValue())
			{
				numberOfEqual ++;
			}
		}	
		if(numberOfEqual == 5)
		{
			score = 15 + 5 * (mStartValue - 1);
		}
		return score;
	}
  private:
	int mStartValue;
};
/**
 * Can calculates the score for the row full house
 */
class FullHouse : public YatzyRowRule
{
  public:
	/**
	 * Construct a class to calculate score for the row full house
	 */
	FullHouse() {}
	/**
	 * Cleans up allocated resources
	 */
	~FullHouse() {}
	/*
     * @see YatzyRowRule#calculateResult(vector<Die> dice)
     */
	int calculateResult(vector<Die> dice)
	{
		int score = -1;
		int valueThree = 0, valueTwo = 0;
		
		sort(dice.begin(), dice.end());

		for(int i = 0; i < 4; i ++)
		{
			for(int j = i + 1; j < 5 && dice[i].getDieValue() == dice[j].getDieValue(); j ++)
			{
				if(j - i  + 1 == 3)
				{
					valueThree = dice[i].getDieValue();
					i = j = 5;
				}				
			}
		}
		for(int i = 0; i < 4; i ++)
		{
			for(int j = i + 1; j < 5 && dice[i].getDieValue() == dice[j].getDieValue(); j ++)
			{
				if(j - i  + 1 == 2)
				{
					valueTwo = dice[i].getDieValue();
					i = j = 5;
				}				
			}
		}

		if(valueThree == valueTwo)
		{			
			reverse(dice.begin(), dice.end());

			for(int i = 0; i < 4; i ++)
			{
				for(int j = i + 1; j < 5 && dice[i].getDieValue() == dice[j].getDieValue(); j ++)
				{
					if(j - i  + 1 == 2)
					{
						valueTwo = dice[i].getDieValue();
						i = j = 5;
					}				
				}
			}
		}
		if(valueThree != 0 && valueTwo != 0 && valueThree != valueTwo)
		{
			score = valueThree * 3 + valueTwo * 2;
		}
		return score;
	}
};
/**
 * Can calculates the score for the row chance
 */
class Chance : public YatzyRowRule
{
  public:
	/**
	 * Construct a class to calculate score for the row chance	 
	 */
	Chance() {}
	/**
	 * Cleans up allocated resources
	 */
	~Chance() {}
	/*
     * @see YatzyRowRule#calculateResult(vector<Die> dice)
     */
	int calculateResult(vector<Die> dice)
	{
		int score = 0;
		for(int i = 0; i < 5; i ++)
		{
			score += dice[i].getDieValue();
		}
		return score;
	}
};

#endif

