# HackerChat
## Software System Project 1

A command line chat application that works with a set of computers on the same network. In addition to messaging, users can set usernames, join chat rooms, and see when new users join or leave a chat.

## Getting Started
To run the chat application, the server and clients need to be on the same network.

The command to run the chat server is:

`.\server`

The command connect to the client is:

`.\client [ip-address-of-server-computer]`

To compile the server and client scripts, run the following command:

`gcc -Wall telnet_server.c -o server`

`gcc -Wall client.c -o client -pthread`

## Authors
* **Ashley Swanson**
* **Sherrie Shen**
* **Nathan Shuster**

## Acknowledgments
Because the code for connecting is highly similar across most programs, there are parts of our project--in particular the socket code--that were copied from some of the below sources due to being standard procedure.

* [TCP server client implementation (geeksforgeeks)](https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/)

* [Multiple client without multi-threading (geeksforgeeks)](https://www.geeksforgeeks.org/socket-programming-in-cc-handling-multiple-clients-on-server-without-multi-threading/)

* [Simple two way chat with multi-threading](http://www.theinsanetechie.in/2014/01/a-simple-chat-program-in-c-tcp.html)

* [Socket programming (geeksforgeeks)](https://www.geeksforgeeks.org/socket-programming-cc/
)
