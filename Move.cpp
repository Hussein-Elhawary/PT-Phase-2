#include "Move.h"
#include "ApplicationManager.h"
#include "Statements/Statement.h"

Move::Move(ApplicationManager* pAppManager) : Action(pAppManager)
{
}

void Move::ReadActionParameters()
{
	st_ptr = pManager->GetSelectedStatement();
	initial = st_ptr->getLeftCorner();
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Click on the new place to move");
	pIn->GetPointClicked(user_click);

}

void Move::Execute()
{
	ReadActionParameters();
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	st_ptr->Move(user_click);
	pOut->ClearStatusBar();
	pOut->PrintMessage("Statement moved successfully");
	/*pManager->GetSelectedStatement()->SetSelected(false);
	pManager->SetSelectedStatement(NULL);*/
	//pManager->removeStatement(st_ptr);
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
}