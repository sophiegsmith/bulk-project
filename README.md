# bulk-project
>Problem: teammmates are creating individual projects into feature branches and not checking in the code to main. Feature branches are broken, and team-members are not merging back into main. Therefore, Sophia Smith cannot compile the latest code and is unable to contribute to the project. Moreover, no team member checked in until I first checked in the initial backend logic on 05/16/2023. 

Sophia Smith has repeatedly asked all group members to add any working piece of the project back to main. But group members have not merged it back in, and there are merging issues. Because of separate projects and merging conflicts, it is hard to get any work done. 

ssmith - here is the inital project, the day 1 - day 7 is read and inside the bulk.cpp, read through this and try to understand


ssmith - commits are bulk.cpp, day1.txt, day2.txt, day3.txt, day4.txt, day5.txt, day6.txt, day7.txt

Corrections 05/21/2023: 

Sophia Smith implemented the backend code for the following requirements:
```bash
 1,2,3,4,5,6,10,11,12,13
 ````
 
And checked in the following code into the main branch, not a feature branch: 
```bash
dailypurchases.hpp: which has all of the backend logic to implement reading in the daily purchase logic

bulkclub.hpp: contains all classes and functionality for requirements 1,2,3,4,5,6,10,11,12,13
```

Moreover, A to-do list was pasted on the ReadMe.md file on the main branch stating that the UI controls needed to be connected to the completed requirements, with specific instructions to check code into the main branch of the github repository. The team members did not adhere to using the main branch, and instead created individual branches that created new QT projects that do not align with the original branch. This code in the individual branches also contain broken code with duplicate classes, and undefined symbols in the linker. 

This was the instructions given that did not work: 

to pull this repository(in terminal):

pwd

//pwd is the command for finding the directory you are in, do not run anything on local such as Documents or Desktop, run in home directory

git clone https://github.com/sophiegsmith/bulk-project.git

it will automatically clone this into your home directory folder for example:

/Users/ssmith/bulk-project

after this is complete, open QtCreator, click open project, then find the name of it: bulk-project

things that need to get done: 
1. admin access
2. displaying sales report 
3. total purchases

classes and data structures needed for this project are in the bulk.cpp file



Using the instructions provided above in a clean directory, the following output is given:
```bash
keke:projcs ssmith$ ls -l 
total 0
keke:projcs ssmith$ pwd 
/Users/ssmith/projcs
keke:projcs ssmith$ ls -l 
total 0
keke:projcs ssmith$ git clone https://github.com/sophiegsmith/bulk-project.git
Cloning into 'bulk-project'...
remote: Enumerating objects: 304, done.
remote: Counting objects: 100% (132/132), done.
remote: Compressing objects: 100% (109/109), done.
remote: Total 304 (delta 68), reused 50 (delta 19), pack-reused 172
Receiving objects: 100% (304/304), 88.65 KiB | 2.22 MiB/s, done.
Resolving deltas: 100% (144/144), done.
keke:projcs ssmith$ cd bulk-project/
keke:bulk-project ssmith$ git branch -a 
* main
  remotes/origin/HEAD -> origin/main
  remotes/origin/adminaccess
  remotes/origin/main
  remotes/origin/memberinfo
  remotes/origin/micahu-patch-1
  remotes/origin/ss
  remotes/origin/wwill24-patch-1
keke:bulk-project ssmith$ git switch -c adminaccess 
Switched to a new branch 'adminaccess'
keke:bulk-project ssmith$ git branch -a 
* adminaccess
  main
  remotes/origin/HEAD -> origin/main
  remotes/origin/adminaccess
  remotes/origin/main
  remotes/origin/memberinfo
  remotes/origin/micahu-patch-1
  remotes/origin/ss
  remotes/origin/wwill24-patch-1
keke:bulk-project ssmith$ git pull remotes/origin/adminacess
fatal: 'remotes/origin/adminacess' does not appear to be a git repository
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
keke:bulk-project ssmith$ git pull origin adminaccess
From https://github.com/sophiegsmith/bulk-project
 * branch            adminaccess -> FETCH_HEAD
hint: Pulling without specifying how to reconcile divergent branches is
hint: discouraged. You can squelch this message by running one of the following
hint: commands sometime before your next pull:
hint: 
hint:   git config pull.rebase false  # merge (the default strategy)
hint:   git config pull.rebase true   # rebase
hint:   git config pull.ff only       # fast-forward only
hint: 
hint: You can replace "git config" with "git config --global" to set a default
hint: preference for all repositories. You can also pass --rebase, --no-rebase,
hint: or --ff-only on the command line to override the configured default per
hint: invocation.
CONFLICT (add/add): Merge conflict in admin.h
Auto-merging admin.h
CONFLICT (add/add): Merge conflict in admin.cpp
Auto-merging admin.cpp
Automatic merge failed; fix conflicts and then commit the result.
keke:bulk-project ssmith$ 

```
This indicates that there are multiple steps steps missing to clone from the feature branches, and that the code is incomplete. This is shown by the merge conflicts displayed when doing a pull from the feature branch. This indicates that the code needs to be merged into the main branch before it can be pulled. 

I was given the following command `git pull origin addminaccess` which is incomplete as shown by the output above. Therefore, I have wasted all day yesterday and part of today trying to pull from branch, which does not work.  








