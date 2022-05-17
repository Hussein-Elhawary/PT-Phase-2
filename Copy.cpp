#include "Copy.h"
#include "ApplicationManager.h"


Copy::Copy(ApplicationManager* pApp) : Action(pApp)
{
}

void Copy::ReadActionParameters()
{

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please Select The statement You Want To Copy..");
	pIn->GetPointClicked(LeftCorner);

	pOut->ClearStatusBar();
}

void Copy::Execute()
{
	Copy::ReadActionParameters();
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	if (pManager->GetStatement(LeftCorner) != NULL)
	{
		Copied = pManager->GetStatement(LeftCorner)->getCopy();
		pManager->setClipboard(Copied); //Statement is in Clipboard
		pOut->PrintMessage("Statement is now in clipboard");
	}
	else
	{
		pOut->PrintMessage("This position has no statements");
	}


}