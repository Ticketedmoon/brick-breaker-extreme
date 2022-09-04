Brick breaker with additional fun features!  
This project will serve as my first **C++** game using **Simple and Fast Multimedia Library** (SFML).

--- 

### How to set up
**Linux**  
To set up on linux, you will need to install SFML through.  
The easiest way to do this is through the your package manager. For Ubuntu/Debian, you can install by running: `setup.sh` or directly with `sudo apt-get install libsfml-dev`.

**Windows**
For Windows, you can install through https://www.sfml-dev.org/  

Once you've progressed passed this step, you can now compile the src code.  
For Ubuntu/Debian distros, you can execute `run_compile.sh` for the program to be compiled.  
**Note:** If this doesn't work, open the `run_compile.sh` file and identify if the sfml libraries are being linked to correctly.  

The command to compil the source code, specify the headers and link to external libs is:  
`g++ ./src/*.cpp -o brick-breaker-extreme.exe -I./headers -lsfml-graphics -lsfml-window -lsfml-system`

**Note:** You may need to update the external library linking for Windows and other Operating Systems.

**Error Log:**
- sfml-graphics-d-2, sfml-system-d-2.  
  The 'd' stands for debug, and 
  these binaries must be placed inside the debug folder. 
