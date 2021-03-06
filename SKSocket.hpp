//
//  SKSocket.hpp
//  base
//
//  Created by dmx on 2017/3/14.
//  Copyright © 2017年 everding. All rights reserved.
//

#ifndef SKSocket_hpp
#define SKSocket_hpp

//using namespace std;

using namespace std;
#include <map>
#include <vector>
#include <string>

#ifdef __cplusplus
extern "C" {
#endif
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <arpa/inet.h>
#ifdef __cplusplus
}
#endif


class SKSocket {
public:
    bool connectOnce();
    void write(char *);
    string read();
    
    inline SKSocket() {};
    SKSocket(string name, string host, int port);
    virtual ~SKSocket();

private:
    int socketId;
    string name;
    string host;
    int port;
    fd_set fdr;
    
    void doSend(const char *);
    string doRecv();
    bool setoptNoSignal();
    int doSelect();

};

#endif /* SKSocket_hpp */
