#!/bin/bash

# Set paths and options
report_file="Memcheck_report"
memcheck_options="--tool=memcheck --leak-check=full --show-leak-kinds=all --log-file=$report_file --track-origins=yes"
executable_path="../../RS030-pacman/build-*/qt"

# Run memcheck
valgrind $memcheck_options $executable_path

# Open file
open $report_file

