#pragma once

#include "Command.h"

class CmdSetAddressMode : public Command
{
public:
	const char* GetName() override
	{
		return "SetAddressMode";
	}
	const char* GetDescription() override
	{
		return "Sets the address mode for texture sampling.";
	}
	bool Execute(const std::vector<std::string>& params) override;
};