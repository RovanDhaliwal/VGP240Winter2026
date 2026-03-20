#pragma once

#include "Command.h"

class CmdSetUseFilter : public Command
{
public:
	const char* GetName() override
	{
		return "SetUseFilter";
	}
	const char* GetDescription() override
	{
		return "Sets whether to use the filter when rendering the image.";
	}
	bool Execute(const std::vector<std::string>& params) override;
};