#ifndef SOFTWAREINTERRUPT_H
#define SOFTWAREINTERRUPT_H

#include <Common.h>

class Software_Interrupt
{
    public:
        Software_Interrupt(int Pin);
        virtual ~Software_Interrupt();
        void setup_SI(PinMode Mode=INPUT);
        void attach_SI(void (*interrupt_func)()=NULL,PinStatus Status=CHANGE);
        void main();
    protected:
        
        
    private:
        void (*interrupt_handle)();
        PinStatus STATUS;
        bool setup=false;
        bool attach=false;
        bool PIN_state;
        bool PIN_old_state;        
        int PIN;
        //static void pass(){};

};

#endif // OPTICINTERRUPT_H
