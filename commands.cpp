
// This is a file to store all of the commands used in console.cpp

#include "commands.h"
#include "internal_functions.h"

using namespace std;

void echo(string inp){
  cout << remove_match_front(inp, "echo ") << endl;
}

void list_nums(string inp){
  string args = remove_match_front(inp, "list_nums ");
  int low = read_num(args);
  args = remove_match_front(args, to_string(low) + " ");
  int high = read_num(args);
  args = remove_match_front(args, to_string(high));
  for (int i = low; i <= high; i++){
	cout << i << endl;
  }
}

void cat(string inp){
  inp = remove_match_front(inp, "cat ");
  string file = "";
  while (inp != ""){
	file = read_word(inp);
	inp = remove_match_front(inp, file + " ");
	ifstream File(file);
	string line;
	cout << "---" << file << "---" << endl;
	while (getline(File, line)){
	  cout << line << endl;
	}
	File.close();
  }

}

void touch(string inp){
  ofstream my_out(remove_match_front(inp, "touch "));
  my_out << "";
  my_out.close();
}

void head(string inp){
  ifstream File(remove_match_front(inp, "head "));
  int count = 0;
  string line;
  while (count < 10 && getline(File, line)){
	cout << line << endl;
	count++;
  }
  File.close();
}

void tail(string inp){
  // I have a very bad implementation that will read through the whole file and store the current and 9 previous line and write them out at the the end
  ifstream File(remove_match_front(inp, "tail "));
  string line;
  deque<string> last_lines;
  while(getline(File, line)){
    if(last_lines.size() == 10){
      last_lines.pop_front();
	}
    last_lines.push_back(line);
  }
  for(unsigned int i = 0; i < last_lines.size(); i++){
	cout << last_lines[i] << endl;
  }
  File.close();
}

void clear(){
  // this is just to get the compiler to not hate me
  int res = system("/bin/echo -e \"\\x1b\\x5b\\x48\\x1b\\x5b\\x32\\x4a\\c\"");
  if (res){
	return;
  }
}
