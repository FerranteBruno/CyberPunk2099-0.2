#include "FloatRectColi.h"

FloatRectColi::FloatRectColi(float x, float y, float w, float h) : 
	izq(x), der(x + w), arr(y), abj(y + h)
{
}

FloatRectColi::FloatRectColi(void)
{
}

FloatRectColi::~FloatRectColi(void)
{
}

bool FloatRectColi::Interseccion(FloatRectColi f)
{

	if (der < f.izq || izq > f.der || arr > f.abj || abj < f.arr) {
		return false;
	}
	else {
		return true;
	}

}
