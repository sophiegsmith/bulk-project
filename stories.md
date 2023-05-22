# Agile Stories for CS1C Final Project


1. The program should be able to read all provided files and accurately add all information
    
    Story Points: 8

    Tasks:
    * Create function that reads in all information from the warehouse_shoppers.txt file 
    * Create function that reads in all information from day1.txt through day7.txt
    * Create function that parses information from all files provided and creates a new Data Structure with the following information:
      * Customer Name
      * Membership Number
      * Membership Type
      * Membership Expiration Date
      * Running Total of Amount Spent
      * Rebate amount for Executive Members
    * Display all information in the Data Structure in a tabular format
    * Create UI display with information provided 
  
2. The Program will allow an administrator to login and use the program
   
   Story Points: 2

   Tasks:
   * Create a function that accepts a pre-set username and password 
   * Create a UI Screen with the following components
      * Text input box for username input
      * Text input box for password input
      * Submit button that accepts information 
   * Create a function that checks to see if the pre-set username and password is correct 
   * Create a function that displays an error message upon incorrect entry of a username, a password, or both
  
3. The Program will generate various types of sales reports
   
   Story Points: 10 

   Tasks: 
   * Create a sales report that contains the folllowing information:
     * List items and quantities sold
     * Total revenue, including tax
     * Names of members that shopped on a given day 
     * Display number of unique shoppers, categorized by membership type
     * Create UI display with information provided 
   * Create a sales report that contains the following information:
     * Items sold per membership type
     * This should be specified by day of the week (Day 1-7)
     * Create UI display with information provided 


4. The Program should be able to display store inventory
   
   Story Points: 2

   Tasks:
   * Create a function that calculates the total revenue generated pre-tax for each item sold
   * Create an inventory report for each item that contains the following information:
     * Item 
     * Quantity sold
     * Revenue (pre-tax)

5. The Program should allow an administrator to search for memberships
   
   Story Points: 8

   Tasks:
   * Create UI display which does the following:
     * A text-input search bar where administrator can look up information based on member name, membership number, month 
     * Display the following information 
       * Membership expiration date
       * Member name 
       * Membership number
       * Cost for membership renewal 
       * Total spent
   * Create a search function that the UI can use to run 

6. The Program should be able to add/delete information 
   
   Story Points: 10 

   Tasks: 
   * Create function that adds information of the following types:
     * Members
     * Items 
   * Create UI with a text input bar for membership information or items, and their prices, plus a submit button.
   * Create function that deletes information of the following types:
     * Members 
     * Items
   * Ensure that no purchases and revenue values are deleted when deleting a member's name and information 
   * Create a UI delete button that wipes memberhship information or inventory information
  
7. The Program should be able to save all changes made to membership or inventory information.

   Story Points: 2
   Tasks:
   * Create function that updates the main data structure with the changed information 


8. The Program should be able to recommend to an administrator if regular members should upgrade to an executive membership 
   
   Story Points: 5

   Tasks:
   * Modify the function that calculates all purchase informations to also display which members purchased over $1000 in merchandise 
   * Add a new column on the Data Structure which is titled 'Recommnedations'
   * For each regular member in the Data Structure that spent over $1000, write 'Upgrade to Executive Membership recommended' in the 'Recommendations' column

9. The Program should be able to recommend to an administrator if executive members should downgrade to a regular membership 

   
   Story Points: 5

   Tasks:
   * Modify the function that calculates all purchase informations to also display which members purchased under $500 in merchandise 
   * For each exectuvite member in the Data Structure that spent under $500, write 'Downgrade to Regular Membership recommended' in the 'Recommendations' column

10. The Program should be able to display the total of rebates available to executive members given a sales report

    Story Points: 3

    Tasks: 
    * Display a UI window with the calculated total rebate available, calculated based on each type of sales report created. 


Project Velocity Points: 55

   