#include <string>
#include <algorithm>
#include <cctype>

int strcmp_case_insensitive(std::string s1, std::string s2, bool SkipSpaces, int MaxChars) {
    //skip saces?
    if (SkipSpaces) {
        std::string temp1, temp2;
        for (char c : s1)
            if (!std::isspace(static_cast<unsigned char>(c)))
                temp1.push_back(c);
        for (char c : s2)
            if (!std::isspace(static_cast<unsigned char>(c)))
                temp2.push_back(c);
        s1 = temp1;
        s2 = temp2;
    }

    //max char?
    if (MaxChars >= 0) {
        if (s1.length() > static_cast<size_t>(MaxChars))
            s1 = s1.substr(0, MaxChars);
        if (s2.length() > static_cast<size_t>(MaxChars))
            s2 = s2.substr(0, MaxChars);
    }

    size_t i = 0, j = 0;
    size_t len1 = s1.length(), len2 = s2.length();

    //leading
    if (len1 > 0 && len2 > 0 &&
        std::isdigit(static_cast<unsigned char>(s1[0])) &&
        std::isdigit(static_cast<unsigned char>(s2[0]))) {
        //extract number from string
        size_t i_end = 0;
        while (i_end < len1 && std::isdigit(static_cast<unsigned char>(s1[i_end])))
            ++i_end;
        size_t j_end = 0;
        while (j_end < len2 && std::isdigit(static_cast<unsigned char>(s2[j_end])))
            ++j_end;

        std::string num1 = s1.substr(0, i_end);
        std::string num2 = s2.substr(0, j_end);

        //leading zeros removal
        auto strip_leading_zeros = [](const std::string& s) -> std::string {
            size_t pos = 0;
            while (pos < s.length() && s[pos] == '0')
                ++pos;
            return (pos == s.length()) ? "0" : s.substr(pos);
        };

        std::string val1 = strip_leading_zeros(num1);
        std::string val2 = strip_leading_zeros(num2);

        //comparing
        if (val1.length() != val2.length())
            return (val1.length() < val2.length()) ? -1 : 1;

        int cmp = val1.compare(val2);
        if (cmp != 0)
            return (cmp < 0) ? -1 : 1;

        //equals, continue
        i = i_end;
        j = j_end;
    }

    //comparing regularly
    while (i < len1 && j < len2) {
        char c1 = std::tolower(static_cast<unsigned char>(s1[i]));
        char c2 = std::tolower(static_cast<unsigned char>(s2[j]));
        if (c1 < c2) return -1;
        if (c1 > c2) return 1;
        ++i;
        ++j;
    }

    //handling time
    if (i < len1) return 1;
    if (j < len2) return -1;
    return 0;
}