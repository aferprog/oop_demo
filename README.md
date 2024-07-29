# OOP Model of Shop

## Description

This project represents an object-oriented programming (OOP) model of a store, which includes both online and offline shops. All products are derived classes of the `Product` class. Each product can be configured to be sold either online or offline. The `SellCenter` class manages the distribution of products to online and/or offline shops based on the product's configuration.

## Technologies

- Virtual inheritance
- Diamond inheritance
- Dispatcher OOP pattern

## Demonstration
First step is a SellCenter configuring 
```
How many online sell-nodes: 3
Enter URL of your online sell-node 1: shop1.com
Enter URL of your online sell-node 2: shop2.com
Enter URL of your online sell-node 3: shop3.com
How many offline sell-nodes: 2
Enter ADDRESS of your offline shop 1: street of shop 121
Enter ADDRESS of your offline shop 2: other address 71
```
Then you can sell any count of products with this object. You have to specify it by a number.
```
Type of object (1 - knife, 2 - screwdriver, 3 - mutitool, 0 - end program): 1
```
After this it's needed to specify product configs: name, price and sell statuses: selling online, offline or both.
```
Enter the name of Knife: super knife
Enter the price of Knife (integer): 130
Sell it online? (Y/N): y
Sell it offline? (Y/N): n
```
Then you can choose if you want to use it before selling.
```
Try to use it? (Y/N): y
```
Result is:
```
I cut bread
An advertisement about 'super knife' was published on 'shop2.com' price 130
An advertisement about 'super knife' was published on 'shop3.com' price 130
An advertisement about 'super knife' was published on 'shop1.com' price 130
```
After that we can sell one more tool any number of times until we write 0.
```
Type of object (1 - knife, 2 - screwdriver, 3 - multitool, 0 - end program): 2
Enter the name of Screwdriver: good screwdriver
Enter the price of Screwdriver (integer): 200
Sell it online? (Y/N): n
Sell it offline? (Y/N): y
Try to use? (Y/N): y
I tight the bolts
The product 'good screwdriver' was directed to 'street of shop 121' with price 200
The product 'good screwdriver' was directed to 'other address 71' with price 200
Type of object (1 - knife, 2 - screwdriver, 3 - multitool, 0 - end program): 3
Enter the name of Multitool: best multi
Enter the price of Multitool (integer): 504
Sell it online? (Y/N): y
Sell it offline? (Y/N): n
Try to use? (Y/N): y
How to use multitool (1 - knife, 2 - screwdriver, other - all together)?: 2
I tight the bolts
An advertisement about 'best multi' was published on 'shop2.com' price 504
An advertisement about 'best multi' was published on 'shop3.com' price 504
An advertisement about 'best multi' was published on 'shop1.com' price 504
Type of object (1 - knife, 2 - screwdriver, 3 - multitool, 0 - end program): 0
```
