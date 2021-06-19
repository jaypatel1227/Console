// #include <iostream>
// #include <fstream>
// #include <string>
#include "console.h"

using namespace std;
// using namespace std::experimental::filesystem;

int main() {
  string prompt = "prompt:/> ";
  string inp = "";
  while (inp != "exit"){
	cout << prompt;
	getline(cin, inp);
	if (ends_with(inp, "\\")){
	  string temp = "";
	  while(not ends_with(inp, "\\")){
		cin >> temp;
		inp = inp + "\n" + temp;
	  }
	}
	evaluate(inp);
  }
}

void evaluate(string inp){
  if (begins_with(inp, "echo")){
	echo(inp);
  }
  
}

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

void echo(string inp){
  cout << remove_match_front(inp, "echo ") << endl;
}