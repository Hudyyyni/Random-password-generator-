Random password generator

To support my program I used "random" : https://github.com/effolkronium/random

How it works:
- I initialize static strings which contain all characters (lower case, upper case, digits and special characters)
- I randomly pick one of the strings
- When picked, I randomly pick a character from current string and add to the password
- At the end I'm checking whether at least one character from the pool has been used in our password, if not, I generate missing character

![image](https://user-images.githubusercontent.com/60985440/133792569-b1bfa6b7-aded-4987-9cb8-6246231ff746.png)
