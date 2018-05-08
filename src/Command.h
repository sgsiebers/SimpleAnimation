#ifndef COMMAND_H
#define COMMAND_H
#include <stdint.h>


//Debug mode
#define DEBUG
#ifdef DEBUG
 #define DEBUG_PRINT(x)  Serial.println (x)
#else
 #define DEBUG_PRINT(x)
#endif



class Command{

public:

	//Abstract constructor
	Command();

    // Called to start executing a command
    virtual void begin() = 0;

    // Called each loop() iteration while the command is executing
    virtual void update() = 0;

	// Determine when the command is done and you should stop calling update()
    // @return True when Command is done
	virtual bool isDone();


protected:
    bool done;

};
#endif

