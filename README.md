# exponentiation

Create a C++ int that you can do `enumber ** enumber` on numbers (note: this turns into `enumber * (*enumber)`, then `enumber * znumber`, then lastly, the result).\
Use ExpMath.h to create `eint`s to do `int` operations _and_ exponentiation. Use `efloat`s to do `float` operations and exponentiation.

1. Clone or download the repository.
2. Copy ExpMath.h into your directory.
3. In your source code, type `#include "ExpMath.h"` and use the `ExpMath::eint`/`ExpMath::efloat` (or, if you prefer, use `using namespace ExpMath` and use `eint`/`efloat` instead).
4. Use the `eint` to create normal integers, with Algol (`a ** b ** c = a ** (b ** c)`) exponentiation, and use `efloat` to do the same with floating-point numbers.
