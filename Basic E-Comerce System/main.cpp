#include <iostream>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    double price;
};

Product inventory[100];
int inventoryCount = 0;

Product* getProductById(int id) {
    for (int i = 0; i < inventoryCount; i++) {
        if (inventory[i].id == id)
            return &inventory[i];
    }
    return nullptr;
}

int main() {
    int userChoice = -1;
    int cart[100];
    int cartSize = 0;

    cout << "Greetings!" << endl;
    cout << "Welcome to Dream Mart" << endl;

    while (userChoice != 0) {
        cout << "\nPlease choose an option:\n";
        cout << "1. View Products\n";
        cout << "2. Add to Cart\n";
        cout << "3. View Cart\n";
        cout << "4. Checkout\n";
        cout << "5. Admin - Add Product\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                if (inventoryCount == 0) {
                    cout << "No products available right now.\n";
                } else {
                    cout << "\n--- Product List ---\n";
                    for (int i = 0; i < inventoryCount; i++) {
                        cout << inventory[i].id << ". " << inventory[i].name << " - R." << inventory[i].price << "\n";
                    }
                }
                break;

            case 2: {
                int selectedId;
                cout << "Enter Product ID to add to cart: ";
                cin >> selectedId;
                Product* selectedProduct = getProductById(selectedId);
                if (selectedProduct != nullptr) {
                    cart[cartSize++] = selectedId;
                    cout << selectedProduct->name << " added to cart.\n";
                } else {
                    cout << "Invalid Product ID.\n";
                }
                break;
            }

            case 3: {
                if (cartSize == 0) {
                    cout << "Your cart is empty.\n";
                } else {
                    cout << "\n--- Your Cart ---\n";
                    double total = 0;
                    for (int i = 0; i < cartSize; i++) {
                        Product* product = getProductById(cart[i]);
                        if (product != nullptr) {
                            cout << product->name << " - R." << product->price << "\n";
                            total += product->price;
                        }
                    }
                    cout << "Total: R." << total << "\n";
                }
                break;
            }

            case 4: {
                if (cartSize == 0) {
                    cout << "Your cart is empty. Nothing to checkout.\n";
                } else {
                    double total = 0;
                    for (int i = 0; i < cartSize; i++) {
                        Product* product = getProductById(cart[i]);
                        if (product != nullptr) {
                            total += product->price;
                        }
                    }
                    cout << "Total Amount Due: R." << total << "\n";
                    cout << "Thank you for shopping with us.\n";
                    cartSize = 0;
                }
                break;
            }

            case 5: {
                Product newProduct;
                newProduct.id = inventoryCount + 1;
                cout << "Enter product name: ";
                cin.ignore(); 
                getline(cin, newProduct.name);
                cout << "Enter product price: ";
                cin >> newProduct.price;
                inventory[inventoryCount++] = newProduct;
                cout << "Product added successfully.\n";
                break;
            }

            case 0:
                cout << "Thank you for visiting Dream Mart. See you soon.\n";
                break;

            default:
                cout << "Invalid option. Please select from the menu.\n";
                break;
        }
    }

    return 0;
}
