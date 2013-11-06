/* Daniel Lännström */
/* danlan01         */

#include "YatsyProgram.h"

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
