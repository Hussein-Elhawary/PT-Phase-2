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


}

void Addconector::Execute()
{
	ReadActionParameters();
	
	Statement *Source;
	Statement *Destination;

	pManager->GetStatement(start);

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	Connector* pAssign = new Connector(Source, Destination);
	pAssign->Draw(pOut);
	
}
//still in progress
