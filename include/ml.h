#ifndef ML_H
#define ML_H

#include <stdbool.h>

typedef struct {
	union {
		struct { float x, y; };
		float val[2];
	};
} v2f;

typedef struct {
	union {
		struct { v2f x, y; };
		struct { float xx, xy, yx, yy; };
		v2f v[2];
		float val[4];
	};
} m2f;

typedef struct {
	union {
		struct { float x, y, z; };
		float val[3];
	};
} v3f;

typedef struct {
	union {
		struct { v3f x, y, z; };
		struct { float xx, xy, xz, yx, yy, yz, zx, zy, zz; };
		v3f v[3];
		float val[9];
	};
} m3f;

typedef struct {
	union {
		struct { float x, y, z, w; };
		float val[4];
	};
} v4f;

typedef struct {
	union {
		struct { v4f x, y, z, w; };
		struct { float xx, xy, xz, xw, yy, yx, yz, yw, zx, zy, zz, zw, wx, wy, wz, ww; };
		v4f v[4];
		float val[16];
	};
} m4f;

bool nearzerof(float x);
float sqf(float x);
float cubef(float x);
float clampf(float l, float h, float x);
bool eqf(float x, float y);
float randf(float l, float h);
bool biasgtf(float x, float y);

v2f mkv2f(float x, float y);
v2f fillv2f(float x);
v2f absv2f(v2f v);
v2f sigv2f(v2f v);
v2f neg2f(v2f v);
v2f addv2f(v2f v, v2f u);
v2f subv2f(v2f v, v2f u);
v2f mulv2f(v2f v, v2f y);
v2f divv2f(v2f v, v2f u);
v2f addv2fs(v2f v, float s);
v2f subv2fs(v2f v, float s);
v2f mulv2fs(v2f v, float s);
v2f divv2fs(v2f v, float s);
bool nearzerov2f(v2f v);
float sqlenv2f(v2f v);
float dotv2f(v2f v, v2f u);
float lenv2f(v2f v);
float sqdistv2f(v2f u, v2f v);
v2f normv2f(v2f v);
v2f rotv2f(v2f v, float theta);
v2f clampv2f(v2f l, v2f h, v2f v);
v2f minv2f(v2f v, v2f u);
v2f maxv2f(v2f v, v2f u);
float crossv2f(v2f v, v2f u);
v2f crossv2fs(v2f v, float s);
v2f crosssv2f(float s, v2f v);

m2f mkm2f(float xx, float xy, float yx, float yy);
m2f mkvm2f(v2f x, v2f y);
m2f orientm2f(float theta);
m2f absm2f(m2f m);
v2f xaxism2f(m2f m);
v2f yaxism2f(m2f m);
m2f transposem2f(m2f m);
m2f mulm2f(m2f m, m2f n);
v2f mulm2fv(m2f m, v2f v);

v4f mkv4f(float x, float y, float z, float w);
v4f mulv4fs(v4f m, float s);
m4f scalem4f(m4f m, v3f s);

m4f eyem4f();
m4f mkvm4f(v4f x, v4f y, v4f z, v4f w);
m4f translatem4f(m4f m, v3f t);
m4f rotm4f(m4f m, float theta, v3f v);
m4f frustumm4f(m4f m, float lf, float rt, float bot, float top, float near, float far);
m4f perpm4f(m4f m, float fovy, float aspect, float near, float far);
m4f orthom4f(m4f m, float lf, float rt, float bot, float top, float near, float far);
m4f mulm4f(m4f m, m4f n);

#endif
