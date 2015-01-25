#include <iostream>
#include <stdio.h>
#include <netinet/in.h>

#include "../../include/network/BroadcastSender.hpp"
#include "../../include/network/BroadcastReceiver.hpp"
#include "../../include/network/UnicastReceiver.hpp"
#include "../../include/network/UnicastSender.hpp"
#include "../../include/resourcemanager/ResourceManager.hpp"
#include "../../include/resourcemanager/Source.hpp"


int main()
{

    //ResourceManager resourceManager;
    //ResourceIdentifier resourceIdentifier;
    //resourceManager.addRemote(ResourceIdentifier("nam",2), Source(sockaddr_in()));
    BroadcastReceiver *broadcastReceiver = new BroadcastReceiver();
    broadcastReceiver->start();
    UnicastReceiver *unicastReceiver = new UnicastReceiver();
    unicastReceiver->start();
    getchar();

    //BroadcastSender *broadcastSender = new BroadcastSender;
    //broadcastSender->requestAllResources();

    UnicastSender *unicastSender = new UnicastSender();

    LocalResource lr("test.txt");
    Part p = lr.getPart(0);
    //unicastSender->requestConfirmation((char*)"Siema", (char *)"25.9.227.212");
    unicastSender->requestPart(&p, (char *)"192.168.2.107");
    fflush(stdout);

    getchar();
    broadcastReceiver->stop();
    broadcastReceiver->join();
    unicastReceiver->stop();
    unicastReceiver->join();
    delete broadcastReceiver;
    delete unicastReceiver;
    //delete broadcastSender;
    //delete unicastSender;
    return 0;
}
