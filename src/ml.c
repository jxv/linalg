#include <stdlib.h>
#include <math.h>
#include "ml.h"

float sqf(float x) {
	return x * x;
}

float cubef(float x) {
	return x * x * x;
}

bool nearzerof(float x) {
	return fabsf(x) < 1e-6;
}

float clampf(float l, float h, float x) {
	return fminf(h, fmaxf(l, x));
}

bool eqf(float x, float y) {
	return fabsf(x - y) <= 1e-6;
}

float randf(float l, float h) {
	return l + (h - l) * ((float)rand() / RAND_MAX);
}

bool biasgtf(float x, float y) {
	const float biasrel = 0.95f;
	const float biasabs = 0.01f;
	return x >= y * biasrel + x * biasabs;
}

v2f mkv2f(float x, float y) {
	return (v2f) { .x = x, .y = y };
}

v2f fillv2f(float x) {
	return mkv2f(x, x);
}

v2f absv2f(v2f v) {
	return mkv2f(fabsf(v.x), fabsf(v.y));
}

v2f sigv2f(v2f v) {
	return mkv2f(-fabsf(v.x), -fabsf(v.y));
}

v2f neg2f(v2f v) {
	return mkv2f(-v.x, -v.y);
}

v2f addv2f(v2f v, v2f u) {
	return mkv2f(v.x + u.x, v.y + u.y);
}

v2f subv2f(v2f v, v2f u) {
	return mkv2f(v.x - u.x, v.y - u.y);
}

v2f mulv2f(v2f v, v2f u) {
	return mkv2f(v.x * u.x, v.y * u.y);
}

v2f divv2f(v2f v, v2f u) {
	return mkv2f(v.x / u.x, v.y / u.y);
}

v2f addv2fs(v2f v, float s) {
	return mkv2f(v.x + s, v.y + s);
}

v2f subv2fs(v2f v, float s) {
	return mkv2f(v.x - s, v.y - s);
}

v2f mulv2fs(v2f v, float s) {
	return mkv2f(v.x * s, v.y * s);
}

v2f divv2fs(v2f v, float s) {
	return mkv2f(v.x / s, v.y / s);
}

bool nearzerov2f(v2f v) {
	return nearzerof(v.x) && nearzerof(v.y);
}

float sqlenv2f(v2f v) {
	return sqf(v.x) + sqf(v.y);
}

float dotv2f(v2f v, v2f u) {
	return v.x * u.x + v.y * u.y;
}

float lenv2f(v2f v) {
	return sqrtf(sqlenv2f(v));
}

float sqdistv2f(v2f u, v2f v) {
	return sqlenv2f(subv2f(u, v));
}

v2f normv2f(v2f v) {
	const float len = lenv2f(v);
	if (nearzerof(len))
		return v;
	return divv2fs(v, len);
}

v2f rotv2f(v2f x, float theta) {
	const float c = cosf(theta);
	const float s = sinf(theta);
	return mkv2f(x.x * c - x.y * s, x.x * s + x.y * c);
}


v2f clampv2f(v2f l, v2f h, v2f v) {
	return mkv2f(clampf(l.x, h.x, v.x), clampf(l.y, h.y, v.y));
}

v2f minv2f(v2f v, v2f u) {
	return mkv2f(fminf(v.x, u.x), fminf(v.y, u.y));
}

v2f maxv2f(v2f v, v2f u) {
	return mkv2f(fmaxf(v.x, u.x), fmaxf(v.y, u.y));
}

float crossv2f(v2f v, v2f u) {
	return v.x * u.y - v.y * u.x;
}

v2f crossv2fs(v2f v, float s) {
	return mkv2f(s * v.y, -s * v.x);
}

v2f crosssv2f(float s, v2f v) {
	return mkv2f(-s * v.y, s * v.x);
}

m2f mkm2f(float xx, float xy, float yx, float yy) {
	return (m2f) {
		.xx = xx, .xy = xy,
		.yx = yx, .yy = yy, 
	};
}

m2f mkvm2f(v2f v, v2f u) {
	return (m2f) { .x = v, .y = u };
}

m2f eyem2f() {
	return mkm2f(1,0,0,1);
}

m2f orientm2f(float theta) {
	const float c = cosf(theta);
	const float s = sinf(theta);
	return mkm2f(c, -s, s, c);
}

m2f absm2f(m2f m) {
	return mkvm2f(absv2f(m.x), absv2f(m.y));
}

v2f xaxism2f(m2f m) {
	return mkv2f(m.xx, m.yx);
}

v2f yaxism2f(m2f m) {
	return mkv2f(m.xy, m.yy);
}

m2f transm2f(m2f m) {
	return mkm2f(m.xx, m.yx, m.xy, m.yy);
}

m2f mulm2f(m2f m, m2f n) {
	return (m2f) {
		.xx = m.xx * n.xx + m.xy * n.yx,
		.xy = m.xx * n.xy + m.xy * n.yy,
		.yx = m.yx * n.xx + m.yy * n.yx,
		.yy = m.yx * n.xy + m.yy * n.yy,
	};
}

v2f mulm2fv(m2f m, v2f v) {
	return mkv2f(m.xx * v.x + m.xy * v.y, m.yx * v.x + m.yy * v.y);
}
