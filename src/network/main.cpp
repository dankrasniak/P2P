#include <iostream>

#include "../../include/network/BroadcastSender.hpp"
#include "../../include/controller/Controller.hpp"
#include "../../include/utils/EventQueue.hpp"
#include "../../include/resourcemanager/ResourceManager.hpp"
#include "../../include/network/UnicastReceiver.hpp"
#include "../../include/network/BroadcastReceiver.hpp"
#include "../../include/interface/Interface.hpp"

int main()
{
    //Interface interf();
   /* BroadcastReceiver *broadcastReceiver = new BroadcastReceiver();
    broadcastReceiver->start();
    UnicastReceiver *unicastReceiver = new UnicastReceiver();
    unicastReceiver->start();
    Controller *controller = new Controller();
    controller->start();
    ResourceIdentifier *ri = new ResourceIdentifier("Victory.mp3", 503200);
    ResourceManager::getInstance().addRemoteResource(*ri, *(new Source((char*)"25.9.227.212")));
    ResourceManager::getInstance().addDownloadedResource(*ri);*/
    //ResourceManager::getInstance().addLocalResource("test.txt");
    //ResourceManager::getInstance().addLocalResource("test.tx");
    //EventQueue::getInstance().push(new IncomingAllResourcesRequestEvent(*(new Source((char*)"192.168.2.107"))));




/*    ResourceManager resourceManager;
    ResourceIdentifier resourceIdentifier;
    resourceManager.addRemoteResource(ResourceIdentifier("nam",2), Source(sockaddr_in()));


    getchar();

    //BroadcastSender *broadcastSender = new BroadcastSender;
    //broadcastSender->requestAllResources();

    //UnicastSender *unicastSender = new UnicastSender();

    LocalResource lr("test.txt");
    Part p1 = lr.getPart(0);
    Part p2 = lr.getPart(1);
    Part p3 = lr.getPart(2);
    //unicastSender->requestPart(&p1, (char *)"25.1.3.6");
    //unicastSender->requestPart(&p2, (char *)"25.1.3.6");
    //unicastSender->requestPart(&p3, (char *)"25.1.3.6");
    DownloadedResource dr(p1.getResourceIdentifier());
    std::cout << dr.getIdOfPartForDownloading() << " " << dr.getIdOfPartForDownloading() << " " << dr.getIdOfPartForDownloading() << " " << dr.getIdOfPartForDownloading() << std::endl;
    dr.addDownloadedPart(p1);
    dr.addDownloadedPart(p2);
    dr.addDownloadedPart(p3);
    fflush(stdout);
*/
/*    getchar();
    broadcastReceiver->stop();
    unicastReceiver->stop();
    broadcastReceiver->join();
    unicastReceiver->join();
    delete broadcastReceiver;
    delete unicastReceiver;
    delete controller;*/
    getchar();
    return 0;
}
