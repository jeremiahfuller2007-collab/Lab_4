#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // Variables
    string foodName;
    char itemCode;
    char memberChoice;
    int quantity;
    double unitPrice;
    double subtotal;
    double discount = 0.0;
    double tax;
    double total;
    bool isMember = false;

    // Get purchase information
    cout << "Enter food name: ";
    getline(cin, foodName);

    cout << "Enter item code: ";
    cin >> itemCode;

    cout << "Enter quantity: ";
    cin >> quantity;

    cout << "Enter unit price: $";
    cin >> unitPrice;

    cout << "Member? (y/n): ";
    cin >> memberChoice;

    // Determine membership
    if (memberChoice == 'y' || memberChoice == 'Y') {
        isMember = true;
    }

    // Calculate subtotal
    subtotal = quantity * unitPrice;

    // Apply 10% member discount
    if (isMember) {
        discount = subtotal * 0.10;
    }

    double discountedSubtotal = subtotal - discount;

    // Calculate 8% tax
    tax = discountedSubtotal * 0.08;
    total = discountedSubtotal + tax;

    // Clear leftover newline before getline()
    cin.ignore();


    // Receipt
    cout << "\n========================================\n";
    cout << "              COFFEE SHOP\n";
    cout << "========================================\n";

    cout << left << setw(20) << "Food:"
         << right << setw(15) << foodName << endl;

    cout << left << setw(20) << "Item Code:"
         << right << setw(15) << itemCode << endl;

    cout << left << setw(20) << "Quantity:"
         << right << setw(15) << quantity << endl;

    cout << left << setw(20) << "Unit Price:"
         << right << setw(15) << fixed << setprecision(2)
         << unitPrice << endl;

    cout << left << setw(20) << "Subtotal:"
         << right << setw(15) << subtotal << endl;

    cout << left << setw(20) << "Member Discount:"
         << right << setw(15) << discount << endl;

    cout << left << setw(20) << "Tax:"
         << right << setw(15) << tax << endl;

    cout << left << setw(20) << "Total:"
         << right << setw(15) << total << endl;

    cout << "========================================\n";

    // Inventory Audit
    cout << "\n              INVENTORY AUDIT\n";
    cout << "========================================\n";

    cout << left << setw(15) << "Code"
         << setw(20) << "Item"
         << right << setw(10) << "Quantity"         << setw(12) << "Price" << endl;

    cout << left << setw(15) << itemCode
         << setw(20) << foodName
         << right << setw(10) << quantity
         << setw(12) << fixed << setprecision(2) << unitPrice
         << endl;

    cout << "========================================\n";

    return 0;
}