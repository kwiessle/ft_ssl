#!/bin/bash

TEST=zsdfbdalsfnadmgnmlanzgmlanzegmljnaermjgnarmlkngjlnzemgkjbmsegnkfjlsgmjkabgljbarenflknamlnfesnareomgbmeorizganuezngmjnfmuezobggezibgzegiboù

echo "TEST 2 --------------- MD5 -----------------"
printf '%s' "    me  ->  "
./ft_ssl md5 $TEST
printf '%s' "   md5  ->  "
md5 -q -s $TEST
echo "--------------------------------------------\n"


echo "TEST 3 ---------------------------- SHA256 ---------------------------------"
printf '%s' "    me  ->  "
./ft_ssl sha256 $TEST
printf '%s' "sha256  ->  "
printf '%s' $TEST | shasum -a 256
echo "----------------------------------------------------------------------------\n"

echo "TEST 4 ---------------------------- SHA512 ---------------------------------"
printf '%s' "    me  ->  "
./ft_ssl sha512 $TEST
printf '%s' "sha256  ->  "
printf '%s' $TEST | shasum -a 512
echo "----------------------------------------------------------------------------\n"
