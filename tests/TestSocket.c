/*
 * File:   TestSocket.c
 * Author: jzendle
 *
 * Created on Oct 8, 2013, 6:06:43 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Socket.h"

/*
 * Simple C Test Suite
 */

static char **_argv;
static int _argc;

void test1() {
    printf("TestSocket test 1\n");

    pSocket ps;

    socketCreate(&ps, 0, 9000, STREAM);

    if (socketListen(ps, 0) == -1) {
        perror("socketListen");
    }

    char command[256];
    sprintf(command, "lsof -i tcp");
    system(command);
    
    socketRelease(ps);


}

void test2() {
    printf("TestSocket test 2\n");
    pSocket ps;

    if (!socketCreate(&ps, 0, 9000, STREAM) && !socketRelease(ps)) {
        printf("%%TEST_PASSED%% time=0 testname=test2 (TestSocket) message=socket created and freed\n");
    } else

        printf("%%TEST_FAILED%% time=0 testname=test2 (TestSocket) message=error message sample\n");
}

int main(int argc, char** argv) {
    _argv = argv;
    _argc = argc;

    printf("%%SUITE_STARTING%% TestSocket\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test1 (TestSocket)\n");
    test1();
    printf("%%TEST_FINISHED%% time=0 test1 (TestSocket) \n");

    printf("%%TEST_STARTED%% test2 (TestSocket)\n");
    test2();
    printf("%%TEST_FINISHED%% time=0 test2 (TestSocket) \n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
