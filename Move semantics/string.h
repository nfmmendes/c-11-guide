#include <iostream>
#include <cstring>

using std::cout;
using std::ostream;
using std::string;
using std::strlen;

namespace dev
{
    class String
    {
    public:
        String() = default;
        String(const char *value);
        ~String();

        String(const String &other);
        String &operator=(const String &other);

        String(String &&other) noexcept;
        String &operator=(String &&other) noexcept;

        friend ostream &
        operator<<(ostream &os, const String &value);

        String operator+(const String &right) const;
        String &operator+=(const String &right);

        String operator+(String &&right) const;
        String &operator+=(String &&right);

        bool operator<(String &right);
        bool operator<(String &&right);

    private:
        char *str{};
    };
} // namespace dev