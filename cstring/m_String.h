#pragma once
#include <iostream>
#include <cstring>

using std::ostream;
using std::istream;

class m_String {
private:
    char *pStr;
    int _size;
public:
    m_String()  {
      pStr = NULL;
      _size = 0;
    }

    m_String(char *str) {
      _size = strlen(str);
      pStr = new char[_size];
      strcpy(pStr, str);
    }

    m_String(int len) {
      pStr = new char[len];
      _size = len;
    }

    ~m_String() {
      delete pStr;
    }

    int size() {
      return _size;
    }

    friend ostream &operator << (ostream &os, m_String &obj);
    friend istream &operator >> (istream &is, m_String &obj);
    friend bool operator == (m_String &str1, m_String &str2);
    friend m_String operator + (m_String &str1, m_String &str2);
};

bool operator == (m_String &str1, m_String &str2) {
  if (str1.size() != str2.size()) { return false; }
  for (int index = 0; index < str1.size(); ++index) {
    if (str1.pStr[index] != str2.pStr[index]) {
      return false;
    }
  }
  return true;
}

istream &operator >> (istream &is, m_String &obj) {
  char BUFF[2048];

  is.getline(BUFF, sizeof BUFF);
  obj = BUFF;

  return is;
}

ostream &operator << (ostream &os, m_String &obj)  {
  for(int i = 0; i < obj.size(); i++) {
    os << obj.pStr[i];
  }
  return os;
}

m_String operator + (m_String &str1, m_String &str2) {
  size_t full_size = strlen(str1.pStr) + strlen(str2.pStr);
  char buf[str1.size()];
  strcpy(buf, str1.pStr);

  str1._size = full_size;

  str1.pStr = new char[full_size];

  int index = 0;

  for(; index < strlen(buf); ++index) {
    str1.pStr[index] = buf[index];
  }
  for (int str_index = 0; index < strlen(buf) + str2.size(); ++index, ++str_index) {
    str1.pStr[index] = str2.pStr[str_index];
  }

  return str1;
}