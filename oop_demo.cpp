#include <iostream>
#include <string>
#include <memory>
#include <set>
using namespace std;

// Product definitions:
class Product {
protected:
    string name;
    int price;
    bool onlineStatus = false, offlineStatus = false;
public:
    Product(string name, int price) {
        this->name = name;
        this->price = price;
    }
    string getName() const{
        return name;
    }
    int getPrice() const {
        return price;
    }
    void setOnlineStatus(bool stat) {
        onlineStatus = stat;
    }
    void setOfflineStatus(bool stat) {
        offlineStatus = stat;
    }
    bool getOnlineStatus() const{
        return onlineStatus;
    }
    bool getOfflineStatus() const {
        return offlineStatus;
    }
    void virtual work() = 0;
    virtual ~Product() = default;
};

class Knife : public virtual Product {
public:
    Knife(string name, int price) : Product(name, price) {}
    void work() override {
        std::cout << "I cut bread" << endl;
    }
};
class Screwdriver : public virtual Product {
public:
    Screwdriver(string name, int price) : Product(name, price) {}
    void work() override {
        std::cout << "I tight the bolts" << endl;
    }
};

class MultiTool : public Knife, public Screwdriver{
public:
    MultiTool(string name, int price)
        : Knife(name, price),
        Screwdriver(name, price),
        Product(name, price) {}
    void work() override {
        cout << "How to use multitool (1 - knife, 2 - screwdriver, other - all together)?: ";
        int type;
        cin >> type;
        if (type == 1) {
            cout << "I cut the bread" << endl;
            return;
        }
        if (type == 2) {
            cout << "I tight the bolts" << endl;
            return;
        }
        cout << "Show knife and screwdriver" << endl;
    }
};

// Products selling:
class Shop {
public:
    void virtual sell(const shared_ptr<Product> prod) = 0;
    virtual ~Shop() = default;
};

class OnlineShop : public Shop {
private:
    string url;
public:
    OnlineShop(string url) {
        this->url = url;
    }
    void sell(const shared_ptr<Product> prod) override {
        cout << "An advertisement about '" << prod->getName() << "' was published on '" << url << "' price " << prod->getPrice() << endl;
    }
};

class OfflineShop : public Shop {
private:
    string address;
public:
    OfflineShop(string address) {
        this->address = address;
    }
    void sell(const shared_ptr<Product> prod) override{
            cout << "The product '" << prod->getName() << "' was directed to '" << address<< "' with price " << prod->getPrice() << endl;
    }
};

class SellCenter {
private:
    set<shared_ptr<OnlineShop>> onlineShops;
    set <shared_ptr<OfflineShop>> offlineShops;
public:
    void addOnlineShop(shared_ptr<OnlineShop> shop) {
        onlineShops.insert(shop);
    }
    void addOfflineShop(shared_ptr<OfflineShop> shop) {
        offlineShops.insert(shop);
    }
    void sell(shared_ptr<Product> prod) {
        if (prod->getOnlineStatus())
            for (auto& shop: onlineShops)
                shop->sell(prod);

        if (prod->getOfflineStatus()) 
            for (auto& shop : offlineShops)
                shop->sell(prod);
    }
};

istream& operator>>(istream& in, SellCenter& cen) {
    int n;
    cout << "How many online sell-nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string url;
        printf("Enter URL of your online sell-node %i: ", i+1);
        cin >> url;
        cen.addOnlineShop(make_shared<OnlineShop>(url));
    }
    cout << "How many offline sell-nodes: ";
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string address;
        printf("Enter ADDRESS of your offline shop %i: ", i+1);
        getline(cin, address);
        cen.addOfflineShop(make_shared<OfflineShop>(address));
    }
    return in;
}

enum ProductType {
    KNIFE=1,
    SCREWDRIVER,
    MULTITOOL
};


int main()
{
    SellCenter sellcenter;
    cin >> sellcenter;
    while (true) {
        cout << "Type of object (1 - knife, 2 - screwdriver, 3 - mutlitool, 0 - end program): ";
        int type;
        cin >> type;
        getchar();
        switch (type)
        {
        case ProductType::KNIFE : {
            string name;
            int price;
            cout << "Enter the name of Knife: ";
            getline(cin, name);
            cout << "Enter the price of Knife (integer): ";
            cin >> price; 
            getchar();
            shared_ptr<Knife> a = make_shared<Knife>(name, price);
            char x;
            cout << "Sell it online? (Y/N): ";
            cin >> x;
            getchar();
            if (x == 'Y' || x == 'y') a->setOnlineStatus(true);
            cout << "Sell it offline? (Y/N): ";
            cin >> x;
            getchar();
            if (x == 'Y' || x == 'y') a->setOfflineStatus(true);

            cout << "Try to use? (Y/N): ";
            cin >> x;
            getchar();
            if (x == 'Y' || x == 'y') a->work();
            sellcenter.sell(a);
            break;
        };
        case ProductType::SCREWDRIVER: {
            string name;
            int price;
            cout << "Enter the name of Screwdriver: ";
            getline(cin, name);
            cout << "Enter the price of Screwdriver (integer): ";
            cin >> price;
            getchar();
            shared_ptr<Screwdriver> a = make_shared<Screwdriver>(name, price);
            char x;
            cout << "Sell it online? (Y/N): ";
            cin >> x;
            getchar();
            if (x == 'Y' || x == 'y') a->setOnlineStatus(true);
            cout << "Sell it offline? (Y/N): ";
            cin >> x;
            getchar();
            if (x == 'Y' || x == 'y') a->setOfflineStatus(true);

            cout << "Try to use? (Y/N): ";
            cin >> x;
            getchar();
            if (x == 'Y' || x == 'y') a->work();
            sellcenter.sell(a);
            break;
        };
        case ProductType::MULTITOOL:
            string name;
            int price;
            cout << "Enter the name of Multitool: ";
            getline(cin, name);
            cout << "Enter the price of Multitool (integer): ";
            cin >> price;
            getchar();
            shared_ptr<MultiTool> a = make_shared<MultiTool>(name, price);
            char x;
            cout << "Sell it online? (Y/N): ";
            cin >> x;
            getchar();
            if (x == 'Y' || x == 'y') a->Product::setOnlineStatus(true);
            cout << "Sell it offline? (Y/N): ";
            cin >> x;
            getchar();
            if (x == 'Y' || x == 'y') a->Product::setOfflineStatus(true);

            cout << "Try to use? (Y/N): ";
            cin >> x;
            getchar();
            if (x == 'Y' || x == 'y') a->work();
            sellcenter.sell(a);
            break;
        }
        if (type == 0) break;
    }
}
