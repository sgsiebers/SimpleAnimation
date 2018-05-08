#ifndef COMMAND_SEQ_H
#define COMMAND_SEQ_H

#include "Command.h"

template <uint8_t SEQ_LEN >
class CommandSequence : public Command {

  public:
    CommandSequence();
    CommandSequence& add(Command* _cmd);
    void begin();
    void update();
  
  private:
    Command* commands[SEQ_LEN];
    const uint8_t length;
    uint8_t size;
    uint8_t currentCommand;

};


template <uint8_t SEQ_LEN >
CommandSequence<SEQ_LEN>::CommandSequence() : length(SEQ_LEN) , size(0), currentCommand(0){}


template <uint8_t SEQ_LEN >
CommandSequence<SEQ_LEN>& CommandSequence<SEQ_LEN>::add(Command* _cmd){
    if(size < length){
        commands[size++] = _cmd;
    }
    return *this;
}



template <uint8_t SEQ_LEN >
void CommandSequence<SEQ_LEN>::begin(){
	DEBUG_PRINT("Begin Seq");
    currentCommand = 0;
    if(size > 0){
        done = false;
        commands[currentCommand]->begin();
    }else{
    	done = true;
    }
}


template <uint8_t SEQ_LEN >
void CommandSequence<SEQ_LEN>::update(){
	commands[currentCommand]->update();
	if(commands[currentCommand]->isDone()){
		currentCommand++;
		if(currentCommand >= size){
    		DEBUG_PRINT("End Seq");
      		done = true;
    	}else{
      	commands[currentCommand]->begin();
    	}
  	}
}




#endif

