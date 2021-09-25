#!/usr/bin/python
import sys
import os
import pickle
class BooksHelper:
   dbFileName="dbfile"
   def __init__(self):
        if os.path.exists(BooksHelper.dbFileName):
          pass
        else:
          print "Initialising the database file..."
          try:
            f=open(BooksHelper.dbFileName,"w")
            f.close()
          except:
            print "Failed to initialise db file..."
            sys.exit(1)
   def getFileSize(self):
        return os.path.getsize(BooksHelper.dbFileName)
   def addNewBook(self):
        isbn_no=raw_input("Enter the ISBN Number :")
        book_title=raw_input("Enter the Book Title :")
        author_name=raw_input("Enter the Author Name :")
        location=raw_input("Enter the location :")
        if self.getFileSize() > 0 :
           print "Adding New Entry..."
           self.addBook(isbn_no,book_title,author_name,location)
        else:
           f=open(BooksHelper.dbFileName,"w")
           tempDict={}
           pickle.dump(tempDict,f)
           f.close()
           self.addBook(isbn_no,book_title,author_name,location)
   def addBook(self,isbn_no,book_title,author_name,location):
           f=open(BooksHelper.dbFileName,"r")
           tempDict=pickle.load(f)
           f.close()
           f=open(BooksHelper.dbFileName,"w")
           tempDict[isbn_no]=[isbn_no,book_title,author_name,location]
           print "Adding the entry...",tempDict
           pickle.dump(tempDict,f)
           f.close()
   def viewAllBooks(self):
    f=open(BooksHelper.dbFileName,"r")
    record=0
    while 1:
     try:
      tempDict=pickle.load(f)
      for k,v in tempDict.iteritems():
          record=record+1
          if record==1:
              print '-' * 75
              print "%-10s %-25s %-25s %-15s" %("ISBN Number","Book Title","Author Name","Location")
              print '-' *  75
          isbn_no,book_title,author_name,location=v
          print "%-10s %-25s %-25s %-15s"%(isbn_no,book_title,author_name,location)
     except:
      if record>0:
       print '-'* 75
      else:  
       print "No Record Found"
       f.close()
      break
       
    raw_input("Press any key to continue...")
   def deleteBookEntryByIsbn(self,isbn_num):
      f=open(BooksHelper.dbFileName,"r")
      while 1:
         try:
           tempDict=pickle.load(f)
           if isbn_num in tempDict.keys():
             del tempDict[isbn_num]
             f.close()
             f=open(BooksHelper.dbFileName,"w")
             pickle.dump(tempDict,f)
             f.close()
             print "Books  with ISBN Number %s is deleted successfully..."% isbn_num
             break
         except EOFError:
          f.close()
          print"Book not found..."
          break
      raw_input("Press any key to continue...")
   def modifyBookEntryByIsbn(self,isbn_num):
      f=open(BooksHelper.dbFileName,"r")
      while 1:
         try:
           tempDict=pickle.load(f)
           if isbn_num in tempDict.keys():
             book_title=raw_input("Enter the book title :")
             author_name=raw_input("Enter the author name :")
             location=raw_input("Enter the location :")
             f.close()
             self.addBook(isbn_num,book_title,author_name,location)
             print "Books  with ISBN Number %s is modified successfully..."% isbn_num
             break
         except EOFError:
          f.close()
          print"Book with ISBN Number %s is not found..." % isbn_num
          break
      raw_input("Press any key to continue...")
      raw_input("Press any key to continue...")
   def searchBook(self,searchString):
      f=open(BooksHelper.dbFileName,"r")
      record=0
      while 1:
         try:
           tempDict=pickle.load(f)
           for k,v in tempDict.iteritems():
               originalString=' '.join(v).lower()
               result=originalString.find(searchString.lower())
               if result!=-1:
                  record+=1
                  if record == 1:
                      print '-' * 75
                      print "%-10s %-25s %-25s %-15s" %("ISBN Number","Book Title","Author Name","Location")
                      print '-' *  75
                  isbn_no,book_title,author_name,location=v
                  print "%-10s %-25s %-25s %-15s"%(isbn_no,book_title,author_name,location)
              
         except EOFError:
           if record>0:
                  print '-'* 75
           else:  
               print "No Record Found"
               f.close()
         break
      
      raw_input("Press any key to continue...")   