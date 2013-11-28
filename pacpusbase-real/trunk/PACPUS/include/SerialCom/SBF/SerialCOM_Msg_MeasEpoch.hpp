/*! 
\class SerialCOM_Msg_MeasEpoch
\brief Allows to handle MeasEpoch messages coming from a PolarX GPS receiver
\author Olivier LE MARCHAND
\version 1.0
\date September 2008
\bug None
\warning None

This block contains code phase, carrier phase, Doppler observations, and measurement quality indicators for all tracked satellites for a particular epoch. This block contains N ChannelData sub-blocks, each sub-block containing all the dual-frequency measurements for a given satellite and a given antenna.

 */

#pragma warning( once : 4290 )
#pragma warning( once : 4274 )

#ifndef _SerialCOM_Msg_MeasEpoch_Plrx_H
#define _SerialCOM_Msg_MeasEpoch_Plrx_H

#include <vector>
#include "SerialCOM_Msg.hpp"
#include "SerialCOM_Protocol.hpp"
#include "structure_septentrio.h"

namespace Plrx
{

class SerialCOM_Msg_MeasEpoch : public SerialCOM_Msg , public SbfDataMeasEpoch
{

public : 

	/*! \brief Constructor. Intitialise the member variables*/
	SerialCOM_Msg_MeasEpoch();

	/*! \brief Copy constructor*/
	//SerialCOM_Msg_RXM_SBAS (const SerialCOM_Msg_RXM_SBAS &source);

	/*! \brief reset internal variables of the message after an error or the end of a 
	 *  message */
	/*! For more information see SerialCOM_Msg::reset*/
	void reset();

	/*! \brief Read the core of the message to check if the object is able to handle this
 	 *  message*/
	/*! For more information see SerialCOM_Msg::identify*/
	int identify(vector<unsigned char> *pbuffer);

	/*! \brief extracts the data of the message contained in the buffer vector*/
	/*! For more information see SerialCOM_Msg::formatData*/
	int formatData(vector<unsigned char> *pbuffer);

	int fromStructFile(void *buf);

	//! return the size of the structure structMeasEpoch
	int getSizeOfStruct(){return sizeof(SbfDataMeasEpoch);};

	//! write the Data of the message in the DByte file
	virtual int writeDByte(road_time_t currentRoadtime, road_timerange_t currentTimerange);
        
         //! Display Data to stdout;
        virtual void stdoutDisplay();
	
};

};


#endif