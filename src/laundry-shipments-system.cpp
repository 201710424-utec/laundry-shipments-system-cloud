#include <iostream> //std::cout std::cin
#include <fstream> //fstream
#include <string> //std::string std::to_string
#include <string.h> //c_str

#include <filesystem> //create_directories()
namespace fs = std::filesystem;

#include <stdlib.h> //_Exit()

bool createCloth() {
  std::string name;
  std::string category;
  std::cin.ignore();
  getline(std::cin, category);
  getline(std::cin, name);
  fs::create_directories("db/categories/");
  std::string path = "db/categories/"+category;
  std::fstream fCategory;
  fCategory.open(path, std::fstream::app);
  while (name != "exit") {
    fCategory << name << '\n';
    getline(std::cin, name);
  }
  fCategory.close();
}

void printFile(std::string filePath) {
  std::string line;
  std::fstream file;
  file.open(filePath, std::fstream::in);
  int option = 1;
  while (getline(file, line)) {
    line = std::to_string(option) + ". " + line;
    std::cout << line << '\n';
    option++;
  }
  file.close();
}

int menuFile(std::string filePath) {
  std::string option;
  printFile(filePath);
  std::cin >> option;
  if (option == "exit") {
    _Exit(0);
  }
  return std::stoi(option);
}

std::string selectCloth(int option, std::string category) {
  std::fstream fCategory;
  std::string line;
  fCategory.open("db/categories/" + category, std::fstream::in);
  for (size_t i = 0; i < option; i++) {
    getline(fCategory, line);
  }
  fCategory.close();
  return line;
}

bool generateTicket() {
  std::string date;
  std::string category;
  int option;
  int totalCloths = 0;
  std::string line;
  std::cout << "Fecha: ";
  std::cin >> date;
  std::fstream ticket;
  fs::create_directories("db/tickets/");
  ticket.open("db/tickets/" + date, std::fstream::app);
  std::cin.ignore();
  getline(std::cin, category);
  while (category != "exit") {
    if (category == "bividies" || category == "chicles") {
      int amount;
      std::cin >> amount;
      line = std::to_string(amount) + " " + category + "\n\n";
      ticket << line;
      totalCloths += amount;
    }else{
      option = menuFile("db/categories/" + category);
      int categoryAmount = 0;
      ticket << category << '\n';
      while (option != 0) {
        line = selectCloth(option, category);
        ticket << '\t' << line <<'\n';
        totalCloths++;
        categoryAmount++;
        option = menuFile("db/categories/" + category);
      }
      ticket << categoryAmount <<"\n\n";
    }
    std::cin.ignore();
    getline(std::cin, category);
  }
  ticket << "\nTotal:\t" << totalCloths;
  ticket << "\nBolsa:\t1";
  ticket << "\n\t···";
  ticket << "\n\t" << ++totalCloths;
  ticket.close();
}

void printTicket() {
  std::string date;
  std::cin >> date;
  std::string line;
  std::fstream file;
  file.open("db/tickets/" + date, std::fstream::in);
  while (getline(file, line)) {
    std::cout << line << '\n';
  }
  file.close();
}

int main(int argc, char const *argv[]) {
  int option;
  std::string assets_path = "assets/";
  while (true) {
    option = menuFile(assets_path + "menus/principal");
    switch (option) {
      case 1:
        createCloth();
        break;
      case 2:
        generateTicket();
        break;
      case 3:
        printTicket();
        break;
    }
  }
  return 0;
}
