#!/bin/bash

cd ../
#bin/gn gen out/Release --args='is_debug=false cc="clang" cxx="clang++"'
bin/gn gen out/Release --args='is_debug=true cc="clang" cxx="clang++"'
ninja -C out/Release
./out/Release/Drawing
