#include <fmt/base.h>
#include <fmt/printf.h>
#include <fmt/core.h>
#include <cstdlib>
#include <iostream>
#include <string>

auto userinput(){
  std::string inp;
  std::getline(std::cin, inp);
  return inp;
}

auto initialize(){
  fmt::print("> ");
  return userinput();
}

int list(){
  int result = system("ls");
  fmt::print("{}", result);
  return 0;
} 

int rm(std::string filename){
  int del = system(fmt::format("rm {}", filename).c_str());
  return 0;
}

int main(){
  fmt::print(initialize());
  return 0;
}
