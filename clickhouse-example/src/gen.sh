#!/bin/bash


for a in $(find ../include -name '*.h'); do
 file_name=$( basename $a .h )
 file_name="$file_name.cpp"
 echo $file_name
 cat << EOF > $file_name
#include <mdh/dev/$(basename $a)>
namespace mdh::dvc {}
EOF
done
