#include <iostream>
#include <string>

//=====================================================
// Base Class: GroceryItem
//=====================================================
class GroceryItem{
protected:
    std::string *name;
    double price;
    int quantity;

public:
    // Constructor
    GroceryItem(std::string n = "", double p = 0.0, int q = 0){
        name = new std::string(n);
        price = p;
        quantity = q;
    }

    // Destructor
    virtual ~GroceryItem(){
        delete name;
    }

    // Copy Constructor
    GroceryItem(const GroceryItem &other){
        name = new std::string(*other.name);
        price = other.price;
        quantity = other.quantity;
    }

    // Copy Assignment Operator
    GroceryItem& operator=(const GroceryItem &other){
        if (this != &other){
            delete name;
            name = new std::string(*other.name);
            price = other.price;
            quantity = other.quantity;
        }

        return *this;
    }

    // Calculate subtotal
    double calculateSum() const{
        return price * quantity;
    }

    double getSum() const{
        return calculateSum();
    }

    std::string getName() const{
        return *name;
    }

    // Pure Virtual Functions
    virtual void display() const = 0;
    virtual std::string getType() const = 0;
};

//=====================================================
// Fruit Class
//=====================================================
class Fruit : public GroceryItem{
public:
    // Constructor
    Fruit(std::string n = "", double p = 0.0, int q = 0)
        : GroceryItem(n, p, q){
    }

    // Copy Constructor
    Fruit(const Fruit &other)
        : GroceryItem(other){
    }

    // Copy Assignment Operator
    Fruit& operator=(const Fruit &other){
        if (this != &other){
            GroceryItem::operator=(other);
        }

        return *this;
    }

    void display() const{
        std::cout << "Type      : Fruit" << std::endl;
        std::cout << "Name      : " << *name << std::endl;
        std::cout << "Price     : PHP " << price << std::endl;
        std::cout << "Quantity  : " << quantity << std::endl;
        std::cout << "Subtotal  : PHP " << calculateSum() << std::endl;
        std::cout << "----------------------------------------"
                  << std::endl;
    }

    std::string getType() const{
        return "Fruit";
    }
};

//=====================================================
// Vegetable Class
//=====================================================
class Vegetable : public GroceryItem{
public:
    // Constructor
    Vegetable(std::string n = "", double p = 0.0, int q = 0)
        : GroceryItem(n, p, q){
    }

    // Copy Constructor
    Vegetable(const Vegetable &other)
        : GroceryItem(other){
    }

    // Copy Assignment Operator
    Vegetable& operator=(const Vegetable &other){
        if (this != &other)
        {
            GroceryItem::operator=(other);
        }

        return *this;
    }

    void display() const{
        std::cout << "Type      : Vegetable" << std::endl;
        std::cout << "Name      : " << *name << std::endl;
        std::cout << "Price     : PHP " << price << std::endl;
        std::cout << "Quantity  : " << quantity << std::endl;
        std::cout << "Subtotal  : PHP " << calculateSum() << std::endl;
        std::cout << "----------------------------------------"
                  << std::endl;
    }

    std::string getType() const{
        return "Vegetable";
    }
};

//=====================================================
// TotalSum Function
//=====================================================
double TotalSum(GroceryItem *GroceryList[], int size){
    double total = 0.0;

    for (int i = 0; i < size; i++){
        if (GroceryList[i] != NULL){
            total += GroceryList[i]->getSum();
        }
    }

    return total;
}

//=====================================================
// Main Function
//=====================================================
int main(){
    const int SIZE = 4;

    // Dynamic Memory Allocation
    GroceryItem *GroceryList[SIZE];

    GroceryList[0] = new Fruit("Apple", 10, 7);
    GroceryList[1] = new Fruit("Banana", 10, 8);
    GroceryList[2] = new Vegetable("Broccoli", 60, 12);
    GroceryList[3] = new Vegetable("Lettuce", 50, 10);

    std::cout << "==========================================" << std::endl;
    std::cout << "         JENNA'S GROCERY LIST" << std::endl;
    std::cout << "==========================================" << std::endl;

    // Display all grocery items
    for (int i = 0; i < SIZE; i++){
        GroceryList[i]->display();
    }

    // Display Total Amount
    std::cout << "==========================================" << std::endl;
    std::cout << "Total Amount : PHP " << TotalSum(GroceryList, SIZE) << ".00" << std::endl;
    std::cout << "==========================================" << std::endl;

    // Remove Lettuce
    std::cout << "Removing Lettuce from the Grocery List..." << std::endl;

    delete GroceryList[3];
    GroceryList[3] = NULL;

    // Display Updated Grocery List
    std::cout << "==========================================" << std::endl;
    std::cout << "       UPDATED GROCERY LIST" << std::endl;
    std::cout << "==========================================" << std::endl;

    for (int i = 0; i < SIZE; i++){
        if (GroceryList[i] != NULL){
            GroceryList[i]->display();
        }
    }

    // Display Updated Total
    std::cout << "==========================================" << std::endl;
    std::cout << "Updated Total Amount : PHP " << TotalSum(GroceryList, SIZE) << ".00" << std::endl;
    std::cout << "==========================================" << std::endl;
    
    //=====================================================
    // Free Remaining Dynamically Allocated Memory
    //=====================================================
    for (int i = 0; i < SIZE; i++){
        if (GroceryList[i] != NULL){
            delete GroceryList[i];
            GroceryList[i] = NULL;
        }
    }

    std::cout << "All remaining grocery items have been deleted." << std::endl;
    std::cout << "Program terminated successfully." << std::endl;

    return 0;
}
              
