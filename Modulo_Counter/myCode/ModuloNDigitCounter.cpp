/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : MODULONDIGITCOUNTER.CPP
* Author          : Girish Tabaraddi
* Description     :
*
*
****************************************************************************/
//System Include Files
#include <iostream>

//Own Include Files
#include "ModuloNDigitCounter.h"
#include "ModuloNCounter.h"

using namespace std;

//Method Implementations

ModuloNDigitCounter::ModuloNDigitCounter(int digits, int type)
{
	this->m_digits = digits;
	this->m_type = type;
	m_Counters = new ModuloNCounter[digits]; //!< An array of counters of type ModuloNCounter, no of counters should be same as no of digits.

	for (int i = 0; i < m_digits; i++)
	{
		m_Counters[i] = ModuloNCounter(type);
	}
}

ModuloNDigitCounter::ModuloNDigitCounter(const ModuloNDigitCounter &orig)
{
	//! Assign the digit value
	m_digits = orig.m_digits;

	//! Assign the type value
	m_type = orig.m_type;

	//Assign Dynamic memory to m_Counters
	m_Counters = new ModuloNCounter[m_digits];

	for(int i = 0; i < m_digits; i++)
	{
		m_Counters[i] = orig.m_Counters[i];
	}
}

ModuloNDigitCounter::~ModuloNDigitCounter()
{
	delete[] m_Counters;
}

void ModuloNDigitCounter::NDigitCounters()
{
	//!< For loop to run the counters till m_digits and check for the overflow.
	for (int i = 0; i < m_digits; i++)
	{
		static int overflow = 0;
		overflow = m_Counters[i].Counter();
		if (overflow == 0)
		{
			break;
		}
	}
}

/**
 * Following lines of code is the one more logic for passing the overflow from one counter to the next counter.
 * Here, we take dynamic array called overflow and initialize with size of digits.
 * Set initially to 0/true, then call the counter function and store it's overflow in the i+1 overflow
 * similarly for the next counter and this loop should run till no of digits, which is nothing but the array of counters we have.
 *
 int* overflow;
 overflow = new int(m_digits);

 overflow[0] = true;

 for(int i = 0; i < m_digits; i++)
 {
 if (overflow[i] == true)
 {
 overflow[i+1] = m_Counters[i].Counter();
 }
 else
 {
 //Do Nothing
 }
 }
 */

ModuloNDigitCounter& ModuloNDigitCounter::operator++()
{
	NDigitCounters();
	return *this;
}

ModuloNDigitCounter ModuloNDigitCounter::operator++(int)
{
	ModuloNDigitCounter temp = *this;
	NDigitCounters();
	return temp;
}

void ModuloNDigitCounter::NDigitCountersPrint(int type, enum_counter_t enum_type){
	if (enum_type == COUNTERNAME)
	{
		if (type == 2)
		{
			cout << m_digits << " Digit Binary Counter" << endl;
		}
		else if (type == 8)
		{
			cout << m_digits << " Digit Octal Counter" << endl;
		}
		else if (type == 10)
		{
			cout << m_digits << " Digit Decimal Counter" << endl;
		}
		else if (type == 16)
		{
			cout << m_digits << " Digit Hexadecimal Counter" << endl;
		}
	}

	else if (enum_type == COUNTERVALUE)
	{
		for (int i = m_digits - 1; i >= 0; i--)
		{
			m_Counters[i].ModuloNCounterPrint(type);
		}
		cout << " ";
	}
}

