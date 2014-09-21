import smtplib

to='madaan.amanmadaan@gmail.com'
user = 'amanmadaan'
pwd = 'sg$123456aman'
smtpserver = smtplib.SMTP("smtp-auth.iitb.ac.in", 25)
smtpserver.ehlo()
smtpserver.starttls()
smtpserver.ehlo()
smtpserver.esmtp_features['auth']='LOGIN DIGEST-MD5 PLAIN'

smtpserver.login('amanmadaan', pwd)
header = 'To:' + to + '\n' + 'From: billgates@microsoft.com\n' + 'Subject:testing \n'
#header = 'To:' + to + '\n' + 'From: ' + user + '@cse.iitb.ac.in\n' + 'Subject:testing \n'
msg = header + '\nWe should have hired you mate\n\n'
smtpserver.sendmail(user, to, msg)
smtpserver.close()
