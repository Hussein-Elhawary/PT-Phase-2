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
	int statcount, conncount;                  //variables to store count of game objects
	statcount = pManager->GetStatCount();// storing the number of occurance
	conncount = pManager->GetConnCount();
	OutFile << statcount << endl; //printing as required file format
	pManager->SaveAll(OutFile, ladder); //calling SaveAll in Grid to be able to Call Save of ladder objects in the cell list
	OutFile << SnakeCount << endl;
	pManager->SaveAll(OutFile, snake); //calling SaveAll in Grid to be able to Call Save of snake objects in the cell list
	OutFile << CardCount << endl;
	pManager->SaveAll(OutFile, card);//calling SaveAll in Grid to be able to Call Save of card objects in the cell list
	OutFile.close(); //closing the opened file 
	pManager->PrintErrorMessage("Successsfully saved the grid, Click anywhere to continue");
}

SaveGrid::~SaveGrid()
{
	//we need at the end of save action to reset issaved parameter in cards 9,10,11 because
	//user may want to save again in the same program execution so to be able to execute SaveGrid again
	//the variables assosiated with saving must be reseted to its intial value
	CardNine::reset_is_saved();
	CardTen::reset_is_saved();
	CardEleven::reset_is_saved();
}