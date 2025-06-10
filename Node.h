//****************************************************************************************************
//
//         File:                        Node.h
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
//         This structure creates a single node for use in a linked list. It holds data of
//		   an unknown type as well as the address of the next node in the list.
//
//****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE data;
	Node <TYPE>* next;

	Node();
	Node(TYPE d, Node <TYPE>* n = nullptr);
};

//****************************************************************************************************

template <typename TYPE>
Node <TYPE> ::Node()
{
	data = 0;
	next = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
Node <TYPE> ::Node(TYPE d, Node <TYPE>* n)
{
	data = d;
	next = n;
}

//****************************************************************************************************

#endif