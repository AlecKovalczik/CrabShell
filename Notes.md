# Notes
## What is the point of this file? 
I created this file to keep track of all of the things I learned throughout the process of creating this system. There will probably be a lot here, and it will primarily be a way for me to reference my work when I am confused and looking back at this later.

## Basic lifespan of a shell
- **Initialize** 
- **Interpret**
- **Terminate**

## Terms
- **[fork](https://pubs.opengroup.org/onlinepubs/7908799/xsh/fork.html)**: Create a new process based on the parent process.

## New Types
- **pid_t** (from `unistd.h`): Signed integer type that is capable of representing a process ID.

## Challenges
- `unistd.h` and `fork` are part of the POSIX standard. They aren't available on Windows.
    - I managed to get the `unistd.h` by using the gcc as a part of [MinGW](https://www.mingw-w64.org/). But this version of `unistd.h` doesn't provided an implementation of `fork`. 

# References
https://brennan.io/2015/01/16/write-a-shell-in-c/
https://igupta.in/blog/writing-a-unix-shell-part-1/