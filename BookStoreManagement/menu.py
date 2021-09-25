#!/usr/bin/python
import sys
import os
from BooksHelper import BooksHelper
d=BooksHelper()

msg="""
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                
                                                             Welcome To Book Store Management

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


1. Add New Book Entry
2. Search Book Entry
3. Modify Book Entry
4. Delete Book Entry
5. View All Books
6. Exit From the Program


"""


while 1:
  print msg
  choice=raw_input("Enter Your Choice:")
  try:
     option=int(choice)
  except:
     print "Invalid Option Entered..."
     raw_input("Press any key to continue...")
     os.system("clear")
  else:
     if option==6:
        sys.exit(1)
     elif option==1:
        d.addNewBook()
     elif option==2:
        searchString=raw_input("Enter search string :")
        d.searchBook(searchString)
     elif option==3:
         isbn_num=raw_input("Enter the ISBN number :")
         d.modifyBookEntryByIsbn(isbn_num)
     elif option==4:
        isbn_num=raw_input("Enter the ISBN number :")
        d.deleteBookEntryByIsbn(isbn_num)
     elif option==5:
        d.viewAllBooks()
     else:
        print "Invalid Option Entered..."
        raw_input("Press any key to continue...")
        os.system("clear")