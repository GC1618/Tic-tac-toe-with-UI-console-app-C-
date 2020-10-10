#pragma once
class InputReceiver
{
public:
	virtual void OnEnterPressed() {};
	virtual void OnEscPressed() {};
	virtual void OnUpArrowPressed() {};
	virtual void OnDownArrowPressed() {};
	virtual void OnLeftArrowPressed() {};
	virtual void OnRightArrowPressed() {};
};

