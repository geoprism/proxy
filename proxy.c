//Wong, Brian: 34216498
//Cha, Yoon Ho: 32075491


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csapp.h"

int main(int argc, char **argv)
{
    int clientfd;
    char *port;
    char *host, buf[MAXLINE];
    rio_t rio;
    host = argv[1];  port = argv[2];
    clientfd = Open_clientfd(host, port);
    Rio_readinitb(&rio, clientfd);
    printf("type:"); fflush(stdout);
    while (Fgets(buf, MAXLINE, stdin) != NULL) {
        Rio_writen(clientfd, buf, strlen(buf));
        Rio_readlineb(&rio, buf, MAXLINE);
        printf("echo:");
        Fputs(buf, stdout);
        printf("type:"); fflush(stdout);
    }
    Close(clientfd);
    exit(0);
}
