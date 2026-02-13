#pragma once

#include "Command.h"

class CmdSetCameraPosition : public Command
{
public: 
	const char* GetName()
	{
		return "SetCameraPosition";
	}
	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetCameraDirection : public Command
{
public: 
	const char* GetName()
	{
		return "SetCameraDirection";
	}
	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetCameraNear : public Command
{
public: 
	const char* GetName()
	{
		return "SetCameraNear";
	}
	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetCameraFar : public Command
{
public: 
	const char* GetName()
	{
		return "SetCameraFar";
	}
	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetCameraFov : public Command
{
public:
	const char* GetName()
	{
		return "SetCameraFov";
	}
	bool Execute(const std::vector<std::string>& params) override;
};

void SetPosition(const Vector3& pos);
void SetDirection(const Vector3& dir);
void SetNearPlane(float nearPlane);
void SetFarPlane(float farPlane);
void SetFOV(float fov);

