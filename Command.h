#pragma once
class InputReceiver;

class Command
{
public:
	Command() {};
	virtual ~Command() {};
	virtual void Execute(InputReceiver&) = 0;
};

class EnterCommand : public Command
{
	virtual void Execute(InputReceiver&);
};

class UpCommand : public Command
{
	virtual void Execute(InputReceiver&);
};

class DownCommand : public Command
{
	virtual void Execute(InputReceiver&);
};

class EscCommand : public Command
{
	virtual void Execute(InputReceiver&);
};

class RightCommand : public Command
{
	virtual void Execute(InputReceiver&);
};

class LeftCommand : public Command
{
	virtual void Execute(InputReceiver&);
};