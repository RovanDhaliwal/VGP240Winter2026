#pragma once

#include "Command.h"

class CmdSetCullMode : public Command
{
public:
	const char* GetName() override
	{
		return "SetCullMode";
	}
	const char* GetDescription() override
	{
		return 
			"SetCullMode(mode)"
			"\n"
			"- sets the cullmode";
	}
	bool Execute(const std::vector<std::string>& params) override;
};