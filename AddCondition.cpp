#include "AddCondition.h"

#include "string"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI/Output.h"

#include "CondStatement.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddCondition::AddCondition(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddCondition::ReadActionParameters()
{
	//SmplAssign* ps=NULL;
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Conditinal Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Enter left hand side:");
	lhs = pIn->GetString(pOut);
	pOut->ClearStatusBar();
	
	bool check = true;
	pOut->PrintMessage("Enter an Operator: ( > , < , == , != , >= , <=)");
	Op = pIn->GetString(pOut);
	while (!(checkOperator(Op)))
	{
		pOut->PrintMessage("Error!please enter a valid operator( > , < , == , != , >= , <=):");
		Op = pIn->GetString(pOut);

	}
	pOut->ClearStatusBar();

	pOut->PrintMessage("Enter right hand side:");
	rhs = pIn->GetString(pOut);
	pOut->ClearStatusBar();


}

void AddCondition::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	pOut->ClickCheck(Corner, UI.ASSGN_WDTH, UI.ASSGN_HI);
	CondStatement *pAssign = new CondStatement(Corner, lhs, Op, rhs);

	pManager->AddStatement(pAssign);
}

bool AddCondition::checkOperator(string Op)
{
	if (Op == "==" || Op == "<" || Op == "<=" || Op == ">" || Op == ">=" || Op == "!=")
	{
		return true;
	}
	return false;
}
