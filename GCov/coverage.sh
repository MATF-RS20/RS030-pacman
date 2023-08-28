#!/bin/bash

# Set paths
files_dir="../PacmanUnitTests/build-*"
coverage_dir="./coverageFiles"
lcov_output="coverage-test.info"
reports_dir="Reports"

# Create coverage directory if it doesn't exist
mkdir -p $coverage_dir

# Copy .gcda and .gcno files to coverage directory
cp -u $files_dir/*.gcda $files_dir/*.gcno $coverage_dir

# Generate coverage info with lcov
lcov --rc lcov_branch_coverage=1 -c -d $coverage_dir -o $lcov_output


# Generate HTML reports
genhtml --rc lcov_branch_coverage=1 -o $reports_dir $lcov_output

# Open HTML report in Firefox
firefox $reports_dir/index.html

