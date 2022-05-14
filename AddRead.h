#pragma once
#include "Read.h"
#include "Actions/Action.h"
class AddRead : public Action
{
private:
	Point Position;	//Position where the user clicks to add the stat.
	string var;
public:
	AddRead(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};

