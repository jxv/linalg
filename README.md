# linalg

The missing POSIX-style math library for vectors, matrices, and quaternions

---

## Types

### Values

Values supported in various structures and functions.

| Value | Abbreviation |
| ----- | ------------ |
| `char` | `c` |
| `unsigned char` | `uc` |
| `short int` | `si` |
| `unsigned short int` | `usi` |
| `int` | `i` |
| `unsigned int` | `ui` |
| `float` | `f` |
| `double` | `d` |
| `long double` | `ld` |

### Struct

Struct's name follows a pattern of `v2*` where the `*` is a value's abbreviation.

| Struct | Info | Examples |
| ------ | -----| -------- |
| `v2*` | 2d vector | `v2c`, `v2uc`, `v2si`, `v2i`, `v2ui`, `v2f`, `v2d`, `v2ld` |
| `v3*` | 3d vector | `v3i`, `v3f`, `v3d`, ... |
| `v4*` | 3d vector | `v4i`, `v4f`, `v4d`, ... |
| `m2*` | 2x2 matrix | `m2i`, `m2f`, `m2d`, ... |
| `m3*` | 3x3 matrix | `m3i`, `m3f`, `m3d`, ... |
| `m4*` | 4x4 matrix | `m4i`, `m4f`, `m4d`, ... |
| `q*` | quaternion  | `qi`, `qf`, `qd`, ... |


---

## Values


Using `float` as the example value.

```
bool nearzerof(const float x);

float sqf(const float x);

float cubef(const float x);

float clampf(const float l, const float h, const float x);

bool eqf(const float x, const float y);

float randf(const float l, const float h);

bool biasgtf(const float x, const float y);

float recipinff(const float x);
```

## Vectors

### 2D Vector

Using `v2f` as the example.

```c
typedef struct {
  union {
    struct { float x, y; };
    float val[2];
  };
} v2f;
```

#### Constructors

```c
v2f _v2f(const float x, const float y);

v2f zerov2f(void);

v2f fillv2f(const float x);
```

#### Functions

```c
bool eqv2f(const v2f v, const v2f u);

v2f absv2f(const v2f v);

v2f sigv2f(const v2f v);

bool nearzerov2f(const v2f v);
```

### 3D Vector

Using `v3f` as the example.

```c
typedef struct {
  union {
    struct { float x, y, z; };
    float val[3];
  };
} v3f;
```

#### Constructors

```c
v3f _v3f(const float x, const float y, const float z);

v3f zerov3f(void);

v3f fillv3f(const float x);
```

### 4D Vector

Using `v4f` as the example.

```c
typedef struct {
  union {
    struct { float x, y, z, w; };
    float val[4];
  };
} v4f;
```

#### Constructors

```c
v4f _v4f(const float x, const float y, const float z, const float w);

v4f v4v3f(const v3f v, const float x);

v4f zerov4f(void);

v4f fillv4f(const float x);
```

### Quaternion

Using `qf` as the example.

```c
typedef struct {
  union {
    struct { float x, y, z, w; };
    v4f v;
    float val[4];
  };
} qf;
```

### 2D Matrix

Using `m2f` as the example.

```c
typedef struct {
  union {
    struct { v2f x, y; };
    struct { float xx, xy, yx, yy; };
    v2f v[2];
    float val[4];
  };
} m2f;
```

#### Constructors

```c
m2f _m2f(
   const float xx, const float xy,
   const float yx, const float yy);

m2f vm2f(const v2f x, const v2f y);

m2f eyem2f(void);

m2f zerom2f(void);

m2f fillm2f(const float x);
```

### 3D Matrix

Using `m3f` as the example.

```c
typedef struct {
  union {
    struct { v3f x, y, z; };
    struct { float xx, xy, xz, yx, yy, yz, zx, zy, zz; };
    v3f v[3];
    float val[9];
  };
} m3f;
```

#### Constructors

```c
m3f _m3f(
   const float xx, const float xy, const float xz,
   const float yx, const float yy, const float yz,
   const float zx, const float zy, const float zz);

m3f vm3f(const v3f x, const v3f y, const v3f z);

m3f eyem3f(void);

m3f zerom3f(void);

m3f fillm3f(const float x);

m3f m3m4f(const m4f m);
```

### 4D Matrix

Using `m4f` as the example.

```c
typedef struct {
  union {
    struct { v4f x, y, z, w; };
    struct { float xx, xy, xz, xw, yx, yy, yz, yw, zx, zy, zz, zw, wx, wy, wz, ww; };
    v4f v[4];
    float val[16];
  };
} m4f;
```

#### Constructors

```c
m4f _m4f(
   const float xx, const float xy, const float xz, const float xw,
   const float yx, const float yy, const float yz, const float yw,
   const float zx, const float zy, const float zz, const float zw,
   const float wx, const float wy, const float wz, const float ww);

m4f vm4f(const v4f x, const v4f y, const v4f z);

m4f eyem4f(void);

m4f zerom3f(void);

m4f fillm4f(const float x);

m4f m4m3f(const m3f m);
```

#### Floating Functions (supports `float`, `double`, `long double`)

```c
m4f rotanglem4f(const float theta);

m4f rotym4f(const float theta);

m4f rotxm4f(const float theta);

m4f rotm4f(const float theta, const v3f v)
```

#### Camera (supports `float`, `double`, `long double`)

```c
m4f frustumf(const float lf, const float rt,
             const float bot, const float top,
             const float near, const float far);

m4f perspf(const float fovy, const float aspect, const float near, const float far);

m4f orthof(const float lf, const float rt,
           const float bot, const float top,
           const float near, const float far);

m4f lookatf(const v3f eye, const v3f target, const v3f up);
```
