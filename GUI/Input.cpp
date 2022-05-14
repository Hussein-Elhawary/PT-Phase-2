
#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(Point& P) const
{
	pWind->WaitMouseClick(P.x, P.y);	//Wait for mouse click
}


string Input::GetString(Output* pO) const
{
	string Str;
	char Key;
	//pO->PrintMessage(" ");
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Str;
		if (Key == 8)	//BackSpace is pressed
			Str.resize(Str.size() - 1);
		else
			Str += Key;
		pO->PrintMessage(Str);
	}

}

double Input::GetValue(Output* pO) const	// Reads a double value from the user 
{
	///TODO: add code to read a double value from the user and assign it to D
	double D = 0;
	string str;
	char st;
	//pO->PrintMessage(" ");

	while (1)
	{
		pWind->WaitKeyPress(st);
		if (st == 27)	//ESCAPE key is pressed
			return 0;	//returns nothing as user has cancelled label
		if (st == 13)	//ENTER key is pressed
		{
			D = stod(str);//convert string to double
			return D;
		}
		if (st == 8)	//BackSpace is pressed
			str.resize(str.size() - 1);
		else
			str += st;
		pO->PrintMessage(str);
	}

	//Read a double value from the user

	return D;
}


//ActionType Input::GetUserAction() const
//{	
//	//This function reads the position where the user clicks to determine the desired action
//
//	int x,y;
//	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
//
//	if(UI.AppMode == DESIGN )	//application is in design mode
//	{
//		//[1] If user clicks on the Toolbar
//		if ( y >= 0 && y < UI.TlBrWdth)
//		{	//Check whick Menu item was clicked
//			if( x >= 0 && x < UI.MnItWdth  )
//				return ADD_SMPL_ASSIGN;
//			if( x >= UI.MnItWdth && x < 2* UI.MnItWdth  )		
//				return ADD_CONDITION;
//			if( x >= UI.MnItWdth && x < 3* UI.MnItWdth  )		
//				return EXIT;
//
//			return DSN_TOOL;	//a click on empty part of the tool bar
//		
//		}
//		
//		//[2] User clicks on the drawing area
//		if ( y >= UI.TlBrWdth && y < UI.height - UI.StBrWdth)
//		{
//			return SELECT;	//user want to select/unselect a statement in the flowchart
//		}
//		
//		//[3] User clicks on the status bar
//		return STATUS;
//	}
//	else	//Application is in Simulation mode
//	{
//		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
//	}
//
//}
//

ActionType Input::GetUserAction() const
{
	//This function reads the position where the user clicks to determine the desired action

	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.TlBrWdth)
		{
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.MnItWdth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_EXIT_DSN: return EXIT;
			case ITM_START: return START;
			case ITM_READ: return READ;
			case ITM_WRITE: return WRITE;
			case ITM_SMPL_ASSIGN: return ADD_SMPL_ASSIGN;
			case ITM_COND: return ADD_CONDITION;
			case ITM_CONNECTOR: return ADD_CONNECTOR;
			case ITM_END: return END;
			case ITM_SELECT: return SELECT;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_SAVE: return SAVE;
			case ITM_EDIT_STAT: return EDIT_STAT;
			case ITM_MOVE:return MOVE;
			case ITM_ZOOM_OUT: return ZOOM_OUT;
			case ITM_ZOOM_IN: return ZOOM_IN;
			case ITM_DEL: return DEL;
			case ITM_SIM_MODE: return SIM_MODE;

			default: return DSN_TOOL;
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.TlBrWdth && y < UI.height - UI.StBrWdth)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//Application is in Simulation mode
	{
		if (y >= 0 && y < UI.TlBrWdth)
		{
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.MnItWdth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_EXIT_SIM: return EXIT;
			case ITM_RUN: return RUN;
			case ITM_STP: return STP;
			case ITM_SIM_FLTOCODE: return FLTOCODE;
			case ITM_DSN_MODE: return DSN_MODE;



			default:return SIM_MODE;	//This should be changed after creating the compelete simulation bar 

			}
		}
	}
}

Input::~Input()
{
}
//