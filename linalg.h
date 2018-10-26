#ifndef LINALG_H
#define LINALG_H

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

#define VALUE_DECLARE(A,B)\
bool nearzero##A(const B x);\
B sq##A(const B x);\
B cube##A(const B x);\
B clamp##A(const B l, const B h, const B x);\
bool eq##A(const B x, const B y);\
B rand##A(const B l, const B h);\
bool biasgt##A(const B x, const B y);\
float recipinf##A(const B x);

VALUE_DECLARE(f,float)

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
v2f addv2nf(v2f v, float n);
v2f subv2nf(v2f v, float n);
v2f mulv2nf(v2f v, float n);
v2f divv2nf(v2f v, float n);
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
v2f crossv2nf(v2f v, float n);
v2f crossnv2f(float n, v2f v);

#define V3_DECLARE(A,B)\
v3##A _v3##A(B x, B y, B z);

V3_DECLARE(f,float)
V3_DECLARE(ui,unsigned int)
V3_DECLARE(si,short int)

v3f zerov3f();
v3f fillv3f(float x);
v3f absv3f(v3f v);
v3f sigv3f(v3f v);
v3f negv3f(v3f v);
v3f addv3f(v3f v, v3f u);
v3f subv3f(v3f v, v3f u);
v3f mulv3f(v3f v, v3f u);
v3f mulv3nf(v3f v, float n);
v3f divv3f(v3f v, v3f u);
v3f divv3nf(v3f v, float n);
bool eqv3f(v3f v, v3f u);
float lenv3f(v3f v);
v3f normv3f(v3f v);
v3f crossv3f(v3f v, v3f u);
float dotv3f(v3f v, v3f u);

#define V4_DECLARE(A,B)\
v4##A _v4##A(B x, B y, B z, B w);

V4_DECLARE(f,float)

v4f v4v3f(v3f v, float w);
v4f zerov4f();
v4f fillv4f(float x);
v4f absv4f(v4f v);
v4f sigv4f(v4f v);
v4f negv4f(v4f v);
v4f addv4f(v4f v, v4f u);
v4f subv4f(v4f v, v4f u);
v4f mulv4f(v4f v, v4f u);
v4f mulv4nf(v4f j, float n);
v4f divv4f(v4f v, v4f u);
v4f divv4nf(v4f v, float n);
bool eqv4f(v4f v, v4f u);
v4f lerpv4f(v4f v, v4f u, float t);
float lenv4f(v4f v);
v4f normv4f(v4f v);
float dotv4f(v4f v, v4f u);
// Quaternion
v4f slerpv4f(v4f a, v4f b, float t);
v4f rotv4f(v4f a, v4f b);
m3f m3v4f(v4f v);
v4f v4axisanglef(v3f axis, float theta);
v4f v4fromv3f(v3f v, v3f u);

#define M2_DECLARE(A,B)\
m2##A _m2##A(B xx, B xy, B yx, B yy);

M2_DECLARE(f,float)

m2f vm2f(v2f x, v2f y);
m2f eyem2f();
m2f zerom2f();
m2f fillm2f(float x);
m2f absm2f(m2f m);
m2f sigm2f(m2f m);
m2f negm2f(m2f m);
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

m3f m3m4f(m4f m);
m3f vm3f(v3f x, v3f y, v3f z);
m3f eyem3f();
m3f zerom3f();
m3f fillm3f(float x);
m3f absm3f(m3f m);
m3f sigm3f(m3f m);
m3f negm3f(m3f m);
m3f transposem3f(m3f m);

#define M4_DECLARE(A,B)\
m4##A _m4##A(B xx, B xy, B xz, B xw, B yx, B yy, B yz, B yw, B zx, B zy, B zz, B zw, B wx, B wy, B wz, B ww);

M4_DECLARE(f,float)

m4f m4m3f(m3f m);
m4f vm4f(v4f x, v4f y, v4f z, v4f w);
m4f eyem4f();
m4f zerom4f();
m4f fillm4f(float x);
m4f absm4f(m4f m);
m4f sigm4f(m4f m);
m4f negm4f(m4f m);
m4f scalem4f(m4f m, v3f s);
m4f addm4f(m4f m, m4f n);
m4f subm4f(m4f m, m4f n);
m4f mulm4f(m4f m, m4f n);
v4f mulm4fv(m4f m, v4f v);
m4f transposem4f(m4f m);
m4f rotanglem4f(float theta);
m4f rotym4f(float theta);
m4f rotxm4f(float theta);
m4f rotm4f(float theta, v3f v);
m4f translatef(v3f t);
m4f frustumf(float lf, float rt, float bot, float top, float near, float far);
m4f perspf(float fovy, float aspect, float near, float far);
m4f orthof(float lf, float rt, float bot, float top, float near, float far);
m4f lookatf(v3f eye, v3f target, v3f up);

#endif
