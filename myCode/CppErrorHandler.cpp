/*
 * CppErrorHandler.cpp
 *
 */


#include <iostream>
using namespace std;

#include "CppErrorHandler.h"


CppErrorHandler::CppErrorHandler(std::string what, std::string where)
{
	m_what = what;
	m_where = where;
}

void CppErrorHandler::report()
{
	cerr << "ERROR in [" << m_where << "] : " << m_what << endl;
}
