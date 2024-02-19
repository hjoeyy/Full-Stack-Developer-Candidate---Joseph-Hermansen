#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
vector<string> list_of_toppings;
unordered_map<string, vector<string>> list_of_pizzas;
string topping;
string pizza_name;
string updated_pizza_name;
int choice;
string updated_topping;

void pizza_menu();
void toppings_menu();
void update_toppings_menu();



void display_toppings() { // function to display list of toppings
    cout << "Available Toppings: ";
    if(!list_of_toppings.empty()) {
        for(int i = 0; i < list_of_toppings.size(); i++) {
            if(i != list_of_toppings.size() - 1) {
                cout << list_of_toppings[i] << ", ";
            }else{
                cout << list_of_toppings[i];
            }
        }
        cout << endl;
        toppings_menu();
    }else{
        cout << "There are no toppings in the list!" << endl << endl;
        toppings_menu();
    }
}
void add_topping() { // function for adding a topping to the list
    cout << "Enter Name of Topping to Add: ";
    cin.ignore();
    getline(cin, topping);
    if(!list_of_toppings.empty()) {
        for(int i = 0; i < list_of_toppings.size(); i++) {
            if(find(list_of_toppings.begin(), list_of_toppings.end(), topping) != list_of_toppings.end()) {
                cout << "That Topping Already Exists! Please enter another topping." << endl << endl;
                break;
            }else{
                list_of_toppings.push_back(topping);
                cout << "Topping Successfully Added to List!" << endl << endl;
                break;
            }
        }
    }else{
        list_of_toppings.push_back(topping);
        cout << "Topping Successfully Added to List!" << endl << endl;
    }
    toppings_menu();
}
void delete_topping() { // function for deleting a topping from the list
    cout << "Enter Name of Topping to Delete: ";
    cin.ignore();
    getline(cin, topping);
    if(!list_of_toppings.empty()) {
        for(int i = 0; i < list_of_toppings.size(); i++) {
            if(find(list_of_toppings.begin(), list_of_toppings.end(), topping) == list_of_toppings.end()) {
                cout << "Topping Doesn't Exist!" << endl << endl;
                break;
            }else{
                if(list_of_toppings[i] == topping) {
                    list_of_toppings.erase(list_of_toppings.begin() + i);
                    cout << "Topping Successfully Deleted from List!" << endl << endl;
                    break;
                }
            }
        }
    }else{
        cout << "There are no toppings in the list!" << endl << endl;
    }
    toppings_menu();
}
void update_topping() { // function for updating a current topping in the list
    cout << "Enter Name of Topping to Update: ";
    cin.ignore();
    getline(cin, topping);
    cout << endl;
    cout << "Enter Name of Topping to Replace it with: ";
    getline(cin, updated_topping);

    if(!list_of_toppings.empty()) {
        for(int i = 0; i < list_of_toppings.size(); i++) {
            if(find(list_of_toppings.begin(), list_of_toppings.end(), topping) == list_of_toppings.end()) {
                cout << "Topping Doesn't Exist! Please enter another topping." << endl << endl;
                break;
            }else{
                if(find(list_of_toppings.begin(), list_of_toppings.end(), updated_topping) != list_of_toppings.end()) {
                    cout << "Topping Already Exists! Please choose another topping." << endl << endl;
                    break;
                }else{
                    if(list_of_toppings[i] == topping) {
                        list_of_toppings[i] = updated_topping;
                        cout << "Topping Successfully Updated!" << endl << endl;
                        break;
                    }
                }
            }
        }
    }else{
        cout << "There are no toppings in the list!" << endl << endl;
    }
    toppings_menu();
}
void display_pizzas() { // function to display list of pizzas and their toppings
    cout << "Available Pizzas: " << endl;
    if(!list_of_pizzas.empty()) {
        for(const auto& it : list_of_pizzas) {
            cout << "Pizza: " << it.first << "  Toppings: [ ";
            for(int i = 0; i < it.second.size(); i++) {
                if(i != it.second.size() - 1) {
                    cout << it.second[i] << ", ";
                }else{
                    cout << it.second[i];
                }
            }
            cout << " ]" << endl;
        }
        cout << endl;
        pizza_menu();
    }else{
        cout << "There are no Pizzas in the List!" << endl << endl;
        pizza_menu();
    }
}
void create_pizza() { // function to create a pizza and add toppings to it
    cout << "Enter Name of Pizza to Create: ";
    cin.ignore();
    getline(cin, pizza_name);
    if(!list_of_pizzas.empty()) {
        if(list_of_pizzas.find(pizza_name) != list_of_pizzas.end()) {
            cout << "That Pizza Already Exists!" << endl << endl;
        }else{
            do{
                cout << "Enter Name of Topping to Add (enter q to stop entering toppings): ";
                getline(cin, topping);
                if(!list_of_toppings.empty() && topping != "q") {
                    if(find(list_of_toppings.begin(), list_of_toppings.end(), topping) == list_of_toppings.end()) {
                        cout << "Topping isn't Available in Toppings List! Go to Manage Toppings to Add it!" << endl << endl;
                    }else{
                        list_of_pizzas[pizza_name].push_back(topping);
                        cout << "Topping Successfully Added to Pizza!" << endl << endl;
                    }
                }else if(topping != "q"){
                    cout << "Topping isn't Available in Toppings List! Go to Manage Toppings to Add it!" << endl << endl;
                }
            }while(topping != "q");
            cout << "Pizza Successfully Added to List!" << endl << endl;
        }
    }else{
        do {
            cout << "Enter Name of Topping to Add (enter q to stop entering toppings): ";
            getline(cin, topping);
            if(!list_of_toppings.empty() && topping != "q") {
                if(find(list_of_toppings.begin(), list_of_toppings.end(), topping) == list_of_toppings.end()) {
                    cout << "Topping isn't Available in Toppings List! Go to Manage Toppings to Add it!" << endl << endl;
                }else{
                    list_of_pizzas[pizza_name].push_back(topping);
                    cout << "Topping Successfully Added to Pizza!" << endl << endl;
                }
            }else if(topping != "q"){
                cout << "Topping isn't Available in Toppings List! Go to Manage Toppings to Add it!" << endl << endl;
            }
        }while(topping != "q");
        cout << "Pizza Successfully Added to List!" << endl << endl;
    }
    pizza_menu();
}
void delete_pizza() { // function to delete a pizza from the list
    cout << "Enter Name of Pizza to Delete: ";
    cin.ignore();
    getline(cin, pizza_name);
    if(!list_of_pizzas.empty()){
        if(list_of_pizzas.find(pizza_name) != list_of_pizzas.end()) {
            list_of_pizzas.erase(pizza_name);
            cout << "Pizza Successfully Deleted from List!" << endl << endl;
        }else{
            cout << "Pizza doesn't exist!" << endl << endl;
        }
    }else{
        cout << "There are No Pizzas in the List!" << endl << endl;
    }
    pizza_menu();
}
void update_pizza() { // function to update a current pizza in the list
    vector<string> temp_toppings;
    cout << "Enter Name of Pizza to Update: ";
    cin.ignore();
    getline(cin, pizza_name);
    cout << endl;
    cout << "Enter Name of Pizza to Replace it with: ";
    getline(cin, updated_pizza_name);

    if(!list_of_pizzas.empty()) {
        if(list_of_pizzas.find(pizza_name) == list_of_pizzas.end()) {
            cout << "Pizza Doesn't Exist!" << endl << endl;
        }
        else if(list_of_pizzas.find(updated_pizza_name) != list_of_pizzas.end()) {
            cout << "Pizza Already Exists! Please enter another Pizza." << endl << endl;
            update_pizza();
        }else{
            temp_toppings = list_of_pizzas.find(pizza_name)->second;
            list_of_pizzas.erase(pizza_name);
            list_of_pizzas.insert({updated_pizza_name, temp_toppings});
            cout << "Pizza Successfully Updated!" << endl << endl;
        }
    }else{
        cout << "There are no Pizzas in the List!" << endl << endl;
    }
    pizza_menu();
}
void add_toppings_to_current_pizza() {
    cout << "Enter Name of Pizza to Add Toppings to: ";
    cin.ignore();
    getline(cin, pizza_name);
    if(!list_of_pizzas.empty()) {
        if(list_of_pizzas.find(pizza_name) == list_of_pizzas.end()) {
            cout << "Pizza Doesn't Exist!" << endl << endl;
        }else{
            do {
                cout << "Enter Name of Topping to Add (press q to stop entering toppings): ";
                getline(cin, topping);
                if(!list_of_toppings.empty() && topping != "q") {
                    if(find(list_of_toppings.begin(), list_of_toppings.end(), topping) == list_of_toppings.end()) {
                        cout << "Topping isn't Available in Toppings List! Go to Manage Toppings to Add it!" << endl << endl;
                    }else{
                        list_of_pizzas.find(pizza_name)->second.push_back(topping);
                        cout << "Topping Successfully Added to Pizza!" << endl << endl;
                    }
                }
            }while(topping != "q");
        }
    }else{
        cout << "There are No Pizzas in the List!" << endl << endl;
    }
    update_toppings_menu();
}
void update_toppings_from_current_pizza() {
    vector<string> temp_toppings;
    cout << "Enter Name of Pizza to Update Toppings From: ";
    cin.ignore();
    getline(cin, pizza_name);
    if(!list_of_pizzas.empty()) {
        if(list_of_pizzas.find(pizza_name) == list_of_pizzas.end()) {
            cout << "Pizza Doesn't Exist!" << endl << endl;
        }else{
            do {
                cout << "Enter Name of Topping to Update (press q to stop entering toppings): ";
                getline(cin, topping);
                cout << "Enter Name of Topping to Replace it with (press q to stop entering toppings): ";\
                getline(cin, updated_topping);
                if (!list_of_toppings.empty() && updated_topping != "q") {
                    if (find(list_of_toppings.begin(), list_of_toppings.end(), updated_topping) ==
                        list_of_toppings.end()) {
                        cout << "Topping isn't Available in Toppings List! Go to Manage Toppings to Add it!" << endl
                             << endl;
                    } else {
                        temp_toppings = list_of_pizzas.find(pizza_name)->second;
                        for (int i = 0; i < temp_toppings.size(); i++) {
                            if(find(temp_toppings.begin(), temp_toppings.end(), topping) == temp_toppings.end()) {
                                cout << "Topping Doesn't Exist in Current Pizza!" << endl << endl;
                                break;
                            }
                            else if (temp_toppings[i] == topping) {
                                temp_toppings[i] = updated_topping;
                                list_of_pizzas.find(pizza_name)->second = temp_toppings;
                                cout << "Topping Successfully Updated!" << endl << endl;
                                break;
                            }
                        }
                    }
                }
            }while(topping != "q" && updated_topping != "q");
        }
    }else{
        cout << "There are No Pizzas in the List!" << endl << endl;
    }
    update_toppings_menu();
}
void delete_toppings_from_current_pizza() {
    vector<string> temp_toppings;
    cout << "Enter Name of Pizza to Delete Toppings From: ";
    cin.ignore();
    getline(cin, pizza_name);
    if(!list_of_pizzas.empty()) {
        if(list_of_pizzas.find(pizza_name) == list_of_pizzas.end()) {
            cout << "Pizza Doesn't Exist!" << endl << endl;
        }else{
            do {
                cout << "Enter Name of Topping to Delete (press q to stop entering toppings): ";
                getline(cin, topping);
                if(!list_of_toppings.empty() && topping != "q") {
                    if(find(list_of_toppings.begin(), list_of_toppings.end(), topping) == list_of_toppings.end()) {
                        cout << "Topping isn't Available in Toppings List! Go to Manage Toppings to Add it!" << endl << endl;
                    }else{
                        temp_toppings = list_of_pizzas.find(pizza_name)->second;
                        for(int i = 0; i < temp_toppings.size(); i++) {
                            if(temp_toppings[i] == topping) {
                                temp_toppings.erase(temp_toppings.begin() + i);
                            }
                        }
                        list_of_pizzas.find(pizza_name)->second = temp_toppings;
                        cout << "Topping Successfully Deleted From Pizza!" << endl << endl;
                    }
                }
            }while(topping != "q");
        }
    }else{
        cout << "There are No Pizzas in the List!" << endl << endl;
    }
    update_toppings_menu();
}
void update_toppings_menu() {
    cout << "Update Toppings on Current Pizza Menu" << endl;
    cout << "1. Add a Topping to a Current Pizza" << endl;
    cout << "2. Update a Current Topping from a Current Pizza" << endl;
    cout << "3. Delete a Current Topping from a Current Pizza" << endl;
    cout << "4. Return to Pizza Menu" << endl;
    cout << "Enter Choice: ";
    for(;;){
        if(cin >> choice) {
            break;
        }else{
            cerr << "Wrong Input!" << endl << endl;
            cin.clear();
            cin.ignore();
            pizza_menu();
        }
    }
    switch(choice) {
        case 1:
            add_toppings_to_current_pizza();
        case 2:
            update_toppings_from_current_pizza();
        case 3:
            delete_toppings_from_current_pizza();
        case 4:
            pizza_menu();
        default:
            cout << "Not a valid choice. Please try again." << endl << endl;
            update_toppings_menu();
    }
}
void main_menu() {
    cout << "Would you like to manage pizzas or toppings?" << endl;
    cout << "1. Manage Pizzas" << endl;
    cout << "2. Manage Toppings" << endl;
    cout << "3. Quit Program" << endl;
    cout << "Enter choice: ";
    for(;;){
        if(cin >> choice) {
            break;
        }else{
            cerr << "Wrong Input!" << endl << endl;
            cin.clear();
            cin.ignore();
            main_menu();
        }
    }
    switch (choice) {
        case 1:
            pizza_menu();
            break;
        case 2:
            toppings_menu();
            break;
        case 3:
            exit(0);
        default:
            cout << "Not a valid choice. Please try again." << endl << endl;
            main_menu();
    }
}
void toppings_menu() { // function for toppings menu
    cout << "Toppings Menu" << endl;
    cout << "1. See List of Available Toppings" << endl;
    cout << "2. Add a Topping" << endl;
    cout << "3. Delete a Topping" << endl;
    cout << "4. Update an Existing Topping" << endl;
    cout << "5. Quit Program" << endl;
    cout << "6. Return to Main Menu" << endl;
    cout << "Enter a choice: ";
    for(;;){
        if(cin >> choice) {
            break;
        }else{
            cerr << "Wrong Input!" << endl << endl;
            cin.clear();
            cin.ignore();
            toppings_menu();
        }
    }
    switch (choice) {
        case 1:
            display_toppings();
        case 2:
            add_topping();
        case 3:
            delete_topping();
        case 4:
            update_topping();
        case 5:
            exit(0);
        case 6:
            main_menu();
        default:
            cout << "Not a valid choice. Please try again." << endl << endl;
            toppings_menu();
    }
}
void pizza_menu() { // function for pizza menu
    cout << "Pizza Menu" << endl;
    cout << "1. See list of Current Pizzas" << endl;
    cout << "2. Create a New Pizza" << endl;
    cout << "3. Delete an Existing Pizza" << endl;
    cout << "4. Update an Existing Pizza" << endl;
    cout << "5. Update Toppings on an Existing Pizza" << endl;
    cout << "6. Quit Program" << endl;
    cout << "7. Return to Main Menu" << endl;
    cout << "Enter a choice: ";
    for(;;){
        if(cin >> choice) {
            break;
        }else{
            cerr << "Wrong Input!" << endl << endl;
            cin.clear();
            cin.ignore();
            pizza_menu();
        }
    }
    switch (choice) {
        case 1:
            display_pizzas();
        case 2:
            create_pizza();
        case 3:
            delete_pizza();
        case 4:
            update_pizza();
        case 5:
            update_toppings_menu();
        case 6:
            exit(0);
        case 7:
            main_menu();
        default:
            cout << "Not a valid choice. Please try again." << endl << endl;
            pizza_menu();
    }
}
int main() {
    main_menu();
    return 0;
}
