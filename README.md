# ZMQ-HTTPRouter
Route traffic to ZMQ sockets from raw HTTP with this router

Setup
=====
```
#haproxy in ubuntu (1.5 adds socket support)
sudo add-apt-repository ppa:vbernat/haproxy-1.5
apt-get update
sudo apt-get install libhiredis-dev redis-server libzmq3-dev uuid-dev libpgm-dev haproxy
#sudo nano /etc/default/haproxy >> ENABLED=1

git clone git://github.com/jedisct1/libsodium.git
cd libsodium
./autogen.sh
./configure && make check
sudo make install
sudo ldconfig
cd ..

git clone git://github.com/zeromq/libzmq.git
cd libzmq
./autogen.sh
./configure && make check
sudo make install
sudo ldconfig
cd ..

git clone git://github.com/zeromq/czmq.git
cd czmq
./autogen.sh
./configure && make check
sudo make install
sudo ldconfig
cd ..

mkdir build
cd build
cmake ..
make
```

Running
=======
```
./httprouter
```


Testing
=======
```
curl -X POST -d 'hello' localhost/
curl localhost/hello
```
