#rpctutorial.thrift

service rpctutorial_IDLserver
{
    /**
    * This will close the module
    **/
    bool quit();

    /**
    *  This function will move the specified arm to the specified angle  
    *  @input: string armside, int angle
    *  @output: ack/nack (success/failure)
    **/
    bool movearm(1:string armside, 2:i32 angle);
}
