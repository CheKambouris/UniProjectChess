#!/bin/bash

echo -e "\nTEST 1: FOOLS MATE"

# cat tests/input_tests/input_test_fools_mate.txt | build/debug/chess
test1=`cat tests/input_tests/fools_mate.txt | build/debug/chess`

if [[ $test1 == *"Invalid move, try again!"* ]]; then
    echo -e "WARNING - Invalid moves were made!"
else
   echo -e "PASSED"
fi


echo -e "\nTEST 2: BLACKMAR–DIEMER GAMBIT"

# cat tests/input_tests/blackmar_gambit.txt | build/debug/chess
test2=`cat tests/input_tests/blackmar_gambit.txt | build/debug/chess`

if [[ $test2 == *"Invalid move, try again!"* ]]; then
    echo -e "WARNING - Invalid moves were made!"
else
   echo -e "PASSED"
fi

echo -e "\n"