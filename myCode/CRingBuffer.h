/***************************************************************************

 * Filename        : CRINGBUFFER.H
 * Author          :
 * Description     :
 *
 *
 ****************************************************************************/

#ifndef CRINGBUFFER_H
#define CRINGBUFFER_H

#include "global.h"
#include <string>

using namespace std;

class CRingBuffer {
private:
	uint8_t* m_pBuffer;
	uint16_t m_size;
	uint16_t m_readIdx;
	uint16_t m_writeIdx;
	uint16_t m_fillLevel;
public:

	/**
	 * Constructor taking uint16_t object
	 */
	CRingBuffer(uint16_t size = 10);
	/**
	 * Read function reads one byte data from  terminal
	 * returns RC_t
	 */

	RC_t read(uint8_t& data);
	/**
	 * Write function writes one byte data from  terminal
	 * returns RC_t
	 */
	RC_t write(uint8_t data);
	/**
	 * ReadforCAN function reads 8s of byte data from  terminal
	 * returns RC_t
	 */
	RC_t readforCAN(uint8_t& data,char array[], int bufferId);
	/**
	 * clear function resets variables to zero;
	 * returns RC_t
	 */
	RC_t clear();
	~CRingBuffer();

};
/********************
 **  CLASS END
 *********************/
#endif /* CRINGBUFFER_H */
