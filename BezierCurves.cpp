#include "BezierCurves.h"


vector2_t Set3PointBezier(const vector2_t& p0, const vector2_t& p1, const vector2_t& p2, float& t, const float speed) {
    vector2_t a = { (1 - t) * p0.x + t * p1.x,(1 - t) * p0.y + t * p1.y };
    vector2_t b = { (1 - t) * p1.x + t * p2.x,(1 - t) * p1.y + t * p2.y };
    t += speed;
    if (t >= 1) {
    	t = 1;
    }
    vector2_t p = { (1 - t) * a.x + t * b.x,(1 - t) * a.y + t * b.y };
    return p;
}
vector2_t BezierPDirection(const vector2_t& p,const vector2_t& p0, const vector2_t& p1, const vector2_t& p2, const float t, const float speed) {
    vector2_t a = { (1 - t) * p0.x + t * p1.x, (1 - t) * p0.y + t * p1.y };
    vector2_t b = { (1 - t) * p1.x + t * p2.x, (1 - t) * p1.y + t * p2.y };
    float tNext = t + speed;
    if (tNext > 1) {
        tNext = 1;
    }

    vector2_t pNext = { (1 - tNext) * a.x + tNext * b.x, (1 - tNext) * a.y + tNext * b.y };

    vector2_t direction = { pNext.x - p.x, pNext.y - p.y };

    return direction;
}
