#!/bin/bash

echo -e "\nTEST 1: FOOLS MATE"

test1=`cat tests/input_tests/fools_mate.txt | build/debug/chess`

if [[ $test1 == *"! "* ]]; then
    echo -e "WARNING - Invalid moves were made!"
else
   echo -e "PASSED"
fi


echo -e "\nTEST 2: BLACKMAR–DIEMER GAMBIT"

test2=`cat tests/input_tests/blackmar_gambit.txt | build/debug/chess`

if [[ $test2 == *"! "* ]]; then
    echo -e "WARNING - Invalid moves were made!"
else
   echo -e "PASSED"
fi


echo -e "\nTEST 3: ROOK EXCHANGE"

test3=`cat tests/input_tests/rook_exchange.txt | build/debug/chess`

if [[ $test3 == *"! "* ]]; then
    echo -e "WARNING - Invalid moves were made!"
else
   echo -e "PASSED"
fi

echo -e "\n"