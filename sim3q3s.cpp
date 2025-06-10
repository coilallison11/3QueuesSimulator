//****************************************************************************************************
//
//         File:                        sim3q3s.cpp
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
//         This program simulates three servers at a business serving customers from three 
//		   separate queues.  
//
//****************************************************************************************************

#include <iostream>
#include <fstream>
using namespace std;

//****************************************************************************************************

#include "Queue.h"
#include "Customer.h"
#include "Server.h"

//****************************************************************************************************

int fillCustomerArray ( Customer cust [] );
int findMinQ ( Queue <Customer> q [], Server serv [] );
void processCustomers ( Customer cust [], Queue <Customer> q [], Server serv [], int totalCust, int & currCust, int time, ofstream & trace);
void processServers ( Server serv [], Queue <Customer> q [], int time, ofstream & trace );
bool isAllDone ( int currCust, int totalCust, Server serv [], Queue <Customer> q [] );

//****************************************************************************************************

int main ()
{
	int time = -1;
	Customer cust [100];
	Server serv [3];
	int currCust = 0,
		totalCust;
	ofstream trace ("trace.txt");
	Queue <Customer> q [3];

	totalCust = fillCustomerArray (cust);

	while ( ! isAllDone ( currCust, totalCust, serv, q ) )
	{
		time ++;
		trace << "t = " << time << endl;
		processCustomers ( cust, q, serv, totalCust, currCust, time, trace );
		processServers ( serv, q, time, trace );
	}

	cout << "All customers processed in " << time << " minutes." << endl;

	return 0;
}

//****************************************************************************************************

int fillCustomerArray ( Customer cust [] )
{
	ifstream custFile ("customerList.txt");
	int count = 0;

	while ( ( count < 100 ) && ( custFile >> cust [count].id >> cust [count].arrivalTime >> cust [count].serviceTime ) )
	{
		count ++;
	}

	custFile.close ();
	return count;
}

//****************************************************************************************************

int findMinQ ( Queue <Customer> q [], Server serv [] )
{
	int minQ = 0;
	int sizes [3];

	for ( int i = 0; i < 3; i ++ )
	{
		sizes [i] = q [i].getNumValues ();

		if ( serv [i].busy )
		{
			sizes [i] ++;
		}
	}

	for ( int i = 1; i < 3; i ++ )
	{
		if ( sizes [i] < sizes [minQ] )
		{
			minQ = i;
		}
	}

	return minQ;
}

//****************************************************************************************************

void processCustomers ( Customer cust [], Queue <Customer> q [], Server serv [], int totalCust, int & currCust, int time, ofstream & trace )
{
	int minQ;
	
	while ( ( currCust < totalCust ) && ( cust [currCust].arrivalTime <= time ) )
	{
		minQ = findMinQ ( q, serv );
		q [minQ].enqueue ( cust [currCust] );
		trace << "cust-id #" << cust [currCust].id << " added to Q" << minQ << endl;
		currCust ++;
	}
}

//****************************************************************************************************

void processServers ( Server serv [], Queue <Customer> q [], int time, ofstream & trace )
{
	Customer cust;

	for ( int i = 0; i < 3; i ++ )
	{
		if ( ( ! serv [i].busy ) || ( serv [i].endTime <= time ) )
		{
			if ( q [i].dequeue (cust) )
			{
				serv [i].custId = cust.id;
				serv [i].endTime = time + cust.serviceTime;
				serv [i].busy = true;
				trace << "S" << i << " start serving cust-id #" << cust.id
					<< ", service length = " << cust.serviceTime
					<< ", service ends at t = " << serv [i].endTime << endl;
			}
			else
			{
				serv [i].busy = false;
				trace << "S" << i << " not busy" << endl;
			}
		}
		else
		{
			trace << "S" << i << " serving cust-id #" << serv [i].custId
				<< " until t = " << serv [i].endTime << endl;
		}
	}

	trace << endl;
}

//****************************************************************************************************

bool isAllDone ( int currCust, int totalCust, Server serv [], Queue <Customer> q [] )
{
	return ( ( currCust >= totalCust ) &&
		( q [0].isEmpty () ) &&
		( q [1].isEmpty () ) &&
		( q [2].isEmpty () ) &&
		( ! serv [0].busy ) &&
		( ! serv [1].busy ) &&
		( ! serv [2].busy ) );
}

//****************************************************************************************************

/*
All customers processed in 85 minutes.
*/