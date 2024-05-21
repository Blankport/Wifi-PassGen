#include <bits/stdc++.h>

using namespace std;

void password (string profile){
	string line, password;
	fstream file;
	ofstream file2;
	int pos;
	
	file.open("key",ios::in);
	file2.open("wi_fi and passwords.txt", ios::out | ios::app);
	if (file.is_open()){
		while(getline(file, line)){
			if(line.find("Key Content")){
			
				while(getline(file, line)){
					pos = line.find("Content");
					if (pos >= 0){
						pos = line.find(":") + 2;
						password = line.substr(pos);
						cout<< profile <<" : "<<password<<"\n"<<endl;
						file2<< profile <<" : "<<password<<"\n"<<endl;
						}
				}
				   	
			
   			}
		}
	}
	else cout<<"Error"<<endl;
	file.close();
	file2.close();
}


void cmd(string profile){
	string open = "netsh wlan show profile \"";
	string close = "\" key=clear > key";
	string command= open+profile+close;
	int n = command.length()+1;
	char cmd[n];
	
	strcpy(cmd, command.c_str());
	
	system(cmd);
   password(profile);
}


int main(){
	fstream read;
	string line, name;
	vector <string> profile;
	int pos;
	
	system("del \"wi_fi and passwords.txt\"");
	system("netsh wlan show profile > profile.txt");
	cout<<"\n\n+--------------------------------------------+"<<endl;
	cout<<"| Wi-Fi and there passwords found on this Pc |"<<endl;
	cout<<"+--------------------------------------------+\n\n"<<endl;

    read.open("profile.txt", ios::in);
	
	if (read.is_open()){
		while(getline(read, line)){
		pos = line.find("All");
		if (pos >= 0){
			pos = line.find(":")+ 2;
			name = line.substr(pos);

			cmd(name);
		}
		}
  			 
	}
	else cout <<"Error on Profiles\a"<<endl;
	read.close();
	system("del profile.txt");
	system("del key");
	
	
}