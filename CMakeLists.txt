# General settings
cmake_minimum_required(VERSION 3.8)
project (blittris)
set(32BLIT_PATH "../" CACHE PATH "Path to 32blit.cmake")
include (${32BLIT_PATH}/32blit.cmake)

# Define the source code and headers tidily here
set(BLITTRIS_CFILES blittris.cpp game.cpp tetronimo.cpp)
set(BLITTRIS_HFILES blittris.hpp game.hpp tetronimo.hpp)

# And call the appropriate blitfuncs!
blit_executable (blittris ${BLITTRIS_CFILES} ${BLITTRIS_HFILES})
blit_assets_yaml (blittris assets.yml)
