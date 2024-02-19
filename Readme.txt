The code is going to be a user console menu with submenus,

1. Compile the code in a Linux terminal preferably Ubuntu 18.04 (WSL) using the command: g++ -std=c++11 pizza.cpp -o pizza.out 
1a. You can also compile the code using any C++11 IDE Compiler if you are unable to compile from the terminal
2. Run the code in the Linux terminal as mentioned above using the ./pizza.out command 
2a. You can also run the code using any C++11 IDE if you are unable to compile from the terminal
3. The code is going to start with a user menu on the console that will have you decide whether to manage pizzas or toppings, you will also have the option to quit the program at any time. Unfortunately the data does not save when you quit the program, while the program is running the data will be saved, navigation through the menus shouldn't be an issue. 
4. The main menu will split into sub menus depending on your decision, the options will display what you can do and you choose the option based on your preference. 

Issues with the code I'm aware of:

User input is case sensitive. A work around this to allow case insensitivity hasn't been implemented unfortunately and is something to keep note of when testing the code. 

