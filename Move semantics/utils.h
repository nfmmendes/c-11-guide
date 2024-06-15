#pragma once

#include <string>
#include <iostream>

namespace dev
{
    class String;
};

#ifdef USE_CUSTOM_STRINGS
using String = dev::String;
#else
using String = std::string;
#endif