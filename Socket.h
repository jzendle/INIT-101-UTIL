/* 
 * File:   Socket.h
 * Author: jzendle
 *
 * Created on October 5, 2013, 7:55 AM
 */

#ifndef SOCKET_H
#define	SOCKET_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct SocketStruct Socket;
    typedef Socket *pSocket;

    enum Protocol {
        STREAM, DATAGRAM
    };

    typedef enum Protocol Protocol;


    // null host implies INET_ADDR_ANY for a server
    extern int socketCreate(Socket **ps, char *hostName, int port, Protocol protocol);


    extern int socketListen(Socket *ps, int backlog);
    
    extern int socketRelease(Socket *ps);



#ifdef	__cplusplus
}
#endif

#endif	/* SOCKET_H */

