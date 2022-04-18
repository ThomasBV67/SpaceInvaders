#include "inputthread.h"

InputThread::InputThread()
{

}

/// <summary>
/// This is the main function used by the thread that deals with controller
/// input. This has not been fully implemented yet.
/// </summary>
void InputThread::process()
{
    string com;

    // Initialisation du port de communication
    cout << "Arduino COM Port: ";
    cin >> com;
    controller = new Controller(com.c_str(), BAUD);

    if (!controller->isConnected())
    {
        cerr << "Impossible de se connecter au port " << string(com) << ". Fermeture du programme!" << endl;
        exit(1);
    }
    if (!controller->begin())
    {
        cout << "Fin du programme sans erreur" << endl;
    }
    else
        cerr << "Death" << endl;
	emit finished();
}