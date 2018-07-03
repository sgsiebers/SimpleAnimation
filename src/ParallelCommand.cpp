#include "ParallelCommand.h"

ParallelCommand::ParallelCommand(Command** _commands, uint8_t _size) : commands(_commands), size(_size) {}


void ParallelCommand::begin(){
	DEBUG_PRINT("Begin Parallel");
    if(size > 0){
        done = false;
        for(uint8_t i = 0; i < size; i++){
            commands[i]->begin();
        }
    }else{
    	done = true;
    }
}


void ParallelCommand::update(){
    done = true;
    for(uint8_t i = 0; i < size; i++){
        if(!commands[i]->isDone()){
        	commands[i]->update();
        }
        done &= commands[i]->isDone();
    }
    #ifdef DEBUG
        if(done){
            DEBUG_PRINT("End Parallel");
        }
    #endif
}
