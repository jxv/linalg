#include <stdlib.h>
#include <math.h>
#include "ml.h"

float recipinff(float x) {
	return nearzerof(x) ? 0 : (1 / x);
}

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

v2f _v2f(float x, float y) {
	return (v2f) { .x = x, .y = y };
}

v2f fillv2f(float x) {
	return _v2f(x, x);
}

v2f absv2f(v2f v) {
	return _v2f(fabsf(v.x), fabsf(v.y));
}

v2f sigv2f(v2f v) {
	return _v2f(-fabsf(v.x), -fabsf(v.y));
}

v2f negv2f(v2f v) {
	return _v2f(-v.x, -v.y);
}

v2f addv2f(v2f v, v2f u) {
	return _v2f(v.x + u.x, v.y + u.y);
}

v2f subv2f(v2f v, v2f u) {
	return _v2f(v.x - u.x, v.y - u.y);
}

v2f mulv2f(v2f v, v2f u) {
	return _v2f(v.x * u.x, v.y * u.y);
}

v2f divv2f(v2f v, v2f u) {
	return _v2f(v.x / u.x, v.y / u.y);
}

v2f addv2fs(v2f v, float s) {
	return _v2f(v.x + s, v.y + s);
}

v2f subv2fs(v2f v, float s) {
	return _v2f(v.x - s, v.y - s);
}

v2f mulv2fs(v2f v, float s) {
	return _v2f(v.x * s, v.y * s);
}

v2f divv2fs(v2f v, float s) {
	return _v2f(v.x / s, v.y / s);
}

bool nearzerov2f(v2f v) {
	return nearzerof(v.x) && nearzerof(v.y);
}

bool eqv2f(v2f v, v2f u) {
	return eqf(v.x, u.x) &&  eqf(v.y, u.y);
}

v2f lerp(v2f v, v2f u, float t) {
	return addv2f(mulv2fs(v, 1 - t), mulv2fs(u, t));
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
	return _v2f(x.x * c - x.y * s, x.x * s + x.y * c);
}


v2f clampv2f(v2f l, v2f h, v2f v) {
	return _v2f(clampf(l.x, h.x, v.x), clampf(l.y, h.y, v.y));
}

v2f minv2f(v2f v, v2f u) {
	return _v2f(fminf(v.x, u.x), fminf(v.y, u.y));
}

v2f maxv2f(v2f v, v2f u) {
	return _v2f(fmaxf(v.x, u.x), fmaxf(v.y, u.y));
}

float crossv2f(v2f v, v2f u) {
	return v.x * u.y - v.y * u.x;
}

v2f crossv2fs(v2f v, float s) {
	return _v2f(s * v.y, -s * v.x);
}

v2f crosssv2f(float s, v2f v) {
	return _v2f(-s * v.y, s * v.x);
}

m2f _m2f(float xx, float xy, float yx, float yy) {
	return (m2f) {
		.xx = xx, .xy = xy,
		.yx = yx, .yy = yy, 
	};
}

m2f vm2f(v2f x, v2f y) {
	return (m2f) { .x = x, .y = y };
}

m2f eyem2f() {
	return _m2f(1,0,0,1);
}

m2f orientm2f(float theta) {
	const float c = cosf(theta);
	const float s = sinf(theta);
	return _m2f(c, -s, s, c);
}

m2f absm2f(m2f m) {
	return vm2f(absv2f(m.x), absv2f(m.y));
}

v2f xaxism2f(m2f m) {
	return _v2f(m.xx, m.yx);
}

v2f yaxism2f(m2f m) {
	return _v2f(m.xy, m.yy);
}

m2f transposem2f(m2f m) {
	return _m2f(m.xx, m.yx, m.xy, m.yy);
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
	return _v2f(m.xx * v.x + m.xy * v.y, m.yx * v.x + m.yy * v.y);
}

v3f _v3f(float x, float y, float z) {
	return (v3f) { .x = x, .y = y, .z = z };
}

v3f zerov3f() {
	return _v3f(0,0,0);
}

v3f addv3f(v3f v, v3f u) {
	return _v3f(v.x + u.x, v.y + u.y, v.z + u.z);
}

v3f mulv3f(v3f v, v3f u) {
	return _v3f(v.x * u.x, v.y * u.y, v.z * u.z);
}

v3f divv3fs(v3f v, float s) {
	return _v3f(v.x / s, v.y / s, v.z / s);
}

float lenv3f(v3f v) {
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}


v4f _v4f(float x, float y, float z, float w) {
	return (v4f) { .x = x, .y = y, .z = z, .w = w };
}

v4f addv4f(v4f v, v4f u) {
	return _v4f(v.x + u.x, v.y + u.y, v.z + u.z, v.w + u.w);
}

v4f mulv4fs(v4f v, float s) {
	return _v4f(v.x * s, v.y * s, v.z * s, v.w * s);
}

m4f zerom4f() {
	return vm4f(_v4f(0,0,0,0), _v4f(0,0,0,0), _v4f(0,0,0,0), _v4f(0,0,0,0));
}

m4f eyem4f() {
	return vm4f(_v4f(1,0,0,0), _v4f(0,1,0,0), _v4f(0,0,1,0), _v4f(0,0,0,1));
}

m4f vm4f(v4f x, v4f y, v4f z, v4f w) {
	return (m4f) { .x = x, .y = y, .z = z, .w = w };
}

m4f addm4f(m4f m, m4f n) {
	return vm4f(addv4f(m.x,n.x),
		    addv4f(m.y,n.y),
		    addv4f(m.z,n.z),
		    addv4f(m.w,n.w));
}

m4f scalem4f(m4f m, v3f s) {
	return vm4f(mulv4fs(m.x, s.x),
		    mulv4fs(m.y, s.y),
		    mulv4fs(m.z, s.z),
		    m.w);
}

m4f translatem4f(v3f t) {
	m4f m = zerom4f();
	m.w = _v4f(t.x, t.y, t.z, 0);
	return m;
}

m4f rotm4f(float theta, v3f v) {
	const float c = cosf(theta);
	const float s = sinf(theta);
	const float c1 = 1 - c;
	const float len = lenv3f(v);
	const v3f u = divv3fs(v, len);
	m4f m = zerom4f();
	m.val[15] = 1.0;
	for (int i = 0; i < 3; i++) {
		m.val[i * 4 + (i + 1) % 3] =  u.val[(i + 2) % 3] * s;
		m.val[i * 4 + (i + 2) % 3] = -u.val[(i + 1) % 3] * s;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			float val = c1 * u.val[i] * u.val[j] + (i == j ? c : 0);
			m.val[i * 4 + j] += val;
		}
	}
	return m;
}

m4f frustumm4f(float lf, float rt, float bot, float top,
	       float near, float far) {
	const float a = 2 * near / (rt - lf);
	const float b = 2 * near / (top - bot);
	const float c = (rt + lf) / (rt - lf);
	const float d = (top + bot) / (top - bot);
	const float e = -(far + near) / (far - near);
	const float f = -2 * far * near / (far - near);
	m4f m;
	m.x = _v4f(a,0,0,0);
	m.y = _v4f(0,b,0,0);
	m.z = _v4f(c,d,e,-1);
	m.w = _v4f(0,0,f,1);
	return m;
}

m4f perspm4f(float fovy, float aspect, float near, float far) {
	const float f = 1 / tanf(fovy * 0.5);
	m4f m = zerom4f();
	m.val[0] = f / aspect;
	m.val[5] = f;
	m.val[10] = (near + far) / (near - far);
	m.val[11] = -1;
	m.val[14] = (2 * near * far) / (near - far);
	m.val[15] = 0;
	return m;
}

m4f orthom4f(float lf, float rt, float bot, float top, float near, float far) {
	const float rl = rt - lf;
	const float tb = top - bot;
	const float fn = far - near;
	m4f m;
	m.x = _v4f(2 / rl, 0, 0, 0);
	m.y = _v4f(0, 2 / tb, 0, 0);
	m.z = _v4f(0, 0, -2 / fn, 0);
	m.w = _v4f(-(rt + lf) / rl, -(top + bot) / tb, -(far + near) / fn, 1);
	return m;
}


m4f mulm4f(m4f m, m4f n) {
	m4f o;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			o.val[j * 4 + i] = 0.0;
			for (int k = 0; k < 4; k++) {
				float val = m.val[k * 4 + i] * n.val[j * 4 + k];
				o.val[j * 4 + i] += val;
			}
		}
	}
	return o;
}
