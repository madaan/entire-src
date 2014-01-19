#sg

from collections import defaultdict
import sys
import string

#create sets from the three wordlists
#se

def create_maps(filenames):
	sets = defaultdict(str)
	sets['e'] = set(line.strip().lower() for line in open(filenames['e']))
	sets['f'] = set(line.strip().lower() for line in open(filenames['f']))
	sets['g'] = set(line.strip().lower() for line in open(filenames['g']))
	return sets

def label_words(target, sets):
	print """
	<html>
	<head>
	<link href="css/bootstrap.min.css" rel="stylesheet">
	</head>
	<body>
	<div class = "container">
	<div class = "jumbotron">
	<h1> Segmenter </h1><br/><p>Labels the languages of the multilingual documents</p></div>
	"""
	
	
	target_file = open(target, "r")

	color = ["C2DFFF", "C3FDB8", "FCDFFF"]
	segmentation_score = 1

	for line in target_file:
		print '<br/>'
		score_segment = 0
		ENG = 0
		GER = 1
		FRE = 2
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
		score_segment = float(score_segment) / len_segment
		segmentation_score *= score_segment

		
				

		print "<span  title = " + str(score_segment) + " style=\"background-color:" + color[count.index(max(count))] + ";\">" + line + "</span> ",

	print '<br/><center> <h1>Segmentation score = ' + str(segmentation_score) + '</center></h1></div></body></html>'


def main():
	filenames = defaultdict(str)
	filenames['e'] = 'data/english.txt'
	filenames['g'] = 'data/german.txt'
	filenames['f'] = 'data/french.txt'
	target = sys.argv[1]
	sets = create_maps(filenames)
	label_words(target, sets)



if __name__ == '__main__':
	main()
