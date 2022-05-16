#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "Statements/Connector.h"
#include "Statements/Statement.h"
class Select : public Action
{
private:
    Point Position;
    Statement* S_ptr;
    Connector* C_ptr;


public:
    Select(ApplicationManager* pAppManager);
    void ReadActionParameters();
    void Execute();
    void unselectstat(Statement* stat);
    void unselectstat(Connector* Conn);
};