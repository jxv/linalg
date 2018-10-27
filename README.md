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
