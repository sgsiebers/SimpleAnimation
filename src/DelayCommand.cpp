#include "DelayCommand.h"




DelayCommand::DelayCommand() : timer(Timer()) {}


void DelayCommand::init(uint32_t _duration){
    timer.setDuration(_duration);
}


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