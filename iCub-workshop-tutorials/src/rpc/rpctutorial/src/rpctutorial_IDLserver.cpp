// This is an automatically-generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <rpctutorial_IDLserver.h>
#include <yarp/os/idl/WireTypes.h>



class rpctutorial_IDLserver_quit : public yarp::os::Portable {
public:
  bool _return;
  void init();
  virtual bool write(yarp::os::ConnectionWriter& connection);
  virtual bool read(yarp::os::ConnectionReader& connection);
};

class rpctutorial_IDLserver_movearm : public yarp::os::Portable {
public:
  std::string armside;
  int32_t angle;
  bool _return;
  void init(const std::string& armside, const int32_t angle);
  virtual bool write(yarp::os::ConnectionWriter& connection);
  virtual bool read(yarp::os::ConnectionReader& connection);
};

bool rpctutorial_IDLserver_quit::write(yarp::os::ConnectionWriter& connection) {
  yarp::os::idl::WireWriter writer(connection);
  if (!writer.writeListHeader(1)) return false;
  if (!writer.writeTag("quit",1,1)) return false;
  return true;
}

bool rpctutorial_IDLserver_quit::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  if (!reader.readListReturn()) return false;
  if (!reader.readBool(_return)) {
    reader.fail();
    return false;
  }
  return true;
}

void rpctutorial_IDLserver_quit::init() {
  _return = false;
}

bool rpctutorial_IDLserver_movearm::write(yarp::os::ConnectionWriter& connection) {
  yarp::os::idl::WireWriter writer(connection);
  if (!writer.writeListHeader(3)) return false;
  if (!writer.writeTag("movearm",1,1)) return false;
  if (!writer.writeString(armside)) return false;
  if (!writer.writeI32(angle)) return false;
  return true;
}

bool rpctutorial_IDLserver_movearm::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  if (!reader.readListReturn()) return false;
  if (!reader.readBool(_return)) {
    reader.fail();
    return false;
  }
  return true;
}

void rpctutorial_IDLserver_movearm::init(const std::string& armside, const int32_t angle) {
  _return = false;
  this->armside = armside;
  this->angle = angle;
}

rpctutorial_IDLserver::rpctutorial_IDLserver() {
  yarp().setOwner(*this);
}
bool rpctutorial_IDLserver::quit() {
  bool _return = false;
  rpctutorial_IDLserver_quit helper;
  helper.init();
  if (!yarp().canWrite()) {
    yError("Missing server method '%s'?","bool rpctutorial_IDLserver::quit()");
  }
  bool ok = yarp().write(helper,helper);
  return ok?helper._return:_return;
}
bool rpctutorial_IDLserver::movearm(const std::string& armside, const int32_t angle) {
  bool _return = false;
  rpctutorial_IDLserver_movearm helper;
  helper.init(armside,angle);
  if (!yarp().canWrite()) {
    yError("Missing server method '%s'?","bool rpctutorial_IDLserver::movearm(const std::string& armside, const int32_t angle)");
  }
  bool ok = yarp().write(helper,helper);
  return ok?helper._return:_return;
}

bool rpctutorial_IDLserver::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  reader.expectAccept();
  if (!reader.readListHeader()) { reader.fail(); return false; }
  yarp::os::ConstString tag = reader.readTag();
  bool direct = (tag=="__direct__");
  if (direct) tag = reader.readTag();
  while (!reader.isError()) {
    // TODO: use quick lookup, this is just a test
    if (tag == "quit") {
      bool _return;
      _return = quit();
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(1)) return false;
        if (!writer.writeBool(_return)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "movearm") {
      std::string armside;
      int32_t angle;
      if (!reader.readString(armside)) {
        reader.fail();
        return false;
      }
      if (!reader.readI32(angle)) {
        reader.fail();
        return false;
      }
      bool _return;
      _return = movearm(armside,angle);
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(1)) return false;
        if (!writer.writeBool(_return)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "help") {
      std::string functionName;
      if (!reader.readString(functionName)) {
        functionName = "--all";
      }
      std::vector<std::string> _return=help(functionName);
      yarp::os::idl::WireWriter writer(reader);
        if (!writer.isNull()) {
          if (!writer.writeListHeader(2)) return false;
          if (!writer.writeTag("many",1, 0)) return false;
          if (!writer.writeListBegin(BOTTLE_TAG_INT, static_cast<uint32_t>(_return.size()))) return false;
          std::vector<std::string> ::iterator _iterHelp;
          for (_iterHelp = _return.begin(); _iterHelp != _return.end(); ++_iterHelp)
          {
            if (!writer.writeString(*_iterHelp)) return false;
           }
          if (!writer.writeListEnd()) return false;
        }
      reader.accept();
      return true;
    }
    if (reader.noMore()) { reader.fail(); return false; }
    yarp::os::ConstString next_tag = reader.readTag();
    if (next_tag=="") break;
    tag = tag + "_" + next_tag;
  }
  return false;
}

std::vector<std::string> rpctutorial_IDLserver::help(const std::string& functionName) {
  bool showAll=(functionName=="--all");
  std::vector<std::string> helpString;
  if(showAll) {
    helpString.push_back("*** Available commands:");
    helpString.push_back("quit");
    helpString.push_back("movearm");
    helpString.push_back("help");
  }
  else {
    if (functionName=="quit") {
      helpString.push_back("bool quit() ");
      helpString.push_back("This will close the module ");
    }
    if (functionName=="movearm") {
      helpString.push_back("bool movearm(const std::string& armside, const int32_t angle) ");
      helpString.push_back("This function will move the specified arm to the specified angle ");
      helpString.push_back("@input: string armside, int angle ");
      helpString.push_back("@output: ack/nack (success/failure) ");
    }
    if (functionName=="help") {
      helpString.push_back("std::vector<std::string> help(const std::string& functionName=\"--all\")");
      helpString.push_back("Return list of available commands, or help message for a specific function");
      helpString.push_back("@param functionName name of command for which to get a detailed description. If none or '--all' is provided, print list of available commands");
      helpString.push_back("@return list of strings (one string per line)");
    }
  }
  if ( helpString.empty()) helpString.push_back("Command not found");
  return helpString;
}


