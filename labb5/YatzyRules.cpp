#include "YatzyRules.h"

YatzyRules::YatzyRules()
{
	for(int i = 1; i <= 6; i ++)
	{
		mRows.push_back(new OnesToSixes(i));
	}
	mRows.push_back(new Equal(2));
	mRows.push_back(new TwoPair());
	mRows.push_back(new Equal(3));
	mRows.push_back(new Equal(4));
	mRows.push_back(new Straight(1));
	mRows.push_back(new Straight(2));
	mRows.push_back(new FullHouse());
	mRows.push_back(new Chance());
	mRows.push_back(new Equal(5));
}
YatzyRules::YatzyRules(const YatzyRules& copyFromMe)
{
	for(int i = 1; i <= 6; i ++)
	{
		mRows.push_back(new OnesToSixes(i));
	}
	mRows.push_back(new Equal(2));
	mRows.push_back(new TwoPair());
	mRows.push_back(new Equal(3));
	mRows.push_back(new Equal(4));
	mRows.push_back(new Straight(1));
	mRows.push_back(new Straight(2));
	mRows.push_back(new FullHouse());
	mRows.push_back(new Chance());
	mRows.push_back(new Equal(5));
}
YatzyRules::~YatzyRules()
{
	for(vector<YatzyRowRule*>::iterator it = mRows.begin(); it != mRows.end(); it ++)
	{
		delete *it;
	}
}
const int YatzyRules::placeDice(vector<Die> dice, int row)
{
	return mRows.at(row - 1)->calculateResult(dice);
}
const vector<int> YatzyRules::getValidRows(vector<Die> dice)
{
	vector<int> validRows;

	for(unsigned int i = 1; i <= mRows.size(); i ++)
	{
		if(mRows.at(i - 1)->calculateResult(dice) != -1)
		{
			validRows.push_back(i);			
		}
	}
	return validRows;
}
