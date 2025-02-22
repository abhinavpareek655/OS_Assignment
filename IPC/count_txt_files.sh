#!/bin/bash

# Script: count_txt_files.sh
# Description: Counts the number of .txt files in the current directory
# Usage: ./count_txt_files.sh

# Pipeline explanation:
# 1. List files in long format
# 2. Extract filenames (9th column)
# 3. Filter lines containing ".txt"
# 4. Count matching lines

ls -l | awk '{print $9}' | grep "\.txt" | wc -l