# Thinnavara Restaurant Management System

A command-line based restaurant management system for ordering food and generating bills.

## Features

- Interactive menu exploration
- Cart management
- Real-time order processing
- Automated bill generation with tax calculations
- Admin access for receipt viewing

## Directory Structure

```
nikhil-gorasa-online-food-ordering-and-billing-system/
├── appetizers.txt          # Contains appetizer menu items and prices
├── beverages.txt          # Contains beverage menu items and prices
├── breads.txt            # Contains bread menu items and prices
├── desserts.txt          # Contains dessert menu items and prices
├── forb.c                # Main program file (Food Ordering and Billing System)
├── main_courses.txt      # Contains main course menu items and prices
├── Pasta&Rice.txt        # Contains pasta and rice dishes with prices
├── receipt.txt          # Stores transaction receipts
└── soups&salads.txt     # Contains soups and salads menu items and prices
```

## Menu Categories

1. **Appetizers**: Starters and snacks (₹20 - ₹250)
2. **Soups & Salads**: Healthy options (₹70 - ₹150)
3. **Main Courses**: Primary dishes (₹150 - ₹300)
4. **Pasta & Rice**: Various rice preparations (₹120 - ₹280)
5. **Breads**: Indian breads (₹20 - ₹80)
6. **Desserts**: Sweet dishes (₹50 - ₹130)
7. **Beverages**: Drinks selection (₹40 - ₹120)

## System Features

### For Customers
- Browse complete menu by categories
- Add multiple items to cart
- Specify quantities for each item
- View running total while ordering
- Get detailed bill with tax breakdown

### For Admin
- Access admin panel using '@' key
- View all transaction receipts
- Monitor sales history

## Bill Generation Details

The system automatically calculates:
- Subtotal of all items
- 20% discount on subtotal
- CGST (7%) on net total
- SGST (5%) on net total
- Final grand total

## Technical Requirements

- C compiler (GCC recommended)
- Windows operating system
- Standard C libraries:
  - stdio.h
  - string.h
  - stdlib.h
  - time.h
  - windows.h
  - conio.h

## How to Run

1. Compile the program:
   ```bash
   gcc forb.c -o restaurant
   ```

2. Run the executable:
   ```bash
   ./restaurant
   ```

3. Follow the on-screen prompts to:
   - Enter your name
   - Explore menu
   - Place orders
   - Complete checkout

## Admin Access

To access admin features:
1. Press '@' at the welcome screen
2. View all transaction receipts

## File Format

All menu files follow the format:
```
Item_Name,Price
```

Example:
```
Samosa,20
Paneer Tikka,180
```

## Example Order & Bill

Here's what your dining experience looks like at Thinnavara Restaurant! 🍽️

### Sample Order
```
🥘 Delicious Items in Cart:
1. Butter Chicken (2x) - The classic creamy curry
2. Garlic Naan (3x) - Fresh from the tandoor
3. Mango Lassi (2x) - Sweet and refreshing
4. Gulab Jamun (4x) - Heavenly dessert
```

### Generated Bill
```
       THINNAVARA Restaurant
         -----------------
Date: Wed Mar 13 15:30:45 2024
Name: Rahul Sharma

---------------------------------------
Items[4]           Qty      Total
---------------------------------------
Butter Chicken      2    Rs. 500.00
Garlic Naan         3    Rs. 180.00
Mango Lassi         2    Rs. 200.00
Gulab Jamun         4    Rs. 320.00
---------------------------------------
Sub Total                Rs. 1200.00
Discount @20%           Rs.  240.00
                        ----------
Net Total               Rs.  960.00
CGST @7%               Rs.   67.20
SGST @5%               Rs.   48.00
---------------------------------------
Grand Total            Rs. 1075.20
---------------------------------------

🎉 Thank you for dining with us! 
Come back soon! 😊
```

### Special Features Showcase

1. **Real-time Cart Updates** 🛒
   ```
   Adding "Butter Chicken" of QTY:2 with ID:1...
   NUMBER OF ITEMS IN YOUR CART: 1    CART VALUE: 500.00
   ```

2. **Interactive Menu Navigation** 📋
   ```
   WE HAVE 7 CATEGORIES AVAILABLE
   1. 🥘 APPETIZERS
   2. 🥗 SOUPS AND SALADS
   3. 🍛 MAIN COURSE
   4. 🍚 PASTA AND RICE DISHES
   5. 🫓 BREADS
   6. 🍨 DESSERTS
   7. 🥤 BEVERAGES
   8. ⬅️ BACK
   YOUR CHOICE : _
   ```

3. **Admin Dashboard Preview** 👨‍💼
   ```
   WELCOME ADMIN! 
   ---------------RECEIPTS----------------
   Today's Sales: ₹15,750
   Total Orders: 12
   Popular Items:
   1. Butter Chicken (15 orders)
   2. Garlic Naan (25 orders)
   3. Mango Lassi (18 orders)
   ```

## Note

- All prices are in Indian Rupees (₹)
- The system supports multiple items per order
- Real-time cart updates and price calculations
- Automated receipt generation and storage
- 🌶️ Spice levels can be customized on request
- 🥬 Vegetarian options available in all categories
- 🕐 Average order processing time: 2-3 minutes


-Nikhil Gorasa
