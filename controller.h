#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include "json.h"

using namespace std;
using json = nlohmann::json;

#define BAUDRATE 115200           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message
#define ARDUINO_WAIT_TIME 2000
#define MAX_DATA_LENGTH 255
#define SHAKETHRESHOLD 600  //Tune this value


struct joystick_Axes 
{ 
    int X = 0;
    int Y = 0;
};
struct ADXL 
{ 
    int Z = 0;
};


class Controller
{

    public:
        explicit Controller(const char *portName, int BAUD);
        ~Controller();
        int begin();
        int readSerialPort(const char *buffer, unsigned int buf_size);
        bool writeSerialPort(const char *buffer, unsigned int buf_size);
        bool isConnected();
        void closeSerial();
        joystick_Axes m_joystick;
        ADXL m_accel;
        int m_Btn_States[5] = {0,0,0,0,0};
        int m_Game_Speed = 0;
        int m_Motor_Mode = -1;
        bool isBombDropped=false;
        bool isStartPressed = false;
        bool isXPressed = false;
        bool isYPressed = false;
        bool isBPressed = false;
        bool isAPressed = false;

    private :
        string btnNames[5] = {"X","Y","B","A","START"};
        bool SendToSerial(json j_msg);
        bool RcvFromSerial(string &msg);
        void getButtonValues(int btnRegister, int btn_States[]);
        bool checkForShake();
        void decodeInputs();
        HANDLE handler;
        bool connected;
        COMSTAT status;
        DWORD errors;
};


#endif  // INCLUDE_CONTROLLER_H