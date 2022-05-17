#include "Validation.h"

Validation::Validation(ApplicationManager* pAppManager):Action(pAppManager)
{
}

void Validation::ReadActionParameters()
{
}

void Validation::Execute()
{
	pManager->CheckIfValid();
}


