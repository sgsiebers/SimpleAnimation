#include "LoopCommand.h"


LoopCommand::LoopCommand(const uint16_t _numIterations, Command* _command) :
	numIterations(_numIterations),
	currentCount(0),
	command(_command){}


void LoopCommand::begin(){
    done = false;
    currentCount = 0;
    command->begin();
}


void LoopCommand::update(){
    command->update();
    if(command->isDone()){
        if(numIterations == INFINITE){
            command->begin();
        }else if(++currentCount >= numIterations){
            done = true;
        }else{
            command->begin();
        }
    }
}
