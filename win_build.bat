@echo off

CLS

echo Building dg_node

IF NOT EXIST "bin" (
  mkdir "bin"
)

IF NOT EXIST "bin/win" (
  mkdir "bin/win"
)

mkdir bin/temp_folder
robocopy /mir bin/temp_folder "bin/win"
rmdir bin/temp_folder

gcc -c src/node/dg_node.c -o bin/win/dg_node

echo "Finished Building"
