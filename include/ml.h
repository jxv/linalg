#ifndef ML_H
#define ML_H

#include <stdbool.h>

#define V2(A,B)\
typedef struct {\
	union {\
		struct { B x, y; };\
		B val[2];\
	};\
} v2##A;

V2(f,float)
V2(i,int)

#define V3(A,B)\
typedef struct {\
	union {\
		struct { B x, y, z; };\
		B val[3];\
	};\
} v3##A;

V3(f,float)
V3(ui,unsigned int)
V3(si,short int)

#define V4(A,B)\
typedef struct {\
	union {\
		struct { B x, y, z, w; };\
		B val[4];\
	};\
} v4##A;

V4(f,float)

#define M2(A,B)\
typedef struct {\
	union {\
		struct { v2##A x, y; };\
		struct { B xx, xy, yx, yy; };\
		v2##A v[2];\
		B val[4];\
	};\
} m2##A;

M2(f,float)

#define M3(A,B)\
typedef struct {\
	union {\
		struct { v3##A x, y, z; };\
		struct { B xx, xy, xz, yx, yy, yz, zx, zy, zz; };\
		v3##A v[3];\
		B val[9];\
	};\
} m3##A;

M3(f,float)

#define M4(A,B)\
typedef struct {\
	union {\
		struct { v4##A x, y, z, w; };\
		struct { B xx, xy, xz, xw, yy, yx, yz, yw, zx, zy, zz, zw, wx, wy, wz, ww; };\
		v4##A v[4];\
		B val[16];\
	};\
} m4##A;

M4(f,float)

#define Q(A,B)\
typedef struct {\
	union {\
		struct { B x, y, z, w; };\
		v4##A v;\
		B val[4];\
	};\
} q##A;

Q(f,float)

bool nearzerof(float x);
float sqf(float x);
float cubef(float x);
float clampf(float l, float h, float x);
bool eqf(float x, float y);
float randf(float l, float h);
bool biasgtf(float x, float y);
float recipinff(float x);

#define V2_DECLARE(A,B)\
v2##A _v2##A(B x, B y);

V2_DECLARE(f,float)
V2_DECLARE(i,int)

v2f zerov2f();
v2f fillv2f(float x);
v2f absv2f(v2f v);
v2f sigv2f(v2f v);
v2f negv2f(v2f v);
v2f addv2f(v2f v, v2f u);
v2f subv2f(v2f v, v2f u);
v2f mulv2f(v2f v, v2f y);
v2f divv2f(v2f v, v2f u);
v2f addv2fs(v2f v, float s);
v2f subv2fs(v2f v, float s);
v2f mulv2fs(v2f v, float s);
v2f divv2fs(v2f v, float s);
bool nearzerov2f(v2f v);
bool eqv2f(v2f v, v2f u);
v2f lerp(v2f v, v2f u, float t);
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

#define V3_DECLARE(A,B)\
v3##A _v3##A(B x, B y, B z);

V3_DECLARE(f,float)
V3_DECLARE(ui,unsigned int)
V3_DECLARE(si,short int)

v3f zerov3f();
v3f negv3f(v3f v);
v3f addv3f(v3f v, v3f u);
v3f subv3f(v3f v, v3f u);
v3f mulv3f(v3f v, v3f u);
v3f mulv3fs(v3f v, float s);
v3f divv3f(v3f v, v3f u);
v3f divv3fs(v3f v, float s);
bool eqv3f(v3f v, v3f u);
float lenv3f(v3f v);
v3f normv3f(v3f v);
v3f crossv3f(v3f v, v3f u);
float dotv3f(v3f v, v3f u);

#define V4_DECLARE(A,B)\
v4##A _v4##A(B x, B y, B z, B w);

V4_DECLARE(f,float)

v4f zerov4f();
v4f v4fv3f(v3f v, float w);
v4f negv4f(v4f v);
v4f addv4f(v4f v, v4f u);
v4f subv4f(v4f v, v4f u);
v4f mulv4f(v4f v, v4f u);
v4f mulv4fs(v4f j, float s);
v4f divv4f(v4f v, v4f u);
v4f divv4fs(v4f v, float s);
bool eqv4f(v4f v, v4f u);
v4f lerpv4f(v4f v, v4f u, float t);
float lenv4f(v4f v);
v4f normv4f(v4f v);
float dotv4f(v4f v, v4f u);
// Quaternion
v4f slerpv4f(v4f a, v4f b, float t);
v4f rotv4f(v4f a, v4f b);
m3f m3v4f(v4f v);
v4f axisanglev4f(v3f axis, float theta);
v4f fromv3v4f(v3f v, v3f u);

#define M2_DECLARE(A,B)\
m2##A _m2##A(B xx, B xy, B yx, B yy);

M2_DECLARE(f,float)

m2f vm2f(v2f x, v2f y);
m2f mulm2f(m2f m, m2f n);
v2f mulm2fv(m2f m, v2f v);
m2f orientm2f(float theta);
m2f absm2f(m2f m);
v2f xaxism2f(m2f m);
v2f yaxism2f(m2f m);
m2f transposem2f(m2f m);

#define M3_DECLARE(A,B)\
m3##A _m3##A(B xx, B xy, B xz, B yx, B yy, B yz, B zx, B zy, B zz);

M3_DECLARE(f,float)

m3f vm3f(v3f x, v3f y, v3f z);
m3f eyem3f();
m3f transposem3f(m3f m);
m4f m4fm3f(m3f m);

#define M4_DECLARE(A,B)\
m4##A _m4##A(B xx, B xy, B xz, B xw, B yx, B yy, B yz, B yw, B zx, B zy, B zz, B zw, B wx, B wy, B wz, B ww);

M4_DECLARE(f,float)

m4f vm4f(v4f x, v4f y, v4f z, v4f w);
m4f scalem4f(m4f m, v3f s);
m4f eyem4f();
m3f m3fm4f(m4f m);
m4f addm4f(m4f m, m4f n);
m4f subm4f(m4f m, m4f n);
m4f mulm4f(m4f m, m4f n);
v4f mulm4fv(m4f m, v4f v);
m4f transposem4f(m4f m);
m4f translatem4f(v3f t);
m4f rotam4f(float theta);
m4f rotm4f(float theta, v3f v);
m4f frustumm4f(float lf, float rt, float bot, float top, float near, float far);
m4f perspm4f(float fovy, float aspect, float near, float far);
m4f orthom4f(float lf, float rt, float bot, float top, float near, float far);
m4f lookatf(v3f eye, v3f target, v3f up);

#endif
