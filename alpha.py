#! /usr/bin/python
#program finds the longest substring in alphabetical order in an entered string

s=raw_input("Enter a string: ")
string = "abcdefghijklmnopqrstuvwxyz"
n=2 # size of a sample of alphabet being checked
m=0 # how far along the sample of alphabet you are
mem=" " # definition of mem

while n<=len(s): # increases the size of the sample by one
    while m<=len(string): # checks for matches with the same sample size moving along the string of alphabet
        for i in range(0,len(s),1):# runs through len(s) number of cases
            if s[i:i+n] == string[m:m+n] and len(s[i:i+n]) > len(mem): # checks if s sample matches with the sample of the alphabet that is being used and if the new found string is longer than the previous one
                mem = s[i:i+n] # overwrites mem if above is true
        m += 1 # moves along the string of alphabet by 1 letter 
    m = 0 # resets m counter
    n += 1 # increses the size of the sample by 1 letter
print("Longest substring in alphabetical order is: " + mem)

                                
