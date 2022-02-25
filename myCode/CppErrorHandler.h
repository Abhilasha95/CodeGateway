/*
 * CppErrorHandler.h
 *
 */

#ifndef CPPERRORHANDLER_H_
#define CPPERRORHANDLER_H_

#include <string>

class CppErrorHandler
{
private:
	std::string m_what;
	std::string m_where;
public:

	//Create an error message which will be thrown
	CppErrorHandler(std::string what, std::string where);

	//Handler for the catch clause
	void report();
};

#endif /* CPPERRORHANDLER_H_ */
