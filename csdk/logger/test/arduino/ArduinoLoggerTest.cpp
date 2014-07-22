//******************************************************************
//
// Copyright 2014 Intel Corporation All Rights Reserved.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=


// Do not remove the include below
#include "ArduinoLoggerTest.h"
#include "logger.h"

const prog_char tag[] PROGMEM = "Arduino";
const prog_char msg[] PROGMEM = "Arduino Logger Test";

const prog_char debugMsg[] PROGMEM = "this is a DEBUG message";
const prog_char infoMsg[] PROGMEM = "this is a INFO message";
const prog_char warningMsg[] PROGMEM = "this is a WARNING message";
const prog_char errorMsg[] PROGMEM = "this is a ERROR message";
const prog_char fatalMsg[] PROGMEM = "this is a FATAL message";

const prog_char multiLineMsg[] PROGMEM = "this is a DEBUG message\non multiple\nlines";


//-----------------------------------------------------------------------------
//  Tests
//-----------------------------------------------------------------------------
void test0() {
    OC_LOG(INFO, tag, msg);
}

void test1() {
    OC_LOG(INFO, 0, msg);
}

void test2() {
    OC_LOG(INFO, tag, 0);
}

void test3() {
    OC_LOG(INFO, 0, 0);
}

void test4() {
    OC_LOG(DEBUG, tag, debugMsg);
    OC_LOG(INFO, tag, infoMsg);
    OC_LOG(WARNING, tag, warningMsg);
    OC_LOG(ERROR, tag, errorMsg);
    OC_LOG(FATAL, tag, fatalMsg);
}

void test5() {
    OC_LOG(DEBUG, tag, multiLineMsg);
}


void test6() {
    // Log buffer
    uint8_t buffer[50];
    for (int i = 0; i < (int)(sizeof buffer); i++) {
        buffer[i] = i;
    }
    OC_LOG_BUFFER(DEBUG, tag, buffer, sizeof buffer);

    // Log buffer, 128 bytes is a good boundary (8 rows of 16 values)
    uint8_t buffer1[128];
    for (int i = 0; i < (int)(sizeof buffer1); i++) {
        buffer1[i] = i;
    }
    OC_LOG_BUFFER(DEBUG, tag, buffer1, sizeof buffer1);

    // 1 below 128 byte boundary
    uint8_t buffer2[127];
    for (int i = 0; i < (int)(sizeof buffer2); i++) {
        buffer2[i] = i;
    }
    OC_LOG_BUFFER(DEBUG, tag, buffer2, sizeof buffer2);

    // 1 above 128 byte boundary
    uint8_t buffer3[129];
    for (int i = 0; i < (int)(sizeof buffer3); i++) {
        buffer3[i] = i;
    }
    OC_LOG_BUFFER(DEBUG, tag, buffer3, sizeof buffer3);
}

//The setup function is called once at startup of the sketch
void setup()
{
    // Add your initialization code here
    OC_LOG_INIT();

    test0();
    delay(2000);
    test1();
    delay(2000);
    test2();
    delay(2000);
    test3();
    delay(2000);
    test4();
    delay(2000);
    test5();
    delay(2000);
    test6();
    delay(2000);
}

// The loop function is called in an endless loop
void loop()
{
    delay(2000);
}
