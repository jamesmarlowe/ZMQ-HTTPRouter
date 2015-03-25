// 
/// \file httprouter.cpp
/// \author James Marlowe
/// \brief respond to http using zmq
//

#include <ctime>
#include "czmq.h"
#include "log.h"
 
int main (void)
{
    zctx_t *ctx = zctx_new ();
    void *router = zsocket_new (ctx, ZMQ_ROUTER);
    zsocket_set_router_raw (router, 1);
    string unixSock = string ("ipc:///tmp/routers/") + argv[1];
    int rc = zsocket_bind (router, unixSock);
    assert (rc != -1);
    
    while (true) {
        //  Get HTTP request
        zframe_t *handle = zframe_recv (router);
        if (!handle)
            break;          //  Ctrl-C interrupt
        char *request = zstr_recv (router);
        log("Request", std::time(nullptr));
        free (request);     //  We throw this away
 
        //  Send Hello World response
        zframe_send (&handle, router, ZFRAME_MORE + ZFRAME_REUSE);
        zstr_send (router, "HTTP/1.1 204");
        //  Close connection to browser
        zframe_send (&handle, router, ZFRAME_MORE);
        zmq_send (router, NULL, 0, 0);
    }
    zctx_destroy (&ctx);
    return 0;
}
