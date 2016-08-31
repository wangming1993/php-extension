#!/bin/bash


phpize

./configure

make

make test

sudo make install

sudo service php5-fpm restart

make distclean

./clear.sh
