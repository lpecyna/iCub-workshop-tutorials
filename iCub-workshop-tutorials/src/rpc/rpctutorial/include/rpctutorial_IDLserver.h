// This is an automatically-generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#ifndef YARP_THRIFT_GENERATOR_rpctutorial_IDLserver
#define YARP_THRIFT_GENERATOR_rpctutorial_IDLserver

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>

class rpctutorial_IDLserver;


class rpctutorial_IDLserver : public yarp::os::Wire {
public:
  rpctutorial_IDLserver();
  /**
   * This will close the module
   */
  virtual bool quit();
  /**
   * This function will move the specified arm to the specified angle
   * @input: string armside, int angle
   * @output: ack/nack (success/failure)
   */
  virtual bool movearm(const std::string& armside, const int32_t angle);
  virtual bool read(yarp::os::ConnectionReader& connection);
  virtual std::vector<std::string> help(const std::string& functionName="--all");
};

#endif
