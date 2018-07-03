#include "DelayCommand.h"




DelayCommand::DelayCommand(uint16_t _duration) : timer(Timer(_duration)) {}


void DelayCommand::begin(){
	DEBUG_PRINT("Begin Delay");
    done = false;
    timer.reset();
}


void DelayCommand::update(){
    done = timer.expired();
	#ifdef DEBUG
	if(done){
		DEBUG_PRINT("Delay Done");
	}
	#endif    
}
