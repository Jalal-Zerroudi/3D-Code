# 3D-Code

Small C++ / OpenGL project for a 3D graphics module. The current program displays a rotating, multicolored pyramid and an on-screen frame counter using GLUT.

## Project files

- `3D_Haram.cpp`: application entry point, scene rendering, and timer-driven rotation.
- `cat_model.obj`: Wavefront OBJ model included in the repository. The current C++ program does not load this model.

## Requirements

- A C++ compiler such as `g++`
- OpenGL, GLU, and GLUT or FreeGLUT development libraries
- A desktop session capable of opening an OpenGL window

On Ubuntu or Debian, install the compiler and FreeGLUT development package:

```bash
sudo apt update
sudo apt install g++ freeglut3-dev
```

## Build and run

From the repository directory:

```bash
g++ 3D_Haram.cpp -o 3d-code -lglut -lGLU -lGL
./3d-code
```

The program opens an 800 × 600 window. The pyramid rotates around the Y axis; a timer updates the rotation and the displayed counter.

## Notes

This example uses the traditional fixed-function OpenGL API and GLUT bitmap text. It is intended as a small learning/demo project rather than a modern OpenGL application. The OBJ file is present as a separate asset and is not rendered by the current source.
