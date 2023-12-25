/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : MODULONCOUNTER.CPP
* Author          : Girish Tabaraddi
* Description     :
*
*
****************************************************************************/
//System Include Files
#include <iostream>

//Own Include Files
#include "ModuloNCounter.h"

using namespace std;

//Method Implementations

ModuloNCounter::ModuloNCounter()
{
	m_CurrentCountValue = 0;
	m_MaxCountValue = 0;
}

ModuloNCounter::ModuloNCounter(int type)
{
	this->m_CurrentCountValue = 0;
	this->m_MaxCountValue = type; //!< assigning the value of type to the m_MaxCountValue, here type - 2/8/10/16
}

bool ModuloNCounter::Counter()
{
	/**
	 * Check if the current value of the counter is less than max_value - 1,
	 * if yes then increment it or set it to 0 and return true, which conveys that overflow has occurred.
	 *
	 */
	if (m_CurrentCountValue < m_MaxCountValue - 1)
	{
		m_CurrentCountValue++; //!< Increments the current value of the counter by 1.
		return false;
	}
	else
	{
		m_CurrentCountValue = 0; //!< reset the current value of the counter to 0.
		return true;
	}
}

ModuloNCounter& ModuloNCounter::operator++()
{
	Counter();
	return *this;
}

ModuloNCounter ModuloNCounter::operator++(int)
{
	ModuloNCounter temp = *this;
	Counter();
	return temp;
}

void ModuloNCounter::ModuloNCounterPrint(int type)
{
	//!< Check if the type passed is of 16 module, if so then print the values after 9 in hex format.
	if (type == 16)
	{
		cout << hex << m_CurrentCountValue;
	}
	else if (type == 2 || type == 8 || type == 10)
	{
		cout << m_CurrentCountValue;
	}
}
