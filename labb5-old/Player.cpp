/* Daniel Lännström */
/* danlan01         */

#include "Player.h"

Player::Player(int nr)
{
    m_nr = nr;
}

Player::~Player() 
{
}

int Player::finalScore() const
{
    return m_score.calcSum();
}

bool Player::isGameOver() const
{
    return m_score.isScoreFull();
}

int Player::getNr() const
{
    return m_nr;
}

void Player::printFinalScore(const IOutputer& ioutputer) const
{
    ioutputer.printString("Spelare ");
    ioutputer.printInt(m_nr);
    ioutputer.printString("\t");
    ioutputer.printInt(finalScore());
    ioutputer.printString("\n");
}

void Player::doTurn(const IOutputer& ioutputer)
{
    /* Print header */
    ioutputer.printString("Spelare ");
    ioutputer.printInt(m_nr);
    ioutputer.printString("\n");

    /* Whatever we want another roll */
    bool cont = true;

    /* First roll */
    m_hand.rerollAll();

    /* Second roll */
    m_hand.printHand(ioutputer); 
    cont = m_hand.reroll(ioutputer);
    m_hand.printHand(ioutputer); 

    /* Third roll */
    if (cont) 
    {
        cont = m_hand.reroll(ioutputer);
        m_hand.printHand(ioutputer); 
    }

    /* Place score */
    m_score.printPosts(ioutputer); 
    m_score.placeHand(ioutputer, m_hand);
    m_score.printPosts(ioutputer); 
}
