#!/bin/bash

# Set paths and options
report_file="Massif_report.txt"
massif_options="--tool=massif --log-file=$report_file --stacks=yes --detailed-freq=10"
executable_path="../../RS030-pacman/build-*/qt"

# Run memcheck
valgrind $massif_options $executable_path

# Copy generated report in file
ms_print massif.out.* > massif_graph.txt

