#pragma once
#include "Actions/Action.h"
#include "Statements/Statement.h"

class Move :public Action
{
	Statement* st_ptr;
	Point user_click;
	Point initial;
public:
	Move(ApplicationManager* pAppManager);
	virtual void ReadActionParameters();
	virtual void Execute();
};