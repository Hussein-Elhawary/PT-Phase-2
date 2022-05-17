#include "Run.h"

#include "string"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI/Output.h"

#include "CondStatement.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
Run::Run(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Run::ReadActionParameters()
{
	//SmplAssign* ps=NULL;
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

}

void Run::Execute()
{
	ReadActionParameters();

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	conncount = pManager->GetConnCount();
	statcount = pManager->GetStatCount();
	statlist = pManager->getstatlist();
	ConnList = pManager->getconlist();

	int startindex;
	int endinex;
	int current_statind = 0;
	int current_connind = 0;
	Connector* current_yconnind = NULL;
	Connector* current_nconnind = NULL;
	bool paths = NULL;
	string** parameternames;
	int* Readparameters;
	int  Readparameterscount = 0;
	Statement* currentlyinuse;

	for (int i = 0; i < statcount; i++)
	{
		if (statlist[i]->gettype() == "startellipse")
		{
			startindex = i;
		}
		if (statlist[i]->gettype() == "endellipse")
		{
			endinex = i;
		}
	}

	current_statind = startindex;

	while (endinex != current_statind)
	{
		if (statlist[current_statind]->gettype() != "rhombus")
		{
			for (int i = 0; i < conncount; i++)
			{
				if (statlist[current_statind]->getPconn() == ConnList[i]);
				{
					current_connind = i;
				}
			}
		}

		if (statlist[current_statind]->gettype() == "rhombus")
		{
			current_yconnind = statlist[current_statind]->GetYes_Conn();
			current_nconnind = statlist[current_statind]->GetNo_Conn();
		}

		if (current_yconnind == NULL)
		{
			if (statlist[current_statind]->gettype() == "readparallelogram")
			{
				parameternames[Readparameterscount] = &(statlist[current_statind]->getvar());
				string text = "Enter " + *parameternames[Readparameterscount] + "value";
				pOut->PrintMessage(text);
				Readparameters[Readparameterscount] = pIn->GetValue(pOut);
				Readparameterscount++;
				pOut->ClearStatusBar();
			}
			else if (statlist[current_statind]->gettype() == "smplrectangle")
			{
				for (int i = 0; i < Readparameterscount; i++)
				{
					if ((statlist[current_statind]->getLHS()) == *parameternames[i])
					{
						Readparameters[i] = stoi(statlist[current_statind]->getRHS());
					}

				}
			}
			else if (statlist[current_statind]->gettype() == "varrectangle")
			{
				for (int i = 0; i < Readparameterscount; i++)
				{
					if ((statlist[current_statind]->getLHS()) == *parameternames[i])
					{
						for (int j = 0; j < Readparameterscount; j++)
							if ((statlist[current_statind]->getRHS()) == *parameternames[j])
							{
								Readparameters[i] = Readparameters[j];
							}



					}

				}

			}
			else if ((statlist[current_statind]->gettype() == "singlerectangle"))
			{
				for (int i = 0; i < Readparameterscount; i++)
				{
					if ((statlist[current_statind]->getLHS()) == *parameternames[i])
					{
						for (int j = 0; j < Readparameterscount; j++)
							if ((statlist[current_statind]->getRHS1()) == *parameternames[j])
							{
								for (int K = 0; K < Readparameterscount; K++)
									if ((statlist[current_statind]->getRHS2()) == *parameternames[K])
									{
										string Op = statlist[current_statind]->getOP();
										if (Op == "+")
										{
											Readparameters[i] = Readparameters[j] + Readparameters[K];
										}
										else if (Op == "-")
										{
											Readparameters[i] = Readparameters[j] - Readparameters[K];
										}
										else if (Op == "*")
										{
											Readparameters[i] = Readparameters[j] * Readparameters[K];
										}
										else if (Op == "/")
										{
											Readparameters[i] = Readparameters[j] / Readparameters[K];
										}

									}

							}



					}

				}




			}
			else if ((statlist[current_statind]->gettype() == "writeparallelogram"))
			{
				for (int i = 0; i < Readparameterscount; i++)
				{
					if ((statlist[current_statind]->getvar()) == *parameternames[i])
					{
						string text = "The final value of " + *parameternames[i] + " is" + to_string(Readparameters[i]);
						pOut->PrintMessage(text);

					}
				}


			}
			else if ((statlist[current_statind]->gettype()) == "endellipse")
			{
				Point x;
				pIn->GetPointClicked(x);
				break;
			}

		}
		else if (current_yconnind != NULL && paths == true)
		{
			currentlyinuse = current_yconnind->getSrcStat();
			if (currentlyinuse->gettype() == "readparallelogram")
			{
				parameternames[Readparameterscount] = &(currentlyinuse->getvar());
				string text = "Enter " + *parameternames[Readparameterscount] + "value";
				pOut->PrintMessage(text);
				Readparameters[Readparameterscount] = pIn->GetValue(pOut);
				Readparameterscount++;
				pOut->ClearStatusBar();
			}
			else if (currentlyinuse->gettype() == "smplrectangle")
			{
				for (int i = 0; i < Readparameterscount; i++)
				{
					if ((currentlyinuse->getLHS()) == *parameternames[i])
					{
						Readparameters[i] = stoi(currentlyinuse->getRHS());
					}

				}
			}
			else if (currentlyinuse->gettype() == "varrectangle")
			{
				for (int i = 0; i < Readparameterscount; i++)
				{
					if ((currentlyinuse->getLHS()) == *parameternames[i])
					{
						for (int j = 0; j < Readparameterscount; j++)
							if ((currentlyinuse->getRHS()) == *parameternames[j])
							{
								Readparameters[i] = Readparameters[j];
							}



					}

				}

			}
			else if ((currentlyinuse->gettype() == "singlerectangle"))
			{
				for (int i = 0; i < Readparameterscount; i++)
				{
					if ((currentlyinuse->getLHS()) == *parameternames[i])
					{
						for (int j = 0; j < Readparameterscount; j++)
							if ((currentlyinuse->getRHS1()) == *parameternames[j])
							{
								for (int K = 0; K < Readparameterscount; K++)
									if ((currentlyinuse->getRHS2()) == *parameternames[K])
									{
										string Op = currentlyinuse->getOP();
										if (Op == "+")
										{
											Readparameters[i] = Readparameters[j] + Readparameters[K];
										}
										else if (Op == "-")
										{
											Readparameters[i] = Readparameters[j] - Readparameters[K];
										}
										else if (Op == "*")
										{
											Readparameters[i] = Readparameters[j] * Readparameters[K];
										}
										else if (Op == "/")
										{
											Readparameters[i] = Readparameters[j] / Readparameters[K];
										}

									}

							}



					}

				}




			}
			else if ((statlist[current_statind]->gettype() == "writeparallelogram"))
			{
				for (int i = 0; i < Readparameterscount; i++)
				{
					if ((statlist[current_statind]->getvar()) == *parameternames[i])
					{
						string text = "The final value of " + *parameternames[i] + " is" + to_string(Readparameters[i]);
						pOut->PrintMessage(text);

					}
				}


			}
			else if ((statlist[current_statind]->gettype()) == "endellipse")
			{
				Point x;
				pIn->GetPointClicked(x);
				break;
			}

		}
		else if (current_nconnind != NULL && paths == false)
		{
			currentlyinuse = current_nconnind->getSrcStat();
			if (currentlyinuse->gettype() == "readparallelogram")
			{
				parameternames[Readparameterscount] = &(currentlyinuse->getvar());
				string text = "Enter " + *parameternames[Readparameterscount] + "value";
				pOut->PrintMessage(text);
				Readparameters[Readparameterscount] = pIn->GetValue(pOut);
				Readparameterscount++;
				pOut->ClearStatusBar();
			}
			else if (currentlyinuse->gettype() == "smplrectangle")
			{
				for (int i = 0; i < Readparameterscount; i++)
				{
					if ((currentlyinuse->getLHS()) == *parameternames[i])
					{
						Readparameters[i] = stoi(currentlyinuse->getRHS());
					}

				}
			}
			else if (currentlyinuse->gettype() == "varrectangle")
			{
				for (int i = 0; i < Readparameterscount; i++)
				{
					if ((currentlyinuse->getLHS()) == *parameternames[i])
					{
						for (int j = 0; j < Readparameterscount; j++)
							if ((currentlyinuse->getRHS()) == *parameternames[j])
							{
								Readparameters[i] = Readparameters[j];
							}



					}

				}

			}
			else if ((currentlyinuse->gettype() == "singlerectangle"))
			{
				for (int i = 0; i < Readparameterscount; i++)
				{
					if ((currentlyinuse->getLHS()) == *parameternames[i])
					{
						for (int j = 0; j < Readparameterscount; j++)
							if ((currentlyinuse->getRHS1()) == *parameternames[j])
							{
								for (int K = 0; K < Readparameterscount; K++)
									if ((currentlyinuse->getRHS2()) == *parameternames[K])
									{
										string Op = currentlyinuse->getOP();
										if (Op == "+")
										{
											Readparameters[i] = Readparameters[j] + Readparameters[K];
										}
										else if (Op == "-")
										{
											Readparameters[i] = Readparameters[j] - Readparameters[K];
										}
										else if (Op == "*")
										{
											Readparameters[i] = Readparameters[j] * Readparameters[K];
										}
										else if (Op == "/")
										{
											Readparameters[i] = Readparameters[j] / Readparameters[K];
										}

									}

							}



					}
					else if ((statlist[current_statind]->gettype() == "writeparallelogram"))
					{
						for (int i = 0; i < Readparameterscount; i++)
						{
							if ((statlist[current_statind]->getvar()) == *parameternames[i])
							{
								string text = "The final value of " + *parameternames[i] + " is" + to_string(Readparameters[i]);
								pOut->PrintMessage(text);

							}
						}


					}
					else if ((statlist[current_statind]->gettype()) == "endellipse")
					{
						Point x;
						pIn->GetPointClicked(x);
						break;
					}

				}

			}
		}
		for (int i = 0; i < statcount; i++)
		{
			if (ConnList[current_connind]->getDstStat() == statlist[i]);
			{
				current_statind = i;
			}

		}

	}

}

