
/***************************************************************************

 * Filename        : CPORT.CPP
 * Author          :
 * Description     :
 *
 *
 ****************************************************************************/


//System Include Files
#include <iostream>
using namespace std;


//Own Include Files
#include "CPort.h"


//Method Implementations



CPort::CPort(uint16_t txSize, uint16_t rxSize) : m_ringBufferTx(txSize), m_ringBufferRx(rxSize)
{
}



RC_t CPort::writeByteStream(string const& data)
{
	RC_t result = RC_ERROR;

	for (uint16_t i = 0; i < data.length(); i++)
	{
		result = m_ringBufferTx.write(data[i]);

		if (RC_SUCCESS != result) return RC_ERROR;
	}

	//Fire TX interrupt
	portTx_isr();

	return result;


}

RC_t CPort::readByteStream(string &data)
{
	string dataFromDriver="";

	RC_t result = RC_ERROR;
	do
	{
		uint8_t ldata = 0;
		result = m_ringBufferRx.read(ldata);
		if (RC_SUCCESS == result)
		{
			dataFromDriver += (char)ldata;
		}
	} while (RC_SUCCESS == result);

	data = dataFromDriver;

	return RC_SUCCESS;
}

RC_t CPort::portTx_isr()
{
	char array[8];
	RC_t result = RC_ERROR;
	do
	{
		uint8_t data = 0;
		for(int i=0 ;i<8;i++)
		{
			//cout<<"portTx_isr is running again"<<endl;
			result = m_ringBufferTx.readforCAN(data,array,i);
		}

		if (RC_SUCCESS == result)
		{
			//writeByte_hw(data);
			cout << "Just wrote to CAN hardware: Package: [ ";
			for(int i=0;i<8;i++)
			{
				cout<<array[i];
			}
			cout<<" ]";
			cout<<endl;
		}
	} while (RC_SUCCESS == result);

	//Todo: real error handling to be added later
	return RC_SUCCESS;
}

RC_t CPort::portRx_isr()
{
	//Todo: real error handling to be added later
	RC_t result = RC_ERROR;
	do
	{
		uint8_t data = 0;

		result = readByte_hw(data);
		if (RC_SUCCESS == result)
		{
			m_ringBufferRx.write(data);
		}

	} while (RC_SUCCESS == result);

	return RC_SUCCESS;

}
