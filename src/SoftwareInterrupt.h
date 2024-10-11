#ifndef SOFTWAREINTERRUPT_H
#define SOFTWAREINTERRUPT_H

#include <Arduino.h>

class Software_Interrupt
{
    public:
        Software_Interrupt(int Pin);
        virtual ~Software_Interrupt();
        void setup(int mode);
        void set_setup(bool state){setup_finished=state;};        
        void attachInterrupt(void (*interrupt_func)()=NULL,int Status=CHANGE, int delay_value=NULL);
        void detachInterrupt();
        void set_init(bool state){init=state;};        
        void main();
        bool operator!=(Software_Interrupt const &rhs) const;
    protected:
        
        
    private:
        bool time_passed;
        unsigned long current_time;
        int delay=0;
        bool irs_flag;
        void (*interrupt_handler)()=NULL;
        int STATUS;
        bool init;
        bool setup_finished=false;
        bool attach_finished=false;
        bool PIN_state;
        bool PIN_old_state;        
        int PIN;
        //static void pass(){};

};

#endif // SOFTWAREINTERRUPT
