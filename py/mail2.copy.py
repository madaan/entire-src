#sg

import smtplib

'''
Global defs
'''
senderEmail = 'dpc@iitb.ac.in'
eventName = 'test event'
emailSubject = 'Chitcode for : ' + eventName

def send_email (message, status):
    fromaddr = 'amanmadaan@cse.iitb.ac.in'
    toaddrs = 'madaan.amanmadaan@gmail.com'
    #imap.cse.iitb.ac.in
    #server = smtplib.SMTP('imap.cse.iitb.ac.in', 25)
    #server.ehlo()
    #server.starttls()
    #server.ehlo()
    #server.login('amanmadaan', 'sg123456amanmadaan')
    server.sendmail(fromaddr, toaddrs, 'Subject: %s\r\n%s' % (status, message))
    server.quit()

'''
Cleans up
'''
def cleanup():
    server.quit()

'''
Actually sends the email
'''
def send_email(toaddrs, subject, msg):
    header = 'To:' + toaddrs + '\n' + 'From:' +senderEmail + '\n' + 'Subject:' + subject +  '\n'
    msgText = header + '\n' + msg + '\n\n'
    print 'Sending ' + msgText
'''
Initializes the server
'''
def getserver():
    server = smtplib.SMTP('imap.cse.iitb.ac.in', 25)
    server.ehlo()
    server.starttls()
    server.ehlo()
    server.login('amanmadaan', 'sg123456amanmadaan')
    

def sendChits(attendeesFile, chitCodesFile):
    attendees = [attendee.strip() for attendee in open(attendeesFile, 'r')]
    chitCodes = [chitCode.strip() for chitCode in open(chitCodesFile, 'r')]
    numAttendees = len(attendees)
    numChits = len(chitCodes)
    if(numChits < numAttendees):
        print 'Not enough codes : %d attendees, %d chitCodes. Need %d more, please check the chit codes file' % numAttendees, numChits, (numAttendees - numChits)
        sys.exit(0)

    for i, attendee in enumerate(attendees):
        toaddrs = attendees.split(",")[1]
        toname = attendees.split(",")[0]
        chitCode = chitCodes[i]
        msg = makeMsg(toname, event, chitCode)
        send_email(toaddrs, emailSubject, msg)
    

def makeMsg(toname, event, chitCode):
    return 'Hi ' + toname + '\n Please note your chitcode for event ' + event + '\n\n\t' + chitcode + '\nThanks!\n'


import sys
if __name__ == '__main__':
    if(len(sys.argv) != 3):
        print 'Usage : python chitdist.py attendeesFile chitCodeFile'
        sys.exit(0)
    sendChits(sys.argv[1], sys.argv[2])

#send_email('message text','subject text')
