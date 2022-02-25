// Standard (system) header files
#include <iostream>
#include <stdlib.h>
// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
#include "CGateway.h"
#include "CPortFactory.h"
#include "ErrorWriter.h"
#include "CentralErrorHandler.h"
#include "CppErrorHandler.h"


// Main program
int main (void)
{

	//CGateway simpleGateway(CPortFactory::UART, CPortFactory::CAN);
	CGateway simpleGateway(CPortFactory::UART,CPortFactory::UART);
	simpleGateway.transmitFromAToB();

	return 0;
}
