#pragma once
#include "ApplicationManager.h"
#include "Actions/Action.h"
class Validation : public Action
{
public:
	Validation(ApplicationManager* pAppManager);
	void ReadActionParameters();
	void Execute();
};

