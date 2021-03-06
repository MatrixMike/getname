#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
//  11.04.2019 15:21:38
//  22.07.2019 11:27:23
// investigate host         hostid       hostname     hostnamectl

int main(int argc, char *argv[])
{
    char *host, **names, **addrs;
    struct hostent *hostinfo;
    if(argc == 1) {
        char myname[256];
        gethostname(myname, 255);
        host = myname;
        printf("point 1: %s %s \n",myname, host);
    }
    else
        host = argv[1];
    hostinfo = gethostbyname(host);
    if(!hostinfo) {
        fprintf(stderr, "cannot get info for host: %s\n", host);
        exit(1);
    }
    printf("results for host %s:\n", host);
    printf("Name: %s\n", hostinfo -> h_name);
    printf("Aliases:");
    names = hostinfo -> h_aliases;
    while(*names) {
        printf(" %s", *names);
        printf(" A another one ");
        names++;
    }
    printf("\n");
    if(hostinfo -> h_addrtype != AF_INET) {
        fprintf(stderr, "not an IP host!\n");
        exit(1);
    }
    addrs = hostinfo -> h_addr_list;
    while(*addrs) {
        printf(" %s", inet_ntoa(*(struct in_addr *)*addrs));
        printf(" B another one ");
        addrs++;
    }
    printf("\n");
    exit(0);
}
