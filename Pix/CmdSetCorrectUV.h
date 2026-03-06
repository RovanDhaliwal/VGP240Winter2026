#pragma once

#include "Command.h"

class CmdSetCorrectUV : public Command
{
public:
	const char* GetName() override 
	{ 
		return "SetCorrectUV"; 
	}
	const char* GetDescription() override 
	{ 
		return "Set correct UV for texture"; 
	}
	bool Execute(const std::vector<std::string>& params) override;
};