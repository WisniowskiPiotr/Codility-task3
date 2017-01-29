#!/bin/bash

#for i in `seq -10 10`
#do
#  ./main.run $i
#done
echo -----1
./main.run []
ans=0
echo Poprawna odpowiedz: $ans
echo -----2
./main.run [1]
ans=1
echo Poprawna odpowiedz: $ans
echo -----3
./main.run [0]
ans=0
echo Poprawna odpowiedz: $ans
echo -----4
./main.run [11]
ans=1
echo Poprawna odpowiedz: $ans
echo -----5
./main.run [1][1]
ans=1
echo Poprawna odpowiedz: $ans
echo -----6
./main.run [11][11]
ans=2
echo Poprawna odpowiedz: $ans
echo -----7
./main.run [01][11]
ans=0
echo Poprawna odpowiedz: $ans
echo -----8
./main.run [110][111][111]
ans=2
echo Poprawna odpowiedz: $ans
echo -----9
./main.run [011][101][110]
ans=0
echo Poprawna odpowiedz: $ans
echo -----10
./main.run [101][111][111]
ans=1
echo Poprawna odpowiedz: $ans
echo -----11
./main.run [111][111][011]
ans=2
echo Poprawna odpowiedz: $ans
echo -----12
./main.run [111][011][101]
ans=1
echo Poprawna odpowiedz: $ans
echo -----13
./main.run [111][111][011]
ans=2
echo Poprawna odpowiedz: $ans
echo -----14
./main.run [111][111][111]
ans=3
echo Poprawna odpowiedz: $ans
echo -----
