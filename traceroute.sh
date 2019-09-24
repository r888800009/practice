#!/bin/sh

if [ -z $1 ]
then
  echo ./traceroute.sh example.com
  exit 1
fi

for i in {1..255}
do
  ping $1 -t $i -D -c 1 | grep icmp
done
