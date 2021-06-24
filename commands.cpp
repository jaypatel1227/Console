
// This is a file to store all of the commands used in console.cpp

#include "commands.h"
#include "internal_functions.h"

using namespace std;

void evaluate(string inp){
  if (inp == "exit"){
	return;
  }
  if (begins_with(inp, "echo ")){
	echo(inp);
  }
  else if (begins_with(inp, "list_nums ")){
	list_nums(inp);
  }
  else if (begins_with(inp, "cat ")){
	cat(inp);
  }
  else if (begins_with(inp, "touch ")){
	touch(inp);
  }
  else if (begins_with(inp, "head ")){
	head(inp);
  }
  else if (begins_with(inp, "tail ")){
	tail(inp);
  }
  else if (begins_with(inp, "clear")){
	clear();
  }
  else if (begins_with(inp, "pwd")){
	pwd();
  }
  else if (begins_with(inp, "history")){
	history();
  }
  else{
	cout << "Unable to read that command." << endl;
  }
}

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
  int res = system("clear");
  // used the system command to call the clear command
  if (res){
	return;
  }
}

void pwd(){
  int res = system("pwd"); 
  if (res){
	return;
  }
}

// WIP I have put it on hiatus as it is kind of annoying to write
void less(string inp){
  string file = remove_match_front(inp, "less ");
  ifstream File(file);

  string line;
  int line_num = 0;
  deque<string> current_lines;
  for (int i = 0; i<19 && getline(File, line); i++){
    if(current_lines.size() == 19){
      current_lines.pop_front();
	  line_num++;
	}
	else{
	  current_lines.push_back("Enter q to quit. \\> ");
	}
    current_lines.push_back(line);
  }
  for(unsigned int i = 0; i < current_lines.size(); i++){
	cout << current_lines[i] << endl;
  }
}

void history(){
  evaluate("cat hist.txt");
}
