/*********************************************************************
// created:    2006/05/10 - 11:25
// filename:   MapClientSocket.h
//
// author:     Gerald Dherbomez
// 
// version:    $Id: MapClientSocket.h 299 2007-10-23 16:11:29Z gdherbom $
//
// purpose:    use this class to send data to the Map server via
//             TCP/IP protocol
*********************************************************************/

#ifndef _MAPCLIENTSOCKET_H_
#define _MAPCLIENTSOCKET_H_



#include <qobject.h>
#include <qsocket.h>
#include <qsemaphore.h>
#include "MapData.h"
#include "kernel/ComponentBase.h"
#include "MapRoadExtraction.h"

#include <math.h>



class MapClientSocket: public QSocket, public ComponentBase
{
  Q_OBJECT

public:
  MapClientSocket(const char * name); 
  ~MapClientSocket(); 
  
  void startActivity(); 
  void stopActivity(); 
  void configureComponent(XmlComponentConfig config); 


  bool displayCar(VEHICLE_POSITION position);
  bool displayGps(VEHICLE_POSITION position);
  bool displayPose(VEHICLE_POSITION position);
  bool displayMatchedPosition(VEHICLE_POSITION position);
  bool displayObject(OBJECT_POSITION object);

  bool extractRoads(ROADS_EXTRACTION_AREA zone);

  int ellipse(double pxx, double pxy, double pyy, float proba,VEHICLE_POSITION * position); 

  MapRoadExtraction* shMem; 

signals:
  void roadExtractionFinished(); 
  void roadExtractionFinished(QString str); 


public slots:
  void connectToServer(QString host, int port);
  
protected slots:
  void sendToServer(enum MAP_DATA type, QString data); 
  void socketConnected();
  void socketConnectionClosed();
  void socketReadyRead();  
  void socketError(int e); 
  
private: 
  QSocket *socket; 

  QSemaphore lock_;

  QString vehiclePositionString(VEHICLE_POSITION position); 
};





#endif
