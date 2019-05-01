naiveutils
==========

Very simple implementations of some UNIX utilities in C for self-educational purposes.

Currently implemented
---------------------

* `cat`
    * `cat_1.c`: Very naive `cat` implementation without flags nor using `getopt`. Emits compiler warnings.
* `cp`
    * `cp_1.c`: Very naive `cp` implementation without flags nor using `getopt`. Can only copy one file to one destination. Does not emit compiler warnings.
* `rm`
    * `rm_1.c`: Very naive `rm` implementation without flags nor using `getopt`. Can only remove one file. Does not emit compiler warnings with `-Wall` flag.
* `find`
    * `find_1.c`: Very naive `find` implementation without flags nor using `getopt`. Emits compiler warnings. Receives a path that will be traversed recursively and a substring to look for in each result. Case dependent.

Notes
-----

* Remember that `#include "file.c"` could load functions from external files.