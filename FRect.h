#pragma once
class FRect
{
public:
	FRect(float x, float y, float w, float h);

	bool Intersects(FRect *f);

	const float Left, Right, Top, Bottom;
};

