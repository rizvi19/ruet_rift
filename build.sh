#!/usr/bin/env bash
set -e

# Linux build command for RUET Rift.
g++ main.cpp -o ruet_rift -lGL -lGLU -lglut

# Windows MinGW note:
# g++ main.cpp -o ruet_rift.exe -lfreeglut -lopengl32 -lglu32
