chitter
=======
This script can be used if you have a list of recepients, a list of codes, and you want to send each receipient "r" a code "c". A bit IITB specific, but can be adopted to suit your purpose with minimal modifications to sendChits.py. 

Apart from that, the script is fairly general and can be used to share discount codes, room allocation and so on.

###Usage
python sendChits.py attendeesFile chitsFile

#####attendeesFile format :
Username,IITB RollNumber  
Eg.  
Aman Madaan, 13305004  

#####chitsFile format :
One chit (information to be distributed on each line)  
Eg.  
Yellow  
Black  

###Configuration
maildegs.py stores all the global configuration information
  
'''  
Global def  
'''  
senderEmail = ''   #sender's email, should be left blank  
senderName = 'Tarun Jain'    
eventName = 'test event'   #the event   
emailSubject = 'Chitcode for : ' + eventName   #Modify to suit your purpose  
