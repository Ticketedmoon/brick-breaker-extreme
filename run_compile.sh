# g++ compiler for cpp files.
# -o to specify the output binary file name.
# -I to specify where the headers are.
# -l to link to external libraries (SFML in this case)
# SFML usage requires `graphics`, `window` and `system` to be linked by default.
g++ ./src/*.cpp -o brick-breaker-extreme.exe -I./headers -lsfml-graphics -lsfml-window -lsfml-system
