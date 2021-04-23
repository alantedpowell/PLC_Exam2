The execution time of declaring the array via subscripting is certainly faster than using pointers. However, with regard to reliability, subscripting can get "sloppy". Each step of accessing and reassigning values to indexes via a pointer is intentional and can prevent unforeseen errors from occurring or running out of memory.

-Alan