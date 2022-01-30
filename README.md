# US-Names

This is a data set I got from data.gov. I've been playing with the data for years, most of the uploaded code manupliates the data in some form or another.

parseBirthdays.cpp can be run by first compiling using:
  
  `g++ -std=c++11 -o getName parseBirthdays.cpp`

  Then running:

  `.getName Henok 1994 M` 
  `.getName <firstName> <year> <sex>`


pyparse.py can be run by first installing dependencies using:

  `pip install -r requirements.txt`

  Then running:
    `python pyparse.py`


Here is an analysis I made of the data using Tableau Software: https://public.tableau.com/profile/henoke.alemayehu#!/vizhome/ssn_baby_names/SocialSecurityApplicants?publish=yes
