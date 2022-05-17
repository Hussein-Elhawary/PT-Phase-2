#pragma once
#include "Write.h"
#include "Actions/Action.h"
class AddWrite : public Action
{
private:
	Point Position;	//Position where the user clicks to add the stat.
	string var;
public:
	AddWrite(ApplicationManager* pAppManager);

	//Write Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();


};

