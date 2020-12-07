#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Football {
  public:
  
    // Factory Method, note it's static
    static Football *make_football(string choice);
  
    // method that we will use polymorphically per product
    virtual void io() = 0;
    
    // Note: need to specify an explicicit default destructor
    virtual ~Football() = default;
};

class touchdown: public Football {
  public:
    void io() {
        cout << "Touchdown: 6 points\n";
    }
};

class fieldgoal: public Football {
  public:
    void io() {
        cout << "Fieldgoal: 3 points\n";
    }
};

class PAT: public Football {
  public:
    void io() {
        cout << "PAT: 1 point\n";
    }
};

class PAT2: public Football {
  public:
    void io() {
        cout << "2 PAT: 2 points\n";
    }
};

class Saftey: public Football {
  public:
    void io() {
        cout << "Saftey: 2 points\n";
    }
};

class Gibberish: public Football {
  public:
    void io() {
        cout << "That isn't a score in football  \n";
    }
};




// this is the FACTORY Method
// it does need to know about the derived methods
// but this allows us to abstract this from our 
// "client" calling code in main()
Football *Football::make_football(string choice) {
  if (choice ==  "touchdown")
    return new touchdown;
  else if (choice == "fieldgoal")
    return new fieldgoal;
  else if (choice == "PAT")
    return new PAT;
  else if (choice == "2PAT")
    return new PAT2;
  else if (choice == "saftey")
    return new Saftey;
  else 
    return new Gibberish;
  
}


// main() is considered the "client"
// while in this example we could hard code the
// derived classes since we are making a menu anyway
// imagine having 

int main() {
  vector<Football*> score;
  string choice;
  while (true) {
    cout << "Enter football scoring or 0 if done: ";
    cin >> choice;
    if (choice == "0") break;
    score.push_back(Football::make_football(choice));
  }
  for (int i = 0; i < score.size(); i++) {
    score[i]->io();
  }
  for (int i = 0; i < score.size(); i++) {
    delete score[i];
  }
}