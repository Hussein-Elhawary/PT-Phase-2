#pragma once
#include "Actions/Action.h"
#include "Statements/Statement.h"

class Addconector :public Action
{
	
	private:
		Point start;
		Point end;
	public:
		Statement* Source;
		Statement* Destination;
		Addconector(ApplicationManager* pAppManager);

		//Read Assignemt statements position
		virtual void ReadActionParameters();

		//Create and add an assignemnt statement to the list of statements
		virtual void Execute();

};

