#include "Command.h"
#include "MenuLine.h"

void EnterCommand::Execute(InputReceiver& inputReceiver)
{
	inputReceiver.OnEnterPressed();
}

void UpCommand::Execute(InputReceiver& inputReceiver)
{
	inputReceiver.OnUpArrowPressed();
}

void DownCommand::Execute(InputReceiver& inputReceiver)
{
	inputReceiver.OnDownArrowPressed();
}

void EscCommand::Execute(InputReceiver& inputReceiver)
{
	inputReceiver.OnEscPressed();
}

void RightCommand::Execute(InputReceiver& inputReceiver)
{
	inputReceiver.OnRightArrowPressed();
}

void LeftCommand::Execute(InputReceiver& inputReceiver)
{
	inputReceiver.OnLeftArrowPressed();
}
