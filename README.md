# Csci191T-01-lessons
Game dev lessons for the group to use

Dhanyu's website for files and external lessons: https://www.dhanyu.com/csci191/

Before running the lessons it is important to note: 
- These lessons are all based in C++ around Windows (due to libSOIL.a library) so it 
  is likely that no other OS will work with these lessons.
- (You only have to do this once!) glut32.dll goes into the 'C:\Windows' folder to 
  replace the one currently there so that the lessons will be able to properly run 
  in the CodeBlocks editor.
- All lessons after lesson02 use SOIL (Simple OpenGL Image Library), the lessons are
  already integrated with SOIL using SOIL.h in "common/include" and libSOIL.a in 
  "common/lib". The SOIL file will be included with Csci191games just in case.
 - If for some reason you have to link the libSOIL.a to the project at hand, go 
   into CodeBlocks > Project > Build Options > Linker Settings, then add the relative 
   libSOIL.a path that can be found in common > lib > libSOIL.a, and finally move
   the path to the top of Link Libraries and hit OK at the bottom.
  
