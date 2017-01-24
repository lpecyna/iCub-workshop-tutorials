#ifndef __RPC_MODULE_H__
#define __RPC_MODULE_H__


#include <yarp/os/LogStream.h>
#include <yarp/os/RFModule.h>
#include <yarp/os/Network.h>
#include "rpctutorial_IDLserver.h"

#include "rpcThread.h"

using namespace std;
using namespace yarp::os;

class rpcModule : public RFModule, public rpctutorial_IDLserver
{
    private:
        // module parameters
        string moduleName;
        string handlerPortName;
        RpcServer handlerPort;

        bool closing;

        // pointer to a new thread
        rpcThread *threadLeftArm;
        rpcThread *threadRightArm;

        // thread stuff
        double threadPeriod;
    public:
        virtual bool configure();
        virtual double getPeriod();
        virtual bool close();
        virtual bool interruptModule();
        virtual bool quit();
        virtual bool updateModule();
        bool movearm(string arm, int angle);
        bool attach(yarp::os::RpcServer &source);

};

#endif
