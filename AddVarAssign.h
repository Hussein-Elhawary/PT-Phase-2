#pragma once
#include "Actions/Action.h"
#include "VarAssign.h"
class AddVarAssign : Action
{
private:
	Point Position;	//Position where the user clicks to add the stat.
	string lhs;
	string rhs;
public:
	AddVarAssign(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};

