#include "String.hpp"

String::String()
  : m_capacity(0),
    m_size(0),
    m_str(nullptr) {
}

String::String(const char* cstr)
  : m_capacity(String::calculateLength(cstr) + 1),
  m_size(m_capacity - 1),
  m_str(new char[m_capacity]) {
  String::copy(m_str, cstr);
}

String::String(const String& other)
  : m_capacity(other.m_capacity),
  m_size(other.m_size),
  m_str(new char[m_capacity]) {
  String::copy(m_str, other.m_str);
}

String::String(String&& other) noexcept 
  : m_capacity(other.m_capacity),
    m_size(other.m_size),
    m_str(other.m_str) {
  other.m_capacity = 0;
  other.m_size = 0;
  other.m_str = nullptr;
}

String::String(const String& lv, const String& rv)
  : m_capacity(lv.m_size + rv.m_size + 1),
    m_size(lv.m_size + rv.m_size),
    m_str(new char[m_capacity]) {
  String::copy(m_str, lv.m_str);
  String::copy(m_str + lv.m_size, rv.m_str);
}

String& String::operator=(const String& other) {
  if (this == &other)
    return *this;

  if (m_capacity > other.m_size) {
    m_size = other.m_size;
  } else {
    delete[] m_str;
    m_capacity = other.m_size + 1;
    m_size = other.m_size;
    m_str = new char[m_capacity];
  }
  String::copy(m_str, other.m_str);
  return *this;
}

String& String::operator=(String&& other) noexcept {
  if (this == &other)
    return *this;

  delete[] m_str;
  m_capacity = other.m_capacity;
  m_size = other.m_size;
  m_str = other.m_str;
  other.m_capacity = 0;
  other.m_size = 0;
  other.m_str = nullptr;
  return *this;
}

String::~String() {
  delete[] m_str;
}

String& String::operator+=(const String& other) {
  append(other.m_str, other.m_size);
  return *this;
}

String& String::operator+=(const char* other) {
  append(other, calculateLength(other));
  return *this;
}

const char* String::c_str() const noexcept {
  return m_str ? m_str : "";
}

String::SIZE_T String::size() const noexcept {
  return m_size;
}

String::SIZE_T String::capacity() const noexcept {
  return m_capacity;
}

void String::toLower() {
  auto str = m_str;
  while (*str) {
    *str = *str + 'a' - 'A';
    ++str;
  }
}

void String::append(const char* str, const String::SIZE_T size) {
  const auto newSize = m_size + size;
  if (m_capacity > newSize) {
    String::copy(m_str + m_size, str);
  } else {
    const auto newCapacity = newSize + 1;
    auto newStr = new char[newCapacity];
    String::copy(newStr, m_str);
    String::copy(newStr + m_size, str);
    
    delete[] m_str;
    m_capacity = newCapacity;
    m_size = newSize;
    m_str = newStr;
  }
}

String::SIZE_T String::calculateLength(const char* cstr) noexcept {
  SIZE_T res = 0;
  while (cstr[res] != '\0') {
    ++res;
  }
  return res;
}

void String::copy(char* dest, const char* src) noexcept {
  while (*dest = *src) {
    ++dest;
    ++src;
  }
}

bool operator>(const String& lv, const String& rv) {
    auto lsCstr = lv.c_str();
    auto rsCstr = rv.c_str();
    while (*lsCstr && (*lsCstr == *rsCstr))
    {
      ++lsCstr;
      ++rsCstr;
    }
    return (*lsCstr - *rsCstr) > 0;
}

String operator+(const String& lv, const String& rv) {
  return String(lv, rv);
}