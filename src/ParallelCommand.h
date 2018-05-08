#ifndef PARALLEL_CMD_H
#define PARALLEL_CMD_H

#include "Command.h"

template <uint8_t SIZE >
class ParallelCommand : public Command {

  public:
    ParallelCommand();
    ParallelCommand& add(Command* _cmd);
    void begin();
    void update();
  
  private:
    Command* commands[SIZE];
    const uint8_t length;
    uint8_t size;
};


template <uint8_t SIZE >
ParallelCommand<SIZE>::ParallelCommand() : length(SIZE) , size(0) {}


template <uint8_t SIZE >
ParallelCommand<SIZE>& ParallelCommand<SIZE>::add(Command* _cmd){
    if(size < length){
        commands[size++] = _cmd;
    }
    return *this;
}



template <uint8_t SIZE >
void ParallelCommand<SIZE>::begin(){
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


template <uint8_t SIZE >
void ParallelCommand<SIZE>::update(){
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


#endif

