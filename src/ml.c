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

#define V2_DEFINE(A,B)\
v2##A _v2##A(B x, B y) {\
	return (v2##A) { .x = x, .y = y };\
}

V2_DEFINE(f,float)
V2_DEFINE(i,int)

v2f zerov2f() {
	return _v2f(0,0);
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

#define V3_DEFINE(A,B)\
v3##A _v3##A(B x, B y, B z) {\
	return (v3##A) { .x = x, .y = y, .z = z };\
}

V3_DEFINE(f,float)
V3_DEFINE(ui,unsigned int)
V3_DEFINE(si,short int)

v3f zerov3f() {
	return _v3f(0,0,0);
}

v3f negv3f(v3f v) {
	return _v3f(-v.x, -v.y, -v.z);
}

v3f addv3f(v3f v, v3f u) {
	return _v3f(v.x + u.x, v.y + u.y, v.z + u.z);
}

v3f subv3f(v3f v, v3f u) {
	return _v3f(v.x - u.x, v.y - u.y, v.z - u.z);
}

v3f mulv3f(v3f v, v3f u) {
	return _v3f(v.x * u.x, v.y * u.y, v.z * u.z);
}

v3f mulv3fs(v3f v, float s) {
	return _v3f(v.x * s, v.y * s, v.z * s);
}

v3f divv3f(v3f v, v3f u) {
	return _v3f(v.x / u.x, v.y / u.y, v.z / u.z);
}

v3f divv3fs(v3f v, float s) {
	return _v3f(v.x / s, v.y / s, v.z / s);
}

bool eqv3f(v3f v, v3f u) {
	return v.x == u.x && v.y == u.y && v.z == u.z;
}

float lenv3f(v3f v) {
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

v3f normv3f(v3f v) {
	const float len = lenv3f(v);
	return _v3f(v.x / len, v.y / len, v.z / len);
}

v3f crossv3f(v3f v, v3f u) {
	return _v3f(
		v.y * u.z - v.z * u.y,
		v.z * u.x - v.x * u.z,
		v.x * u.y - v.y * u.x
	);
}

float dotv3f(v3f v, v3f u) {
	return v.x * u.x + v.y * u.y + v.z * u.z;
}

#define V4_DEFINE(A,B)\
v4##A _v4##A(B x, B y, B z, B w) {\
	return (v4##A) { .x = x, .y = y, .z = z, .w = w };\
}

V4_DEFINE(f,float)

v4f zerov4f() {
	return _v4f(0,0,0,0);
}

v4f v4fv3f(v3f v, float w) {
	return _v4f(v.x, v.y, v.z, w);
}

v4f negv4f(v4f v) {
	return _v4f(-v.x, -v.y, -v.z, -v.w);
}

v4f addv4f(v4f v, v4f u) {
	return _v4f(v.x + u.x, v.y + u.y, v.z + u.z, v.w + u.w);
}

v4f subv4f(v4f v, v4f u) {
	return _v4f(v.x - u.x, v.y - u.y, v.z - u.z, v.w - u.w);
}

v4f mulv4f(v4f v, v4f u) {
	return _v4f(v.x * u.x, v.y * u.y, v.z * u.z, v.w * u.w);
}

v4f mulv4fs(v4f v, float s) {
	return _v4f(v.x * s, v.y * s, v.z * s, v.w * s);
}

v4f divv4f(v4f v, v4f u) {
	return _v4f(v.x / u.x, v.y / u.y, v.z / u.z, v.w / u.w);
}

v4f divv4fs(v4f v, float s) {
	return _v4f(v.x / s, v.y / s, v.z / s, v.w / s);
}

bool eqv4f(v4f v, v4f u) {
	return v.x == u.x && v.y == u.y && v.z == u.z && v.w == u.w;
}

v4f lerpv4f(v4f v, v4f u, float t) {
	const float s = 1 - t;
	return _v4f(
		s * v.x + t * u.x,
		s * v.y + t * u.y,
		s * v.z + t * u.z,
		s * v.w + t * u.w
	);
}

v4f normv4f(v4f v) {
	return divv4fs(v, sqrtf(dotv4f(v,v)));
}

float dotv4f(v4f v, v4f u) {
	return v.x * u.x + v.y * u.y + v.z * u.z + v.w * u.w;
}

v4f slerpv4f(v4f a, v4f b, float t) {
	const float dot = dotv4f(a, b);
	if (dot > 1 - 1e-6) {
		return normv4f(addv4f(a, mulv4fs(subv4f(a, b), t)));
	}
	const float dot_ = clampf(0, 1, dot);
	const float theta = acosf(dot_) * t;
	const v4f c = normv4f(subv4f(b, mulv4fs(a, dot_)));
	return normv4f(addv4f(mulv4fs(a, cosf(theta)), mulv4fs(c, sinf(theta))));
}

v4f rotv4f(v4f a, v4f b) {
	return normv4f(_v4f(
		a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
		a.w * b.y + a.y * b.w + a.z * b.x - a.x * b.z,
		a.w * b.z + a.z * b.w + a.x * b.y - a.y * b.x,
		a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z
	));
}

m3f m3v4f(v4f v) {
	const float s = 2;
	float xs, ys, zs, wx, wy, wz, xx, xy, xz, yy, yz, zz;
	xs = v.x * s;  ys = v.y * s;  zs = v.z * s;
	wx = v.w * xs; wy = v.w * ys; wz = v.w * zs;
	xx = v.x * xs; xy = v.x * ys; xz = v.x * zs;
	yy = v.y * ys; yz = v.y * zs; zz = v.z * zs;
	m3f m;
	m.xx = 1 - (yy + zz); m.yx = xy - wz;  m.zx = xz + wy;
	m.xy = xy + wz; m.yy = 1 - (xx + zz); m.zy = yz - wx;
	m.xz = xz - wy; m.yz = yz + wx; m.zz = 1 - (xx + yy);
	return m;
}

v4f fromv3v4f(v3f v, v3f u) {
	if (eqv3f(v, negv3f(u))) {
		return axisanglev4f(_v3f(1,0,0), M_PI);
	}
	const v3f c = crossv3f(v, u);
	const float d = dotv3f(v, u);
	const float s = sqrtf((1 + d) * 2);
	return _v4f(c.x / s, c.y / s, c.z / s, s / 2);
}

v4f axisanglev4f(v3f axis, float theta) {
	const float s = sinf(theta / 2);
	const float c = cosf(theta / 2);
	return _v4f(s * axis.x, s * axis.y, s * axis.z, c);
}

#define M2_DEFINE(A,B)\
m2##A _m2##A(B xx, B xy, B yx, B yy) {\
	return (m2f) {\
		.x = _v2##A(xx,xy),\
		.y = _v2##A(yx,yy),\
	};\
}

M2_DEFINE(f,float)

m2f vm2f(v2f x, v2f y) {
	return (m2f) { .x = x, .y = y };
}

m2f eyem2f() {
	return _m2f(1,0,0,1);
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

#define M3_DEFINE(A,B)\
m3##A _m3##A(B xx, B xy, B xz, B yx, B yy, B yz, B zx, B zy, B zz) {\
	return (m3##A) {\
		.x = _v3##A(xx,xy,xz),\
		.y = _v3##A(yx,yy,yz),\
		.z = _v3##A(zx,zy,zz),\
	};\
}

M3_DEFINE(f,float)

m3f vm3f(v3f x, v3f y, v3f z) {
	return (m3f) { .x = x, .y = y, .z = z };
}

m3f transposem3f(m3f m) {
	return _m3f(m.xx, m.yx, m.zx, m.xy, m.yy, m.zy, m.xz, m.yz, m.zz);
}

m4f m4fm3f(m3f m) {
	return vm4f(
		_v4f(m.xx, m.xy, m.xz, 0),
		_v4f(m.yx, m.yy, m.yz, 0),
		_v4f(m.zx, m.zy, m.zz, 0),
		_v4f(0,0,0,1)
	);
}

#define M4_DEFINE(A,B)\
m4##A _m4##A(B xx, B xy, B xz, B xw, B yx, B yy, B yz, B yw, B zx, B zy, B zz, B zw, B wx, B wy, B wz, B ww) {\
	return (m4##A) {\
		.x = _v4##A(xx,xy,xz,xw),\
		.y = _v4##A(yx,yy,yz,yw),\
		.z = _v4##A(zx,zy,zz,zw),\
		.w = _v4##A(wx,wy,wz,ww),\
	};\
}

M4_DEFINE(f,float)

m4f vm4f(v4f x, v4f y, v4f z, v4f w) {
	return (m4f) { .x = x, .y = y, .z = z, .w = w };
}

m4f zerom4f() {
	return vm4f(zerov4f(), zerov4f(), zerov4f(), zerov4f());
}

m4f eyem4f() {
	return vm4f(_v4f(1,0,0,0), _v4f(0,1,0,0), _v4f(0,0,1,0), _v4f(0,0,0,1));
}

m3f m3fm4f(m4f m) {
	return (m3f) {
		.x = _v3f(m.xx, m.xy, m.xz),
		.y = _v3f(m.yx, m.yy, m.yz),
		.z = _v3f(m.zx, m.zy, m.zz),
	};
}

m4f addm4f(m4f m, m4f n) {
	return vm4f(addv4f(m.x,n.x),
		    addv4f(m.y,n.y),
		    addv4f(m.z,n.z),
		    addv4f(m.w,n.w));
}

m4f subm4f(m4f m, m4f n) {
	return vm4f(subv4f(m.x,n.x),
		    subv4f(m.y,n.y),
		    subv4f(m.z,n.z),
		    subv4f(m.w,n.w));
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

v4f mulm4fv(m4f m, v4f v) {
	return _v4f(dotv4f(m.x, v), dotv4f(m.y, v), dotv4f(m.z, v), dotv4f(m.w, v));
}

m4f transposem4f(m4f m) {
	return _m4f(
		m.xx, m.yx, m.zx, m.wx,
		m.xy, m.yy, m.zy, m.wy,
		m.xz, m.yz, m.zz, m.wz,
		m.xw, m.yw, m.zw, m.ww
	);
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

m4f rotam4f(float theta) {
	const float c = cosf(theta);
	const float s = sinf(theta);
	m4f m = eyem4f();
	m.xx = c;
	m.xy = s;
	m.yx = -s;
	m.yy = c;
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


m4f lookatf(v3f eye, v3f target, v3f up) {
	v3f z = normv3f(subv3f(eye, target));
	v3f x = normv3f(crossv3f(up, z));
	v3f y = normv3f(crossv3f(z, x));
	m4f m = vm4f(v4fv3f(x, 0), v4fv3f(y, 0), v4fv3f(z, 0), _v4f(0,0,0,1));
	v4f eye_ = mulm4fv(m, v4fv3f(negv3f(eye), -1));
	m = transposem4f(m);
	m.w = eye_;
	return m;
}

