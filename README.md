# -IIC3585-Grupo7-Tarea3

## Instrucciones
- Para compilar c++:
    - Instalar g++
    - Instalar gdb
    - Instalar make
- Instalar [Emscripten](https://emscripten.org/docs/getting_started/downloads.html)
- Una vez instalado correr lo siguiente para activar emcc: 
    - `./emsdk activate latest`
    - `source ./emsdk_env.sh`
- Para generar archivo WASM y html correr `em++ ./dist/hello.cpp -s WASM=1 -o ./dist/index.html -s NO_EXIT_RUNTIME=0`
- Correr npm install, luego npm start para correr el webserver