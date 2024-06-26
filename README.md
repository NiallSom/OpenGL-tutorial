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


#### Now download GLFW here: https://www.glfw.org/download  
  - Under `Windows pre-compiled binaries` select your version to download in my case its the `64-bit` version.
  - Now unzip this folder.
  - Navigate to `liv-vc2022` as its the most recent version and copy the `glfw3.dll` file into your compilers `bin` folder.
  - Then copy over the `.lib` files into your compilers `lib` folder.
#### Structure

Project\
 │ │ └── include\
 │ │      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── KHR\
 │ │      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── khrplatform.h\
 │ │      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── glad\
 │ │      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── glad.h\
 │&nbsp;└──lib\
 │&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└──only files: .lib (Windows) \
 │&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;.a (Linux, lib static) \
 │&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;.so (Linus, lib shared) \
 │ \
 │ \
 main.cpp \
 glad.c


#### Now within your `CMakeLists.txt` file write the following code
```
cmake_minimum_required(VERSION 3.28)
project(OpenGL-tutorial)

set(CMAKE_CXX_STANDARD 17)

# Add executable
add_executable(Graphics main.cpp
        glad.c
)

target_link_libraries(Graphics -lfreeglut -lglew32 -lopengl32 glfw3 libglfw3.a)
```
`Graphics` Is the parent folder to OpenGL-tutorial. 

# sin é
