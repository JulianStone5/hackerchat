# HackerChat
## Software Systems Project 1
### Ashley Swanson, Nathan Shuster, Sherrie Shen
#### Feb 17th, 2019

## Project Goals
The goal of this project is to create a chat app using socket programming. Our minimum viable product is a two-way chat where the server and the client each represent a user, and each selects a username at the start. A more ambitious version that we would like to strive for is a server that connects to multiple clients at once and passes messages between them using forking. We would also like to add an in-app game such as rock-paper-scissors to learn more about data processing on the server-side.

## Learning Goals
We want to increase our comfort level of developing in C and construct a basic understanding of network programming. By the end of the project, we should understand and be able to implement mechanics of creating clients and servers with socket programming in C with a TCP/IP client server model. This learning includes both the process necessary to connect a client and server, as well as the mechanics of passing information between the two, error checking, and potentially processing data on the server-side in the case of our project extension.

## Resources
We first needed to learn about basic concepts of server-client communications. We started this by reading Chapter 11 of Head First C and Chapter 9 of Think OS. From there, we have continued seeking out resources as needed to develop our understanding. We have found several chat-room repositories on GitHub that we are referencing throughout the process. Additionally, we have found project ideas for expanding beyond a 2-person chat room that outline the difficulty level of different expansions. We have been following the example from geeks for geeks on creating a tcp server client and an example we found on creating a one to one chat program with threading. 

## Plan/First Steps
We currently have an implementation working where a client can input a username and send and receive messages tagged with that username back and forth with a server. We are currently working on fixing small formatting issues to make the chat application look more professional and streamlined. We expect to finish this over the next few days.

Another near term goal is improving the limited username functionality. Currently, only the client can input a username and server messages are sent back as simply “server”. Usernames also don’t show up when displaying your own messages on the computer. This task will be complete when these issues have been resolved.
Moving forward, the next big thing that we are working on is to develop a version of the program with one server and multiple clients to mimic the functionality of a true “chat room”, rather than just a 2-way application. This task will be done when a message sent from a running version of the client code is posted to all other clients connected to the same server.  

Because network programming is a new concept to all of us, we have found it to be most productive to work with everyone in the same room working together on a task, so all members of our group will be responsible for the above steps.
