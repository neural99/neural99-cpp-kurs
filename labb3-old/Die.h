#ifndef DIE_H
#define DIE_H

/**
 * A pseudo random die with any number of sides
 **/
class Die
{
  public:		
	/**
	 * Constructs a die with 6 sides	 
	 */
	Die();
	/**
	 * Constructs a die with any number of sides
	 *
	 * @param sides number of sides for the die
	 */
	Die(unsigned int sides);
	/**
	 * Cleans up allocated resources
	 */
	virtual ~Die();
	/**
	 * Rolls the die and produces a pseudo random number between 1 and number of sides 
	 * 
	 * @return int die value
	 */
	int rollDie();
	/**
	 * Gets the current value of the die without re-rolling it
	 *
	 * @return int die value
	 */
	const int getDieValue() const; /* Modified */
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
	bool operator< (const Die& die) const;
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
	bool operator> (const Die& die) const;
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
	bool operator== (const Die& die) const;
  private:
	/**
	 * Initiates the die
	 */
	void initialize();

	static unsigned int mInitiator;
	int mValue;
	unsigned int mSides;
};

#endif 
