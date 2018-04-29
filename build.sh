#!/bin/bash

clear

echo "Building dg_node"

if [ ! -d "./bin" ]; then
  mkdir ./bin
fi

rm -rf bin/*

gcc -c src/node/dg_node.c -o bin/dg_node

echo "Finished Building"
