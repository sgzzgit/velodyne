/*********************************************************************
//  created:    2006/05/05 - 17:06
//  filename:   MapServerSocketInterface.h
//
//  author:     Gerald Dherbomez
// 
//  version:    $Id: MapServerSocketInterface.h 339 2007-12-17 17:40:47Z gdherbom $
//
//  purpose:    Class that identifies a client close to the server
//
//  todo:       For the moment, the road extraction functionnality supports 
//              only one client due to 2 reasons :
//              - the use of shared memory to transmit the result
//              - the socket identifier is not transmit to the MapMainWindow object
//              so this last is not able to send the acknowledge to the corresponding 
//              socket interface
// 
*********************************************************************/


#ifndef _MAPSERVERSOCKETINTERFACE_H_
#define _MAPSERVERSOCKETINTERFACE_H_


#include <QTcpSocket>
#include "MapData.h"


class MapServerSocketInterface : public QSocket
{
  Q_OBJECT
public:
	MapServerSocketInterface(int socket, QObject *parent=0, const char *name=0 );
	~MapServerSocketInterface();
  void sendToClient(QString data); 
  

protected slots:
  // Function called when new data appear on the TCP port
  void readClient(); 
  void socketConnectionClosed();
  
private:
  VEHICLE_POSITION parseVehiclePosition(QStringList list); 
  ROADS_EXTRACTION_AREA parseRoadExtractionParam(QStringList list); 

  int socket_; 


};



#endif