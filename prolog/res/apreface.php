<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<!--Place meta tags here-->
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<TITLE>Preface</TITLE>
<meta name="description" content="Tutorial explains Prolog concepts with text, diagrams and 
specialized diagrams for illustrating flow-of-control. Uses 
full program examples to lead you step-by-step 
through writing: an adventure game, an intelligent data-base, 
an expert system and an order entry program.">
<meta name="keywords" content="Prolog, Prolog language, Prolog tutorial,
Prolog programming, Prolog examples, free Prolog, Prolog interpreter, 
logic, logic programming, 
AI, artificial intelligence, rules, business rules, process rules, rule-based systems, 
expert systems,  
reasoning, inferencing, inference engines, intelligent software, 
sample code, source code, 
Amzi! Prolog, Amzi!, Amzi, Adventure in Prolog, Logic Explorer
">

<meta name="author" content="Amzi! inc." />

<!--Make sure this always points to the stylesheet-->
<link href="/main.css" rel="stylesheet" type="text/css" />
<link rel="shortcut icon" href="/favicon.ico" type="image/x-icon">
<link rel="icon" href="/favicon.ico" type="image/x-icon">
<script type="text/javascript">

  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-8213130-1']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>
</head>

<body>
<div id="big_picture">
<!-- The top bar -->
<div style="background:#000000; padding: 0px; width:800px;">
  <div style="background:#000000; width:150px; height:125px; float:left;">
		<img src="/images/squirrel_125x140.jpg" width="140" height="125" />
  </div>
    <div style="background:#000000; padding: 0px; float:left; height:125px; width:610px;">
    	<div style="background:#000000; vertical-align:middle; height:60px; padding: 5px;">
        	<div style="float:left; background:#000000; padding-left:15px; vertical-align:middle; width:200px;">
            	<!-- <h1>Amzi! inc.</h1> -->
                <img src="/images/amzi_text.jpg" />
            </div>
        	<div style="float:right; background:#000000;">
				<form action="http://www.google.com/cse" id="cse-search-box">
				<div>
                	<input type="hidden" name="cx" value="009543582401049328519:y_b7qntti6m" />
                	<input type="hidden" name="ie" value="UTF-8" />
                	<input type="text" name="q" size="31" />
                	<input type="submit" name="sa" value="Search" />
				</div>
            	</form>
            	<script type="text/javascript"
					src="http://www.google.com/cse/brand?form=cse-search-box&lang=en"></script>
            </div>
			<div style="clear:both;"></div>
		</div>
        <div style="background:#000000; padding: 10px; width:580px; font-size:14px;">
            <table width="80%" border="1" align="center" cellpadding="4" cellspacing="0" bordercolor="#CC9933">
              <tr>
                <td align="center"><a class="black" href="/index.php">Home</a></td>
                <td align="center"><a class="black" href="/AmziNewsletter">Newsletters</a></td>
                <td align="center"><a class="black" href="/articles">Articles</a></td>
                <td align="center"><a class="black" href="/videos">Videos</a></td>
                <td align="center"><a class="black" href="/support/index.php">Support</a></td>
                <td align="center"><a class="black" href="/company/contact_form.php">Contact</a></td>
              </tr>
          </table>
      </div>
    </div>
    <div style="clear:both;"></div>
</div>


<div id="content">

    <!--Side Navigation-->
    <div id="leftMenu">
<p align="center"><a href="index.php"><b>Adventure in Prolog</b></a></p>
<hr />
<p><a href="advtop.php">Contents</a></p>
<p><a href="apreface.php">Preface</a></p>
<p><a href="aprolog.php">Prolog Tools</a></p>
<p><a href="a1start.php">1- Getting Started</a></p>
<p><a href="a2facts.php">2- Facts</a></p>
<p><a href="a3simple.php">3- Simple Queries</a></p>
<p><a href="a4comqry.php">4- Compound Queries</a></p>
<p><a href="a5rules.php">5- Rules</a></p>
<p><a href="a6arith.php">6- Arithmetic</a></p>
<p><a href="a7manage.php">7- Managing Data</a></p>
<p><a href="a8recurs.php">8- Recursion</a></p>
<p><a href="a9struct.php">9- Data Structures</a></p>
<p><a href="a10unif.php">10- Unification</a></p>
<p><a href="a11lists.php">11- Lists</a></p>
<p><a href="a12oper.php">12- Operators</a></p>
<p><a href="a13cut.php">13- Cut</a></p>
<p><a href="a14cntrl.php">14- Control Structures</a></p>
<p><a href="a15nlang.php">15- Natural Language</a></p>
<p><a href="appendix.php">Appendix</a></p>
<p><a href="advidx.php">Index</a></p>
<p>
<br />
<br />
<br />

<br />
<br />
<br />
</p>


</div>    <!--End Side Navigation-->

    <div id="beef">
    
        <!--Start content-->

      <div style="margin: 5px; float:right; width: 250px; background:#FFFFFF; border:double black thick; padding:5px;">
        <p>
        <em>Adventure</em> established the architecture of all fantasy computer games to follow.  It was the first to create structures representing places and items and characters and to let the player explore and interact with the environment.</p>
        <p>  It was as totally addictive as today's wonderous graphical games that have built on the that very same architecture. </p><p> To learn more about the granddaddy of all such games, see: <a href="http://www.rickadams.org/adventure/a_history.html">Colossal Cave Adventure</a> and/or google Adventure and Willie Crowther. </p>
      </div>

<H1>Preface</H1>
<hr />

<P>I was working for an aerospace company in the 1970s when someone got
a copy of the original <em>Adventure</em> game and installed it
on our mainframe computer. For the next month my lunch hours, evenings
and weekends, as well as normal work hours, were consumed with fighting
the fierce green dragon and escaping from the twisty little passages. Finally,
with a few hints about the plover's egg and dynamite, I had proudly earned
all the points in the game.
<P>My elation turned to terror as I realized it was time for my performance
review. My boss was a stern man, who was more comfortable with machines
than with people.  He opened up a large computer printout containing a
log of the hours each of his programmers spent on the mainframe computer.
He said he noticed that recently I had been working evenings and weekends
and that he admired that type of dedication in his employees. He gave me
the maximum raise and told me to keep up the good work.

<P>Ever since I've had a warm spot in my heart for adventure games. Years
later, when I got my first home computer, I immediately started
to write my own adventure game in 'C'. First came the tools, a simple dynamic
database to keep track of the game state and pattern matching functions
to search that database. Then came a natural language parser for the front
end. Functions implemented the various rules of the game. 

<P>At around the same time I joined the Boston Computer Society and attended
a lecture of the newly formed Artificial Intelligence group. The lecture
was about Prolog. I was amazed--here was a language that included all of
the tools needed for building adventure games and more. 

<P>It had a much richer dynamic database and more powerful pattern matcher
than the one I had written, plus its syntax was rules, which are much more
natural for coding the specification of the game. It had a built-in search
engine and, to top it all off, had tools for natural language processing.

<P>I learned Prolog from the classic Clocksin and Mellish text and started
writing adventure games anew. 

<P>I went on to use Prolog for a number of expert system applications at
my then current job, including a mainframe database performance tuning
system and installation expert. This got others interested in the language
and I began teaching it as well. 

<P>While the applications we were using Prolog for were serious and performed
a key role in improving technical support for the growing company, I still
found the adventure game to be an excellent showcase for teaching the language.

<P>This book is the result of that work. It takes a pragmatic, rather than
theoretical, approach to the language and is designed for programmers interested
in adding this powerful language to their bag of tools. 

<P>I offer my thanks to Will Crowther and Don Woods for writing the first
(and in my opinion still the best) adventure game and to the Boston Computer
Society for testing the ideas in the book. Thanks also to Ray Reeves, who
speaks fluent Prolog, and Nancy Wilson, who speaks fluent English, for
their careful reading of the text.<BR>


<P>Dennis Merritt<BR>
Stow, Massachusetts, April 1996 

<P>


        <!--end content-->
    </div>
<div style="clear:both;"></div>
<hr />
<p class="copyright">Copyright © 1995-2010 Amzi! inc. All Rights Reserved.<br />
Amzi!, Logic Server, ARulesXL, KnowledgeWright, Adventure in Prolog, Building Expert Systems in Prolog, are trademarks of Amzi! inc.<br />
Flying squirrel photo Copyright © Joe McDonald</p>
<br/></div>  <!-- content container -->
</div>  <!-- big_picture -->

</body>
</html>
