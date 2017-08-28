#ifndef STUDENT_HASHER_H
#define STUDENT_HASHER_H

#include <math.h>
#include "HasherBase.h"
#include <string>

/*
Assignment: CS 211 - MA8
Description: hasher
Author: "Jack" Daniel Kinne
HSU ID: 9395-18119
Completion Time: 3 Hours
*/
using namespace std;

class StudentHasher : public HasherBase<string>
{
	virtual int getHash(const string &item, int mod_by)
	{
        int FNV = 1099511628211;
		int hash = 1;
		for (char ch : item)
		{
            hash += FNV;  // 3 secs, three cases pass.  Fowler-Noll-Vo 64 bit prime.
           hash ^= FNV * hash;
		}


		return hash % mod_by;
	}

};
#endif
