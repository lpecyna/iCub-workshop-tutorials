#ifndef __RPC_THREAD_H__
#define __RPC_THREAD_H__

#include <iomanip>
#include <iostream> // __func__
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <yarp/os/Bottle.h>
#include <yarp/os/BufferedPort.h>
#include <yarp/os/Log.h>
#include <yarp/os/LogStream.h>
#include <yarp/os/Port.h>
#include <yarp/os/Property.h>
#include <yarp/os/RateThread.h>
#include <yarp/os/RpcClient.h>
#include <yarp/os/Time.h>
#include <yarp/os/Vocab.h>
#include <yarp/sig/Vector.h>
#include <algorithm>
 #include <yarp/dev/ControlBoardInterfaces.h>
 #include <yarp/dev/PolyDriver.h>

 using namespace yarp::dev;
 using namespace yarp::sig;
using namespace std;
using namespace yarp::os;

class rpcThread : public RateThread
{
    private:
        string moduleName;
        string armside;

        IPositionControl *pos;
        IEncoders *encs;
        Vector encoders;
        Vector command;
        Vector tmp;

        bool stopping;


    public:
        rpcThread(const string &_moduleName, const double _period, const string &_armside);
        virtual void run();
        virtual void close();
        virtual bool threadInit();
        bool move(int angle);

};

#endif
