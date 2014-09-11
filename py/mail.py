import smtplib
 
to='mittal.ashish61@gmail.com'
user = 'amanmadaan'
pwd = 'sg^123456aman'
smtpserver = smtplib.SMTP("smtp-auth.iitb.ac.in",25)
smtpserver.ehlo()
smtpserver.starttls()
smtpserver.ehlo()
smtpserver.login(user, pwd)
header = 'To:' + to + '\n' + 'From: ' + user + '@iitb.ac.in\n' + 'Subject:testing \n'
msg = header + '\n this is a test message\n\n'
smtpserver.sendmail(user, to, msg)
smtpserver.close()
