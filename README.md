naiveutils
==========

Very simple implementations of some UNIX utilities in C for self-educational purposes.

Currently implemented
---------------------
* `cat`
    * `cat_1.c`: Very naive `cat` implementation without flags nor using `getopt`. Emits compiler warnings.
* `cp`
    * `cp_1.c`: Very naive `cp` implementation without flags nor using `getopt`. Can only copy one file to one destination. Does not emit compiler warnings.

Notes
-----

* Remember that `#include "file.c"` could load functions from external files.