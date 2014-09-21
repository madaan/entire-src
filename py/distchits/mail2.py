#sg
import smtplib
import maildefs
import getpass

'''
Cleans up
'''
def cleanup(server):
    server.quit()

'''
Actually sends the email
'''
def send_email(server, toaddrs, subject, msg):
    header = 'To:' + toaddrs + '\n' + 'From:' + maildefs.senderEmail + '\n' + 'Subject:' + subject +  '\n'
    msgText = header + '\n' + msg + '\n\n'
    server.sendmail(maildefs.senderEmail, toaddrs, 'Subject: %s\r\n%s' % (subject, msgText))
    print msgText

'''
Handles login
Thanks : http://stackoverflow.com/questions/1761744/python-read-password-from-stdin
'''

def login():
    user = raw_input("CSE Mail Username (only username): ")
    maildefs.senderEmail = user + '@cse.iitb.ac.in'
    passPrompt = lambda: (getpass.getpass('CSE Mail Password: '), getpass.getpass('Retype password: '))
    pass1, pass2 = passPrompt()
    while pass1 != pass2:
        print 'Passwords don\'t match!'
        pass1, pass2 = passPrompt()
    return (user, pass1)


'''
Initializes the server
'''
def getserver():
    server = smtplib.SMTP('imap.cse.iitb.ac.in', 25)
    server.ehlo()
    server.starttls()
    server.ehlo()
    user, password = login()
    server.login(user, password)
    return server
    

'''
Takes list of attendees and chits as input, calls send_email required number of times
'''
def sendChits(attendeesFile, chitCodesFile):
    attendees = [attendee.strip() for attendee in open(attendeesFile, 'r')]
    chitCodes = [chitCode.strip() for chitCode in open(chitCodesFile, 'r')]
    server = getserver()
    numAttendees = len(attendees)
    numChits = len(chitCodes)
    if(numChits < numAttendees):
        print 'Not enough codes : %d attendees, %d chitCodes. Need %d more, please check the chit codes file' % numAttendees, numChits, (numAttendees - numChits)
        sys.exit(0)

    for i, attendee in enumerate(attendees):
        #toaddrs = attendees[i].split(",")[1] + '@iitb.ac.in'
        toaddrs = '133050004@iitb.ac.in'
        toname = attendees[i].split(",")[0]
        chitCode = chitCodes[i]
        msg = makeMsg(toname, chitCode)
        send_email(server, toaddrs, maildefs.emailSubject, msg)
    cleanup(server)
    

'''
The message text
'''
def makeMsg(toname, chitCode):
    return 'Hi ' + toname + '\n\nPlease note your chitcode for event \'' + maildefs.eventName + '\'\n\n\t' + chitCode + '\nThanks!\n'


import sys
if __name__ == '__main__':
    if(len(sys.argv) != 3):
        print 'Usage : python chitdist.py attendeesFile chitCodeFile'
        sys.exit(0)
    sendChits(sys.argv[1], sys.argv[2])

#send_email('message text','subject text')
