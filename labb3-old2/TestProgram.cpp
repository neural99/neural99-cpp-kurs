#include "TestProgram.h"

void TestProgram::run()
{
    IOutputer ioutputer;
    DieHand dh;

    dh.printHand(ioutputer); 
    dh.reroll(ioutputer);
    dh.printHand(ioutputer); 
    dh.reroll(ioutputer);
    dh.printHand(ioutputer); 
}
