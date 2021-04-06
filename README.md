# Csci191T-01-lessons
Game dev lessons for the group to use

Dhanyu's website for files and external lessons: https://www.dhanyu.com/csci191/

Before running the lessons it is important to note: 
- These lessons are all based in C++ around Windows (due to libSOIL.a and 
  libirrKlang.a library) so no other OS will work with these lessons (unless 
  these libraries are updated for changed for another OS).
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
- This project uses irrKlang after lesson08 for sounds as well. To link the library
  to the actual project in codeBlocks just do the previous step stated for 
  irrKlang.a and just move its path one under libSOIL.a. (irrKlang .dll's are locally 
  added to the project file instead of adding it to the "C:\Windows" directory. The 
  irrKlang .h files are already added into the "common/include/SNDS" directory as well).
  
