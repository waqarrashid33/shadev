# shadev
repository for developing shaders


TASK June 21,2017:(Asus Tinker Board)
#Make example work by not using GLFW.(It uses it for linux), not for raspberry pi
#If still complains about the driver, go after the driver, (It complains about the driver in glslviewer

Install glmark for testing speed


https://learnopengl.com/#!Advanced-OpenGL/Framebuffers

Post on stakeoverflow about directly to framebuffer
https://stackoverflow.com/questions/39758261/opengl-directly-to-linux-framebuffer-without-x-server

[Read this one] also explore the other options provided in this link to see if they are capable of wirting directly to framebuffer 
https://learnopengl.com/#!Getting-started/Creating-a-window

Post about rendering while not using x windows
http://discourse.glfw.org/t/off-screen-rendering-and-x-windows/784

glfw support for hidden windows
http://www.glfw.org/docs/latest/context_guide.html#context_offscreen


https://tinkerboarding.co.uk/forum/index.php



# EGL changes
## TODO:
1. Test EGL on tinkerboard to see if its working. Just download some examples from internte and try to run them.
  a. native_window = createnNativeWindow() seems to be a library function. Used in example
  b. In raspberry pi part of code, they had done this manually using vc related libraries
  c. Find the corresponding function which enables us to write to framebuffer directly or learn how to do it manually like rpi

2. Porting glslViewer to EGL:
## App.cpp
It Contains void initGL (glm::ivec4 &_viewport, bool _headless), and then it has two sections, one for raspberry pi which seems to be using egl and one for OSX or Linux which is using GLFW.

The raspberry pi part will be very useful in converting the GLFW part to EGL or writing its own.
