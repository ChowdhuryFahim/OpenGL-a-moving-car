# About the Project

  Project description:

    The project is a demonstration of Computer Graphics using OpenGL.
    Running the code initiates the car to move from the left side of the screen to the right.
    The car's body is made using polygon and the tyres using circle.
    Pressing the "Esc" key on the keyboard terminates the whole program.
    
    In the main function I have used the usual glutInit function to initiate the glut and glutInitWindowMode to determine the glut window mode. glutWindowSize,
    glutWindowPosition to determine the main window size and position. The glutDisplayFunc is creates the Car in the frame and callsback DrawGLScene which delivers 
    the whole car. 
    
    In the DrawGLScene drawing of the whole car happens. The car has been made using the GL_POLYGON and the GlutIdleFunc keeps calling the DrawGLScene until the 
    termination key is pressed, which in this case is ESC key. 
    
    The rtri and rquad is used to make rotation in the program.
    
    The drawBall function is to create the wheels of the car. It contains the radius and the color of the project. 
    
    The keyPressed function is used as a termination of the whole program. Whenever the ESC key is pressed the program ends instantly.
  
  Requirements of the project:

    1. IDE (CodeBlocks)
    2. Language: C++
    3. Packages: OpenGL and Glut 
  
  Hearlty thanks to
  
  Project Co-Ordinator:
      Masum Ahmed Chowdhury Esha 
      Lecturer, 
      Metropolitan University
    
    
GIF file of the project:
   ![CGM Lab Project](https://user-images.githubusercontent.com/76619766/170770710-797f9288-bdb8-498f-9bce-1d751fc777d8.gif)
