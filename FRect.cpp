#include "FRect.h"

FRect::FRect(float x, float y, float w, float h) :
	Left(x), Right(x + w), Top(y), Bottom(y + h)
{

}

bool FRect::Intersects(FRect *f) {

	if (Right < f->Left || Left > f->Right ||
		Top > f->Bottom || Bottom < f->Top) {
		return false;
	}
	else
	{
		return true;
	};
}