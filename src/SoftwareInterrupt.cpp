#include "SoftwareInterrupt.h"
#include "Arduino.h"

Software_Interrupt::Software_Interrupt(int Pin){
    PIN=Pin;
}


Software_Interrupt::~Software_Interrupt(){
    //dtor
}

void Software_Interrupt::setup(int mode){
    if ((mode==INPUT) || (mode==INPUT_PULLUP)){
        pinMode(PIN, mode);
        setup_finished=true;
    }
}

void Software_Interrupt::attachInterrupt(void (*interrupt_func)(),int Status, int delay_value){
  if (interrupt_func==NULL){
    attach_finished=false;
  }else{
    interrupt_handler=interrupt_func;
    STATUS=Status;
    delay=delay_value;
    attach_finished=true;
    init=true;
  }
}
void Software_Interrupt::detachInterrupt(){
  attach_finished=false;
  interrupt_handler=NULL;
}

bool Software_Interrupt::operator!=(Software_Interrupt const &rhs) const {
    return PIN != rhs.PIN;
}


void Software_Interrupt::main(){
    if(setup_finished && attach_finished){
        //init state
        if (init){
            PIN_old_state=digitalRead(PIN);
            init=false;
            time_passed=true;
        }else{
            if (time_passed){
                PIN_state=digitalRead(PIN);
            }else{
                if (millis()-current_time>=delay){
                    time_passed=true;
                }
                return;
            }
            if ((STATUS==RISING & PIN_old_state==LOW & PIN_state==HIGH)|| (STATUS==FALLING & PIN_old_state==HIGH & PIN_state==LOW) || (STATUS==CHANGE & PIN_old_state!=PIN_state)){
                interrupt_handler();
            }
            if (PIN_old_state!=PIN_state){
                PIN_old_state=PIN_state;
                if (delay>0){
                    current_time=millis();
                    time_passed=false;
                }
            }
        }
    }
}

