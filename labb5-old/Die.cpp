#include <time.h>
#include <stdlib.h>
#include "Die.h"

/**
*	Initiates the static counter that we will use as seed.
*/
unsigned int Die::mInitiator = static_cast<unsigned int>(time(NULL)); 

/**
* Constructs a die with 6 sides	 
*/
Die::Die()
{
	mSides = 6;
	initialize();
};

/**
* Constructs a die with any number of sides
*
* @param sides number of sides for the die
*/
Die::Die(unsigned int sides)
{
	mSides = sides;		
	initialize();
};

/**
* Cleans up allocated resources
*/
Die::~Die() 
{

};

/**
* Rolls the die and produces a pseudo random number between 1 and number of sides 
* 
* @return int die value
*/
int Die::rollDie()
{
	mValue = rand() % mSides + 1;
	return mValue;
};

/**
* Gets the current value of the die without re-rolling it
*
* @return int die value
*/
const int Die::getDieValue() const /* Modified */
{
	return mValue;
};

/**
* Operator < that can be used to compare two dice objects.
* A comparison of two dice will only consider the dice value
* and not the number of sides of the dice.
*
* <code>Die die1(6); //with value 5<br>
* Die die2(20); //with value 4<br>
* if(die1 < die2) //will return false</code> 
*
* @param die the other die that we want to compare with
* @return bool true if the other dice has a greater value
*/
bool Die::operator< (const Die& die) const
{
	return mValue < die.mValue;
};

/**
* Operator > that can be used to compare two dice objects.
* A comparison of two dice will only consider the dice value
* and not the number of sides of the dice.
*
* <code>Die die1(6); //with value 5<br>
* Die die2(20); //with value 4<br>
* if(die1 > die2) //will return true</code>
*
* @param die the other die that we want to compare with
* @return bool true if the other dice has a smaller value
*/
bool Die::operator> (const Die& die) const
{
	return mValue > die.mValue;
};

/**
* Operator == that can be used to compare two dice objects.
* A comparison of two dice will only consider the dice value
* and not the number of sides of the dice.
*
* <code>Die die1(6); //with value 5<br>
* Die die2(20); //with value 5<br>
* if(die1 == die2) //will return true</code> 
*
* @param die the other die that we want to compare with
* @return bool true if the other dice has the same value
*/
bool Die::operator== (const Die& die) const
{
	return mValue == die.mValue;
};

/**
* Initiates the die
*/
void Die::initialize()
{
	srand(mInitiator++);
	rollDie();
};


