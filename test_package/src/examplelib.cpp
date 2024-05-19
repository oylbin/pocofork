#include <iostream>
#include "Poco/Random.h"
#include <Poco/RandomStream.h>
#include "examplelib.h"

std::string generateRandomString(size_t length)
{
    Poco::RandomInputStream ris;
    std::string randomString;
    randomString.reserve(length);

    while (randomString.size() < length)
    {
        char ch = static_cast<char>(ris.get());
        // Filter to only printable ASCII characters (excluding space)
        if (ch >= 33 && ch <= 126)
        {
            randomString.push_back(ch);
        }
    }

    return randomString;
}