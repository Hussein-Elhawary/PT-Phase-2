#include "AddWrite.h"
#include "string"

#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddWrite::AddWrite(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddWrite::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Write Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Enter Variable:");
	var = pIn->GetString(pOut);
	pOut->ClearStatusBar();

}

void AddWrite::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//string t = pIn->GetString(pOut);
	//const char* strstr(const char* str1, const char* str2);
	Write* pWrite = new Write(Corner, var);
	pOut->ClearStatusBar();


	pManager->AddStatement(pWrite);
}