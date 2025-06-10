//****************************************************************************************************
//
//         File:                        Customer.h
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
//         This struct creates a customer who needs a service at a business.
//		   
//
//****************************************************************************************************

#ifndef CUSTOMER_H
#define CUSTOMER_H

//****************************************************************************************************

struct Customer
{
	int id;
	int arrivalTime;
	int serviceTime;

	Customer();
};

//****************************************************************************************************

Customer::Customer()
{
	id = -1;
	arrivalTime = -1;
	serviceTime = 0;
}

#endif