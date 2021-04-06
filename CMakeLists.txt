cmake_minimum_required(VERSION 3.17)
project(SABOTEUR-groupe-AM C)

set(CMAKE_C_STANDARD 99)

add_executable(SABOTEUR-groupe-AM main.c structure.h fonctionSetup.c fonctionSetup.h)

IF(WIN32)
    target_link_libraries(SABOTEUR-groupe-AM -lmingw32 -lallegro-5.0.10-monolith-md-debug)

ELSE()
    INCLUDE_DIRECTORIES(/usr/local/include)
    LINK_DIRECTORIES(/usr/local/lib)
    file(GLOB LIBRARIES "/usr/local/lib/*.dylib")
    message("LIBRARIES = ${LIBRARIES}")
    TARGET_LINK_LIBRARIES(SABOTEUR-groupe-AM ${LIBRARIES})
ENDIF(WIN32)