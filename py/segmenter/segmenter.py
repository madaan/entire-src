# -*- coding: utf-8 -*-
#sg

from collections import defaultdict
import sys
import string
import codecs
import math
from kitchen.text.converters import getwriter
#create sets from the three wordlists
#se

def create_maps(filenames):
    sets = defaultdict(str)
    sets['e'] = set(line.strip().lower() for line in codecs.open(filenames['e'], encoding = 'utf-8', mode = 'rb', errors = 'ignore'))
    sets['f'] = set(line.strip().lower() for line in codecs.open(filenames['f'], encoding = 'utf-8', mode = 'rb', errors = 'ignore'))
    sets['g'] = set(line.strip().lower() for line in codecs.open(filenames['g'], encoding = 'utf-8', mode = 'rb', errors = 'ignore'))
    return sets

def label_doc(target_doc, sets):
    
    UTF8Writer = codecs.getwriter('utf8')
    sys.stdout = UTF8Writer(sys.stdout)
    color = ["C2DFFF", "C3FDB8", "FCDFFF"] #English, German, French
    ENG = 0
    GER = 1
    FRE = 2
    print """
    <html>
    <head>
    <link href="css/bootstrap.min.css" rel="stylesheet">
    </head>
    <body>
    <div class = "container">
        <h1><span class="glyphicon glyphicon-random">
 Answer 5</span></h1>
    """
    print "<p style=\"background-color: " + color[ENG] + "\">English</p>"
    print "<p style=\"background-color: " + color[GER] + "\">German</p>"
    print "<p style=\"background-color: " + color[FRE] + "\">French</p><hr>"
    target_doc_handle = open(target_doc, "r")

    segmentation_score = 1

    for line in target_doc_handle:
        print '<br/>'
        score_segment = 0
        len_segment = 0
        count = [0, 0, 0]
        for word in line.split():

            '''for each line, we will maintain a goodness score that will depend on how confused the labeller is. This is given by 
            goodness_segment = score_segment / length_segment
            score_segment  = sum(score of words in segment)
            score_word = 1 / #languages in which the word is found
            '''
            score_word = 1
            wc = word
            len_segment += 1
            word = word.lower().replace("'s", '')
            if word in string.punctuation:
                continue
            else:
                if word in sets['f']:
                    count[FRE] += 1
                    score_word = score_word + 1

                if word in sets['e']:
                    count[ENG] += 1
                    score_word = score_word + 1

                if word in sets['g']:
                    count[GER] += 1
                    score_word = score_word + 1

                score_segment = score_segment + 1 / score_word
        #done processing a segment
        #lower the score_segment lower will log, higher will be 
        #-ve log. Thus, lower segmentation scores are desired
        score_segment = float(score_segment) / len_segment
        score_segment = -math.log(score_segment)
        segmentation_score += score_segment
        para = "<p  title = " + str(score_segment) + " style=\"background-color:" + color[count.index(max(count))] + ";\">" + line + "</p> "
        print para
    epilouge =  '<br/><center> <h1>Segmentation score = ' + str(segmentation_score) + ' (0 is the best)</center></h1></div></body></html>'
    print epilouge

def main():
    filenames = defaultdict(str)
    filenames['e'] = 'data/english.txt'
    filenames['g'] = 'data/german.txt'
    filenames['f'] = 'data/french.txt'
    target = sys.argv[1]
    sets = create_maps(filenames)
    label_doc(target, sets)



if __name__ == '__main__':
    main()
