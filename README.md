# bulk-project

In the updated code the following items were added:

# Per Rubric Requirements:  

    Completed Items that need testing: 

    Requirement 1

    Requirement 2

    Requirement 3

    Requirement 4

    Requirement 5

    Requirement 6

    Requirement 10

    Requirement 11

    Requirement 12

    Requirement 13

    Items that Need to Be done:

    Requirement 7

    Requirement 8

    Requirement 9

    Requirement 14

    Requirement 15


# Classes
    class DailyPurchases : this encapsulates all of the daily purchases

    class BulkClub: encapsulates all of the business logic for the application

# To Do:

    1. Redirect all the stdout in the bulk class to QT UI objects

    2. Separate code into .hpp and .cpp files

    3. Debug Unit Tests

        Debugging and unit Testing can be done through VScode, dont waste time in QT debugging. 

    4. Requirements 7,8,9,14,15



# Unit Testing
    1. test_bulkclub.cpp tests whether the information from the warehouse_shoppers.txt file was loaded correctly.

    to compile this program use the following command:

    ```bash
    g++ -g -O0 -o bulkclub_app  test_bulkclub.cpp
    ```

    2. test_dailypurchase.cpp test whether the information from the daily purchases text filese were loaded and added properly, this accounts for adding together all purchases and calculating rebates

    to compile this programe use the following command:

    ```bash
    g++ -g -O0 -o purchase_app test_dailypurchases.cpp
    ```

    ## Debugging in VSCode

    Create a launch.json file and copy the following information;

    ```json
    {
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(lldb) purchase_app Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/unit-testing/purchase_app",
            "args": [],
            "stopAtEntry": true,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb"
        },

        {
            "name": "(lldb) Launch bulkClub",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/unit-testing/bulkclub_app",
            "args": [],
            "stopAtEntry": true,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb"
        }

    ]
}
    ```



