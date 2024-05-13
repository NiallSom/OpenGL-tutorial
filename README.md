# OpenGL tutorial
## Setup
#### First install glad here: https://glad.dav1d.de/
  - Choose `C/C++`.
  - API gl `Version 3.3`.
  - Profile Compatability `Core`.
  - Under options ensure `Generate a loader` is ticked.
  - Then click generate and download the zip file.
#### When you've unzipped glad follow these steps:
   - Copy `KHR` and `glad` to your compilers include files.
   - Within your compilers lib files copy over `libglad.a`.
   - Now finally, add `glad.c`to your projects source files with your `main.cpp` file.


### Now download GLFW here: https://www.glfw.org/download  
  - Under `Windows pre-compiled binaries` select your version to download in my case its the `64-bit` version.
  - Now unzip this folder.
  - Navigate to `liv-vc2022` as its the most recent version and copy the `glfw3.dll` file into your compilers `bin` folder.
  - Then copy over the `.lib` files into your compilers `lib` folder.
#### Structure

Project\
 │ │ └── include\
 │ │      ├── KHR\
 │ │      │   └── khrplatform.h\
 │ │      └── glad\
 │ │          └── glad.h\
   └──lib\
 &nbsp;└──only files: .lib (Windows)\
# C'est fini!
