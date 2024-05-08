#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <tagclass>"
    exit 1
fi

cp handleTemplate.cpp $1Handle.cpp
cp handleTemplate.h $1Handle.h
sed -i -e "s/<tagclass>/$1/g" $1Handle.cpp
sed -i -e "s/<tagclass>/$1/g" $1Handle.h
