/*
 * ErrorWriter.cpp
 *
 */


#include <iostream>
#include <fstream>
using namespace std;

#include "ErrorWriter.h"

ErrorWriter::ErrorWriter(std::ostream& stream) : m_out(stream)
{
}


void ErrorWriter::operator ()(std::string message)
{
	m_out << message << endl;
}

ErrorWriter::~ErrorWriter()
{
}
