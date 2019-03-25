# HackerChat
## Software Systems Project 1
### Ashley Swanson, Nathan Shuster, Sherrie Shen
#### March 26th, 2019

## Project Goals
The goal of this project is to create a chat app using socket programming. Our minimum viable product is a two-way chat where the server and the client each represent a user, and each selects a username at the start. A more ambitious version that we would like to strive for is a server that connects to multiple clients at once and passes messages between them using forking. We would also like to add an in-app game such as rock-paper-scissors to learn more about data processing on the server-side.

## Learning Goals
We want to increase our comfort level of developing in C and construct a basic understanding of network programming. By the end of the project, we should understand and be able to implement mechanics of creating clients and servers with socket programming in C with a TCP/IP client server model. This learning includes both the process necessary to connect a client and server, as well as the mechanics of passing information between the two, error checking, and potentially processing data on the server-side in the case of our project extension.

## Resources
We first needed to learn about basic concepts of server-client communications. We started this by reading Chapter 11 of Head First C and Chapter 9 of Think OS. From there, we have continued seeking out resources as needed to develop our understanding. We have found several chat-room repositories on GitHub that we are referencing throughout the process. Additionally, we have found project ideas for expanding beyond a 2-person chat room that outline the difficulty level of different expansions. We have been following the example from geeks for geeks on creating a tcp server client and an example we found on creating a one to one chat program with threading.

## Project Explanation

## Code Snippets

## Design Decisions
For the chat application, we implemented a TCP server client model. The rationale behind this design decision instead of implementing a UDP model is that we value reliability and absolute guarantee that the data transferred remains intact and arrives in the same order in which it was sent. The clients form a direct connection with the server. With the TCP protocol, if the sender does not get a correct response, it will resend the packets to ensure the recipient received them. Packets are also checked for errors.  The general frame of a TCP model can be summarized using the diagram below:

![TCP Model](/images/tcp.png)

### Server:

The server side of the chat application is able to handle multiple client connection and check activity from each of the client. For the chat application, we decided to implement multiplexing with `select()`.  The syntax of `select()` is

![Select function1](/images/select_fun.png)

We first create a set of file descriptors of the data type `fd_set` stored in `readfds`. In `select()` arguments, we tell the kernel we would like to read from each file descriptor and the kernel uses one thread to block on one function call until at least one file descriptor requested operation available. The implementation of select() in the chat application is shown below:

![Select function2](/images/select.png)

We decided to use select() instead of other multithreading approaches such as fork() because select allows us to have one process and check for activities from all clients represented as file descriptors. In fork(), we create a new process in the form of a cloned server for every single connection. This creates a layer of complexity when dealing with figuring out the order of running each process and how to broadcast messages to specific clients. Using one process to handle all clients provides us with a easier mental model and platform to build upon.

### Client:

The socket programming aspect on the client side is similar to that of a server. The server has an order of receiving and sending messages: send welcome message to new client, receive message from all clients and redirect message to corresponding client. This is different for the client. The client side of the chat application uses threading to handle both receiving and sending messages functionality since there is no inherent order between which action happens before another. The threading part is shown below:

![Client threading](/images/client_thread.png)

### Additional functionality:

To make our chat application more realistic to an actual chat application, we added a few functionalities on top of the TCP server client model. We allowed user to enter a username and display the username of each sender along with the message. We also added multiple chat room functionality where the user can choose to join specific chat groups.


## Reflections
We have achieved our learning goal of understanding C better and learning about basic network programming. While experimenting different models and methods for socket programming, we were able to understand the basic functionality and structure for creating a server and client. Some works and some did not. For example, we successfully create a simpe two-way chat with threading but that model is not enough for multiple clients and we have to change the server. If time allows, we could have explored the details of each associated function for the TCP model more. The final deliverable of the chat application met our mvp of a simple multi user chat application. We were able to increase the complexity of this application by adding usernames and chat room features. Between the lower and upper bounds we identified, we are closer to the upper bounds because we were able to achieve multi user but we did not have time to add in features such as a game functionality as rock paper scissors and host the chat server on a web.
