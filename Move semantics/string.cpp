#include "string.h"

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::strlen;

namespace dev
{
    String::String(const char *value)
    {
#ifdef ENABLE_CUSTOM_STRING_COUT
        cout << "Const char * constructor with value \"" << value << "\" " << endl;
#endif
        auto lenght = strlen(value);
        str = new char[lenght + 1];
        std::strcpy(str, value);
    }

    String::~String()
    {
        delete[] str;
    }

    String::String(const String &other)
    {
#ifdef ENABLE_CUSTOM_STRING_COUT
        cout << "Copy constructor with value \"" << other << "\" " << endl;
#endif
        auto lenght = strlen(other.str);
        str = new char[lenght + 1];
        std::strcpy(str, other.str);
    }

    String &String::operator=(const String &other)
    {
#ifdef ENABLE_CUSTOM_STRING_COUT
        cout << "Copy assignment with value \"" << other << "\" " << endl;
#endif
        if (other.str == nullptr)
        {
            delete[] str;
            return *this;
        }

        auto newLenght = strlen(other.str);
        if (str == nullptr)
        {
            str = new char[newLenght + 1];
            std::strcpy(str, other.str);
            return *this;
        }

        if (newLenght > strlen(str))
        {
            delete[] str;
            str = new char[newLenght + 1];
            std::strcpy(str, other.str);
            return *this;
        }

        std::strcpy(str, other.str);
        return *this;
    }

    String::String(String &&other) noexcept
    {
#ifdef ENABLE_CUSTOM_STRING_COUT
        cout << "Move constructor with value \"" << other << "\" " << endl;
#endif
        str = other.str;
        other.str = nullptr;
    }

    String &String::operator=(String &&other) noexcept
    {
#ifdef ENABLE_CUSTOM_STRING_COUT
        cout << "Move assignment with value \"" << other << "\" " << endl;
#endif
        str = other.str;
        other.str = nullptr;
        return *this;
    }

    String String::operator+(const String &right) const
    {
#ifdef ENABLE_CUSTOM_STRING_COUT
        cout << "By value concatenation" << endl;
#endif
        String result{str};
        result += right;

        return result;
    }

    String &String::operator+=(const String &right)
    {
#ifdef ENABLE_CUSTOM_STRING_COUT
        cout << "By copy += operator" << endl;
#endif
        char *newString = new char(strlen(str) + strlen(right.str) + 1);
        strcpy(newString, str);
        strcat(newString, right.str);

        delete[] str;
        str = newString;

        return *this;
    }

    String String::operator+(String &&right) const
    {
#ifdef ENABLE_CUSTOM_STRING_COUT
        cout << "By move concatenation" << endl;
#endif
        String result{str};
        result += right;

        return result;
    }

    String &String::operator+=(String &&right)
    {
#ifdef ENABLE_CUSTOM_STRING_COUT
        cout << "By move += operator" << endl;
#endif
        char *newString = new char(strlen(str) + strlen(right.str) + 1);
        strcpy(newString, str);
        strcat(newString, right.str);

        delete[] str;
        str = newString;

        return *this;
    }

    bool String::operator<(String &right)
    {
        if (str == nullptr)
            return false;
        if (right.str == nullptr)
            return true;
        return strcmp(str, right.str) < 0;
    }

    bool String::operator<(String &&right)
    {
        if (str == nullptr)
            return false;
        if (right.str == nullptr)
            return true;
        return strcmp(str, right.str) < 0;
    }

    ostream &
    operator<<(ostream &os, const String &value)
    {
        if (value.str != nullptr)
            os << value.str;
        return os;
    }

} // namespace dev