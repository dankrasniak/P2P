#ifndef DOWNLOADED_RESOURCE
#define DOWNLOADED_RESOURCE

#include <boost/smart_ptr/shared_ptr.hpp>
#include <fstream>
#include "ResourceIdentifier.hpp"
#include "Part.hpp"

class DownloadedResource
{
public:
    DownloadedResource(const ResourceIdentifier& identifier);

    void addDownloadedPart(const Part& part);

private:
    bool isComplete() const;
    unsigned getPartsCount();

    mutable std::ofstream file;
    ResourceIdentifier identifier;

    std::vector<bool> partsDownloaded;
    unsigned partsCount;
};

#endif // DOWNLOADED_RESOURCE