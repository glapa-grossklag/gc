# gc

This is a garbage collector, for C! Well, not really. All memory returned by `allocate()` is guaranteed to be freed before the program ends. Therefore, `valgrind` will report zero memory leaks.

To use this in your own programs, just include `"gc.h"` and use `allocate()` instead of `malloc()`.
