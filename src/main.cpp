#include <cstdio>
#include <fstream>
#include <list>
#include "String.hpp"

int main() {
  try {
  	std::ifstream ifs("input.txt");
  	if (!ifs.is_open()) {
  	  std::fprintf(stderr, "File not open\n");
  	  return 1;
  	}

  	std::string s;
  	std::list<String> container;
  	while (ifs >> s)
  	  container.push_back(s.c_str());
  	ifs.close();

  	container.sort(
  	  [](const String& lv, const String& rv)
  	  {
  	  	String lvc(lv);
  	  	lvc.toLower();
  	  	String rvc(rv);
  	  	rvc.toLower();
  	  	return lvc > rvc;
  	  });

  	for (const auto& e : container)
      std::printf("%s\n", e.c_str());
  }
  catch (const std::exception& e) {
    std::fprintf(stderr, "%s\n", e.what());
  	return 2;
  }
  catch (...) {
  	return 3;
  }
  return 0;
}
