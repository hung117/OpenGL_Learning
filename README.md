# OpenGL_Learning

An OpenGL learning project

# BASIC CONCEPT

## OPENGL

is not a library, it is a specification( description of how something should work),<br/>
telling the compiler, OS what to do, it's not an implementation.

## GLUT, FREEGLUT, GLEW

Implementations of OpenGL.<br/>

-GLUT,FreeGLUT and GLFW basically do the same thing, but GLUT & FREEGLUT are ancient way to do things.<br/>
-GLFW or freeglut will allow us to create a window, and receive mouse and keyboard input in a cross-platform way.<br/>
-OpenGL does not handle window creation or input, so we have to use these library for handling window, keyboard, mouse, joysticks, input and other purpose.<br/>

### GLUT,FreeGLUT

Utility Toolkit, which is an official and very old way of doing that. It include the function in compile time

### GLFW

Graphics Library Framework

### GLEW

is a cross-platform C/C++ library that helps in querying and loading OpenGL extensions in <bold>" RUN TIME "</bold>

## GLAD

Because OpenGL is only really a standard/specification it is up to the driver manufacturer to implement the specification to a driver that the specific graphics card supports. Since there are many different versions of OpenGL drivers, the location of most of its functions is not known at compile-time and needs to be queried at run-time.<br/>

It would be complicated doing it myself, thus using a pre-build header doing just that is easier<br/> Hence Glad comes in.<br/>

# MISC

## Decimal RGB to float

decimal / 255<br/>
example: rgb(0,102,102,255)= rgb(0.0f,0.4f,0.4f,1.0f)
