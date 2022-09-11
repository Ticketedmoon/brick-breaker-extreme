## Brick breaker Extreme!  
#### This project is my first **C++** game. 

##### Dependencies: 
- SFML

---

##### In-Motion
![Sun 11 Sep 2022 16:09:08 IST](https://user-images.githubusercontent.com/21260839/189535571-3ee54d46-833f-4303-bce8-5eae787aafe5.png)

##### Game Over
![Sun 11 Sep 2022 16:17:28 IST](https://user-images.githubusercontent.com/21260839/189535574-4d078b9a-7dfa-4f2a-a65e-936f27fdb8c2.png)

##### Victory
![Sun 11 Sep 2022 16:19:30 IST](https://user-images.githubusercontent.com/21260839/189535575-c374cb66-36d8-4d9d-a822-65a1318e09ef.png)


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
  
The command to compile the source code, specify the headers and link to external libs is:  
`g++ ./src/*.cpp -o brick-breaker-extreme.exe -I./include -lsfml-graphics -lsfml-window -lsfml-system`

**Note:** You may need to update the external library linking for Windows and other Operating Systems.
**Note:** You may need to specify the C++ version to use newer features in SFML. This can be done like so:
`g++ -std=c++17 ./src/*.cpp -o brick-breaker-extreme.exe -I./include -lsfml-graphics -lsfml-window -lsfml-system`

Alternatively, you can use `cmake` by:  
0. Install the latest stable release of cmake at: https://cmake.org/download/
1. cloning the SFML lib at https://github.com/SFML/SFML.  
2. create a `build/` directory, `cd` into it and run `cmake ..`.
3. You may be required to resolve some installation errors, you can do by installing
   the appropriate necessary libs. Use `apt-cache search` for that.
4. Once resolved, run `cmake ..` again - SFML should install successfully.
5. Compile with `g++` as per usual and include the SFML include header files with `-I{PATH_TO_SFML_INCLUDE_DIRECTORY}`
   Also you will be required to include the SFML libraries. This will be the generated `lib` folder from the `cmake` script ran before.  
   - You can add `-L{PATH_TO_LIBS}` to your compilation command to specify a lib directory.  
   - You will also be required to specify the needed components like so:   
   `-lsfml-graphics -lsfml-window -lsfml-system`

### Library linking issues at runtime
If you have no errors with compilation, but face errors at runtime regarding libary loading, you can run:  
- `ldd {PATH_TO_GENERATED_EXECUTABLE}` to see how libraries are linked to your binary.
- You can run `ldconfig {PATH_TO_LIB_DIRECTORY}` to automatically configure libs for your application's runtime.


**Error Log:**
- sfml-graphics-d-2, sfml-system-d-2.  
  The 'd' stands for debug, and 
  these binaries must be placed inside the debug folder. 
