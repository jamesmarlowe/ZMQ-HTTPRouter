# ZMQ-HTTPRouter
Route traffic to ZMQ sockets from raw HTTP with this router

Setup
=====
```
#haproxy in ubuntu (1.5 adds socket support)
sudo add-apt-repository ppa:vbernat/haproxy-1.5
apt-get update
sudo apt-get install libhiredis-dev redis-server libzmq3-dev haproxy
#sudo nano /etc/default/haproxy >> ENABLED=1
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
