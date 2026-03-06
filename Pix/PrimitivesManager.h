#pragma once

#include "Vertex.h"
#include "Rasterizer.h"

enum class Topology
{
	Point,
	Line,
	Triangle
};

enum class CullMode
{
	None,
	Back,
	Front,
};

class PrimitivesManager
{
public:
	static PrimitivesManager* Get();

	void OnNewFrame();
	void SetCullMode(CullMode mode);
	void SetCorrectUV(bool correctUV);

	// Start accepting values
	bool BeginDraw(Topology topology, bool applyTransform = false);
	// Add vertices to the list, only if drawing is enabled
	void AddVertex(const Vertex& vertex);
	// Send all the stored vertices to the raterizer
	bool EndDraw();

private:
	PrimitivesManager();

	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Point;
	CullMode mCullMode = CullMode::None;
	bool mDrawBegin = false;
	bool mApplyTransform = false;
	bool mCorrectUV = false;
};