#pragma once
#include "Actions/Action.h"
class AddSingleOpAssign :
    public Action
{
private:
	string lhs;
	string rhs1;
	string rhs2;
	string Op;
	Point Position;	//Position where the user clicks to add the stat.
public:
	AddSingleOpAssign(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};

