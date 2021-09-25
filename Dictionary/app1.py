import json
from difflib import get_close_matches

data=json.load(open("data.json"))
def translate(xyz):
   xyz=xyz.lower()
   if xyz in data:
      return data[xyz]
   elif xyz.capitalize() in data:
      return data[xyz.capitalize()]
   elif xyz.upper() in data:
      return data[xyz.upper()]
   elif len(get_close_matches(xyz,data.keys()))>0:
        yes_ans=input("Did you mean %s instead? Enter Y if yes, or N if no:"%get_close_matches(xyz,data.keys())[0])
        if yes_ans =="Y":
           return data[get_close_matches(xyz,data.keys())[0]] 
        elif yes_ans =="N":
           return "The word does not exist in this Dictionary. PLease double check it!"
        else:
           return "Could not understand your entry."
   else:
      return "The word does not exist in this Dictionary. PLease double check it!"

word_inp=input("Enter your word to find its meaning:")
output= translate(word_inp)

if type(output)==list:
   for item in output:
      print(item)
else:
   print(output)
