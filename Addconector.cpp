#include "Addconector.h"
#include "string"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI/Output.h"

#include "CondStatement.h"

#include <sstream>
#include "Statements/Connector.h"

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
Addconector::Addconector(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Addconector::ReadActionParameters()
{
	
	//SmplAssign* ps=NULL;
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	

	pOut->PrintMessage("press on starting Statement:");
	pIn->GetPointClicked(start);
	pOut->ClearStatusBar();

	pOut->PrintMessage("press on Ending Statement:");
	pIn->GetPointClicked(end);
	pOut->ClearStatusBar();

	
	Source = pManager->GetStatement(start);
	Destination = pManager->GetStatement(end);

	while (Source == nullptr)
	{
		pOut->PrintMessage("Re-click on starting Statement:");
		pIn->GetPointClicked(start);
		pOut->ClearStatusBar();
		Source = pManager->GetStatement(start);
	}

	while (Destination == nullptr)
	{

		pOut->PrintMessage("Re-click on Ending Statement:");
		pIn->GetPointClicked(end);
		pOut->ClearStatusBar();
		Destination = pManager->GetStatement(end);
	}

	}

void Addconector::Execute()
{
	ReadActionParameters();
	string usertext;
	//Statement *Source;
	//Statement *Destination;

	//Source = pManager->GetStatement(start);
	//while (Source == NULL);
	//{
	//	pOut->PrintMessage("Erorr ,press on starting Statement again:");
	//	pIn->GetPointClicked(start);
	//	pOut->ClearStatusBar();
	//	Source = pManager->GetStatement(start);
	//}
	//Destination = pManager->GetStatement(end);
	//
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	

	start = Source->getOutlet();
	end = Destination->getInlet();

	if (Source->gettype() == "rhombus")
	{

		pOut->PrintMessage("yes connector on connector: (y/n)");
		usertext = pIn->GetString(pOut);
		pOut->ClearStatusBar();
		while (usertext != "y" && usertext != "Y" && usertext != "n" && usertext != "N")
		{
			pOut->PrintMessage("(try again) yes connector on connector: (y/n)");
			usertext = pIn->GetString(pOut);
			pOut->ClearStatusBar();
		}
		if (usertext == "y" || usertext == "Y")
		{
			start = Source->getOutletyes();
		}
		else
		{
			start = Source->getOutletno();

		}
	}
	Connector* pAssign = new Connector(start, end);
	pAssign->Draw(pOut);

}
//still in progress
