/***************************************************************************

 * Filename        : CRINGBUFFER.CPP
 * Author          :
 * Description     :
 *
 *
 ****************************************************************************/


//System Include Files
#include <iostream>
#include <cstring>
using namespace std;

//Own Include Files
#include "CRingBuffer.h"

//Method Implementations

CRingBuffer::CRingBuffer(uint16_t size)
{
	cout << "just created buffer having size " << size << endl;

	m_fillLevel = 0;
	m_readIdx = 0;
	m_writeIdx = 0;

	//Todo: check range
	m_size = size;

	m_pBuffer = new uint8_t[size];
}


CRingBuffer::~CRingBuffer()
{
	delete[] m_pBuffer;
}

RC_t CRingBuffer::read(uint8_t& data)
{
	if (m_fillLevel > 0)
	{
		data = m_pBuffer[m_readIdx++];

		m_readIdx %= m_size;
		m_fillLevel--;

		return RC_SUCCESS;
	}
	else
	{
		return RC_BUFFERUNDERFLOW;
	}

}
RC_t CRingBuffer::readforCAN(uint8_t& data,char array[], int bufferId)
{
	if(m_fillLevel > 0)
	{
		if (true)
		{
			data = m_pBuffer[m_readIdx++];
			array[bufferId]=data;
			m_readIdx %= m_size;
			m_fillLevel--;
			//std::cout<<"readforCAN is running again"<<std::endl;
			//return RC_SUCCESS;
		}
		//std::cout<<"value of buffer is "<<std::endl;
		//for(int i=0;i<8;i++)
		//{
			//std::cout<<array[i];
		//}

		//std::cout<<std::endl;
		return RC_SUCCESS;
	}
	else
	{
		return RC_BUFFERUNDERFLOW;
	}

}

RC_t CRingBuffer::write(uint8_t data)
{
	if (m_fillLevel < m_size)
	{
		m_pBuffer[m_writeIdx++] = data;

		m_writeIdx %= m_size;
		m_fillLevel++;

		return RC_SUCCESS;
	}
	else
	{
		return RC_BUFFERUNDERFLOW;
	}
}

RC_t CRingBuffer::clear()
{
	m_fillLevel = 0;
	m_readIdx = 0;
	m_writeIdx = 0;

	return RC_SUCCESS;
}
