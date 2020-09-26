# complex
Implementation of complex numbers for C++ by Rok Medves

# To do

- [x] Create a Makefile
- [x] create a complex.cpp
- [x] make a namespace with functions like complex power, exponential, sine, cosine
- [x] enable Complex * double multiplication etc...
- [ ] finish off complexFunction namespace with log, sin, cos, pow etc.
- [ ] maybe a feature to plot it all in gnuplot some time? 
- [ ] overload "+-*/" for complex and double with friend functions, not member functions
- [ ] make the >> operator more intuitive to use
- [ ] still need to check what happens if one includes <cmath> in main code and calls it with a 
- [ ] make a library such that the user does not need to include complex.hh into their code.

# What I learnt 

- if you overload the exp() function you have to store the original pointer/reference coming form <cmath> *BEFORE* importing complex.hh into complex.cc
