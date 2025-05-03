# CPS 3525 Project 1 – CGI Web Form with C++ (GET Method)

## 🔍 Project Overview

This project is part of **CPS 3525 - Internet Programming** and demonstrates the use of **C++** with **CGI** to process an HTML web form using the **GET** method. The application was hosted and tested on the [OBI server](https://yoda.kean.edu/cgi-bin/) provided by Kean University.

The web form takes user input and sends it to a C++ backend, which performs input validation, string analysis, and displays meaningful output or error messages directly in the browser.

---

## 🌐 Features

- HTML form with the following inputs:
  - Text input for **Name** (`name`)
  - Radio buttons for **Gender** (`gender`) – options: `M` or `F`
  - Number input for **Age** (`age`) – must be integer between 1–99
  - Calendar input for **Birthday** (`birthday`)
  - Four checkboxes for courses (`CPS1231`, `CPS2231`, `CPS2232`, `CPS3250`)
  - Dropdown for **Town** (`town`) – options: Union, Newark, Edison, Harrison
  - Text input for **String Analysis** (`mydata`)
- Server-side processing in **C++**
- Input validation with user-friendly error messages in red
- Output includes:
  - Display of all entered values
  - Character frequency analysis (ASCII sorted)
  - Detection of characters with max and min frequency
  - Age cross-check from birthday against entered age
- All output and errors rendered in one page

---

## 💻 How to Run (on OBI Server)

1. Upload all source files to the `cgi-bin/CPS3525/` directory of your OBI server space via SFTP.
2. Ensure that the C++ file is compiled for CGI:
   ```bash
   g++ -o project1.cgi project1.cpp
   chmod 755 project1.cgi
