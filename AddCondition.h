#pragma once
#include "Actions/Action.h"
class AddCondition : public Action
{
private:
	string lhs;
	string rhs;
	string Op;
	Point Position;	//Position where the user clicks to add the stat.
public:
	AddCondition(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();
	virtual bool checkOperator(string Op);

};

