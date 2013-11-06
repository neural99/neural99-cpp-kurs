#include "TestProgram.h"

void YatsyProgram::run()
{
    IOutputer ioutputer;
    YatsyHand yh;

    yh.printHand(ioutputer); 
    yh.reroll(ioutputer);
    yh.printHand(ioutputer); 
    yh.reroll(ioutputer);
    yh.printHand(ioutputer); 
}
