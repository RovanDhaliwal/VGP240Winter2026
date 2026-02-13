#pragma once

#include "Command.h"

class CmdEnableDepthBuffer : public Command
{
public:
	const char* GetName() override
	{
		return "EnableDepthBuffer";
	}
	const char* GetDescription() override
	{
		return "Enables the depth buffer for rendering.";
	}
	bool Execute(const std::vector<std::string>& params) override;
};
