# exponentiation
Create a C++ int that you can do `eint ** eint` on numbers (note: this turns into `eint * (*eint)`, then `eint * zint`, then lastly, the result).\
Use eint.cpp to create `eint`s to do `int` operations _and_ exponentiation.
1. Clone or download the respository.
2. Copy eint.cpp into your directory.
3. In your source code, type `#include "eint.cpp"` and use the `ExpMath::eint` (or, if you prefer, use `using namespace ExpMath` and use `eint` instead).
4. Use the `eint` to create normal ints, with Algol (`a ** b ** c = a ** (b ** c)`) exponentiationt
