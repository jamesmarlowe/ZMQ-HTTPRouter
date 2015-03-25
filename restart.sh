#!/bin/bash

clear

if [ "$#" -ne 1 ]; then
	echo "must provide number of httprouter processess to create"
	exit
fi

echo "stopping haproxy"
sudo service haproxy stop

echo "stopping httprouter processes"
sudo killall httprouter

echo "creating haproxy config"
cat haproxy.cfg > haproxy.conf
mkdir -p /tmp/routers/
for i in `seq 1 $1`; do
    ./build/httprouter $i&
    sudo chmod 777 /tmp/routers/$i
    echo "    server router$i unix@/tmp/routers/$i maxconn 3" >> haproxy.conf
done

echo "starting haproxy"
sudo cp -f haproxy.conf /etc/haproxy/haproxy.cfg
#sudo cp -f 204.http /etc/haproxy/errors/204.http
sudo service haproxy start
