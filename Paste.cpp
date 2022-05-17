#include "Paste.h"
#include "Paste.h"
#include "ApplicationManager.h"
#include "AddCondition.h"//
#include "AddEnd.h"
#include "AddRead.h"
#include "AddSingleOpAssign.h"
#include "Addconector.h"
#include "AddStart.h"
#include "AddVarAssign.h"
#include "AddWrite.h"
#include "Actions/AddSmplAssign.h"
#include "SingleOperator.h"
Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{

}

void Paste::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please Select The position to paste..");
	pIn->GetPointClicked(PastePoint);

	pOut->ClearStatusBar();
}

void Paste::Execute()
{
	ReadActionParameters();
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	Pasted = pManager->getClipboard();

	if (Pasted != NULL)
	{

		if (dynamic_cast<CondStatement*>(Pasted)) // Pasted is downcasted to conditional Statement
		{
			CondStatement* ptr1 = (CondStatement*)Pasted;
			CondStatement* ptr2 = new CondStatement(PastePoint, ptr1->getLHS(), ptr1->getOP(), ptr1->getRHS());
			pManager->AddStatement(ptr2);
			pOut->ClearStatusBar();
			pOut->PrintMessage("Pasted Successfully");
		}
		if (dynamic_cast<End*>(Pasted)) // Pasted is downcasted to End
		{
			End* ptr1 = (End*)Pasted;
			End* ptr2 = new End(PastePoint);
			pManager->AddStatement(ptr2);
			pOut->ClearStatusBar();
			pOut->PrintMessage("Pasted Successfully");
		}
		if (dynamic_cast<SmplAssign*>(Pasted)) // Pasted is downcasted to simple assignement
		{
			SmplAssign* ptr1 = (SmplAssign*)Pasted;
			SmplAssign* ptr2 = new SmplAssign(PastePoint, ptr1->getLHS(), ptr1->getRHS());
			pManager->AddStatement(ptr2);
			pOut->ClearStatusBar();
			pOut->PrintMessage("Pasted Successfully");
		}
		if (dynamic_cast<VarAssign*>(Pasted)) // Pasted is downcasted to var
		{
			VarAssign* ptr1 = (VarAssign*)Pasted;
			VarAssign* ptr2 = new VarAssign(PastePoint, ptr1->getLHS(), ptr1->getRHS());
			pManager->AddStatement(ptr2);
			pOut->ClearStatusBar();
			pOut->PrintMessage("Pasted Successfully");
		}
		if (dynamic_cast<SingleOperator*>(Pasted)) // Pasted is downcasted to var
		{
			SingleOperator* ptr1 = (SingleOperator*)Pasted;
			SingleOperator* ptr2 = new SingleOperator(PastePoint, ptr1->getLHS(), ptr1->getRHS1(), ptr1->getOP(), ptr1->getRHS2());
			pManager->AddStatement(ptr2);
			pOut->ClearStatusBar();
			pOut->PrintMessage("Pasted Successfully");
		}
		if (dynamic_cast<Start*>(Pasted)) // Pasted is downcasted to start
		{
			Start* ptr1 = (Start*)Pasted;
			Start* ptr2 = new Start(PastePoint);
			pManager->AddStatement(ptr2);
			pOut->ClearStatusBar();
			pOut->PrintMessage("Pasted Successfully");
		}
		if (dynamic_cast<Read*>(Pasted)) // Pasted is downcasted to start
		{
			Read* ptr1 = (Read*)Pasted;
			Read* ptr2 = new Read(PastePoint, ptr1->getVAR());
			pManager->AddStatement(ptr2);
			pOut->ClearStatusBar();
			pOut->PrintMessage("Pasted Successfully");
		}
		if (dynamic_cast<Write*>(Pasted)) // Pasted is downcasted to start
		{
			Write* ptr1 = (Write*)Pasted;
			Write* ptr2 = new Write(PastePoint, ptr1->getVAR());
			pManager->AddStatement(ptr2);
			pOut->ClearStatusBar();
			pOut->PrintMessage("Pasted Successfully");
		}


	}

}