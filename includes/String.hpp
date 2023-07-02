#pragma once

class String {
public:
  using SIZE_T = unsigned int;
  String();
  String(const char* cstr);
  
  String(const String& other);
  String(String&& other) noexcept;
  String(const String& lv, const String& rv);
  
  String& operator=(const String& other);
  String& operator=(String&& other) noexcept;
  
  ~String();
  
  String& operator+=(const String& other);
  String& operator+=(const char* other);

  const char* c_str() const noexcept;
  SIZE_T size() const noexcept;
  SIZE_T capacity() const noexcept;
  
  void toLower();

private:
  void append(const char* str, const SIZE_T size);
  static SIZE_T calculateLength(const char* cstr) noexcept;
  static void copy(char* dest, const char* src) noexcept;

private:
  SIZE_T m_capacity;
  SIZE_T m_size;
  char* m_str;
};

bool operator>(const String& lv, const String& rv);
String operator+(const String& lv, const String& rv);
