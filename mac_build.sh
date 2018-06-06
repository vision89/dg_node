#!/bin/bash

clear

echo "Building dg_node"

if [ ! -d "./bin" ]; then
  mkdir ./bin
fi

if [ ! -d "./bin/mac" ]; then
  mkdir ./bin/mac
fi

rm -rf bin/mac/*

gcc -c src/node/dg_node.c -o bin/mac/dg_node

echo "Finished Building"
