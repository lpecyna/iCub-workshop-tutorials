#include "rpcmodule.h"

bool rpcModule::configure()
{
    moduleName = "rpcmodule";

    handlerPortName = "/" + moduleName + "/rpc";
    handlerPort.open(handlerPortName.c_str());

    attach(handlerPort);

    threadPeriod = 0.033; // [s]

    threadRightArm = new rpcThread(moduleName,threadPeriod, "right");
    threadLeftArm = new rpcThread(moduleName,threadPeriod, "left");

    closing = false;

    threadRightArm->start();
    threadLeftArm->start();
    return true;

}

double rpcModule::getPeriod()
{
    return 0.0;
}

bool rpcModule::updateModule()
{
    return !closing;
}

bool rpcModule::attach(RpcServer &source)
{
    return this->yarp().attachAsServer(source);
}

bool rpcModule::quit()
{
    threadRightArm->close();
    threadLeftArm->close();
    handlerPort.close();
    return true;
}

bool rpcModule::movearm(string arm, int angle)
{
    if (arm == "left")
    {
        threadLeftArm->move(angle);
        return true;
    }
    else if (arm == "right")
    {
        threadRightArm->move(angle);
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

bool rpcModule::interruptModule()
{
    handlerPort.interrupt();
    threadRightArm->askToStop();

    threadLeftArm->askToStop();

    return true;
}

bool rpcModule::close()
{

    yInfo("starting shutdown procedure");
    threadRightArm->close();
    threadLeftArm->close();
    threadRightArm->stop();
    threadLeftArm->stop();
    if (threadLeftArm) delete threadLeftArm;
    if (threadRightArm) delete threadRightArm;

    handlerPort.close();
    yInfo("Module terminated");
    return true;
}
