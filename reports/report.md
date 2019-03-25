# HackerChat
## Software Systems Project 1
### Ashley Swanson, Nathan Shuster, Sherrie Shen
#### March 26th, 2019

## Project Description
We developed a command line chat application that works with a set of computers on the same network. In addition to messaging, users can set usernames, join chat rooms, and see when new users join or leave a chat.

At the beginning of the semester, the MVP was defined as a two chat and the stretch goal set as usernames, chatrooms, multiple users, and mini-games (such as rock paper scissors) inside of the program. We easily achieved our MVP and most of our stretch goals but unfortunately ran out of time and fell short of implementing minigames.


## Learning Goals
Our primary goal was to understand how client/server and socket programming can be used to develop a successful chat application in C. We hoped to learn about how to implement such a network (using the TCP/IP model) and also to explore topics like threading. In addition, we aimed to increase our comfort level developing in C through the successful development of the program.

We were able to achieve all of our learning goals and in particular gained a strong understanding of socket programming that we hope will be useful in the coming weeks as it is covered in class.


## Resources
In addition to the suggested HeadFirst C chapter 11 and Think OS chapter 9, we tapped a variety of resources throughout the development process. The most broadly useful came from the website geeksforgeeks.org because of their superior documentation compared to most other resources we could find online.

This was the most used link and helped get our first, two-way chat working.<br/>
https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/

This one helped us expand our program to work with more than one user.<br/>
https://www.geeksforgeeks.org/socket-programming-in-cc-handling-multiple-clients-on-server-without-multi-threading/

And the below two were helpful for conceptual understanding and debugging.<br/>
http://www.theinsanetechie.in/2014/01/a-simple-chat-program-in-c-tcp.html
<br/>
https://www.geeksforgeeks.org/socket-programming-cc/]


We believe it would be worth considering adding the first link (https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/) to the class resources.


## Project Explanation
The finalized version of hackerchat uses a TCP server client model to allow for multiple user connection to the central server. By running the client executable, the user is asked to provide a username and the name of the chat room which they wish to enter. This allows the server to filter all incoming messages so that it can dispures them to those in the same chat room. Our program allows up to 30 clients to be connected at once, and anywhere between 1 and 30 users can be in a given chat.

To enhance the experience further and learn about structuring functionality in a server which continually receives messages in no given order, we added notifications to indicate when a user entered or left a given chat. The following diagram illustrates the flow of this functionality once several clients have connected. 

![Server Model](https://github.com/NathanShuster/hackerchat/blob/master/reports/images/server_flow_chart.png)

## Code Snippets

## Design Decisions
For the chat application, we implemented a TCP server client model. The rationale behind this design decision instead of implementing a UDP model is that we value reliability and absolute guarantee that the data transferred remains intact and arrives in the same order in which it was sent. The clients form a direct connection with the server. With the TCP protocol, if the sender does not get a correct response, it will resend the packets to ensure the recipient received them. Packets are also checked for errors.  The general frame of a TCP model can be summarized using the diagram below:

![TCP Model](https://github.com/NathanShuster/hackerchat/blob/master/reports/images/client_server_diagram.png)

### Server:

The server side of the chat application is able to handle multiple client connection and check activity from each of the client. For the chat application, we decided to implement multiplexing with `select()`.  The syntax of `select()` is

![Select function1](https://github.com/NathanShuster/hackerchat/blob/master/reports/images/select_fun.png)

We first create a set of file descriptors of the data type `fd_set` stored in `readfds`. In `select()` arguments, we tell the kernel we would like to read from each file descriptor and the kernel uses one thread to block on one function call until at least one file descriptor requested operation available. The implementation of select() in the chat application is shown below:

![Select function2](https://github.com/NathanShuster/hackerchat/blob/master/reports/images/select.png)

We decided to use select() instead of other multithreading approaches such as fork() because select allows us to have one process and check for activities from all clients represented as file descriptors. In fork(), we create a new process in the form of a cloned server for every single connection. This creates a layer of complexity when dealing with figuring out the order of running each process and how to broadcast messages to specific clients. Using one process to handle all clients provides us with a easier mental model and platform to build upon.

### Client:

The socket programming aspect on the client side is similar to that of a server. The server has an order of receiving and sending messages: send welcome message to new client, receive message from all clients and redirect message to corresponding client. This is different for the client. The client side of the chat application uses threading to handle both receiving and sending messages functionality since there is no inherent order between which action happens before another. The threading part is shown below:

![Client threading](https://github.com/NathanShuster/hackerchat/blob/master/reports/images/client_thread.png)

### Additional functionality:

To make our chat application more realistic to an actual chat application, we added a few functionalities on top of the TCP server client model. We allowed user to enter a username and display the username of each sender along with the message. We also added multiple chat room functionality where the user can choose to join specific chat groups.


## Reflections
We have achieved our learning goal of understanding C better and learning about basic network programming. While experimenting different models and methods for socket programming, we were able to understand the basic functionality and structure for creating a server and client. Some works and some did not. For example, we successfully create a simpe two-way chat with threading but that model is not enough for multiple clients and we have to change the server. If time allows, we could have explored the details of each associated function for the TCP model more. The final deliverable of the chat application met our mvp of a simple multi user chat application. We were able to increase the complexity of this application by adding usernames and chat room features. Between the lower and upper bounds we identified, we are closer to the upper bounds because we were able to achieve multi user but we did not have time to add in features such as a game functionality as rock paper scissors and host the chat server on a web.
