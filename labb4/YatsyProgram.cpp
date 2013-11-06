/* Daniel Lännström */
/* danlan01         */

#include <vector>

#include "YatsyProgram.h"

void YatsyProgram::run()
{
    IOutputer ioutputer;
    YatsyHand yh;
    Score score;
    bool cont = true;

    ioutputer.printString("Välkommen till Yatsy!\n\n");

    /* Until Game Over */
    while (!score.isScoreFull()) 
    {
        /* Until a valid alternative has been chosen */
        while (true) 
        {
            char c = ioutputer.readCharacter("Vill du slå tärningar (s) eller avsluta (a)? ");
            if (c == 'a')
            {
                return; 
            } 
            else if (c == 's')
            {
                break;
            }
        }

        /* First roll */
        yh.rerollAll();

        /* Second roll */
        yh.printHand(ioutputer); 
        cont = yh.reroll(ioutputer);
        yh.printHand(ioutputer); 

        /* Third roll */
        if (cont) 
        {
            cont = yh.reroll(ioutputer);
            yh.printHand(ioutputer); 
        }

        /* Place score */
        score.printPosts(ioutputer); 
        score.placeHand(ioutputer, yh);
        score.printPosts(ioutputer); 
    }

    ioutputer.printString("----------------------\n");
    ioutputer.printString("Spel slut\n");
    ioutputer.printString("----------------------\n");
    score.printPosts(ioutputer);
}
