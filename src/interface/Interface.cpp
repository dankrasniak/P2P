#include <iostream>
#include <istream>
#include "../../include/interface/Interface.hpp"
#include "../../include/resourcemanager/ResourceManager.hpp"

using namespace std;

inline void Q(string X)
{
    cout << X << endl;
}

Interface::Interface() :
    isFinished(false)
{
    addOptions();
}

void Interface::start()
{
    welcomingText();
    menu();
    char c;
    while(!isFinished)
    {
        cin >> c;
        int X = c - '0';
        while (X == 0 || X > options.size())
        {
            Q("Błędna decyzja!");
            cin >> c;
            X = c - '0';
        }
        (*this.*options[X])();
    }
}

void Interface::welcomingText()
{
     Q("Welcome to RR Torrent!");
}

void Interface::menu()
{
    Q("");
    Q("Menu:");
    Q("1. Enlist local resources.");
    Q("2. Enlist remote reources.");
    Q("3. Enlist revoked reources.");
    Q("4. Xit.");
}

void Interface::addOptions()
{
    //addSingleOption(1, &Interface::addLocalResource);
    options.insert(make_pair(1, &Interface::enlistLocalResources));
    options.insert(make_pair(2, &Interface::enlistRemoteResources));
    options.insert(make_pair(3, &Interface::enlistRevokedResources));
    options.insert(make_pair(4, &Interface::stop));
}

void Interface::enlistLocalResources()
{
    options.clear();
    Q("");
    Q("Local Resources:");
    vector<ResourceIdentifier> resources = ResourceManager::getInstance().getLocalResourcesInfo();
    int i;
    std::string str;
    for(i = 1; i <= resources.size(); i++)
    {
        str += i+48;
        str.append(". " + resources[i].getName());
        Q(str);
        str.clear();
        options.insert(make_pair(i, &Interface::revokeResource));
    }
    str += i+48;
    str.append(". Add new local resource.");
    options.insert(make_pair(i, &Interface::addLocalResource));
    Q(str);
    str.clear();
    i++;
    str += i+48;
    str.append(". Back.");
    options.insert(make_pair(i, &Interface::back));
    Q(str);
}

void Interface::enlistRemoteResources()
{
    options.clear();
    Q("");
    Q("Remote Resources:");
    vector<ResourceIdentifier> resources = ResourceManager::getInstance().getRemoteResourcesInfo();
    int i;
    std::string str;
    for(i = 1; i <= resources.size(); i++)
    {
        str += i+48;
        str.append(". " + resources[i].getName());
        Q(str);
        str.clear();
        options.insert(make_pair(i, &Interface::downloadResource));
    }
    str += i+48;
    str.append(". Back.");
    options.insert(make_pair(i, &Interface::back));
    Q(str);
}

void Interface::enlistRevokedResources()
{
    options.clear();
    Q("");
    Q("Revoked Resources:");
    vector<ResourceIdentifier> resources = ResourceManager::getInstance().getRevokedResourcesInfo();
    int i;
    std::string str;
    for(i = 1; i <= resources.size(); i++)
    {
        str += i+48;
        str.append(". " + resources[i].getName());
        Q(str);
        str.clear();
        options.insert(make_pair(i, &Interface::revertResource));
    }
    str += i+48;
    str.append(". Back.");
    options.insert(make_pair(i, &Interface::back));
    Q(str);
}

void Interface::stop()
{
    isFinished = true;
}



void Interface::addSingleOption(unsigned id, methodPointer method)
{
    //options.insert(std::pair<unsigned int, void (Interface::*)()>(id, *method));
}

void Interface::addLocalResource()
{
    Q("siema");
    options.clear();
    menu();
    addOptions();
}

void Interface::revokeResource()
{

    options.clear();
    menu();
    addOptions();
}

void Interface::downloadResource()
{

    options.clear();
    menu();
    addOptions();
}

void Interface::revertResource()
{

    options.clear();
    menu();
    addOptions();
}

void Interface::back() {
    options.clear();
    menu();
    addOptions();
}
