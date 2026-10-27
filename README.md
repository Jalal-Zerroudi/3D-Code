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


## Rendering pipeline

Each refresh follows the order implemented in `renderScene()`:

1. Clear the color and depth buffers, rebuild a 45° perspective projection, and place the camera with `gluLookAt`.
2. Rotate the model-view matrix around the Y axis and draw the pyramid's four side triangles. The source does not draw a bottom face, so the pyramid is open underneath.
3. Render the decorative `*` characters with `JALAL()` and `JALAL_SWIT()`. These are GLUT bitmap glyphs positioned in 3D; they are not geometry loaded from `cat_model.obj`.
4. Switch temporarily to a pixel-based orthographic projection in `Turns()`, disable depth testing so the counter stays above the 3D scene, then restore both matrices and the previous depth-test state.
5. Present the completed back buffer with `glutSwapBuffers()`, which avoids drawing an incomplete frame on screen.


## Runtime behavior

- The timer requests an update every **25 ms** (about **40 updates per second**).
- Each update advances the Y-axis angle by **2°** and wraps it after **360°**. One complete rotation therefore takes 180 updates, or approximately **4.5 seconds**.
- The on-screen `Turns` value counts timer callbacks; it is not a frame-rate measurement or a count of completed rotations.
- Resizing the window updates the viewport and perspective aspect ratio, while depth testing keeps nearer faces in front.

## Troubleshooting and visual check

| Symptom | Check |
| --- | --- |
| `GL/glut.h: No such file or directory` | Install the development headers, not only the runtime library; on Ubuntu/Debian, use the `freeglut3-dev` package listed above. |
| `undefined reference` to `glut*`, `glu*`, or `gl*` | Keep `-lglut -lGLU -lGL` after `3D_Haram.cpp` in the build command. |
| The application cannot open a display | Run from a graphical desktop session. SSH, containers, and WSL need access to a working display server; successful compilation alone does not provide one. |
| The window opens but the scene does not render | Confirm that the graphics environment supports the legacy fixed-function OpenGL calls used by this example. |

After launching, check that the colored pyramid rotates, the `Turns` counter increases, and resizing the window preserves the pyramid's proportions. No keyboard or mouse controls are registered in the current source; use the window manager's close control to end the demo.

The build command above targets Linux-style OpenGL libraries. Windows and macOS require platform-specific GLUT/OpenGL setup and linker options; this repository does not currently provide those build configurations.

## Notes

This example uses the traditional fixed-function OpenGL API and GLUT bitmap text. It is intended as a small learning/demo project rather than a modern OpenGL application. The OBJ file is present as a separate asset and is not rendered by the current source.
