#include "Save.h"
Save::Save(ApplicationManager* pApp) :Action(pApp)
{
}

void Save::ReadActionParameters()
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter the file name to save data into:");
	name = pIn->GetString(pOut); //get the file name from the user
	OutFile.open(name + ".txt"); // opening the file for output
	pOut->ClearStatusBar();
}

void Save::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int statcount, conncount;                  
	statcount = pManager->GetStatCount();// storing the number of occurance
	conncount = pManager->GetConnCount();
	OutFile << statcount << endl; //printing as required file format
	pManager->SaveAll(OutFile); //calling SaveAll to be able to Call Save of Statements and connectors in the flow chart
	//OutFile.close(); //closing the opened file 
	pOut->PrintMessage("Successsfully saved the flowchart, Click anywhere to continue");
}

