#!/bin/bash


files=`ls -l | grep -v -E "(\.c$|\.h$|config.m4|install\.sh|clear\.sh|README\.md)"`

for file in $files:
do
    if [ -f $file ];
        then
        rm -rf $file
    elif [ -d $file ];
        then
        if [ $file != "." -a $file != ".." ];
            then
            rm -rf $file
        fi
    fi
done
