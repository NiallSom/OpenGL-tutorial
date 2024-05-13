# OpenGL tutorial
## Setup
first install glad here: https://glad.dav1d.de/
  - Choose `C/C++`
  - API gl `Version 3.3`
  - Profile Compatability `Core`
  - Under options ensure `Generate a loader` is ticked
  - Then click generate and download the zip file
When you've unzipped glad follow these steps:
   - Copy `KHR` and `glad` to your compilers include files
   - Within your compilers lib files copy over `libglad.a`.
   - Now finally, add `glad.c`to your projects source files with your `main.cpp` file.
