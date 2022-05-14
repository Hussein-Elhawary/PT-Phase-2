#include "AddSingleOpAssign.h"
#include "Actions/Action.h"
#include "string"

#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI\Output.h"

#include <sstream>
#include "SingleOperator.h"

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddSingleOpAssign::AddSingleOpAssign(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddSingleOpAssign::ReadActionParameters()
{
	//singleAssign* ps=NULL;
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Single Operator Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Enter left hand side:");
	lhs = pIn->GetString(pOut);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Enter first parameter:");
	rhs1 = pIn->GetString(pOut);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Enter operation:");
	Op = pIn->GetString(pOut);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Enter second parameter:");
	rhs2 = pIn->GetString(pOut);
	pOut->ClearStatusBar();

}

void AddSingleOpAssign::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	SingleOperator* pAssign = new SingleOperator(Corner, lhs, rhs1, Op, rhs2);

	pManager->AddStatement(pAssign);
}
