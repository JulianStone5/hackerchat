// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 4444
#define BUF_SIZE 1024

void * receiveMessage(void * socket) {
 int sockfd, ret;
 char buffer[BUF_SIZE];
 sockfd = (int) socket;
 memset(buffer, 0, BUF_SIZE);
 for (;;) {
  ret = recv(sockfd , buffer, BUF_SIZE,0);
  if (ret < 0) {
   printf("Error receiving data!\n");
  } else {
   printf("server: ");
   fputs(buffer, stdout);
   //printf("\n");
  }
 }
}

int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[BUF_SIZE] = {0};
    char * serverAddr;
    pthread_t rThread;

    if (argc <2) { //checks that user input server ip address
      printf("Missing server ip address");
      exit(1);
    }

    serverAddr = argv[1]; //to get server ip address from command line

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(serverAddr);
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, serverAddr, &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    //creating a new thread for receiving messages from the server
    int ret = pthread_create(&rThread, NULL, receiveMessage, (void *) sock);
    if (ret) {
     printf("ERROR: Return Code from pthread_create() is %d\n", ret);
     exit(1);
    }

    while(fgets(buffer, BUF_SIZE, stdin) != NULL) {
        //int ret = send(sock , hello , strlen(hello) , 0 );
        ret = send(sock , buffer , BUF_SIZE , 0);
        if(ret < 0) {
          printf("Error sending data");
        }
        printf("Message sent\n");
        //valread = read( sock , buffer, 1024);
        //printf("%s\n",buffer );
    }
    close(sock);
    pthread_exit(NULL);
    return 0;
}
