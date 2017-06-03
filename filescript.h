
#ifndef MKDIR_FILESCRIPT_H
#define MKDIR_FILESCRIPT_H

template<typename Out>

void split(const std::string &s, char delim, Out result);

std::vector<std::string> split(const std::string &s, char delim);

inline bool exists (const std::string& name);

void filescript();


#endif //MKDIR_FILESCRIPT_H