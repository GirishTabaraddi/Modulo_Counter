/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : MODULONCOUNTER.H
* Author          : Girish Tabaraddi
* Description     :
*
*
****************************************************************************/

#ifndef MODULONCOUNTER_H
#define MODULONCOUNTER_H

/**
 * A Modulo N Counter class, which displays the counter values from 1 to values less then MaxValue of the counter(N).
 * An overflow is called when the current value is more than MaxValue and the current value is set to 0. 
 */
class ModuloNCounter {
private:
    /**
     * an integer MaxCountValue with range: 0 to 4,294,967,295
     */
    int m_CurrentCountValue;

    /**
     * an integer CurrentCountValue with range: 0 to 4,294,967,295
     */
    int m_MaxCountValue;
public:

    /**
     * A default constructor to initialize the class attributes to 0.
     * @see ModuloNCounter()
     * Also, we need Default Constructor for dynamic initialization of the array using new keyword which requires a non-parametrized constructor.
     * More Details: https://www.geeksforgeeks.org/how-to-initialize-array-of-objects-with-parameterized-constructors-in-c/
     */
    ModuloNCounter();

    /**
     * A parameterized constructor to initialize the class attributes m_MaxCountValue to digits.
     * @param[in] type - an unsigned integer with value of the type of counter i.e., module-2 counter then type = 2
     * @see ModuloNCounter() 
     */
    ModuloNCounter(int type);

	/**
	 * @brief copy constructor of Single Digit Counter
	 * Performs Deep copy of the original constructor
	 * m_CurrentCountValue, m_MaxCountValue
	 * @param[in] orig : gets const reference to the object.
	 */
    ModuloNCounter(const ModuloNCounter &orig)
    {
    	m_CurrentCountValue = orig.m_CurrentCountValue; //! Assign the Current Count value
    	m_MaxCountValue = orig.m_MaxCountValue; //! Assign the Max Count value
    }
    /**
     * A normal member function, that takes one parameter and returns boolean type(true/false).
     * @see Counter()
     * @param[in] no parameters
     * @return true or false
     */
    bool Counter();

    /**
     * A normal member function that takes one parameter and returns void type.
     * 	 	@see ModuloNCounterPrint()
     * 	 	@param[in] type an unsigned integer value, which will have value of variable type - modulo provided by user.
     * 	 	@return void - displays the output on the console
     */
    void ModuloNCounterPrint(int type);

	/**
	 * The following is a pre-increment operator overloading method.
	 * The method increments the object first and then assigns the value to the variable.
	 * It is of the Single counter class type
	 */
    ModuloNCounter& operator++();

	/**
	 * The following is a post-increment operator overloading method.
	 * The method assigns the value to the variable and then increments it.
	 * It is of the Single counter class type
	 */
    ModuloNCounter operator++(int);
};
/********************
**  CLASS END
*********************/
#endif /* MODULONCOUNTER_H */
