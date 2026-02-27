#include "LightTypes.h"
#include "MaterialManager.h"
#include "Camera.h"

// Directional Light =======================================================================
X::Color DirectionalLight::ComputeLightColor(const Vector3& position, const Vector3& normal)
{
	Camera* camera = Camera::Get();
	MaterialManager* mm = MaterialManager::Get();

	X::Color ambient = mAmbient * mm->GetMaterialAmbient();

	Vector3 L = -mDirection;
	float dot = X::Math::Max(MathHelper::Dot(L, normal), 0.0f);
	X::Color diffuse = mDiffuse * mm->GetMaterialDiffuse() * dot;

	Vector3 v = MathHelper::Normalize(camera->GetPosition() - position);
	Vector3 r = MathHelper::Normalize(L + v);
	float fallOff = X::Math::Max((float)pow(MathHelper::Dot(r, normal), mm->GetMaterialShininess()), 0.0f);
	X::Color specular = mSpecular * mm->GetMaterialSpecular() * fallOff;

	return ambient + diffuse + specular;
}
void DirectionalLight::SetDirection(const Vector3& direction)
{
	mDirection = MathHelper::Normalize(direction);
}

// Point Light ===========================================================================
X::Color PointLight::ComputeLightColor(const Vector3& position, const Vector3& normal)
{
	Camera* camera = Camera::Get();
	MaterialManager* mm = MaterialManager::Get();

	Vector3 L = mPosition - position;
	float distance = MathHelper::Magnitude(L);
	L /= distance;

	float attenuation = 1.0f / (mAttenConst + (mAttenLinear * distance) + (mAttenQuad * distance * distance));
	float iL = X::Math::Clamp(attenuation, 0.0f, 1.0f);


	X::Color ambient = mAmbient * mm->GetMaterialAmbient();

	float dot = X::Math::Max(MathHelper::Dot(L, normal), 0.0f);
	X::Color diffuse = mDiffuse * mm->GetMaterialDiffuse() * dot * iL;

	Vector3 v = MathHelper::Normalize(camera->GetPosition() - position);
	Vector3 r = MathHelper::Normalize(L + v);
	float fallOff = X::Math::Max((float)pow(MathHelper::Dot(r, normal), mm->GetMaterialShininess()), 0.0f);
	X::Color specular = mSpecular * mm->GetMaterialSpecular() * fallOff * iL;

	return ambient + diffuse + specular;
}
void PointLight::SetPosition(const Vector3& position)
{
	mPosition = position;
}
void PointLight::SetAttenuation(float kConstant, float kLinear, float kQuadratic)
{
	mAttenConst = kConstant;
	mAttenLinear = kLinear;
	mAttenQuad = kQuadratic;	
}

// Spot Light ===========================================================================
X::Color SpotLight::ComputeLightColor(const Vector3& position, const Vector3& normal)
{
	Camera* camera = Camera::Get();
	MaterialManager* mm = MaterialManager::Get();

	Vector3 L = mPosition - position;
	float distance = MathHelper::Magnitude(L);
	L /= distance;

	X::Color ambient = mAmbient * mm->GetMaterialAmbient();

	Vector3 lightDir = -L;
	float dotDir = MathHelper::Dot(lightDir, mDirection);
	if (dotDir < mCosAngle)
	{
		return ambient;
	}

	float spot = pow(dotDir, mDecay);
	float attenuation = spot / (mAttenConst + (mAttenLinear * distance) + (mAttenQuad * distance * distance));
	float iL = X::Math::Clamp(attenuation, 0.0f, 1.0f);


	float dot = X::Math::Max(MathHelper::Dot(L, normal), 0.0f);
	X::Color diffuse = mDiffuse * mm->GetMaterialDiffuse() * dot * iL;

	Vector3 v = MathHelper::Normalize(camera->GetPosition() - position);
	Vector3 r = MathHelper::Normalize(L + v);
	float fallOff = X::Math::Max((float)pow(MathHelper::Dot(r, normal), mm->GetMaterialShininess()), 0.0f);
	X::Color specular = mSpecular * mm->GetMaterialSpecular() * fallOff * iL;

	return ambient + diffuse + specular;
}
void SpotLight::SetPosition(const Vector3& position)
{
	mPosition = position;
}
void SpotLight::SetDirection(const Vector3& direction)
{
	mDirection = MathHelper::Normalize(direction);
}
void SpotLight::SetAttenuation(float kConstant, float kLinear, float kQuadratic)
{
	mAttenConst = kConstant;
	mAttenLinear = kLinear;
	mAttenQuad = kQuadratic;
}
void SpotLight::SetAngle(float angle)
{
	mCosAngle = cos(angle);
}
void SpotLight::SetDecay(float decay)
{
	mDecay = decay;
}