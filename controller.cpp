/* 
 * Auteur: Simon Jourdenais  
 * Date: Avril 2022
 * Projet: S2EI Space Invaders
 * Brief: Classe controller et série mergé ensemble.
 *        Le constructeur de l'objet démarre le port série
 *        La fonction begin() est basically le main
 *        Les connexions vers QT doivent être faites dans la fonction decodeInputs.
*/

#include "controller.h"
/*---------------------------Definition de fonctions ------------------------
Fonction principale -- A démarrer dans un thread et utiliser la f
Entrée : Tampon de réception du message
Sortie : Code d'erreur, 1 = erreur, 0 = ok
Traitement : Réception du message
-----------------------------------------------------------------------------*/
int Controller::begin() 
{
    json j_msg_send, j_msg_rcv; // Structure de donnees JSON pour envoie et reception
    string raw_msg, com;      
    unsigned char countSend=120;
    unsigned char countRead=0;
    char past_Speed=0;
    // Boucle infinie pour la communication bidirectionnelle Arduino-PC
    while(1) 
    {
        if(!this->SendToSerial(j_msg_send)) 
        {    //Envoie au Arduino
            cerr << "Erreur lors de l'envoie du message. " << endl;
        }

        // Reception message Arduino
        j_msg_rcv.clear(); // effacer le message precedent
        if(!this->RcvFromSerial(raw_msg)) 
        {
            cerr << "Erreur lors de la reception du message. " << endl;
        }
        
        // Impression du message de l'Arduino, si valide
        if(raw_msg.size()>0) {
            j_msg_rcv = json::parse(raw_msg);       // Transfert du message en json
            this->m_joystick.X = j_msg_rcv["Joy_X"];    
            this->m_joystick.Y = j_msg_rcv["Joy_Y"];
            this->m_accel.Z = j_msg_rcv["Acc_Z"];
            this->m_Game_Speed = j_msg_rcv["pot_Value"];
            this->getButtonValues(j_msg_rcv["btn_Value"], this->m_Btn_States);
            this->decodeInputs();  //Decodes values from inputs -- Sert aussi a modifier des valeurs pour des fins de test
            j_msg_send["vitesse_Jeu"] = this->m_Game_Speed;  //Valeur de vie a afficher - Pot Value instead as of now   
            if(this->checkForShake())
                this->m_Motor_Mode=3; //Mode 3 = bomba
            j_msg_send["moteur_On"] = this->m_Motor_Mode;  

            //Debugging section -- Affiche les trames envoyées et recues en alternance a une vitesse plus lisible :)
            
            if(this->m_Motor_Mode!=0)
                cout << j_msg_send <<endl;
            else if(past_Speed!=this->m_Game_Speed)
                cout << j_msg_rcv <<endl;
            past_Speed=this->m_Game_Speed;
            this->m_Motor_Mode=0;
            //countSend+=10;
            //countRead+=10;
            
            //cout << j_msg_send <<endl;
            //cout << j_msg_rcv <<endl;
        }
        Sleep(20); // Fréquence de comm de 50 Hertz
    }
    return 0;
}
/*---------------------------Definition de fonctions ------------------------
Fonction de verification de jerk motion
Entrée : None
Sortie : True si la manette a été brassée vigoureusement sinon false
Traitement : Store plusieurs valeurs et verifie si plus de 2 peaks qui ont 
passés le threshold ont eu lieu ( 2 shake) en moins d'une seconde 
-----------------------------------------------------------------------------*/
bool Controller::checkForShake()
{
    static int z_ValuesList[50];
    static char z_Counts=0;
    char shakeCount=0;

    this->m_accel.Z=z_ValuesList[z_Counts];

    if(z_Counts<50)
        z_Counts+=1;
    else
        z_Counts=0;

    for(int i =0;i<50;i++)
    {
        if(z_ValuesList[i]>= SHAKETHRESHOLD)
            shakeCount+=1;
    }
    if(shakeCount >=2)
    {
        this->isBombDropped = true;
        return true;
    }
    return false;
}

/*---------------------------Definition de fonctions ------------------------
Fonction de décodage des entrées
Entrée : None
Sortie : None
Traitement : Explicite les evennements de la manette pour QT
-----------------------------------------------------------------------------*/
void Controller::decodeInputs()    
{
    //Decoding game Speed from pot value ( already in m game speed)
    this->m_Game_Speed=10-(this->m_Game_Speed*10/1000);  //le vrai calcul serais divisé par 1023. F

    //Decoding events from buttons
    //Button presses are stored as flags in the object Controller
    //m_button_States contenait deja les états des boutons, mais a partir de ce switchcase il est facile de connecter les
    //Event de QT ----------------
    for(int button=0;button<5;button++)
    {
        switch(button)
        {
            case 0:
            {
                if(this->m_Btn_States[0]==1)
                    this->isXPressed = true;
                else 
                    this->isXPressed =false;
                break;
            }
            case 1:
            {
                if(this->m_Btn_States[1]==1)
                    this->isYPressed = true;
                else 
                    this->isYPressed =false;
                break;
            }
            case 2:
            {
                if(this->m_Btn_States[2]==1)
                    this->isBPressed = true;
                else 
                    this->isBPressed =false;
                break;
            }
            case 3:
            {
                if(this->m_Btn_States[3]==1)
                    this->isAPressed = true;
                else 
                    this->isAPressed =false;
                break;
            }
            case 4:
            {
                if(this->m_Btn_States[4]==1)
                    this->isStartPressed = true;
                else 
                    this->isStartPressed =false;
                break;
            }
        }
    }
     //Shake Test Values
    if(this->isStartPressed && this->m_Game_Speed>9)
        this->m_Game_Speed = 11;   
    else if(this->isStartPressed && this->m_Game_Speed ==9)
        this->m_Motor_Mode=99;
    else if(this->isStartPressed &&  this->m_Game_Speed<9 &&this->m_Game_Speed>=8)
        this->m_Motor_Mode=5;
    else if(this->isStartPressed && this->m_Game_Speed<8 &&this->m_Game_Speed>=6)
        this->m_Motor_Mode=4;
    else if(this->isStartPressed &&  this->m_Game_Speed<6 &&this->m_Game_Speed>=4)
        this->m_Motor_Mode=3;
    else if(this->isStartPressed &&  this->m_Game_Speed<4 &&this->m_Game_Speed>=2)
        this->m_Motor_Mode=2;
    else if(this->isStartPressed &&  this->m_Game_Speed<2)
        this->m_Motor_Mode=1;
}

/*---------------------------Definition de fonctions ------------------------
Fonction de determination du bouton appuyé
Entrée : Registre des valeurs boutons
Sortie : Void - Enregistre les valeurs des boutons dans le pointeur
Traitement : Get button values
-----------------------------------------------------------------------------*/
void Controller::getButtonValues(int btnRegister, int btn_States[])
{
    for(int i = 0;i<5;i++)
    {
        if((btnRegister&(1<<i)) >0)
        {
            btn_States[i]=1;
            //cout << "Bouton " << btnNames[i]<< " was pressed." <<endl;
        }
        else
            btn_States[i]=0;
    }
}
/*---------------------------Definition de fonctions ------------------------
Fonction d'envoi
Entrée : Tampon de réception du message
Sortie : Code d'erreur, 1 = erreur, 0 = ok
Traitement : Réception du message
-----------------------------------------------------------------------------*/
bool Controller::SendToSerial(json j_msg) 
{
    // Return 0 if error
    string msg = j_msg.dump();
    bool ret = this->writeSerialPort(msg.c_str(), msg.length());
    return ret;
}


/*---------------------------Definition de fonctions ------------------------
Fonction de réception
Entrée : Port de communication, message à envoyer
Sortie : Code d'erreur, 1 = erreur, 0 = ok
Traitement : Envoie du message
-----------------------------------------------------------------------------*/
bool Controller::RcvFromSerial(string &msg) {
    // Return 0 if error
    // Message output in msg
    string str_buffer;
    char char_buffer[MSG_MAX_SIZE];
    int buffer_size;

    msg.clear(); // clear string
    // Read serialport until '\n' character (Blocking)
    while(msg.back()!='\n') {
        if(msg.size()>MSG_MAX_SIZE) {
            return false;
        }

        buffer_size = this->readSerialPort(char_buffer, MSG_MAX_SIZE);
        str_buffer.assign(char_buffer, buffer_size);
        msg.append(str_buffer);
    }

    msg.pop_back(); //remove '/n' from string
    return true;
}


//Constructeur de l'objet Controller.
//Contient en fait le constructeur de l'objet SerialPort qui a été assimilé..
Controller::Controller(const char *portName, int BAUD)
{
    this->connected = false;

    this->handler = CreateFileA(static_cast<LPCSTR>(portName),
                                GENERIC_READ | GENERIC_WRITE,
                                0,
                                NULL,
                                OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL,
                                NULL);
    if (this->handler == INVALID_HANDLE_VALUE)
    {
        if (GetLastError() == ERROR_FILE_NOT_FOUND)
        {
            std::cerr << "ERROR: Handle was not attached.Reason : " << portName << " not available\n";
        }
        else
        {
            std::cerr << "ERROR!!!\n";
        }
    }
    else
    {
        DCB dcbSerialParameters = {0};

        if (!GetCommState(this->handler, &dcbSerialParameters))
        {
            std::cerr << "Failed to get current serial parameters\n";
        }
        else
        {
            dcbSerialParameters.BaudRate = BAUDRATE;
            dcbSerialParameters.ByteSize = 8;
            dcbSerialParameters.StopBits = ONESTOPBIT;
            dcbSerialParameters.Parity = NOPARITY;
            dcbSerialParameters.fDtrControl = DTR_CONTROL_ENABLE;

            if (!SetCommState(handler, &dcbSerialParameters))
            {
                std::cout << "ALERT: could not set serial port parameters\n";
            }
            else
            {
                this->connected = true;
                PurgeComm(this->handler, PURGE_RXCLEAR | PURGE_TXCLEAR);
                Sleep(ARDUINO_WAIT_TIME);
            }
        }
    }
}
//Deconstructeur
Controller::~Controller()
{
    if (this->connected)
    {
        this->connected = false;
        CloseHandle(this->handler);
    }
}

// Reading bytes from serial port to buffer;
// returns read bytes count, or if error occurs, returns 0
int Controller::readSerialPort(const char *buffer, unsigned int buf_size)
{
    DWORD bytesRead{};
    unsigned int toRead = 0;

    ClearCommError(this->handler, &this->errors, &this->status);

    if (this->status.cbInQue > 0)
    {
        if (this->status.cbInQue > buf_size)
        {
            toRead = buf_size;
        }
        else
        {
            toRead = this->status.cbInQue;
        }
    }

    memset((void*) buffer, 0, buf_size);

    if (ReadFile(this->handler, (void*) buffer, toRead, &bytesRead, NULL))
    {
        return bytesRead;
    }

    return 0;
}

// Sending provided buffer to serial port;
// returns true if succeed, false if not
bool Controller::writeSerialPort(const char *buffer, unsigned int buf_size)
{
    DWORD bytesSend;

    if (!WriteFile(this->handler, (void*) buffer, buf_size, &bytesSend, 0))
    {
        ClearCommError(this->handler, &this->errors, &this->status);
        return false;
    }
    
    return true;
}

// Checking if serial port is connected
bool Controller::isConnected()
{
    if (!ClearCommError(this->handler, &this->errors, &this->status))
    {
        this->connected = false;
    }

    return this->connected;
}

void Controller::closeSerial()
{
    CloseHandle(this->handler);
}