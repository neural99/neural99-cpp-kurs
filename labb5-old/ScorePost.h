/* Daniel Lännström */
/* danlan01         */

#ifndef SCOREPOST_H
#define SCOREPOST_H

#include <string>

#include "IOutputer.h"

using namespace std;

/**
 * A post in a Score object
 * @author Daniel Lannstrom
**/ 
class ScorePost 
{
    public:
        /**
          * Constructs a Score with 15 score posts
        **/ 
        ScorePost(int nr, const string& name);

        /**
          * Clean-up
        **/ 
        virtual ~ScorePost();

        /**
          *  Has a value been assigned to this post?
        **/ 
        bool isEmpty() const; 
        
        /**
          *  Assign a value to this post
          *  @param newValue value to assign
        **/ 
        void setValue(int newValue);

        /**
          *  Return current value
        **/ 
        const int getValue() const;

        /**
          *  Return the listing number for this post
        **/ 
        const int getNr() const;

        /**
          *  Return the pretty prining name for this post
        **/ 
        const string getName() const;

        /**
          *  Print post 
          *  @param ioutputer object used for I/O
        **/ 
        void printPost(const IOutputer& ioutputer) const;

    private:

        int m_nr;
        string m_name;
        int m_value;
};

#endif
