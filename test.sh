#!/bin/bash

TEST=zdp

echo "TEST 2 --------------- MD5 -----------------"
printf '%s' "    me  ->  "
./ft_ssl md5 -q -s $TEST
printf '%s' "   md5  ->  "
md5 -q -s $TEST
echo "--------------------------------------------\n"


echo "TEST 3 ---------------------------- SHA256 ---------------------------------"
printf '%s' "    me  ->  "
./ft_ssl sha256 -q -s $TEST
printf '%s' "sha256  ->  "
printf '%s' $TEST | shasum -a 256
echo "----------------------------------------------------------------------------\n"


echo "TEST 4 ---------------------------- SHA512 ---------------------------------"
printf '%s' "    me  ->  "
./ft_ssl sha512 -q -s $TEST
printf '%s' "sha256  ->  "
printf '%s' $TEST | shasum -a 512
echo "----------------------------------------------------------------------------\n"


echo "TEST 5 --------------- ENC_BASE_64 -----------------"
printf '%s' "    me  ->  "
echo *TEST | ./ft_ssl base64
echo 
printf '%s' "base64  ->  "
echo *TEST | base64
echo "----------------------------------------------------\n"
