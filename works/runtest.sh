#!/usr/bin/env bash
rm log.txt
rm gamelog
rm replay.txt

for i in 1 2 3 4 5 6 7 8
do 
  export "PLAYER"$i"_IP"=127.0.0.$i
  export "PLAYER"$i"_PORT"=600$i
  export "PLAYER"$i"_ID"=$i$i$i$i
done


./gameserver -gip 127.0.0.1 -seq replay -d 1 -m 10000 -b 50 -t 2000 -h 500 & 

sleep 1



for i in 1
do
 ../works/target/game 127.0.0.1 6000 127.0.0.$i 600$i $i$i$i$i random 0</dev/null 1>/dev/null 2>/dev/null &
done
../works/target/game 127.0.0.1 6000 127.0.0.2 6002 2222 raise 0</dev/null 1>/dev/null 2>/dev/null &
../works/target/game 127.0.0.1 6000 127.0.0.3 6003 3333 random 0</dev/null 1>/dev/null 2>/dev/null &
../works/target/game 127.0.0.1 6000 127.0.0.4 6004 4444 fold 0</dev/null 1>/dev/null 2>/dev/null &
../works/target/game 127.0.0.1 6000 127.0.0.5 6005 5555 check 0</dev/null 1>/dev/null 2>/dev/null &
../works/target/game 127.0.0.1 6000 127.0.0.6 6006 6666 call 0</dev/null 1>/dev/null 2>/dev/null &
../works/target/game 127.0.0.1 6000 127.0.0.7 6007 7777 check 0</dev/null 1>/dev/null 2>/dev/null &
../works/target/game 127.0.0.1 6000 127.0.0.8 6008 8888 0</dev/null 1>gamelog 2>/dev/null &
