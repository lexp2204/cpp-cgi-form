#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include <stdexcept>
#include <sstream>
#include <map>


using namespace cgicc;
using namespace std;


    //isInteger function
    bool isInteger(const string& str) {
    if (str.empty()) {
        return false;
    }

    for (char c : str) {
        if (!isdigit(c)) {
            return false;  // If any character is not a digit, return false
        }
    }

    return true;  // All characters are digits, return true
}

  //isValid function for age range
  bool isValidAge(int age) {
    return age > 0 && age < 100;
}

  //Calculating Age function
  int calculateAge(int birthYear, int birthMonth, int birthDay, int currentYear, int currentMonth, int currentDay) {
    int age = currentYear - birthYear;

    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;  // If birthday hasn't occurred yet this year, subtract 1
    }

    return age;
    }


int main() {
    // Create a Cgicc object to access form data
    Cgicc form;

    // Send HTTP header indicating HTML content
    cout << HTTPHTMLHeader() << endl;
    
    // Start HTML response
    cout << "<html>\n";
    cout << "<head>\n";
    cout << "<title>CPS 3523 Project 1</title>\n";
    cout << "</head>\n";
    cout << "<body>\n";
    cout << "<h2>CPS 3525 project 1</h2>\n";
    
    cout << "<p><strong>Alexis_Penn</strong></p>";

    cout << "<span>Input information: </span><br>";
  
    // Process form data
    // Retrieve text input data (User Name)
    const_form_iterator name = form.getElement("name");
    cout << "<span>Name: " << (name != form.getElements().end() ? (*name).getValue() : "Not provided") << "</span><br>";

    // Gender selection (radio button)
    const_form_iterator gender = form.getElement("gender");
    if (gender != form.getElements().end()) {
        cout << "<span>Gender: " << ((*gender).getValue() == "M" ? "M" : "F") << "</span><br>";
    } else {
        cout << "<span>Gender: Not provided</span>\n";
    }
    
    //Declared variable
    string ageValue=" ";
    int ageInt=-1;
    

    // Age input (number)
    const_form_iterator age = form.getElement("age");
      if(age != form.getElements().end()){          //If age is not empty it will proceed
        ageValue = (*age).getValue();
        
        //Use isInteger function
        if(isInteger(ageValue)){
        
        ageInt= stoi(ageValue);
        
          if(isValidAge(ageInt)) {
          
            cout << "<span>Age:" << ageValue << "</span><br>";
        } else{
            cout << "<span>Age:" << ageValue << "</span><br>";
            cout << "<span style='color:red;'>Error: Age must be between 1 and 99.</span><br>";
        }
        } else{
            cout << "<span>Age:" << ageValue << "</span><br>";
            cout << "<span style='color:red;'>Error: Age must be an integer.</span><br>";
          }
      }
    
    
    
    

    // Birthday input (date)
    // Current date (10/22/2023)
    int currentYear = 2023;
    int currentMonth = 10;
    int currentDay = 22;
    
    const_form_iterator birthday = form.getElement("birthday");
    
      if (birthday != form.getElements().end() && !(*birthday).getValue().empty()) {
        string birthdayString = (*birthday).getValue();
        
        int birthYear, birthMonth, birthDay;
        char dash1, dash2;
        
        // Parse the birthday
        stringstream ss(birthdayString);
        ss >> birthYear >> dash1 >> birthMonth >> dash2 >> birthDay;
        
        
        
         int calculatedAge = calculateAge(birthYear, birthMonth, birthDay, currentYear, currentMonth, currentDay);
        
          
         if (ageInt != calculatedAge) {
            cout << "<span>Birthday: " << (birthday != form.getElements().end() ? (*birthday).getValue() : "Not provided") << "</span><br>";
            cout << "<span style='color:red;'>Error: Your age should be (" << calculatedAge << "), NOT (" << ageInt << ").</span><br>";
            } else {
              cout << "<span>Birthday: " << (birthday != form.getElements().end() ? (*birthday).getValue() : "Not provided") << "</span><br>";
            }
                     

    // Courses (checkboxes)
    cout << "Courses Selected: ";
    cout << "<ul>";
    
    bool coursesSelected = false;
    if (form.getElement("CPS1231") != form.getElements().end()) {
        cout << "<li>CPS1231</li>";
        coursesSelected = true;
    }
    if (form.getElement("CPS2231") != form.getElements().end()) {
        cout << "<li>CPS2231</li> ";
        coursesSelected = true;
    }
    if (form.getElement("CPS2232") != form.getElements().end()) {
        cout << "<li>CPS2232</li> ";
        coursesSelected = true;
    }
    if (form.getElement("CPS3250") != form.getElements().end()) {
        cout << "<li>CPS3250</li> ";
        coursesSelected = true;
    }
    if (!coursesSelected) {
        cout << "None";
    }
    
    cout << "</ul>";
    
    
    // Township select box
    const_form_iterator town = form.getElement("town");
    cout << "<span>Township: " << (town != form.getElements().end() ? (*town).getValue() : "Not provided") << "</span><br>";

    // String input (my-data)
    const_form_iterator myData = form.getElement("mydata");
    
    string inputData=(myData != form.getElements().end() ? (*myData).getValue() : "Not provided");
    cout << "<span>String Input:" << inputData << "</span><br>";
    
    // Step 1: Count the frequency of each character in "my-data" input
    std::map<char, int> charCount;
    for (char c : inputData) {
        if (isalpha(c)) {  // To Only count alphabetic characters
            charCount[c]++;
        }
    }
    
    // Step 2: Start the HTML table for displaying characters and their counts
    cout << "<table border='1' cellpadding='2' cellspacing='0'>\n";
    cout << "<tr><th>ASCII #</th><th>Char</th><th>Count</th></tr>\n";
    
    for (auto it = charCount.begin(); it != charCount.end(); ++it) {
        cout << "<tr><td>" << it->first << "</td><td>" << int(it->first) << "</td><td>" << it->second << "</td></tr>\n";
    }

    cout << "</table>\n";
    
    
    // To track characters with max and min counts
    int maxCount = INT_MIN, minCount = INT_MAX;
    string maxChars, minChars;
    
    for (auto it = charCount.begin(); it != charCount.end(); ++it) {
        // Find the max count
        if (it->second > maxCount) {
            maxCount = it->second;
            maxChars = string(1, it->first);
        } else if (it->second == maxCount) {
            maxChars += " " + string(1, it->first);
        }
        
        // Find the min count
        if (it->second < minCount) {
            minCount = it->second;
            minChars = string(1, it->first);
        } else if (it->second == minCount) {
            minChars += " " + string(1, it->first);
        }
    }

    // Step 4: Print the character(s) with maximum count
    cout << "<span>Character: "<< maxChars << " has maximum count: " << maxCount << "</span><br>";

    // Step 5: Print the character(s) with minimum count
    cout << "<span>Character: "<< minChars << " has minimum count: " << minCount << "</span><br>";
    
    
    

    // End HTML response
    cout << "</body></html>" << endl;

    return 0;
}
}

