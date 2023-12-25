/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : MODULONDIGITCOUNTER.H
* Author          : Girish Tabaraddi
* Description     :
*
*
****************************************************************************/

#ifndef MODULONDIGITCOUNTER_H
#define MODULONDIGITCOUNTER_H
#include "ModuloNCounter.h"

/**
 * A Modulo N Digit Counter class, that takes the ModuloNCounter as a pointer instance and displays the counter values from 1 to values less then MaxValue of the counter(type).
 * An overflow is called when the current value is more than MaxValue and the current value is set to 0.
 * Once the overflow is caught, the next counter inline starts counting.This is done for as many counters as digits are entered by user. 
 */
class ModuloNDigitCounter {
private:
    /**
     * A pointer that stores an array of counters.
     */
    ModuloNCounter* m_Counters;
    /**
     * Class attribute which stores the value of digits passed. 
     */
    int m_digits;
    /**
     * Class attribute which stores the value of type passed i.e., 2/8/10/16. 
     */
    int m_type;

public:

	/**
	 * Enumeration Name: enum_counter_t
	 * The below enum_counter_t is used to pass the values to print method.
	 * @param - COUNTERNAME -> this value is used to pass the name of the counter to the print method.
	 * @param - COUNTERVALUE -> this value is used to pass the current value of the counter to the print method.
	 */
	typedef enum
	{
		COUNTERNAME, COUNTERVALUE
	} enum_counter_t;

    /**
     * @brief A default constructor to initialize the class attributes.
     *  @param[in] digits - integer type which takes the value provided by the user. This is for the no of digits of the counter.
     *  @param[in] type - integer type which has the value of type of modulo counter the user provides i.e., 2/8/10/16. 
     */
    ModuloNDigitCounter(int digits, int type);

	/**
	 * @brief copy constructor of NDigit
	 * Performs Deep copy of the original constructor
	 * m_digits, m_type, *m_Counters
	 * m_MaxCountValue = type ; assigned value to 0 so that count can start from 0
	 * @param[in] orig : gets const reference to the object.
	 * @return This pointer
	 */
    ModuloNDigitCounter(const ModuloNDigitCounter &orig);

    /**
     * A normal member function, which calls the Counter function.
     * @see NDigitCounters()
     * @param[in] no parameters
     * @return void
     */
    void NDigitCounters();

    /**
     * A normal member function that takes two parameters and returns void type.
     * @see NDigitCountersPrint()
     * @param[in] type - an unsigned integer value, which will have value of variable type - provided by user i.e., 2/8/10/16.
     * @param[in] enum_type an enumeration type parameter for printing Name and Value of the counters.
     * @return void - displays the output on the console 
     */
    void NDigitCountersPrint(int type, enum_counter_t enum_type);

	/**
	 * The following is a pre-increment operator overloading method.
	 * The method increments the object first and then assigns the value to the variable.
	 *
	 */
    ModuloNDigitCounter& operator++();

	/**
	 * The following is a post-increment operator overloading method.
	 * The method assigns the value to the variable and then increments it.
	 *
	 */
    ModuloNDigitCounter operator++(int);

    /**
     * A destructor to de-allocate the memory assigned to the class attribute.
     * @see ~ModuloNDigitCounter() 
     */
    ~ModuloNDigitCounter();
};
/********************
**  CLASS END
*********************/
#endif /* MODULONDIGITCOUNTER_H */
