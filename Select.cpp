#include "Select.h"

Select::Select(ApplicationManager* pAppManager) : Action(pAppManager)
{
}

void Select::ReadActionParameters()
{
	//pointers to input and output (like AddSmplAssign)
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Select: Click to select the statement/connector");

	//get point clicked by the user in an object of class point called "user_Clicked"
	pIn->GetPointClicked(Position);
	//---------------------------------------------------------------------------------------------------

	S_ptr = pManager->GetStatement(Position);		//waiting for zahar's function
	C_ptr = pManager->GetConnector(Position);

}

void Select::Execute()
{
	ReadActionParameters();
	if (S_ptr != NULL)
	{
		if(pManager->GetSelectedStatement()!=NULL )
		{
		pManager->GetSelectedStatement()->unselectstat();
		}
		unselectstat(S_ptr);
		pManager->SetSelectedStatement(S_ptr);  // Selecting the last selected statement pointer to the new selected statement
		S_ptr->SetSelected(true);

	}

}

void Select::unselectstat(Statement * stat)
{
	stat->unselectstat();
	if(pManager->GetSelectedStatement() == stat)
	{ 
	pManager->SetSelectedStatement(NULL);
	}

}