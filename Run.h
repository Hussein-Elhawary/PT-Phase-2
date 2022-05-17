#pragma once
#include "Actions/Action.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"

class Run : public Action
{	private:
	ApplicationManager* pManager;
	int conncount;
	int statcount;
	Statement** statlist;
	Connector** ConnList;

	public:

		Run(ApplicationManager* pAppManager);
		void ReadActionParameters();
		void Run::Execute();
};