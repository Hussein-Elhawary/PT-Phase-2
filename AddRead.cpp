#include "AddRead.h"
#include "string"

#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddRead::AddRead(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddRead::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Read Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Enter Variable:");
	var = pIn->GetString(pOut);
	pOut->ClearStatusBar();

}

void AddRead::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	pOut->ClickCheck(Corner, UI.ASSGN_WDTH, UI.ASSGN_HI);
	Read* pRead = new Read(Corner , var);
	pOut->ClearStatusBar();


	pManager->AddStatement(pRead);
}