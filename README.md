# A simple infosec themed text-based simulation.

You are a hacker tasked with purloining some info from a bank server. The idea is to build
a system that can be re-used for little demos like this. The user will have to use basic cyber sec skills to try to understand the 
communication protocol used by the bank servers and build a tool to break their strange encryption scheme to extract info. I want to 
keep each scenario short, but use each to build a little more of the system. After this initial commit, there is only the pretend 
boot sequence and login process that actually authenticates using a real username and password, generating a phony _hash_ using my 
own little made up algorithm and comparing it to the hash of the entered password. Next is to write the basic commands a user will be able
to run and figure out what the actual challenge itself will be. I need to implement the bank network somehow and figure out what my fake 
protocol will look like and how to generate the _traffic_ that will pass over it.
