#pragma once

#include "Vertex.h"
#include "Rasterizer.h"

enum class Topology
{
	Point,
	Line,
	Triangle
};

class PrimitivesManager
{
public:
	static PrimitivesManager* Get();

	// Start accepting values
	bool BeginDraw(Topology topology);
	// Add vertices to the list, only if drawing is enabled
	void AddVertex(const Vertex& vertex);
	// Send all the stored vertices to the raterizer
	bool EndDraw();

private:
	PrimitivesManager();

	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Point;
	bool mDrawBegin = false;

};