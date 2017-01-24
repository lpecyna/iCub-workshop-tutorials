#include "rpcmodule.h"

int main()
{
    printf("starting...\n");
    Network yarp;
    printf("yarp is alive\n");
    rpcModule module;
    printf("module is initialized\n");
    if(! yarp.checkNetwork() )
    {
        yError("YARP server not available!");
        return -1; // EXIT_FAILURE
    }
    printf("module going to start\n");
    module.runModule();
    return 0;
}
