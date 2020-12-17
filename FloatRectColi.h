#pragma once
class FloatRectColi
{
public:
	FloatRectColi(float x, float y, float w, float h);

	FloatRectColi(void);
	~FloatRectColi(void);

	bool Interseccion(FloatRectColi f);

	const float izq, der, arr, abj;

};

