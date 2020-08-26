#!/bin/bash

read -p "problem num:" p_num 
file_name="`ls ./clion/leetcode/editor/en/ | grep $p_num`"
mv ./clion/leetcode/editor/en/$file_name ./$file_name

