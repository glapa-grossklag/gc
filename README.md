# gc

This is a garbage collector, for C! Well, not really. All memory returned by `allocate()` is guaranteed to be freed before the program ends. Therefore, `valgrind` will report zero memory leaks.

- Use `allocate(size)` to allocate `size` bytes of memory.
- Use `collect()` to free all memory allocated by `allocate()`. This is done automatically at the end of the program, but can be done earlier if needed.
