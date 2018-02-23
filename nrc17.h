//polling approach to send ir signal.
//38khz modulation signal generated by an outside oscillator
//no other interrupt running
//protoco used: nrc17

//hardware configuration
#define IR_PORT				P2
#define IR_DDR				P2
#define IR					(1<<0)			//ir output pin

//you may need to adjust the following to achieve the desired timing
//each frame is 20ms
//for a frame of 0xff, 0xff, the frequency reading is 17340hz
#define IR_DLY				37				//parameters to generate 500us delay
#define IR_PADDING()		{NOP(); NOP(); NOP(); /*NOP();*/}

//comment the following line if 38khz signal to be generated by an outside source
//#define IR_38KMCU					//if 38k to be generated by the mcu
//end hardware configuration

//reset the ir pin
void ir_init(void);

//send 38khz out for 500us
void ir_on(void);

//output cleared for 500us
void ir_off(void);

void ir_one(void);

void ir_zero(void);

//send an ir pre-pulse
//a pre-pulse consists of 1, followed by two empty slots.
void ir_pre(void);

//send a byte
//lsb first
void ir_byte(unsigned char dat);

//send a frame
//a frame consists of a pre-pulse, a start bit (1), a command byte and an address byte
void ir_frame(unsigned char cmd, unsigned char addr);