Search:

================Search Test:
Enter 731:
Please enter the SKU: 731
        SKU: 731
       Name: Allen's Apple Juice
      Price: 1.79
   Quantity: 100
Minimum Qty: 10
   Is Taxed: Yes
Enter 222:
Please enter the SKU: 222
Item not found!


Update:

================Update Test:
Enter the follwoing:
         SKU: 111
        Name: Grape
      Price : 22.22
   Quantity : 22
Minimum Qty : 2
   Is Taxed : y
Overwrite old data? (Y)es/(N)o: n
Enter new data:
        SKU: 111
       Name: Grape
      Price: 22.22
   Quantity: 22
Minimum Qty: 2
   Is Taxed: y
Overwrite old data? (Y)es/(N)o: n
--== Aborted! ==--
Unchanged Item Data:
        SKU: 111
       Name: Ones!
      Price: 11.11
   Quantity: 11
Minimum Qty: 1
   Is Taxed: Yes
Enter the follwoing:
         SKU: 111
        Name: Grape
      Price : 22.22
   Quantity : 22
Minimum Qty : 2
   Is Taxed : y
Overwrite old data? (Y)es/(N)o: y
Enter new data:
        SKU: 111
       Name: Grape
      Price: 22.22
   Quantity: 22
Minimum Qty: 2
   Is Taxed: y
Overwrite old data? (Y)es/(N)o: y
--== Updated! ==--
Updated Item:
        SKU: 111
       Name: Grape
      Price: 22.22
   Quantity: 22
Minimum Qty: 2
   Is Taxed: Yes

Add Test:
================Add Test:
Total items in Storage: 20, Max no: 21
Enter the follwoing:
         SKU: 222
        Name: Grape
      Price : 22.22
   Quantity : 22
Minimum Qty : 2
   Is Taxed : y
Add Item? (Y)es/(N)o: n
        SKU: 222
       Name: Grape
      Price: 22.22
   Quantity: 22
Minimum Qty: 2
   Is Taxed: y
Add Item? (Y)es/(N)o: n
--== Aborted! ==--
Garbage here! Nothing is added, No of items in storage: 20
        SKU: 0
       Name:
      Price: 0.00
   Quantity: 0
Minimum Qty: 0
   Is Taxed: No
WARNING: Quantity low, please order ASAP!!!
Enter the follwoing:
         SKU: 222
        Name: Grape
      Price : 22.22
   Quantity : 22
Minimum Qty : 2
   Is Taxed : y
Add Item? (Y)es/(N)o: y
        SKU: 222
       Name: Grape
      Price: 22.22
   Quantity: 22
Minimum Qty: 2
   Is Taxed: y
Add Item? (Y)es/(N)o: y
--== Added! ==--
New item is added, No of itemsinstorage: 21
        SKU: 222
       Name: Grape
      Price: 22.22
   Quantity: 22
Minimum Qty: 2
   Is Taxed: Yes
Adding 333:
Can not add new item; Storage Full!

Add or Update test:
================AddOrUpdate Test:
Enter 731 and then 'n':
Please enter the SKU: 731
        SKU: 731
       Name: Allen's Apple Juice
      Price: 1.79
   Quantity: 100
Minimum Qty: 10
   Is Taxed: Yes
Item already exists, Update? (Y)es/(N)o: n
--== Aborted! ==--
Enter 731, 'y' and then:
       Name: Apple
      Price: 1.80
   Quantity: 101
Minimum Qty: 11
   Is Taxed: n
Overwrite old data? (Y)es/(N)o: y
Please enter the SKU: 731
        SKU: 731
       Name: Allen's Apple Juice
      Price: 1.79
   Quantity: 100
Minimum Qty: 10
   Is Taxed: Yes
Item already exists, Update? (Y)es/(N)o: y
Enter new data:
        SKU: 731
       Name: Apple
      Price: 1.80
   Quantity: 101
Minimum Qty: 11
   Is Taxed: n
Overwrite old data? (Y)es/(N)o: y
--== Updated! ==--
Updated Item:
        SKU: 731
       Name: Apple
      Price: 1.80
   Quantity: 101
Minimum Qty: 11
   Is Taxed: No
Enter 444:
Please enter the SKU: 444
Can not add new item; Storage Full!

Adjust Quantity test:
================AdjustQty Test:
Invalid SKU Test; Enter 444:
Please enter the SKU: 444
SKU not found in storage!
Aborting Entry test; Enter 731 and then 0:
Please enter the SKU: 731
        SKU: 731
       Name: Allen's Apple Juice
      Price: 1.79
   Quantity: 100
Minimum Qty: 10
   Is Taxed: Yes
Please enter the quantity to checkout; Maximum of 100 or 0 to abort: 0
--== Aborted! ==--
Checking out with low quantity warning; Enter 731 and then 90:
Please enter the SKU: 731
        SKU: 731
       Name: Allen's Apple Juice
      Price: 1.79
   Quantity: 100
Minimum Qty: 10
   Is Taxed: Yes
Please enter the quantity to checkout; Maximum of 100 or 0 to abort: 90
--== Checked out! ==--
Quantity is low, please reorder ASAP!!!
Stocking; Enter 731 and then 50:
Please enter the SKU: 731
        SKU: 731
       Name: Allen's Apple Juice
      Price: 1.79
   Quantity: 10
Minimum Qty: 10
   Is Taxed: Yes
WARNING: Quantity low, please order ASAP!!!
Please enter the quantity to stock; Maximum of 989 or 0 to abort: 50
--== Stocked! ==--
        SKU: 731
       Name: Allen's Apple Juice
      Price: 1.79
   Quantity: 60
Minimum Qty: 10
   Is Taxed: Yes