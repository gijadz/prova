cmake_minimum_required(VERSION 3.20)

set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "")
set(CMAKE_MAKE_PROGRAM "ninja" CACHE INTERNAL "")

project(prova)

# Disabilita la ricerca automatica di SFML, adesso lo fa manualmente
set(SFML_ROOT "C:/Users/Giada Schicchi/Desktop/Laboratorio/SFML-2.5.1")

# Configurazione manuale degli include
include_directories("${SFML_DIR}/include")

include_directories("C:/Users/Giada Schicchi/Desktop/Laboratorio/SFML-2.5.1/include")
link_directories("C:/Users/Giada Schicchi/Desktop/Laboratorio/SFML-2.5.1/lib")

# Configurazione manuale delle librerie
link_directories("${SFML_DIR}/lib")

add_executable(prova main.cpp)

# Link esplicito alle librerie SFML
target_link_libraries(prova
        sfml-graphics-d
        sfml-window-d
        sfml-system-d
        opengl32
        gdi32
        freetype
)

# Copia automatica delle DLL (x esecuzione)
add_custom_command(TARGET prova POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        #"${SFML_ROOT}/bin/sfml-graphics-2.dll"
        "C:/Users/Giada Schicchi/Desktop/Laboratorio/SFML-2.5.1/bin/sfml-graphics-2.dll"
        #"${SFML_ROOT}/bin/sfml-window-2.dll"
        "C:/Users/Giada Schicchi/Desktop/Laboratorio/SFML-2.5.1/bin/sfml-window-2.dll"
        #"${SFML_ROOT}/bin/sfml-system-2.dll"
        "C:/Users/Giada Schicchi/Desktop/Laboratorio/SFML-2.5.1/bin/sfml-system-2.dll"
        $<TARGET_FILE_DIR:prova>
)