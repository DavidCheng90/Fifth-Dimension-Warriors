#ifndef RECT_H
#define RECT_H

#include "Circle.h"

class Rect
{
public:
	Rect();
	Rect(const Vec2& a, const Vec2& b);
	Rect(float x0, float y0, float x1, float y1);

	void forceInside(Circle& A);
	bool isPtInside(const Vec2& pt);
	bool isHitBy(const Circle& attack);

	Vec2 minPt;
	Vec2 maxPt;
};

#endif // RECT_H