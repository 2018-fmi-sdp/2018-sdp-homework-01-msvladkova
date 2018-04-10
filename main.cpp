#include<iostream>
#include<string.h>
using namespace std;

class Command {
    private:
    string _name;
    
    public:
    Command();
    Command(string name);
    string getName();
    virtual bool doExecute(string cmdLine, string* output){};
    friend ostream& operator<<(ostream &os, Command &c){os<<c._name; return os;};
    
};

Command :: Command(){
    _name="";
}

Command :: Command(string name){
    _name=name;
}

string Command::getName()
{
    return _name;
}

class QuitCmd : public Command{
    bool doExecute(string cmdLine, string* output){
        return true;
    }
    
};

class HelpCmd : public Command{
    private:
    Command* _commands;
    int _numberofcommands=0;
    public:
    HelpCmd(Command* ,int);
    bool doExecute(string cmdLine, string* output);
};

HelpCmd :: HelpCmd(Command* commands, int numberofcommands)
{
    _commands=commands;
    _numberofcommands=numberofcommands;
}

bool HelpCmd :: doExecute(string cmdLine, string* output){
    for(int i=0; i<_numberofcommands; i++){
        cout<<_commands[i]<<endl;
    }
    return true;
}

class PromptCmd : public Command
{   private:
      string _prompt=">";
    public:
      PromptCmd(string);
      void setPrompt(string);
      bool doExecute(string cmdLine, string* output);
};

PromptCmd :: PromptCmd(string prompt)
{
    setPrompt(prompt);
}

void PromptCmd :: setPrompt(string prompt)
{
    _prompt=prompt;
}

bool PromptCmd :: doExecute(string cmdLine, string* output)
{
    while(true) cout<<_prompt<<" ";
    return true;
}

class AsmRegSetCmd : public Command
{ private:
   int _number;
   int _registers[10]={0};
  public:
   AsmRegSetCmd(int number,int registers[10]);
   bool doExecute(string cmdLine, string* output);
   
};

AsmRegSetCmd :: AsmRegSetCmd(int number, int registers[10])
{
    _number=number;
    _registers[10]=registers[10];
}

int main()
    {
        return 0;
    }
