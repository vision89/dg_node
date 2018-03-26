#!/bin/bash

clear

echo "Building the dg_node

rm -rf ./bin/*

gcc -c ./src/node/dg_node.c -o ./bin/dg_node

echo "Finished Building"
