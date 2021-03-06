#ifndef PART_HPP
#define PART_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <stdint.h>
#include "../utils/Configuration.hpp"
#include "ResourceIdentifier.hpp"


class Part
{
    public:
        Part();
        Part(const ResourceIdentifier &ri, unsigned id, unsigned size, std::istream &data_stream);
        const ResourceIdentifier& getResourceIdentifier() const;
        unsigned getId() const;
        unsigned getSize() const;
        const uint8_t* getData() const;

    private:
        ResourceIdentifier resourceIdentifier;
        unsigned id;
        unsigned size;
        uint8_t data[Configuration::PART_SIZE];
};


#endif
