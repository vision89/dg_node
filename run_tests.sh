#!/bin/bash

clear

echo "Building the Tests"

rm -rf ./tests/bin/*

gcc -o ./tests/bin/tests ./src/node/dg_node.c ./tests/src/tests.c

echo "Finished Building"

echo "Running Tests"

./tests/bin/tests

echo "Finished Running Tests"
