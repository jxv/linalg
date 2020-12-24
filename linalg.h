#ifndef LINALG_H
#define LINALG_H

#include <stdbool.h>

#define LINALG_MAX(x,y) (((x) >= (y)) ? (x) : (y))
#define LINALG_MIN(x,y) (((x) <= (y)) ? (x) : (y))

#define absi abs
#define absf fabsf
#define absd fabs
#define absld fabsld

#define mini(x,y) LINALG_MIN((x),(y))
#define minf fminf
#define mind fmin
#define minld fminl

#define maxi(x,y) LINALG_MAX((x),(y))
#define maxf fmaxf
#define maxd fmax
#define maxld fmaxl

#define tand tan
#define tanld tanl

#define sind sin
#define sinld sinl

#define asind asin
#define asinld asinl

#define cosd cos
#define cosld cosl

#define acosd acos
#define acosld acosl

#define atand atan
#define atanld atanl

#define atan2d atan2
#define atan2ld atan2l

#define sqrtd sqrt
#define sqrtld sqrtl

#define LINALG_V2_STRUCT(A,B)\
typedef struct {\
    union {\
        struct { B x, y; };\
        B val[2];\
    };\
} v2##A;

LINALG_V2_STRUCT(c,char)
LINALG_V2_STRUCT(uc,unsigned char)
LINALG_V2_STRUCT(si,short int)
LINALG_V2_STRUCT(usi,unsigned short int)
LINALG_V2_STRUCT(i,int)
LINALG_V2_STRUCT(ui,unsigned int)
LINALG_V2_STRUCT(f,float)
LINALG_V2_STRUCT(d,double)
LINALG_V2_STRUCT(ld,long double)

#define LINALG_V3_STRUCT(A,B)\
typedef struct {\
    union {\
        struct { B x, y, z; };\
        B val[3];\
    };\
} v3##A;

LINALG_V3_STRUCT(c,char)
LINALG_V3_STRUCT(uc,unsigned char)
LINALG_V3_STRUCT(si,short int)
LINALG_V3_STRUCT(usi,unsigned short int)
LINALG_V3_STRUCT(i,int)
LINALG_V3_STRUCT(ui,unsigned int)
LINALG_V3_STRUCT(f,float)
LINALG_V3_STRUCT(d,double)
LINALG_V3_STRUCT(ld,long double)

#define LINALG_V4_STRUCT(A,B)\
typedef struct {\
    union {\
        struct { B x, y, z, w; };\
        B val[4];\
    };\
} v4##A;

LINALG_V4_STRUCT(c,char)
LINALG_V4_STRUCT(uc,unsigned char)
LINALG_V4_STRUCT(si,short int)
LINALG_V4_STRUCT(usi,unsigned short int)
LINALG_V4_STRUCT(i,int)
LINALG_V4_STRUCT(ui,unsigned int)
LINALG_V4_STRUCT(f,float)
LINALG_V4_STRUCT(d,double)
LINALG_V4_STRUCT(ld,long double)

#define LINALG_M2_STRUCT(A,B)\
typedef struct {\
    union {\
        struct { v2##A x, y; };\
        struct { B xx, xy, yx, yy; };\
        v2##A v[2];\
        B val[4];\
    };\
} m2##A;

LINALG_M2_STRUCT(c,char)
LINALG_M2_STRUCT(uc,unsigned char)
LINALG_M2_STRUCT(si,short int)
LINALG_M2_STRUCT(usi,unsigned short int)
LINALG_M2_STRUCT(i,int)
LINALG_M2_STRUCT(ui,unsigned int)
LINALG_M2_STRUCT(f,float)
LINALG_M2_STRUCT(d,double)
LINALG_M2_STRUCT(ld,long double)

#define LINALG_M3_STRUCT(A,B)\
typedef struct {\
    union {\
        struct { v3##A x, y, z; };\
        struct { B xx, xy, xz, yx, yy, yz, zx, zy, zz; };\
        v3##A v[3];\
        B val[9];\
    };\
} m3##A;

LINALG_M3_STRUCT(c,char)
LINALG_M3_STRUCT(uc,unsigned char)
LINALG_M3_STRUCT(si,short int)
LINALG_M3_STRUCT(usi,unsigned short int)
LINALG_M3_STRUCT(i,int)
LINALG_M3_STRUCT(ui,unsigned int)
LINALG_M3_STRUCT(f,float)
LINALG_M3_STRUCT(d,double)
LINALG_M3_STRUCT(ld,long double)

#define LINALG_M4_STRUCT(A,B)\
typedef struct {\
    union {\
        struct { v4##A x, y, z, w; };\
        struct { B xx, xy, xz, xw, yx, yy, yz, yw, zx, zy, zz, zw, wx, wy, wz, ww; };\
        v4##A v[4];\
        B val[16];\
    };\
} m4##A;

LINALG_M4_STRUCT(c,char)
LINALG_M4_STRUCT(uc,unsigned char)
LINALG_M4_STRUCT(si,short int)
LINALG_M4_STRUCT(usi,unsigned short int)
LINALG_M4_STRUCT(i,int)
LINALG_M4_STRUCT(f,float)
LINALG_M4_STRUCT(d,double)
LINALG_M4_STRUCT(ld,long double)

#define LINALG_Q_STRUCT(A,B)\
typedef struct {\
    union {\
        struct { B x, y, z, w; };\
        v4##A v;\
        B val[4];\
    };\
} q##A;

LINALG_Q_STRUCT(c,char)
LINALG_Q_STRUCT(uc,unsigned char)
LINALG_Q_STRUCT(si,short int)
LINALG_Q_STRUCT(usi,unsigned short int)
LINALG_Q_STRUCT(i,int)
LINALG_Q_STRUCT(f,float)
LINALG_Q_STRUCT(d,double)
LINALG_Q_STRUCT(ld,long double)

#define LINALG_VALUE_DECLARE(A,B)\
static bool nearzero##A(const B x);\
static B sq##A(const B x);\
static B cube##A(const B x);\
static B clamp##A(const B l, const B h, const B x);\
static bool eq##A(const B x, const B y);\
static B rand##A(const B l, const B h);\
static bool biasgt##A(const B x, const B y);\
static B recipinf##A(const B x);

LINALG_VALUE_DECLARE(f,float)
LINALG_VALUE_DECLARE(d,double)

#define LINALG_V2_CTOR_DECLARE(A,B)\
static v2##A _v2##A(const B x, const B y);\
static v2##A zerov2##A(void);\
static v2##A fillv2##A(const B x);

LINALG_V2_CTOR_DECLARE(f,float)
LINALG_V2_CTOR_DECLARE(d,double)
LINALG_V2_CTOR_DECLARE(i,int)

#define LINALG_V2_FUNC_DECLARE(A,B)\
static bool eqv2##A(const v2##A v, const v2##A u);\
static v2##A absv2##A(const v2##A v);\
static v2##A sigv2##A(const v2##A v);\
static v2##A negv2##A(const v2##A v);\
static v2##A addv2##A(const v2##A v, const v2##A u);\
static v2##A subv2##A(const v2##A v, const v2##A u);\
static v2##A mulv2##A(const v2##A v, const v2##A y);\
static v2##A divv2##A(const v2##A v, const v2##A u);\
static v2##A addv2n##A(const v2##A v, const B n);\
static v2##A subv2n##A(const v2##A v, const B n);\
static v2##A mulv2n##A(const v2##A v, const B n);\
static v2##A divv2n##A(const v2##A v, const B n);\
static B dotv2##A(const v2##A v, const v2##A u);\
static B crossv2##A(const v2##A v, const v2##A u);\
static v2##A crossv2n##A(const v2##A v, const B n);\
static v2##A crosssv2##A(const B s, const v2##A v);\
static v2##A minv2##A(const v2##A v, const v2##A u);\
static v2##A maxv2##A(const v2##A v, const v2##A u);

LINALG_V2_FUNC_DECLARE(f,float)
LINALG_V2_FUNC_DECLARE(d,double)

#define LINALG_V2_FLOATING_DECLARE(A,B)\
static bool nearzerov2##A(const v2##A v);\
static v2##A lerp##A(const v2##A v, const v2##A u, const B t);\
static B sqlenv2##A(const v2##A v);\
static B lenv2##A(const v2##A v);\
static B sqdistv2##A(const v2##A u, const v2##A v);\
static v2##A normv2##A(const v2##A v);\
static v2##A rotv2##A(const v2##A v, const B theta);\
static v2##A clampv2##A(const v2##A l, const v2##A h, const v2##A v);\

LINALG_V2_FLOATING_DECLARE(f,float)
LINALG_V2_FLOATING_DECLARE(d,double)

#define LINALG_V3_CTOR_DECLARE(A,B)\
static v3##A _v3##A(const B x, const B y, const B z);\
static v3##A zerov3##A(void);\
static v3##A fillv3##A(const B x);

LINALG_V3_CTOR_DECLARE(f,float)
LINALG_V3_CTOR_DECLARE(d,double)
LINALG_V3_CTOR_DECLARE(i,int)

#define LINALG_V3_FUNC_DECLARE(A,B)\
static bool eqv3##A(const v3##A v, const v3##A u);\
static v3##A absv3##A(const v3##A v);\
static v3##A sigv3##A(const v3##A v);\
static v3##A negv3##A(const v3##A v);\
static v3##A addv3##A(const v3##A v, const v3##A u);\
static v3##A subv3##A(const v3##A v, const v3##A u);\
static v3##A mulv3##A(const v3##A v, const v3##A u);\
static v3##A mulv3n##A(const v3##A v, const B n);\
static v3##A divv3##A(const v3##A v, const v3##A u);\
static v3##A divv3n##A(const v3##A v, const B n);\
static v3##A crossv3##A(const v3##A v, const v3##A u);\
static B dotv3##A(const v3##A v, const v3##A u);

LINALG_V3_FUNC_DECLARE(f,float)
LINALG_V3_FUNC_DECLARE(d,double)

#define LINALG_V3_FLOATING_DECLARE(A,B)\
static v3##A normv3##A(const v3##A v);\
static B lenv3##A(const v3##A v);

LINALG_V3_FLOATING_DECLARE(f,float)
LINALG_V3_FLOATING_DECLARE(d,double)

#define LINALG_V4_CTOR_DECLARE(A,B)\
static v4##A _v4##A(const B x, const B y, const B z, const B w);\
static v4##A v4v3##A(const v3##A v, const B w);\
static v4##A zerov4##A(void);\
static v4##A fillv4##A(const B x);

LINALG_V4_CTOR_DECLARE(f,float)
LINALG_V4_CTOR_DECLARE(d,double)

#define LINALG_V4_FUNC_DECLARE(A,B)\
static bool eqv4##A(const v4##A v, const v4##A u);\
static v4##A absv4##A(const v4##A v);\
static v4##A sigv4##A(const v4##A v);\
static v4##A negv4##A(const v4##A v);\
static v4##A addv4##A(const v4##A v, const v4##A u);\
static v4##A subv4##A(const v4##A v, const v4##A u);\
static v4##A mulv4##A(const v4##A v, const v4##A u);\
static v4##A mulv4##A##s(const v4##A v, const B s);\
static v4##A divv4##A(const v4##A v, const v4##A u);\
static v4##A divv4##A##s(const v4##A v, const B s);\
static B dotv4##A(const v4##A v, const v4##A u);

LINALG_V4_FUNC_DECLARE(f,float)
LINALG_V4_FUNC_DECLARE(d,double)

#define LINALG_V4_FLOATING_DECLARE(A,B)\
static v4##A lerpv4##A(const v4##A v, const v4##A u, const B t);\
static v4##A normv4##A(const v4##A v);

LINALG_V4_FLOATING_DECLARE(f,float)
LINALG_V4_FLOATING_DECLARE(d,double)

#define LINALG_Q_DECLARE(A,B)\
static v4##A slerpv4##A(const v4##A a, const v4##A b, const B t);\
static v4##A rotv4##A(const v4##A a, const v4##A b);\
static m3##A m3v4##A(const v4##A v);\
static v4##A v4fromv3##A(const v3##A v, const v3##A u);\
static v4##A v4axisangle##A(const v3##A axis, const B theta);

LINALG_Q_DECLARE(f,float)
LINALG_Q_DECLARE(d,double)

#define LINALG_M2_CTOR_DECLARE(A,B)\
static m2##A _m2##A(const B xx, const B xy, const B yx, const B yy);\
static m2##A vm2##A(const v2##A x, const v2##A y);\
static m2##A eyem2##A(void);\
static m2##A zerom2##A(void);\
static m2##A fillm2##A(const B x);

LINALG_M2_CTOR_DECLARE(f,float)
LINALG_M2_CTOR_DECLARE(d,double)

#define LINALG_M2_FUNC_DECLARE(A,B)\
static m2##A absm2##A(const m2##A m);\
static m2##A sigm2##A(const m2##A m);\
static m2##A negm2##A(const m2##A m);\
static m2##A mulm2##A(const m2##A m, const m2##A n);\
static v2##A mulm2##A##v(const m2##A m, const v2##A v);\
static v2##A xaxism2##A(const m2##A m);\
static v2##A yaxism2##A(const m2##A m);\
static m2##A transposem2##A(const m2##A m);

#define LINALG_M2_FLOATING_DECLARE(A,B)\
static m2##A orientm2##A(const B theta);\

LINALG_M2_FLOATING_DECLARE(f,float)
LINALG_M2_FLOATING_DECLARE(d,double)

#define LINALG_M3_CTOR_DECLARE(A,B)\
static m3##A _m3##A(const B xx, const B xy, const B xz, const B yx, const B yy, const B yz, const B zx, const B zy, const B zz);\
static m3##A m3m4##A(const m4##A m);\
static m3##A vm3##A(const v3##A x, const v3##A y, const v3##A z);\
static m3##A eyem3##A(void);\
static m3##A zerom3##A(void);\
static m3##A fillm3##A(const B x);

LINALG_M3_CTOR_DECLARE(f,float)
LINALG_M3_CTOR_DECLARE(d,double)

#define LINALG_M3_FUNC_DECLARE(A,B)\
static m3##A absm3##A(const m3##A m);\
static m3##A sigm3##A(const m3##A m);\
static m3##A negm3##A(const m3##A m);\
static m3##A transposem3##A(const m3##A m);

LINALG_M3_FUNC_DECLARE(f,float)
LINALG_M3_FUNC_DECLARE(d,double)

#define LINALG_M4_CTOR_DECLARE(A,B)\
static m4##A _m4##A(const B xx, const B xy, const B xz, const B xw, const B yx, const B yy, const B yz, const B yw, const B zx, const B zy, const B zz, const B zw, const B wx, const B wy, const B wz, const B ww);\
static m4##A vm4##A(const v4##A x, const v4##A y, const v4##A z, const v4##A w);\
static m4##A eyem4##A(void);\
static m4##A zerom4##A(void);\
static m4##A fillm4##A(const B x);\
static m4##A m4m3##A(const m3##A m);

LINALG_M4_CTOR_DECLARE(f,float)
LINALG_M4_CTOR_DECLARE(d,double)

#define LINALG_M4_FUNC_DECLARE(A,B)\
static m4##A absm4##A(const m4##A m);\
static m4##A sigm4##A(const m4##A m);\
static m4##A negm4##A(const m4##A m);\
static m4##A addm4##A(const m4##A m, const m4##A n);\
static m4##A subm4##A(const m4##A m, const m4##A n);\
static m4##A mulm4##A(const m4##A m, const m4##A n);\
static v4##A mulm4##A##v(const m4##A m, const v4##A v);\
static m4##A scalem4##A(const m4##A m, const v3##A s);\
static m4##A transposem4##A(const m4##A m);\
static m4##A translate##A(const v3##A t);

LINALG_M4_FUNC_DECLARE(f,float)
LINALG_M4_FUNC_DECLARE(d,double)

#define LINALG_M4_FLOATING_DECLARE(A,B)\
static m4##A rotanglem4##A(const B theta);\
static m4##A rotym4##A(const B theta);\
static m4##A rotxm4##A(const B theta);\
static m4##A rotm4##A(const B theta, const v3##A v);

LINALG_M4_FLOATING_DECLARE(f,float)
LINALG_M4_FLOATING_DECLARE(d,double)

#define LINALG_M4_CAMERA_DECLARE(A,B)\
static m4##A frustum##A(const B lf, const B rt, const B bot, const B top, const B near, const B far);\
static m4##A persp##A(const B fovy, const B aspect, const B near, const B far);\
static m4##A ortho##A(const B lf, const B rt, const B bot, const B top, const B near, const B far);\
static m4##A lookat##A(const v3##A eye, const v3##A target, const v3##A up);

LINALG_M4_CAMERA_DECLARE(f,float)
LINALG_M4_CAMERA_DECLARE(d,double)

// Implementation

#define LINALG_VALUE_DEFINE(A,B)\
static inline bool nearzero##A(const B x) {\
    return abs##A(x) < 1e-6;\
}\
\
static inline B sq##A(const B x) {\
    return x * x;\
}\
\
static inline B cube##A(const B x) {\
    return x * x * x;\
}\
\
static inline B clamp##A(const B l, const B h, const B x) {\
    return min##A(h, max##A(l, x));\
}\
\
static inline bool eq##A(const B x, const B y) {\
    return abs##A(x - y) <= 1e-6;\
}\
\
static inline B rand##A(const B l, const B h) {\
    return l + (h - l) * ((B)rand() / RAND_MAX);\
}\
\
static inline bool biasgt##A(const B x, const B y) {\
    const B biasrel = (B)0.95;\
    const B biasabs = (B)0.01;\
    return x >= y * biasrel + x * biasabs;\
}\
\
static inline B recipinf##A(const B x) {\
    return nearzero##A(x) ? 0 : (1 / x);\
}

LINALG_VALUE_DEFINE(f,float)
LINALG_VALUE_DEFINE(d,double)

static inline bool eqi(const int x, const int y) { return x == y; }

#define LINALG_V2_CTOR(A,B)\
static inline v2##A _v2##A(const B x, const B y) {\
    return (v2##A) { .x = x, .y = y };\
}\
\
static inline v2##A zerov2##A(void) {\
    return _v2##A(0,0);\
}\
\
static inline v2##A fillv2##A(const B x) {\
    return _v2##A(x, x);\
}

LINALG_V2_CTOR(f,float)
LINALG_V2_CTOR(d,double)
LINALG_V2_CTOR(i,int)

#define LINALG_V2_FUNC(A,B)\
static inline v2##A absv2##A(const v2##A v) {\
    return _v2##A(abs##A(v.x), abs##A(v.y));\
}\
\
static inline v2##A sigv2##A(const v2##A v) {\
    return _v2##A(-abs##A(v.x), -abs##A(v.y));\
}\
\
static inline bool eqv2##A(const v2##A v, const v2##A u) {\
    return eq##A(v.x, u.x) &&  eq##A(v.y, u.y);\
}\
\
static inline v2##A negv2##A(const v2##A v) {\
    return _v2##A(-v.x, -v.y);\
}\
\
static inline v2##A addv2##A(const v2##A v, const v2##A u) {\
    return _v2##A(v.x + u.x, v.y + u.y);\
}\
\
static inline v2##A subv2##A(const v2##A v, const v2##A u) {\
    return _v2##A(v.x - u.x, v.y - u.y);\
}\
\
static inline v2##A mulv2##A(const v2##A v, const v2##A u) {\
    return _v2##A(v.x * u.x, v.y * u.y);\
}\
\
static inline v2##A divv2##A(const v2##A v, const v2##A u) {\
    return _v2##A(v.x / u.x, v.y / u.y);\
}\
\
static inline v2##A addv2n##A(const v2##A v, const B s) {\
    return _v2##A(v.x + s, v.y + s);\
}\
\
static inline v2##A subv2n##A(const v2##A v, const B s) {\
    return _v2##A(v.x - s, v.y - s);\
}\
\
static inline v2##A mulv2n##A(const v2##A v, const B s) {\
    return _v2##A(v.x * s, v.y * s);\
}\
\
static inline v2##A divv2n##A(const v2##A v, const B s) {\
    return _v2##A(v.x / s, v.y / s);\
}\
\
static inline B dotv2##A(const v2##A v, const v2##A u) {\
    return v.x * u.x + v.y * u.y;\
}\
\
static inline B crossv2##A(const v2##A v, const v2##A u) {\
    return v.x * u.y - v.y * u.x;\
}\
\
static inline v2##A crossv2n##A(const v2##A v, const B s) {\
    return _v2##A(s * v.y, -s * v.x);\
}\
\
static inline v2##A crosssv2##A(const B s, const v2##A v) {\
    return _v2##A(-s * v.y, s * v.x);\
}\
\
static inline v2##A minv2##A(const v2##A v, const v2##A u) {\
    return _v2##A(min##A(v.x, u.x), min##A(v.y, u.y));\
}\
\
static inline v2##A maxv2##A(const v2##A v, const v2##A u) {\
    return _v2##A(max##A(v.x, u.x), max##A(v.y, u.y));\
}

LINALG_V2_FUNC(f,float)
LINALG_V2_FUNC(d,double)

#define LINALG_V2_FLOATING_DEFINE(A,B)\
static inline bool nearzerov2##A(const v2##A v) {\
    return nearzero##A(v.x) && nearzero##A(v.y);\
}\
\
static inline v2##A lerp##A(const v2##A v, const v2##A u, const B t) {\
    return addv2##A(mulv2n##A(v, 1 - t), mulv2n##A(u, t));\
}\
\
static inline B sqlenv2##A(const v2##A v) {\
    return sq##A(v.x) + sq##A(v.y);\
}\
\
static inline B lenv2##A(const v2##A v) {\
    return sqrt##A(sqlenv2##A(v));\
}\
\
static inline B sqdistv2##A(const v2##A u, const v2##A v) {\
    return sqlenv2##A(subv2##A(u, v));\
}\
\
static inline v2##A normv2##A(const v2##A v) {\
    const B len = lenv2##A(v);\
    if (nearzero##A(len))\
        return v;\
    return mulv2n##A(v, 1 / len);\
}\
\
static inline v2##A rotv2##A(const v2##A x, const B theta) {\
    const B c = cos##A(theta);\
    const B s = sin##A(theta);\
    return _v2##A(x.x * c - x.y * s, x.x * s + x.y * c);\
}\
\
static inline v2##A clampv2##A(const v2##A l, const v2##A h, const v2##A v) {\
    return _v2##A(clamp##A(l.x, h.x, v.x), clamp##A(l.y, h.y, v.y));\
}

LINALG_V2_FLOATING_DEFINE(f,float)
LINALG_V2_FLOATING_DEFINE(d,double)

#define LINALG_V3_CTOR_DEFINE(A,B)\
static inline v3##A _v3##A(const B x, const B y, const B z) {\
    return (v3##A) { .x = x, .y = y, .z = z };\
}\
static inline v3##A zerov3##A(void) {\
    return _v3##A(0,0,0);\
}\
\
static inline v3##A fillv3##A(const B x) {\
    return _v3##A(x,x,x);\
}

LINALG_V3_CTOR_DEFINE(f,float)
LINALG_V3_CTOR_DEFINE(d,double)
LINALG_V3_CTOR_DEFINE(i,int)

#define LINALG_V3_FUNC_DEFINE(A,B)\
static inline bool eqv3##A(const v3##A v, const v3##A u) {\
    return v.x == u.x && v.y == u.y && v.z == u.z;\
}\
\
static inline v3##A absv3##A(const v3##A v) {\
    return _v3##A(abs##A(v.x), abs##A(v.y), abs##A(v.z));\
}\
\
static inline v3##A sigv3##A(const v3##A v) {\
    return _v3##A(-abs##A(v.x), -abs##A(v.y), -abs##A(v.z));\
}\
\
static inline v3##A negv3##A(const v3##A v) {\
    return _v3##A(-v.x, -v.y, -v.z);\
}\
\
static inline v3##A addv3##A(const v3##A v, const v3##A u) {\
    return _v3##A(v.x + u.x, v.y + u.y, v.z + u.z);\
}\
\
static inline v3##A subv3##A(const v3##A v, const v3##A u) {\
    return _v3##A(v.x - u.x, v.y - u.y, v.z - u.z);\
}\
\
static inline v3##A mulv3##A(const v3##A v, const v3##A u) {\
    return _v3##A(v.x * u.x, v.y * u.y, v.z * u.z);\
}\
\
static inline v3##A mulv3n##A(const v3##A v, const B s) {\
    return _v3##A(v.x * s, v.y * s, v.z * s);\
}\
\
static inline v3##A divv3##A(const v3##A v, const v3##A u) {\
    return _v3##A(v.x / u.x, v.y / u.y, v.z / u.z);\
}\
\
static inline v3##A divv3n##A(const v3##A v, const B s) {\
    return _v3##A(v.x / s, v.y / s, v.z / s);\
}\
\
static inline v3##A crossv3##A(const v3##A v, const v3##A u) {\
    return _v3##A(\
        v.y * u.z - v.z * u.y,\
        v.z * u.x - v.x * u.z,\
        v.x * u.y - v.y * u.x\
    );\
}\
\
static inline B dotv3##A(const v3##A v, const v3##A u) {\
    return v.x * u.x + v.y * u.y + v.z * u.z;\
}

LINALG_V3_FUNC_DEFINE(f,float)
LINALG_V3_FUNC_DEFINE(d,double)

#define LINALG_V3_FLOATING_DEFINE(A,B)\
static inline B lenv3##A(const v3##A v) {\
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);\
}\
\
static inline v3##A normv3##A(const v3##A v) {\
    const B len = lenv3##A(v);\
    return _v3##A(v.x / len, v.y / len, v.z / len);\
}

LINALG_V3_FLOATING_DEFINE(f,float)
LINALG_V3_FLOATING_DEFINE(d,double)

#define LINALG_V4_CTOR_DEFINE(A,B)\
static inline v4##A _v4##A(const B x, const B y, const B z, const B w) {\
    return (v4##A) { .x = x, .y = y, .z = z, .w = w };\
}\
\
static inline v4##A v4v3##A(const v3##A v, const B w) {\
    return _v4##A(v.x, v.y, v.z, w);\
}\
\
static inline v4##A zerov4##A(void) {\
    return _v4##A(0,0,0,0);\
}\
\
static inline v4##A fillv4##A(const B x) {\
    return _v4##A(x,x,x,x);\
}

LINALG_V4_CTOR_DEFINE(f,float)
LINALG_V4_CTOR_DEFINE(d,double)

#define LINALG_V4_FUNC_DEFINE(A,B)\
static inline bool eqv4##A(const v4##A v, const v4##A u) {\
    return v.x == u.x && v.y == u.y && v.z == u.z && v.w == u.w;\
}\
\
static inline v4##A absv4##A(const v4##A v) {\
    return _v4##A(abs##A(v.x), abs##A(v.y), abs##A(v.z), abs##A(v.w));\
}\
\
static inline v4##A sigv4##A(const v4##A v) {\
    return _v4##A(-abs##A(v.x), -abs##A(v.y), -abs##A(v.z), -abs##A(v.w));\
}\
\
static inline v4##A negv4##A(const v4##A v) {\
    return _v4##A(-v.x, -v.y, -v.z, -v.w);\
}\
\
static inline v4##A addv4##A(const v4##A v, const v4##A u) {\
    return _v4##A(v.x + u.x, v.y + u.y, v.z + u.z, v.w + u.w);\
}\
\
static inline v4##A subv4##A(const v4##A v, const v4##A u) {\
    return _v4##A(v.x - u.x, v.y - u.y, v.z - u.z, v.w - u.w);\
}\
\
static inline v4##A mulv4##A(const v4##A v, const v4##A u) {\
    return _v4##A(v.x * u.x, v.y * u.y, v.z * u.z, v.w * u.w);\
}\
\
static inline v4##A mulv4##A##s(const v4##A v, const B s) {\
    return _v4##A(v.x * s, v.y * s, v.z * s, v.w * s);\
}\
\
static inline v4##A divv4##A(const v4##A v, const v4##A u) {\
    return _v4##A(v.x / u.x, v.y / u.y, v.z / u.z, v.w / u.w);\
}\
\
static inline v4##A divv4##A##s(const v4##A v, const B s) {\
    return _v4##A(v.x / s, v.y / s, v.z / s, v.w / s);\
}\
static inline B dotv4##A(const v4##A v, const v4##A u) {\
    return v.x * u.x + v.y * u.y + v.z * u.z + v.w * u.w;\
}

LINALG_V4_FUNC_DEFINE(f,float)
LINALG_V4_FUNC_DEFINE(d,double)

#define LINALG_V4_FLOATING_DEFINE(A,B)\
static inline v4##A lerpv4##A(const v4##A v, const v4##A u, const B t) {\
    const B s = 1 - t;\
    return _v4##A(\
        s * v.x + t * u.x,\
        s * v.y + t * u.y,\
        s * v.z + t * u.z,\
        s * v.w + t * u.w\
    );\
}\
\
static inline v4##A normv4##A(const v4##A v) {\
    return mulv4##A##s(v, 1 / sqrtf(dotv4##A(v,v)));\
}

LINALG_V4_FLOATING_DEFINE(f,float)
LINALG_V4_FLOATING_DEFINE(d,double)

#define LINALG_Q_DEFINE(A,B)\
static inline v4##A slerpv4##A(const v4##A a, const v4##A b, const B t) {\
    const B dot = dotv4##A(a, b);\
    if (dot > 1 - 1e-6) {\
        return normv4##A(addv4##A(a, mulv4##A##s(subv4##A(a, b), t)));\
    }\
    const B dot_ = clamp##A(0, 1, dot);\
    const B theta = acos##A(dot_) * t;\
    const v4##A c = normv4##A(subv4##A(b, mulv4##A##s(a, dot_)));\
    return normv4##A(addv4##A(mulv4##A##s(a, cos##A(theta)), mulv4##A##s(c, sin##A(theta))));\
}\
\
static inline v4##A rotv4##A(const v4##A a, const v4##A b) {\
    return normv4##A(_v4##A(\
        a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,\
        a.w * b.y + a.y * b.w + a.z * b.x - a.x * b.z,\
        a.w * b.z + a.z * b.w + a.x * b.y - a.y * b.x,\
        a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z\
    ));\
}\
\
static inline m3##A m3v4##A(const v4##A v) {\
    const B s = 2;\
    B xs, ys, zs, wx, wy, wz, xx, xy, xz, yy, yz, zz;\
    xs = v.x * s;  ys = v.y * s;  zs = v.z * s;\
    wx = v.w * xs; wy = v.w * ys; wz = v.w * zs;\
    xx = v.x * xs; xy = v.x * ys; xz = v.x * zs;\
    yy = v.y * ys; yz = v.y * zs; zz = v.z * zs;\
    m3##A m;\
    m.xx = 1 - (yy + zz); m.yx = xy - wz;  m.zx = xz + wy;\
    m.xy = xy + wz; m.yy = 1 - (xx + zz); m.zy = yz - wx;\
    m.xz = xz - wy; m.yz = yz + wx; m.zz = 1 - (xx + yy);\
    return m;\
}\
\
static inline v4##A v4fromv3##A(const v3##A v, const v3##A u) {\
    if (eqv3##A(v, negv3##A(u))) {\
        return v4axisangle##A(_v3##A(1,0,0), M_PI);\
    }\
    const v3##A c = crossv3##A(v, u);\
    const B d = dotv3##A(v, u);\
    const B s = sqrt##A((1 + d) * 2);\
    return _v4##A(c.x / s, c.y / s, c.z / s, s / 2);\
}\
\
static inline v4##A v4axisangle##A(const v3##A axis, const B theta) {\
    const B s = sin##A(theta / 2);\
    const B c = cos##A(theta / 2);\
    return _v4##A(s * axis.x, s * axis.y, s * axis.z, c);\
}

LINALG_Q_DEFINE(f,float)
LINALG_Q_DEFINE(d,double)

#define LINALG_M2_CTOR_DEFINE(A,B)\
static inline m2##A _m2##A(const B xx, const B xy, const B yx, const B yy) {\
    return (m2##A) {\
        .x = _v2##A(xx,xy),\
        .y = _v2##A(yx,yy),\
    };\
}\
\
static inline m2##A vm2##A(const v2##A x, const v2##A y) {\
    return (m2##A) { .x = x, .y = y };\
}\
\
static inline m2##A eyem2##A(void) {\
    return _m2##A(1,0,0,1);\
}\
\
static inline m2##A zerom2##A(void) {\
    return vm2##A(zerov2##A(), zerov2##A());\
}\
\
static inline m2##A fillm2##A(const B x) {\
    return vm2##A(fillv2##A(x), fillv2##A(x));\
}

LINALG_M2_CTOR_DEFINE(f,float)
LINALG_M2_CTOR_DEFINE(d,double)

#define LINALG_M2_FUNC_DEFINE(A,B)\
static inline m2##A absm2##A(const m2##A m) {\
    return vm2##A(absv2##A(m.x), absv2##A(m.y));\
}\
\
static inline m2##A sigm2##A(const m2##A m) {\
    return vm2##A(sigv2##A(m.x), sigv2##A(m.y));\
}\
\
static inline m2##A negm2##A(const m2##A m) {\
    return vm2##A(negv2##A(m.x), negv2##A(m.y));\
}\
\
static inline m2##A mulm2##A(const m2##A m, const m2##A n) {\
    return (m2##A) {\
        .xx = m.xx * n.xx + m.xy * n.yx,\
        .xy = m.xx * n.xy + m.xy * n.yy,\
        .yx = m.yx * n.xx + m.yy * n.yx,\
        .yy = m.yx * n.xy + m.yy * n.yy,\
    };\
}\
\
static inline v2##A mulm2##A##v(const m2##A m, const v2##A v) {\
    return _v2##A(m.xx * v.x + m.xy * v.y, m.yx * v.x + m.yy * v.y);\
}\
\
static inline v2##A xaxism2##A(const m2##A m) {\
    return _v2##A(m.xx, m.yx);\
}\
\
static inline v2##A yaxism2##A(const m2##A m) {\
    return _v2##A(m.xy, m.yy);\
}\
\
static inline m2##A transposem2##A(const m2##A m) {\
    return _m2##A(m.xx, m.yx, m.xy, m.yy);\
}

#define LINALG_M2_FLOATING_DEFINE(A,B)\
static inline m2##A orientm2##A(const B theta) {\
    const B c = cos##A(theta);\
    const B s = sin##A(theta);\
    return _m2##A(c, -s, s, c);\
}

LINALG_M2_FLOATING_DEFINE(f,float)
LINALG_M2_FLOATING_DEFINE(d,double)

#define LINALG_M3_CTOR_DEFINE(A,B)\
static inline m3##A _m3##A(const B xx, const B xy, const B xz, const B yx, const B yy, const B yz, const B zx, const B zy, const B zz) {\
    return (m3##A) {\
        .x = _v3##A(xx,xy,xz),\
        .y = _v3##A(yx,yy,yz),\
        .z = _v3##A(zx,zy,zz),\
    };\
}\
\
static inline m3##A m3m4##A(const m4##A m) {\
    return (m3##A) {\
        .x = _v3##A(m.xx, m.xy, m.xz),\
        .y = _v3##A(m.yx, m.yy, m.yz),\
        .z = _v3##A(m.zx, m.zy, m.zz),\
    };\
}\
\
static inline m3##A vm3##A(const v3##A x, const v3##A y, const v3##A z) {\
    return (m3##A) { .x = x, .y = y, .z = z };\
}\
\
static inline m3##A eyem3##A(void) {\
    return _m3##A(1,0,0,0,1,0,0,0,1);\
}\
\
static inline m3##A zerom3##A(void) {\
    return vm3##A(zerov3##A(), zerov3##A(), zerov3##A());\
}\
\
static inline m3##A fillm3##A(const B x) {\
    return vm3##A(fillv3##A(x), fillv3##A(x), fillv3##A(x));\
}

LINALG_M3_CTOR_DEFINE(f,float)
LINALG_M3_CTOR_DEFINE(d,double)

#define LINALG_M3_FUNC_DEFINE(A,B)\
static inline m3##A absm3##A(const m3##A m) {\
    return vm3##A(absv3##A(m.x), absv3##A(m.y), absv3##A(m.z));\
}\
\
static inline m3##A sigm3##A(const m3##A m) {\
    return vm3##A(sigv3##A(m.x), sigv3##A(m.y), sigv3##A(m.z));\
}\
\
static inline m3##A negm3##A(const m3##A m) {\
    return vm3##A(negv3##A(m.x), negv3##A(m.y), negv3##A(m.z));\
}\
\
static inline m3##A transposem3##A(const m3##A m) {\
    return _m3##A(m.xx, m.yx, m.zx, m.xy, m.yy, m.zy, m.xz, m.yz, m.zz);\
}

LINALG_M3_FUNC_DEFINE(f,float)
LINALG_M3_FUNC_DEFINE(d,double)

#define LINALG_M4_CTOR_DEFINE(A,B)\
static inline m4##A _m4##A(const B xx, const B xy, const B xz, const B xw, const B yx, const B yy, const B yz, const B yw, const B zx, const B zy, const B zz, const B zw, const B wx, const B wy, const B wz, const B ww) {\
    return (m4##A) {\
        .x = _v4##A(xx,xy,xz,xw),\
        .y = _v4##A(yx,yy,yz,yw),\
        .z = _v4##A(zx,zy,zz,zw),\
        .w = _v4##A(wx,wy,wz,ww),\
    };\
}\
\
static inline m4##A m4m3##A(const m3##A m) {\
    return vm4##A(\
        _v4##A(m.xx, m.xy, m.xz, 0),\
        _v4##A(m.yx, m.yy, m.yz, 0),\
        _v4##A(m.zx, m.zy, m.zz, 0),\
        _v4##A(0,0,0,1)\
    );\
}\
\
static inline m4##A vm4##A(const v4##A x, const v4##A y, const v4##A z, const v4##A w) {\
    return (m4##A) { .x = x, .y = y, .z = z, .w = w };\
}\
\
static inline m4##A eyem4##A(void) {\
    return _m4##A(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);\
}\
\
static inline m4##A zerom4##A(void) {\
    return vm4##A(zerov4##A(), zerov4##A(), zerov4##A(), zerov4##A());\
}

LINALG_M4_CTOR_DEFINE(f,float)
LINALG_M4_CTOR_DEFINE(d,double)

#define LINALG_M4_FUNC_DEFINE(A,B)\
static inline m4##A absm4##A(const m4##A m) {\
    return vm4##A(absv4##A(m.x), absv4##A(m.y), absv4##A(m.z), absv4##A(m.w));\
}\
\
static inline m4##A fillm4##A(const B x) {\
    return vm4##A(fillv4##A(x), fillv4##A(x), fillv4##A(x), fillv4##A(x));\
}\
\
static inline m4##A sigm4##A(const m4##A m) {\
    return vm4##A(sigv4##A(m.x), sigv4##A(m.y), sigv4##A(m.z), sigv4##A(m.w));\
}\
\
static inline m4##A negm4##A(const m4##A m) {\
    return vm4##A(negv4##A(m.x), negv4##A(m.y), negv4##A(m.z), negv4##A(m.w));\
}\
\
static inline m4##A addm4##A(const m4##A m, const m4##A n) {\
    return vm4##A(addv4##A(m.x,n.x), addv4##A(m.y,n.y), addv4##A(m.z,n.z), addv4##A(m.w,n.w));\
}\
\
static inline m4##A subm4##A(const m4##A m, const m4##A n) {\
    return vm4##A(subv4##A(m.x,n.x), subv4##A(m.y,n.y), subv4##A(m.z,n.z), subv4##A(m.w,n.w));\
}\
\
static inline m4##A mulm4##A(const m4##A m, const m4##A n) {\
    m4##A o;\
    for (int i = 0; i < 4; i++) {\
        for (int j = 0; j < 4; j++) {\
            o.val[j * 4 + i] = 0.0;\
            for (int k = 0; k < 4; k++) {\
                B val = m.val[k * 4 + i] * n.val[j * 4 + k];\
                o.val[j * 4 + i] += val;\
            }\
        }\
    }\
    return o;\
}\
\
static inline v4##A mulm4##A##v(const m4##A m, const v4##A v) {\
    return _v4##A(dotv4##A(m.x, v), dotv4##A(m.y, v), dotv4##A(m.z, v), dotv4##A(m.w, v));\
}\
\
static inline m4##A scalem4##A(const m4##A m, const v3##A s) {\
    return vm4##A(mulv4##A##s(m.x, s.x), mulv4##A##s(m.y, s.y), mulv4##A##s(m.z, s.z), m.w);\
}\
\
static inline m4##A transposem4##A(const m4##A m) {\
    return _m4##A(\
        m.xx, m.yx, m.zx, m.wx,\
        m.xy, m.yy, m.zy, m.wy,\
        m.xz, m.yz, m.zz, m.wz,\
        m.xw, m.yw, m.zw, m.ww\
    );\
}\
\
static inline m4##A translate##A(const v3##A t) {\
    m4##A m = zerom4##A();\
    m.w = _v4##A(t.x, t.y, t.z, 0);\
    return m;\
}

LINALG_M4_FUNC_DEFINE(f,float)
LINALG_M4_FUNC_DEFINE(d,double)

#define LINALG_M4_FLOATING_DEFINE(A,B)\
static inline m4##A rotanglem4##A(const B theta) {\
    const B c = cos##A(theta);\
    const B s = sin##A(theta);\
    m4##A m = eyem4##A();\
    m.xx = c;\
    m.xy = s;\
    m.yx = -s;\
    m.yy = c;\
    return m;\
}\
\
static inline m4##A rotym4##A(const B theta) {\
    const B c = cos##A(theta);\
    const B s = sin##A(theta);\
    m4##A m = eyem4##A();\
    m.xx = c;\
    m.xz = s;\
    m.zx = -s;\
    m.zz = c;\
    return m;\
}\
\
static inline m4##A rotxm4##A(const B theta) {\
    const B c = cos##A(theta);\
    const B s = sin##A(theta);\
    m4##A m = eyem4##A();\
    m.yy = c;\
    m.yz = -s;\
    m.zy = s;\
    m.zz = c;\
    return m;\
}\
\
static inline m4##A rotm4##A(const B theta, const v3##A v) {\
    const B c = cos##A(theta);\
    const B s = sin##A(theta);\
    const B c1 = 1 - c;\
    const B len = lenv3##A(v);\
    const v3##A u = mulv3n##A(v, 1 / len);\
    m4##A m = zerom4##A();\
    m.val[15] = 1.0;\
    for (int i = 0; i < 3; i++) {\
        m.val[i * 4 + (i + 1) % 3] =  u.val[(i + 2) % 3] * s;\
        m.val[i * 4 + (i + 2) % 3] = -u.val[(i + 1) % 3] * s;\
    }\
    for (int i = 0; i < 3; i++) {\
        for (int j = 0; j < 3; j++) {\
            B val = c1 * u.val[i] * u.val[j] + (i == j ? c : 0);\
            m.val[i * 4 + j] += val;\
        }\
    }\
    return m;\
}
        
LINALG_M4_FLOATING_DEFINE(f,float)
LINALG_M4_FLOATING_DEFINE(d,double)

#define LINALG_M4_CAMERA_DEFINE(A,B)\
static inline m4##A frustum##A(const B lf, const B rt, const B bot, const B top, const B near, const B far) {\
    const B a = 2 * near / (rt - lf);\
    const B b = 2 * near / (top - bot);\
    const B c = (rt + lf) / (rt - lf);\
    const B d = (top + bot) / (top - bot);\
    const B e = -(far + near) / (far - near);\
    const B f = -2 * far * near / (far - near);\
    m4##A m;\
    m.x = _v4##A(a,0,0,0);\
    m.y = _v4##A(0,b,0,0);\
    m.z = _v4##A(c,d,e,-1);\
    m.w = _v4##A(0,0,f,1);\
    return m;\
}\
\
static inline m4##A persp##A(const B fovy, const B aspect, const B near, const B far) {\
    const B f = 1 / tanf(fovy * 0.5);\
    m4##A m = zerom4##A();\
    m.val[0] = f / aspect;\
    m.val[5] = f;\
    m.val[10] = (near + far) / (near - far);\
    m.val[11] = -1;\
    m.val[14] = (2 * near * far) / (near - far);\
    m.val[15] = 0;\
    return m;\
}\
\
static inline m4##A ortho##A(const B lf, const B rt, const B bot, const B top, const B near, const B far) {\
    const B rl = rt - lf;\
    const B tb = top - bot;\
    const B fn = far - near;\
    m4##A m;\
    m.x = _v4##A(2 / rl, 0, 0, 0);\
    m.y = _v4##A(0, 2 / tb, 0, 0);\
    m.z = _v4##A(0, 0, -2 / fn, 0);\
    m.w = _v4##A(-(rt + lf) / rl, -(top + bot) / tb, -(far + near) / fn, 1);\
    return m;\
}\
\
static inline m4##A lookat##A(const v3##A eye, const v3##A target, const v3##A up) {\
    const v3##A z = normv3##A(subv3##A(eye, target));\
    const v3##A x = normv3##A(crossv3##A(up, z));\
    const v3##A y = normv3##A(crossv3##A(z, x));\
    const m4##A m = vm4##A(v4v3##A(x, 0), v4v3##A(y, 0), v4v3##A(z, 0), _v4##A(0,0,0,1));\
    const v4##A eye_ = mulm4##A##v(m, v4v3##A(negv3##A(eye), -1));\
    const m4##A m_ = transposem4##A(m);\
    return vm4##A(m_.x, m_.y, m_.z, eye_);\
}

LINALG_M4_CAMERA_DEFINE(f,float)
LINALG_M4_CAMERA_DEFINE(d,double)

#endif
