#ifndef SOCKET_H
#include "Socket.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

struct SocketStruct {
    int socket;
};

//typedef Socket *pSocket;

int socketCreate(Socket **ps, char *host, int port, Protocol protocol) {
    int fd;
    struct sockaddr_in adr_inet;
    int adr_len;
    int ret = 0;
    int prot = ( protocol == STREAM ? SOCK_STREAM : SOCK_DGRAM);

    fd = socket(PF_INET, SOCK_STREAM, 0);

    if (fd == -1) {
        perror("socket");
        return ret;
    }

    Socket *newSocket = calloc(1, sizeof (Socket));
    if (newSocket == NULL) {
        perror("calloc");
        return ret;
    }

    newSocket->socket = fd;

    *ps = newSocket;

    memset(&adr_inet, 0, sizeof (adr_inet));
    adr_inet.sin_family = AF_INET;
    adr_inet.sin_port = ntohs(port);
    
    if (host == NULL)
        adr_inet.sin_addr.s_addr = ntohl(INADDR_ANY);
    else {
        if (inet_aton(host, &adr_inet.sin_addr) == 0) {
            perror("inet_aton");
            return ret;
        }
        adr_len = sizeof (adr_inet);
    }


    // bind address to socket

    /* Now bind the address to the socket */
    if (bind(fd,
            (struct sockaddr *) &adr_inet,
            sizeof (adr_inet)) == -1) {
        perror("bind");
        return ret;
    }

    return !ret;

}

int socketListen(Socket *ps, int backlog) {
    return listen(ps->socket, backlog);
}

int socketRelease(Socket *ps) {
    close(ps->socket);
    free(ps);
    return 0;
}
#endif
