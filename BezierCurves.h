#pragma once
#include "Vector2.h"
vector2_t Set3PointBezier(const vector2_t& p0, const vector2_t& p1, const vector2_t& p2, float& t, const float speed);
vector2_t BezierPDirection(const vector2_t& p,const vector2_t& p0, const vector2_t& p1, const vector2_t& p2, const float t, const float speed);