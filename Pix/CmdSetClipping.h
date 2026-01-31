#pragma once

#include "Command.h"

class CmdSetClipping : public Command
{
public:
	const char* GetName() override
	{
		return "SetClipping";
	}
	const char* GetDescription() override
	{
		"SetClipping(true/false";
	}

	bool Execute(const std::vector<std::string>& params);
};