#pragma once
#include "fstream"
#include "ApplicationManager.h"
#include "Actions/Action.h"
class Save : public Action
{
	string name;      //name of file to output to
	ofstream OutFile; //the file itself access
public:
	Save(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads Save action parameters (file name)

	virtual void Execute();
							
};

