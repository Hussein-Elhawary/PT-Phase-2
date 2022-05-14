#include "ApplicationManager.h"
#include "Actions\AddSmplAssign.h"
#include "AddVarAssign.h"
#include "AddStart.h"
#include "AddEnd.h"
#include "AddRead.h"
#include "AddWrite.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "AddSingleOpAssign.h"
#include "AddCondition.h"
#include "string"
#include "Addconector.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	StatCount = 0;
	ConnCount = 0;
	pSelectedStat = NULL;	//no Statement is selected yet
	
	//Create an array of Statement pointers and set them to NULL		
	for(int i=0; i<MaxCount; i++)
	{
		StatList[i] = NULL;	
		ConnList[i] = NULL;
	}
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	string assingntype = "0";
	//According to ActioType, create the corresponding action object
	switch (ActType)
	{
		case ADD_SMPL_ASSIGN:
			pOut->PrintMessage("Please enter a value to decide which type of assignment.(1 for simple, 2 for variable ,3 single operator)");
			assingntype = pIn->GetString(pOut);
			while (assingntype !=  "1" && assingntype != "2" && assingntype != "3")
			{
				pOut->PrintMessage("re-enter from the valid selection value to decide which type of assignment.(1 for simple, 2 for variable ,3 single operator)");
				assingntype = pIn->GetString(pOut);

			}

			if (assingntype == "1")
			{
				pAct = new AddSmplAssign(this);
				break;
			}
			else if (assingntype == "2")
			{
				pAct = new AddVarAssign(this);
				break;

			}
			else if (assingntype == "3")
			{
				pAct = new AddSingleOpAssign(this);
				break;
			}

		case START:
			pAct = new AddStart(this);
			break;

		case END:
			pAct = new AddEnd(this);
			break;

		case READ:
			pAct = new AddRead(this);
			break;

		case WRITE:
			pAct = new AddWrite(this);
			break;

		case ADD_CONDITION:
			///create AddCondition Action here
			pAct = new AddCondition(this);
			break;
		case ADD_CONNECTOR:

			pAct = new Addconector(this);
			break;

		case SELECT:
			///create Select Action here

			break;

		case EXIT:
			///create Exit Action here
			
			break;
		
		case STATUS:
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}



//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//
//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement *pStat)
{
	if(StatCount < MaxCount)
		StatList[StatCount++] = pStat;
	
}

////////////////////////////////////////////////////////////////////////////////////
Statement *ApplicationManager::GetStatement(Point P) const
{
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL


	///Add your code here to search for a statement given a point P(x,y)	
	for (int i = 0; i < StatCount; i++)
	{
		Point leftcorner = StatList[i]->getstatmentposition();

		Point RightCorner;
		RightCorner.x = leftcorner.x + UI.ASSGN_WDTH; // calculated all the corners just in case
		RightCorner.y = leftcorner.y ;

		Point BottomLeftCorner;
		BottomLeftCorner.x = leftcorner.x;
		BottomLeftCorner.y = leftcorner.y + UI.ASSGN_HI;

		Point BottomRightCorner;
		BottomRightCorner.x = leftcorner.x + UI.ASSGN_WDTH;
		BottomRightCorner.y = leftcorner.y + UI.ASSGN_HI;

		string type = StatList[i]->gettype();

		if (P.x >= leftcorner.x && P.x <= RightCorner.x && P.y >= BottomLeftCorner.y && P.y <= RightCorner.y)
		{
			
		return StatList[i];
		}
	}
	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement *ApplicationManager::GetSelectedStatement() const
{	return pSelectedStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement *pStat)
{	pSelectedStat = pStat;	}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	//Draw all statements
	for(int i=0; i<StatCount; i++)
		StatList[i]->Draw(pOut);
	
	//Draw all connections
	for(int i=0; i<ConnCount; i++)
		ConnList[i]->Draw(pOut);

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////


//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<StatCount; i++)
		delete StatList[i];
	for(int i=0; i<StatCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;
	
}
