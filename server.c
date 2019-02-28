#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
int listener;
int queue_size = 10;

void bind_to_port(int socket){
  struct sockaddr_in name; /* create socket descriptor*/
  name.sin_family = AF_INET;
  name.sin_port = (in_port_t)htons(PORT);
  name.sin_addr.s_addr=htonl(INADDR_ANY); /*Bind socket to all available*/
                                          /*interfaces, constant = 0*/
  int reuse = 1;
  // Forcefully attaching socket to make it sticky so can be reused, parameter(socket, level, option)
  if (setsocketopt(socket, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1){
    perror("Can't set the reuse option on the socket");
  }
  int c = bind(socket, (struct sockaddr *) &name, sizeof(name)); // grab the port
  // sockaddr is a struct that has socket family name and address
  if (c == -1){
    perror("Can't bind to socket");
    exit(EXIT_FAILURE);
  }
}

int open_listener_socket(){
  int listener_d = socket(PF_INET, SOCK_STREAM, 0); //Sock stream is connection orientated
  if(listener_d == -1){
    perror("Can't open socket");
    exit(EXIT_FAILURE);
  }
  return listener_d;
}

/*
Send a string to a client
*/
int say(int socket, char *s){
  int result = send(socket, s, strlen(s),0);
  if (result == -1){
    fprintf(stderr, "%s: %s\n", "Error talking to the client", strerror(errno));
    /* DOn't call error since we don't want to stop the server if there's a problem with one client*/
  }
  return result; // check if successfully send a string to the client
}

void handle_shutdown(int sig){
  if(listener){
    close(listener);
  }
  fprintf(stderr, "Bye!\n");
  exit(0);
}

int main(int argc, char *argv[]){
  listener = open_listener_socket(); // create internet streaming socket
  bind_to_port(listener); // bind the socket on the port
  if (listen(listener,queue_size) == -1){ // set queue size for listening
    perror("Can't listen!");
    exit(EXIT_FAILURE);
  }
  struct sckaddr_storage client_addr
  unsigned int address_size = sizeof(client_addr);
  int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
  if(connect_d == -1){
    perror("Can't open secondary socket");
  }
  puts("Waiting for connection");
  char buf[255];
  while(1){
    
  }

  returns 0;
}
