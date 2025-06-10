//****************************************************************************************************
//
//         File:                        Server.h
//
//         Student:                     Allison Coil
//
//         Assignment:                  Program  # 9
//
//         Course Name:                 Data Structures   I
//
//         Course Number:               COSC 3050 - 01
//
//         Due:                         Apr 14, 2021
//
//
//         This struct creates a server to deal with customers at some kind of business.
//		   
//
//****************************************************************************************************

#ifndef SERVER_H
#define SERVER_H

//****************************************************************************************************

struct Server
{
	int custId;
	int endTime;
	bool busy;

	Server();
};

//****************************************************************************************************

Server::Server()
{
	custId = -1;
	endTime = -1;
	busy = false;
}

//****************************************************************************************************

#endif