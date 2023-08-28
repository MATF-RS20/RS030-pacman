#!/bin/bash

# Set paths and options
callgrind_options="--tool=callgrind --cache-sim=yes --branch-sim=yes"
executable_path="../../RS030-pacman/build-*/qt"

# Run memcheck
valgrind $callgrind_options $executable_path

# Call Kcachegrind
kcachegrind callgrind.out.*
