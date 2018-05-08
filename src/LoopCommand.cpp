#include "LoopCommand.h"


LoopCommand::LoopCommand() {}

void LoopCommand::init(const uint16_t _iters, Command* _command){
    loopIters = _iters;
    command = _command;
}


void LoopCommand::begin(){
    done = false;
    loopCount = 0;
    isInfinite = (loopIters == INFINITE);
    command->begin();
}


void LoopCommand::update(){
    command->update();
    if(command->isDone()){
        if(isInfinite){
            command->begin();
        }else if(++loopCount >= loopIters){
            done = true;
        }else{
            command->begin();
        }
    }
}
