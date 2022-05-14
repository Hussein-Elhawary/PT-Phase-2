#include "AddVarAssign.h"


#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddVarAssign::AddVarAssign(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddVarAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Variable Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Enter left hand side:");
	lhs = pIn->GetString(pOut);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Enter right hand side:");
	rhs = pIn->GetValue(pOut);
	pOut->ClearStatusBar();
}

void AddVarAssign::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	VarAssign* pAssign = new VarAssign(Corner, "", "");

	pManager->AddStatement(pAssign);
}


