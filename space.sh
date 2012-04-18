#!/bin/sh

#
#   Script converts TABs to spaces in a given file
#

if [ $# -ne 1 ]; then
     echo 1>&2 "This script converts TABs to spaces in a given file
                \\n\\n\\tUsage: $0 "
     exit 127
fi

expand $1 > temp && mv temp $1
