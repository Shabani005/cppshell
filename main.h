
#include <fmt/base.h>
#include <fmt/printf.h>
#include <fmt/core.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ncurses.h>

auto userinput(){
  std::string inp;
  std::getline(std::cin, inp);
  return inp;
}

auto initialize(){
  fmt::print("> ");
  std::string output;
  output = userinput();
  fmt::print("{}", output);
  return output;
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

auto ncurseinit(){
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  refresh();
  
  
  //endwin();
}
