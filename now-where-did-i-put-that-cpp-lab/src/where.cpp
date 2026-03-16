#include <string>
#include <iostream>
#include <cctype>

// helper to check if pattern contains unescaped wildcard characters
static bool hasWildcard(const std::string& pat) {
    for (size_t i = 0; i < pat.size(); ++i) {
        if (pat[i] == '/') {
            // skip the escaped character
            ++i;
            continue;
        }
        if (pat[i] == '*' || pat[i] == '?')
            return true;
    }
    return false;
}

//wildcard time
static bool matchPattern(const std::string& s, int i, const std::string& p, int j, bool cs) {
    //end
    if (j == (int)p.length())
        return true;

    //all *
    if (i > (int)s.length())
        return false;

    // dealing escape char
    if (p[j] == '/') {
        if (j + 1 >= (int)p.length())
            return false;               // invalid pattern, but assume well-formed
        char expected = p[j + 1];
        if (i < (int)s.length() && (cs ? s[i] == expected : std::tolower(s[i]) == std::tolower(expected)))
            return matchPattern(s, i + 1, p, j + 2, cs);
        return false;
    }
    //* matches zero or more char
    else if (p[j] == '*') {
        // Try zero match
        if (matchPattern(s, i, p, j + 1, cs))
            return true;
        // Try one or more matches
        if (i < (int)s.length() && matchPattern(s, i + 1, p, j, cs))
            return true;
        return false;
    }
    // ? matches any single char
    else if (p[j] == '?') {
        if (i < (int)s.length())
            return matchPattern(s, i + 1, p, j + 1, cs);
        return false;
    }
    //nromie
    else {
        if (i < (int)s.length() && (cs ? s[i] == p[j] : std::tolower(s[i]) == std::tolower(p[j])))
            return matchPattern(s, i + 1, p, j + 1, cs);
        return false;
    }
}

// s tring search
int find(std::string input, std::string want, int start, bool caseSensitive) {
    if (want.empty())
        return 0;                       // empty string always found at beginning
    if (start < 0)
        start = 0;

    //simple substring search
    if (!hasWildcard(want)) {
        for (int i = start; i <= (int)input.length() - (int)want.length(); ++i) {
            bool match = true;
            for (int j = 0; j < (int)want.length(); ++j) {
                char a = input[i + j];
                char b = want[j];
                if (caseSensitive) {
                    if (a != b) { match = false; break; }
                } else {
                    if (std::tolower(a) != std::tolower(b)) { match = false; break; }
                }
            }
            if (match)
                return i;
        }
        return -1;
    }
    //try every starting position
    for (int i = start; i <= (int)input.length(); ++i) {
        if (matchPattern(input, i, want, 0, caseSensitive))
            return i;
    }
    return -1;
}

//search
int find(std::string input, char want, int start, bool caseSensitive) {
    if (start < 0)
        start = 0;
    for (int i = start; i < (int)input.length(); ++i) {
        char c = input[i];
        if (caseSensitive) {
            if (c == want)
                return i;
        } else {
            if (std::tolower(c) == std::tolower(want))
                return i;
        }
    }
    return -1;
}