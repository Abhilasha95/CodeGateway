/***************************************************************************
 * Filename        : CPORTFACTORY.H
 * Author          :
 * Description     :
 *
 *
 ****************************************************************************/

#ifndef CPORTFACTORY_H
#define CPORTFACTORY_H

#include "CPort.h"
#include "CUartPort.h"
#include "CCanPort.h"


class CPortFactory {
private:
	/**@link dependency*/
	/*# CUartPort lnkCUartPort; */
	/**@link dependency*/
	/*# CCanPort lnkCCanPort; */
public:

	enum port_t{UART, CAN, NONE};

	/**
	 * Will initialize the peripheral port and set up the RX and TX buffers
	 *
	 * Constructor will initialize the peripheral port and set up the RX and TX buffers
	 */

	static CPort* createCanPort(
			CCanPort::port_t port = CCanPort::NONE,
			uint32_t baudrate = 1000000,
			uint16_t bufferSizeRx = CAN_DEFAULTBUFFERSIZE,
			uint16_t bufferSizeTx = CAN_DEFAULTBUFFERSIZE);
	/**
	 * Will initialize the peripheral port and set up the RX and TX buffers
	 *
	 * Constructor will initialize the peripheral port and set up the RX and TX buffers
	 * Please check the hardware limitations to ensure proper configuration parameters.
	 */

	static CPort* createUartPort(
			CUartPort::port_t port = CUartPort::NONE,
			uint32_t baudrate = 115200,
			uint8_t bits = 8,
			CUartPort::parity_t parity = CUartPort::NOPARITY,
			uint8_t stopbits = 1,
			uint16_t bufferSizeRx = UART_DEFAULTBUFFERSIZE,
			uint16_t bufferSizeTx = UART_DEFAULTBUFFERSIZE);

	/**
	 * Will create a port using the default configuration of the port (i.e. the default parameters set above)
	 */
	static CPort* createPort(port_t port);


};
/********************
 **  CLASS END
 *********************/
#endif /* CPORTFACTORY_H */
