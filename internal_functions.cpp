
// This contains internal functions to be used in commands.cpp

#include "internal_functions.h"

bool begins_with(string inp, string match){
  bool flag = true;
  for (int i = 0; i < int(match.length()); i++){
	if (inp[i] != match[i]){
	  flag = false;
	  break;
	}
  }
  return flag;
}

string remove_match_front(string inp, string match){
  string res = "";
  for (int i = int(match.length()); i < int(inp.length()); i++){
	res += inp[i];
  }
  return res;
}

bool ends_with(string inp, string match){
  bool flag = true;
  for (int i = int(match.length()-1); i >= 0; i--){
	if (inp[i] != match[i]){
	  flag = false;
	  break;
	}
  }
  return flag;
}

string remove_match_end(string inp, string match){
  string res = "";
  for (int i = 0; i < int(inp.length() - match.length()); i--){
	res += inp[i];
  }
  return res;
}

int read_num(string inp){
  return stoi(inp.substr(0, inp.find(" ")));
}

string read_word(string inp){
  return inp.substr(0, inp.find(" "));
}

void append_hist(int i, string inp){
  ofstream append("hist.txt", ios::app);
  append << i << " " << inp << endl;
  append.close();
}

int read_hist_num(){
  fstream hist("hist_num.txt");
  hist.seekg(0);  
  string lin;
  getline(hist, lin);
  int i;
  if (lin.empty()){
	hist.seekp(0);
	hist << "0";
	i = 0;
  }
  else{
	i = stoi(lin);
  }
  return i;
}
void increment_num(){
  fstream num("hist_num.txt");
  string x;
  getline(num, x);
  int i = stoi(x);
  num.seekp(0);
  num << i+1;
  num.close();
}
