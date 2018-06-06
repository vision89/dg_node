#!/bin/bash

clear

echo "Building dg_node"

if [ ! -d "./bin" ]; then
  mkdir ./bin
fi

if [ ! -d "./bin/linux" ]; then
  mkdir ./bin/linux
fi

rm -rf bin/linux/*

gcc -c src/node/dg_node.c -o bin/linux/dg_node

echo "Finished Building"
