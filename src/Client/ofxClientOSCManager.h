#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxCommonTimeOsc.h"
#include "DataPacket.h"
#include "ofxXmlSettings.h"
// ---------------------------------------------------------------------------------------------------------------------------------------------------
//
class ofxClientOSCManager
{
public:

    ofxClientOSCManager();
    ~ofxClientOSCManager();

    void    init( int _uniqueComputerID, int _port = 7778);
    
    void    init( string _settingsfile = "settings/oscsync-settings.xml");

    void    _update(ofEventArgs &e);

    void    sendData( vector<string> _valuesStrings, vector<int> _valuesInt, vector<float> _valuesFloat );

    void    sendData(DataPacket _packet);

    inline ofxOscSender*  getOSCSender()
    {
        return &sender;
    }

    inline ofxOscReceiver*  getOSCReceiver()
    {
        return &receiver;
    }

    inline ofxCommonTimeOSC*  getCommonTimeOscObj()
    {
        return &commonTimeOsc;
    }

    ofEvent<DataPacket>  newDataEvent;

private:

    int				uniqueComputerID;

    ofxCommonTimeOSC		commonTimeOsc;

    bool			haveSetupSender;
    ofxOscSender		sender;

    ofxOscReceiver		receiver;

};
