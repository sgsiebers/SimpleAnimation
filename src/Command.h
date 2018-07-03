#ifndef COMMAND_H
#define COMMAND_H

#include <Arduino.h>
#include <stdint.h>
#include "Debug.h"




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

