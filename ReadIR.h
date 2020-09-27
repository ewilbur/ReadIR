#pragma once

#include <IRremote.h>

static const int IR_SENSOR_PIN = 7; // Set to the pin reading the IR sensor
static const unsigned long DELAY_TIME = 50; // Time to wait between IR reads (ms)

typedef enum {
    POWER,
    VOL_UP,
    FUNC_STOP,
    FAST_BACK,
    PLAY_PAUSE,
    FAST_FORWARD,
    DOWN,
    VOL_DOWN,
    UP,
    EQ,
    ST_REPT,
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    NOTHING,
} ir_remote_button_t;

class ReadIR
    : public IRrecv {
private:
    typedef unsigned long ir_signal_t;
    static ir_remote_button_t decode_ir_signal(ir_signal_t signal) {
        switch (signal) {
            case 0xffa25d: return POWER;
            case 0xff629d: return VOL_UP;
            case 0xffe21d: return FUNC_STOP;
            case 0xff22dd: return FAST_BACK;
            case 0xff02fd: return PLAY_PAUSE;
            case 0xffc23d: return FAST_FORWARD;
            case 0xffe01f: return DOWN;
            case 0xffa857: return VOL_DOWN;
            case 0xff906f: return UP;
            case 0xff6897: return ZERO;
            case 0xff9867: return EQ;
            case 0xffb04f: return ST_REPT;
            case 0xff30cf: return ONE;
            case 0xff18e7: return TWO;
            case 0xff7a85: return THREE;
            case 0xff10ef: return FOUR;
            case 0xff38c7: return FIVE;
            case 0xff5aa5: return SIX;
            case 0xff42bd: return SEVEN;
            case 0xff4ab5: return EIGHT;
            case 0xff52ad: return NINE;
            default      : return NOTHING;
        }
    }

    ir_signal_t receive_ir_signal() {
        do {
            while (!this->decode(&this->results)) {
                delay(DELAY_TIME);
            }
        } while (this->results.overflow);
        ir_signal_t value = this->results.value;
        this->resume();
        return value;
    }

protected:
    decode_results results;

public:
    ReadIR() 
        : IRrecv(IR_SENSOR_PIN) 
    {}

    ReadIR(int recvpin)
        : IRrecv(recvpin)
    {}

    ReadIR(int recvpin, int blinkpin) 
        : IRrecv(recvpin, blinkpin)
    {}

    ir_remote_button_t get_button_press() {
        return this->decode_ir_signal(this->receive_ir_signal());
    }
};
