#include <stdio.h>
 #include <yarp/os/Network.h>
 #include <yarp/dev/ControlBoardInterfaces.h>
 #include <yarp/dev/PolyDriver.h>
 #include <yarp/os/Time.h>
 #include <yarp/sig/Vector.h>
 
 #include <string>

#include "rpcThread.h"
 
 using namespace yarp::dev;
 using namespace yarp::sig;
 using namespace yarp::os;


rpcThread::rpcThread(const string &_moduleName, const double _period, const string &_armside) : moduleName(_moduleName), RateThread(int(_period*1000.0)), armside(_armside)
{
}

bool rpcThread::threadInit()
{

     std::string robotName="icubSim";
     std::string remotePorts="/";
     remotePorts+=robotName;
     if (armside == "left")
     {
        remotePorts+="/left_arm";
     }
     else if (armside == "right")
     {
        remotePorts+="/right_arm";
     }
 
     std::string localPorts="/test/client/"+ armside;
 
     Property options;
     options.put("device", "remote_controlboard");
     options.put("local", localPorts.c_str());   //local port names
     options.put("remote", remotePorts.c_str());         //where we connect to
 
     // create a device
     PolyDriver robotDevice(options);
     if (!robotDevice.isValid()) {
         printf("Device not available.  Here are the known devices:\n");
         printf("%s", Drivers::factory().toString().c_str());
         return 0;
     }
 

 
     bool ok;
     ok = robotDevice.view(pos);
     ok = ok && robotDevice.view(encs);
 
     if (!ok) {
         printf("Problems acquiring interfaces\n");
         return 0;
     }
 
     int nj=0;
     pos->getAxes(&nj);

     encoders.resize(nj);
     tmp.resize(nj);
     command.resize(nj);
     
    // This command will set reference accelerations to generate the velocity profile, considered to be 50 deg/sec^2
     int i;
     for (i = 0; i < nj; i++) {
          tmp[i] = 50.0;
     }
     pos->setRefAccelerations(tmp.data());
    // This will set the speed of the different joints at 10 deg/sec
     for (i = 0; i < nj; i++) {
         tmp[i] = 10.0;
         pos->setRefSpeed(i, tmp[i]);
     }
 
     //pos->setRefSpeeds(tmp.data()))
     
     //fisrst read all encoders
     //

    stopping = false;

     //now set the shoulder to some value
   
     return 0;
}

void rpcThread::run()
{
     while (!stopping)
     {
        yarp::os::Time::delay(0.1);
     }
     return;
}

void rpcThread::close()
{
    stopping = true;
}

bool rpcThread::move(int angle)
{
     printf("waiting for encoders");
     while(!encs->getEncoders(encoders.data()))
     {
         Time::delay(0.1);
         printf(".");
     }
     printf("\n;");
 
     command=encoders;

     command[0]=angle;
     pos->positionMove(command.data());
     return true; 
}
