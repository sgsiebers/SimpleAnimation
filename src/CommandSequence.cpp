#include "CommandSequence.h"


CommandSequence::CommandSequence(Command** _commands, uint8_t _size) : commands(_commands), size(_size), currentCommand(0){}


void CommandSequence::begin(){
	DEBUG_PRINT("Begin Seq");
    currentCommand = 0;
    done = false;
    commands[currentCommand]->begin();
}


void CommandSequence::update(){
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
