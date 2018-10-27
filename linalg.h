#ifndef LINALG_H
#define LINALG_H

#include <stdbool.h>

#define fmind fmin
#define fmaxd fmax
#define fabsd fabs
#define fminld fminl
#define fmaxld fmaxl
#define fabsld fabsl
#define sind sin
#define cosd cos
#define asind asin
#define acosd acos
#define sqrtd sqrt
#define sinld sinl
#define cosld cosl
#define sqrtld sqrtl
#define asinld asinl
#define acosld acosl

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
        struct { B xx, xy, xz, xw, yy, yx, yz, yw, zx, zy, zz, zw, wx, wy, wz, ww; };\
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
bool nearzero##A(const B x);\
B sq##A(const B x);\
B cube##A(const B x);\
B clamp##A(const B l, const B h, const B x);\
bool eq##A(const B x, const B y);\
B rand##A(const B l, const B h);\
bool biasgt##A(const B x, const B y);\
B recipinf##A(const B x);

LINALG_VALUE_DECLARE(f,float)
LINALG_VALUE_DECLARE(d,double)

#define LINALG_V2_DECLARE(A,B)\
v2##A _v2##A(const B x, const B y);\
v2##A zerov2##A(void);\
v2##A fillv2##A(const B x);\
v2##A negv2##A(const v2##A v);\
v2##A addv2##A(const v2##A v, const v2##A u);\
v2##A subv2##A(const v2##A v, const v2##A u);\
v2##A mulv2##A(const v2##A v, const v2##A y);\
v2##A divv2##A(const v2##A v, const v2##A u);\
v2##A addv2n##A(const v2##A v, const B n);\
v2##A subv2n##A(const v2##A v, const B n);\
v2##A mulv2n##A(const v2##A v, const B n);\
v2##A divv2n##A(const v2##A v, const B n);

LINALG_V2_DECLARE(f,float)
LINALG_V2_DECLARE(d,double)
LINALG_V2_DECLARE(i,int)

#define LINALG_V2_FP_DECLARE(A,B)\
bool eqv2##A(const v2##A v, const v2##A u);\
v2##A absv2##A(const v2##A v);\
v2##A sigv2##A(const v2##A v);\
bool nearzerov2##A(const v2##A v);\
v2##A lerp##A(const v2##A v, const v2##A u, const B t);\
B sqlenv2##A(const v2##A v);\
B dotv2##A(const v2##A v, const v2##A u);\
B lenv2##A(const v2##A v);\
B sqdistv2##A(const v2##A u, const v2##A v);\
v2##A normv2##A(const v2##A v);\
v2##A rotv2##A(const v2##A v, const B theta);\
v2##A clampv2##A(const v2##A l, const v2##A h, const v2##A v);\
v2##A minv2##A(const v2##A v, const v2##A u);\
v2##A maxv2##A(const v2##A v, const v2##A u);\
B crossv2##A(const v2##A v, const v2##A u);\
v2##A crossv2n##A(const v2##A v, const B n);\
v2##A crossnv2##A(const B n, const v2##A v);\
v2##A crosssv2##A(const B s, const v2##A v);

LINALG_V2_FP_DECLARE(f,float)
LINALG_V2_FP_DECLARE(d,double)

#define LINALG_V3_DECLARE(A,B)\
v3##A _v3##A(B x, B y, B z);

LINALG_V3_DECLARE(f,float)
LINALG_V3_DECLARE(d,double)

#define LINALG_V3_FP_DECLARE(A,B)\
v3##A zerov3##A(void);\
v3##A fillv3##A(const B x);\
v3##A absv3##A(const v3##A v);\
v3##A sigv3##A(const v3##A v);\
v3##A negv3##A(const v3##A v);\
v3##A addv3##A(const v3##A v, const v3##A u);\
v3##A subv3##A(const v3##A v, const v3##A u);\
v3##A mulv3##A(const v3##A v, const v3##A u);\
v3##A mulv3n##A(const v3##A v, const B n);\
v3##A divv3##A(const v3##A v, const v3##A u);\
v3##A divv3n##A(const v3##A v, const B n);\
bool eqv3##A(const v3##A v, const v3##A u);\
B lenv3##A(const v3##A v);\
v3##A normv3##A(const v3##A v);\
v3##A crossv3##A(const v3##A v, const v3##A u);\
B dotv3##A(const v3##A v, const v3##A u);

LINALG_V3_FP_DECLARE(f,float)
LINALG_V3_FP_DECLARE(d,double)

#define LINALG_V4_DECLARE(A,B)\
v4##A _v4##A(B x, B y, B z, B w);

LINALG_V4_DECLARE(f,float)
LINALG_V4_DECLARE(d,double)

#define LINALG_V4_FP_DECLARE(A,B)\
v4##A v4v3##A(const v3##A v, const B w);\
v4##A zerov4##A(void);\
v4##A fillv4##A(const B x);\
v4##A absv4##A(const v4##A v);\
v4##A sigv4##A(const v4##A v);\
v4##A negv4##A(const v4##A v);\
v4##A addv4##A(const v4##A v, const v4##A u);\
v4##A subv4##A(const v4##A v, const v4##A u);\
v4##A mulv4##A(const v4##A v, const v4##A u);\
v4##A mulv4n##A(const v4##A j, const B n);\
v4##A divv4##A(const v4##A v, const v4##A u);\
v4##A divv4n##A(const v4##A v, const B n);\
bool eqv4##A(const v4##A v, const v4##A u);\
v4##A lerpv4##A(const v4##A v, const v4##A u, const B t);\
B lenv4##A(const v4##A v);\
v4##A normv4##A(const v4##A v);\
B dotv4##A(const v4##A v, const v4##A u);

LINALG_V4_FP_DECLARE(f,float)
LINALG_V4_FP_DECLARE(d,double)

#define LINALG_Q_DECLARE(A,B)\
v4##A slerpv4##A(const v4##A a, const v4##A b, const B t);\
v4##A rotv4##A(const v4##A a, const v4##A b);\
m3##A m3v4##A(const v4##A v);\
v4##A v4fromv3##A(const v3##A v, const v3##A u);\
v4##A v4axisangle##A(const v3##A axis, const B theta);

LINALG_Q_DECLARE(f,float)
LINALG_Q_DECLARE(d,double)

#define LINALG_M2_DECLARE(A,B)\
m2##A _m2##A(B xx, B xy, B yx, B yy);

LINALG_M2_DECLARE(f,float)
LINALG_M2_DECLARE(d,double)

#define LINALG_M2_FP_DECLARE(A,B)\
m2##A vm2##A(const v2##A x, const v2##A y);\
m2##A eyem2##A(void);\
m2##A zerom2##A(void);\
m2##A fillm2##A(const B x);\
m2##A absm2##A(const m2##A m);\
m2##A sigm2##A(const m2##A m);\
m2##A negm2##A(const m2##A m);\
m2##A mulm2##A(const m2##A m, const m2##A n);\
v2##A mulm2##A##v(const m2##A m, const v2##A v);\
m2##A orientm2##A(const B theta);\
m2##A absm2##A(const m2##A m);\
v2##A xaxism2##A(const m2##A m);\
v2##A yaxism2##A(const m2##A m);\
m2##A transposem2##A(const m2##A m);

LINALG_M2_FP_DECLARE(f,float)
LINALG_M2_FP_DECLARE(d,double)

#define LINALG_M3_DECLARE(A,B)\
m3##A _m3##A(B xx, B xy, B xz, B yx, B yy, B yz, B zx, B zy, B zz);

LINALG_M3_DECLARE(f,float)
LINALG_M3_DECLARE(d,double)

#define LINALG_M3_FP_DECLARE(A,B)\
m3##A m3m4##A(const m4##A m);\
m3##A vm3##A(const v3##A x, const v3##A y, const v3##A z);\
m3##A eyem3##A(void);\
m3##A zerom3##A(void);\
m3##A fillm3##A(const B x);\
m3##A absm3##A(const m3##A m);\
m3##A sigm3##A(const m3##A m);\
m3##A negm3##A(const m3##A m);\
m3##A transposem3##A(const m3##A m);

LINALG_M3_FP_DECLARE(f,float)
LINALG_M3_FP_DECLARE(d,double)

#define LINALG_M4_DECLARE(A,B)\
m4##A _m4##A(B xx, B xy, B xz, B xw, B yx, B yy, B yz, B yw, B zx, B zy, B zz, B zw, B wx, B wy, B wz, B ww);

LINALG_M4_DECLARE(f,float)
LINALG_M4_DECLARE(d,double)

#define LINALG_M4_FP_DECLARE(A,B)\
m4##A m4m3##A(const m3##A m);\
m4##A vm4##A(const v4##A x, const v4##A y, const v4##A z, const v4##A w);\
m4##A eyem4##A(void);\
m4##A zerom4##A(void);\
m4##A fillm4##A(const B x);\
m4##A absm4##A(const m4##A m);\
m4##A sigm4##A(const m4##A m);\
m4##A negm4##A(const m4##A m);\
m4##A scalem4##A(const m4##A m, const v3##A s);\
m4##A addm4##A(const m4##A m, const m4##A n);\
m4##A subm4##A(const m4##A m, const m4##A n);\
m4##A mulm4##A(const m4##A m, const m4##A n);\
v4##A mulm4##A##v(const m4##A m, const v4##A v);\
m4##A transposem4##A(const m4##A m);\
m4##A rotanglem4##A(const B theta);\
m4##A rotym4##A(const B theta);\
m4##A rotxm4##A(const B theta);\
m4##A rotm4##A(const B theta, const v3##A v);\
m4##A translate##A(const v3##A t);\
m4##A frustum##A(const B lf, const B rt, const B bot, const B top, const B near, const B far);\
m4##A persp##A(const B fovy, const B aspect, const B near, const B far);\
m4##A ortho##A(const B lf, const B rt, const B bot, const B top, const B near, const B far);\
m4##A lookat##A(const v3##A eye, const v3##A target, const v3##A up);

LINALG_M4_FP_DECLARE(f,float)
LINALG_M4_FP_DECLARE(d,double)

#endif
