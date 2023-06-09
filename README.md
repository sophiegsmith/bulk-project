# 5/24/2023
## change log:
* [`SophieS`] pushed initial search button and displaying into the table view window
* [`SophieS`] refactored member info page and changed fields
* [`SophieS`] add search query funtionality
* [`SophieS`] added member contribution into the README.md
* [`SophieS`] ability to view the TableView with data when you click the button to go to memberinfo UI, and when clicking on the cell, it will fill the parameters correctly
* ['SophieS'] initial QMessage Box for total rebate
* ['SophieS'] made a button in adminMainPage that connects to GitHub page

# 5/23/2023
## change log:
* [`SophieS`]Changed back-end logic to use QString versus std::string; there is a compatibility problem with QT/Clang and std::string.
* [`SophieS`]Refactored sales UI to include a text box to display the daily sales report.
* [`SophieS`]Refactored member info UI to use a table view.
* [`SophieS`]Added to logic to search for expired members and display them in the table view
* [`MicahU`] Created UML diagrams for 1 Class diagram, 1 Activity Class Diagram, 3 State Case Diagrams, and 3 Use case diagram


# 5/22/2023
## Change log: 
* [`SophieS`]Connected backend logic to run the daily sales report. The output of the sales run is displayed in a message box since not UI object was available to output this data.
* [`SophieS`] Connected a button to sales ui back to main page
* [`SophieS`] connected a button to memberinfo ui back to main page
## Debugging/Running
I needed to manually copy the data files to the application to the build directory. For example, the following is the command for MacOS.   For Windows, it must be something similar. 
```bash
cp -vf *.txt ../build-adminaccess-Qt_6_5_0_for_macOS-Debug/adminaccess.app/Contents/MacOS/
```

# 05/21/2023 
## Change log
* [`SophieS`]restored readme from trying to fix merge comflicts
* [`SophieS`] Added `stories.md` Ten agile stories which include their descriptions, associated tasks, and story points 
* [`Will`] created the Uis for login page and allowed capability for group members to login, added Ui for adminmainpage, added UI for member information, added ui for sales information
* [`Will`] helped with merging conflicts

# 05/16/2023 (retroactive change log)
## Change log
* [`SophieS`] initial check-in of Qt project and backend code which implements the application requirements (see below), includes unit tests and sample processing of the features

# bulk-project

In the updated code the following items were added:

# Classes:

    class DailyPurchases : this encapsulates all of the daily purchases
    
    class BulkClub: encapsulates all of the business logic for the application
    
## Requirements:
    These are completed, but require unit testing. See corresponding unit tests. 

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
    
    
    
## To Do:

    1. Redirect all the stdout in the bulk class to QT UI objects
    2. Separate code into .hpp and .cpp files
    3. Debug Unit Tests 
        This can be done in VSCode
    4. Requirements 7, 8, 9, 14, 15 
    5. Do Unit Testing on Items 1, 2, 3, 4, 5, 6, 10, 11, 12, 13
    6. UML diagrams: 1 class diagram, 3 use cases, 3 state cases, 1 activity diagram



## Unit Testing

1. test_bulkclub.cpp tests whether the information from the warehouse_shoppers.txt file was loaded correctly.

    to compile this program use the following command:
        
```bash
g++ -g -O0 -o bulkclub_app  test_bulkclub.cpp
```   

2. test_dailypurchase.cpp test whether the information from the daily purchases text filese were loaded and added properly, this accounts for adding together all purchases and calculating rebates

    to compile this program use the following command:
    
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


