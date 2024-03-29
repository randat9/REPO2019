#ifndef TSTRING_H
#define TSTRING_H
#include <cstring>

class TString {
    public:
        TString(const char* s = nullptr); // c-tor
        TString(const TString& s); // cc-tor
        TString(TString&& s); // mvc-tor
        ~TString(); // d-tor
        TString& operator=(const TString& s); // copy operator=
        TString& operator=(TString&& s); // move operator=
        char& operator[](size_t n);
        const char& operator[](size_t n) const; 

        char* begin() { return ptr; } 
        char* end() { return ptr+len; } 
        size_t length() const { return len; } 
        size_t size() const { return len; } 
        void clear() { delete [] ptr; ptr = nullptr; len = 0; } 
        bool empty() const { return len ? false : true; } 
        char& front() { return *ptr; } 
        const char& front() const { return *ptr; } 
        char& back() { return *(ptr+len-1); } 
        const char& back() const { return *(ptr+len-1); } 
        void push_back(char c) { insert(len,c); }
        void push_back(const char* c) { insert(len,c); }
        operator char*() { return ptr; }
        operator const char*() const { return ptr; }

        char* insert(size_t pos, const char* c);
        char* insert(size_t pos, char c);

    private:
        char* ptr = nullptr;
        std::size_t len = 0;

    friend std::ostream& operator<<(std::ostream& strumien, const TString& s);
    friend std::istream& operator>>(std::istream& strumien, TString& s);
};

#endif // TSTRING_H