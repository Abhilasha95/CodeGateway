/*
 * CParser.h
 */

#ifndef CPARSER_H_
#define CPARSER_H_

#include "global.h"
#include "CPort.h"
#include "CPortFactory.h"


class CGateway
{
private:
	CPort* m_portA;
	CPort* m_portB;
public:
	/**
	 * Constructor taking explicit port objects
	 */
	CGateway(CPort& portA, CPort& portB);

	/**
	 * Contructor, using the default factory settings
	 */
	CGateway(CPortFactory::port_t portA,  CPortFactory::port_t portB);
	/**
	 * Function to read data from port A and write it to port B
	 * \return RC_t
	 */

	RC_t transmitFromAToB();

	virtual ~CGateway();
};

#endif /* CPARSER_H_ */
