<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<!--Place meta tags here-->
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>Amzi! inc. Adventure in Prolog tutorial</title>
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

<h1>13</h1>
<hr />
<H2>Cut</H2>

<P>Up to this point, we have worked with Prolog's backtracking<!AMZI_INDEX= Backtracking, cut>
execution behavior. We have seen how to use that behavior to write compact
predicates. </P>

<P>Sometimes it is desirable to selectively turn off backtracking. Prolog
provides a predicate that performs this function. It is called the <B>cut</B>,
represented by an exclamation point (!). </P>

<P>The cut<!AMZI_INDEX= Cut> effectively tells Prolog to freeze all the
decisions made so far in this predicate. That is, if required to backtrack,
it will automatically fail without trying other alternatives. </P>

<P>We will first examine the effects of the cut and then look at some practical
reasons to use it. </P>

<P><IMG SRC="advfig9.gif" HEIGHT=166 WIDTH=239></P>

<P>Figure 13.1. The effect of the cut on flow of control </P>

<P>When the cut is encountered, it re-routes backtracking, as shown in
figure 13.1. It short-circuits backtracking in the goals to its left on
its level, and in the level above, which contained the cut. That is, both
the parent goal (middle goal of top level) and the goals of the particular
rule being executed (second level) are affected by the cut. The effect
is undone if a new route is taken into the parent goal. Contrast figure
13.1 with figure 5.1. </P>

<P>We will write some simple predicates that illustrate the behavior of
the cut, first adding some data to backtrack over. </P>

<UL>
<PRE><FONT COLOR="#000080">data(one).
data(two).
data(three).</FONT></PRE>
</UL>

<P>Here is the first test case. It has no cut and will be used for comparison
purposes<!AMZI_INDEX= Cut, examples of>. </P>

<UL>
<PRE><FONT COLOR="#000080">cut_test_a(X) :-
  data(X).
cut_test_a('last clause').</FONT></PRE>
</UL>

<P>This is the control case, which exhibits the normal behavior. </P>

<UL>
<PRE><FONT COLOR="#000080">?- cut_test_a(X), write(X), nl, fail.
one
two
three
last clause
no</FONT></PRE>
</UL>

<P>Next, we put a cut at the end of the first clause. </P>

<UL>
<PRE><FONT COLOR="#000080">cut_test_b(X) :-
  data(X),
  !.
cut_test_b('last clause').</FONT></PRE>
</UL>

<P>Note that it stops backtracking through both the data/1 subgoal (left),
and the cut_test_b parent (above). </P>

<UL>
<PRE><FONT COLOR="#000080">?- cut_test_b(X), write(X), nl, fail.
one
no</FONT></PRE>
</UL>

<P>Next we put a cut in the middle of two subgoals. </P>

<UL>
<PRE><FONT COLOR="#000080">cut_test_c(X,Y) :-
  data(X),
  !,
  data(Y).
cut_test_c('last clause').</FONT></PRE>
</UL>

<P>Note that the cut inhibits backtracking in the parent cut_test_c and
in the goals to the left of (before) the cut (first data/1). The second
data/1 to the right of (after) the cut is still free to backtrack. </P>

<UL>
<PRE><FONT COLOR="#000080">?- cut_test_c(X,Y), write(X-Y), nl, fail.
one - one
one - two
one - three
no</FONT></PRE>
</UL>

<P>Performance is the main reason to use the cut<!AMZI_INDEX= Cut, performance considerations>.
This separates the logical purists from the pragmatists. Various arguments
can also be made as to its effect on code readability and maintainability.
It is often called the 'goto' of logic programming. </P>

<P>You will most often use the cut when you know that at a certain point
in a given predicate, Prolog has either found the only answer, or if it
hasn't, there is no answer. In this case you insert a cut in the predicate
at that point. </P>

<P>Similarly, you will use it when you want to force a predicate to fail
in a certain situation, and you don't want it to look any further. </P>

<H3><A NAME="UsingTheCut"></A>Using the Cut</H3>

<P>We will now introduce to the game the little puzzles that make adventure
games fun to play. We will put them in a predicate called puzzle/1. The
argument to puzzle/1 will be one of the game commands, and puzzle/1 will
determine whether or not there are special constraints on that command,
reacting accordingly. </P>

<P>We will see examples of both uses of the cut in the puzzle/1 predicate.
The behavior we want is </P>

<UL>
<LI>If there is a puzzle, and the constraints are met, quietly succeed.
</LI>

<LI>If there is a puzzle, and the constraints are not met, noisily fail.
</LI>

<LI>If there is no puzzle, quietly succeed. </LI>
</UL>

<P>The puzzle in Nani Search is that in order to get to the cellar, the
game player needs to both have the flashlight and turn it on. If these
criteria are met we know there is no need to ever backtrack through puzzle/1
looking for other clauses to try. For this reason we include the cut. </P>

<UL>
<PRE><FONT COLOR="#000080">puzzle(goto(cellar)):-
  have(flashlight),
  turned_on(flashlight),
  !.</FONT></PRE>
</UL>

<P>If the puzzle constraints are not met, then let the player know there
is a special problem. In this case we also want to force the calling predicate
to fail, and we don't want it to succeed by moving to other clauses of
puzzle/1. Therefore we use the cut<!AMZI_INDEX= Cut, and fail/0; fail/0, and cut>
to stop backtracking, and we follow it with fail. </P>

<UL>
<PRE><FONT COLOR="#000080">puzzle(goto(cellar)):-
  write('It''s dark and you are afraid of the dark.'),
  !, fail.</FONT></PRE>
</UL>

<P>The final clause is a catchall for those commands that have no special
puzzles associated with them. They will always succeed in a call to puzzle/1.
</P>

<UL>
<PRE><FONT COLOR="#000080">puzzle(_).</FONT></PRE>
</UL>

<P>For logical purity, it is always possible to rewrite the predicates
without the cut. This is done with the built-in predicate not/1<!AMZI_INDEX= not/1; Cut;  not/0,  instead of>.
Some claim this provides for clearer code, but often the explicit and liberal
use of 'not' clutters up the code, rather than clarifying it. </P>

<P>When using the cut, the order of the rules becomes important. Our second
clause for puzzle/1 safely prints an error message, because we know the
only way to get there is by the first clause failing before it reached
the cut. </P>

<P>The third clause is completely general, because we know the earlier
clauses have caught the special cases. </P>

<P>If the cuts were removed from the clauses, the second two clauses would
have to be rewritten. </P>

<UL>
<PRE><FONT COLOR="#000080">puzzle(goto(cellar)):-
  not(have(flashlight)),
  not(turned_on(flashlight)),
  write('Scared of dark message'),
  fail.
puzzle(X):-
  not(X = goto(cellar)).</FONT></PRE>
</UL>

<P>In this case the order of the clauses would not matter. </P>

<P>It is interesting to note that not/1 is defined using the cut. It also
uses call/1, another built-in predicate that calls a predicate. </P>

<UL>
<PRE><FONT COLOR="#000080">not(X) :- call(X), !, fail.<!AMZI_INDEX= not/1
>
not(X).</FONT></PRE>
</UL>

<P>In the next chapter we will see how to add a command loop to the game.
Until then we can test the puzzle predicate by including a call to it in
each individual command. For example </P>

<UL>
<PRE><FONT COLOR="#000080">goto(Place) :-<!AMZI_INDEX= goto/1
> 
  puzzle(goto(Place)),
  can_go(Place),
  move(Place),
  look.</FONT></PRE>
</UL>

<P>Assuming the player is in the kitchen, an attempt to go to the cellar
will fail. </P>

<UL>
<PRE><FONT COLOR="#000080">?- goto(cellar).
It's dark and you are afraid of the dark.
no

?- goto(office).
You are in the office...</FONT></PRE>
</UL>

<P>Then if the player takes the flashlight, turns it on, and return to
the kitchen, all goes well. </P>

<UL>
<PRE><FONT COLOR="#000080">?- goto(cellar).
You are in the cellar... </FONT></PRE>
</UL>

<H3><A NAME="Exercises"></A>Exercises</H3>

<H4>Adventure Game</H4>

<P>1- Test the puzzle/1 predicate by setting up various game situations
and seeing how it responds. When testing predicates with cuts you should
always use the semicolon (;) after each answer to make sure it behaves
correctly on backtracking. In our case puzzle/1 should always give one
response and fail on backtracking. </P>

<P>2- Add your own puzzles for different situations and commands. </P>

<H4>Expert System</H4>

<P>3- Modify the ask and menuask predicates to use cut to replace the use
of not. </P>

<H4>Customer Order Entry</H4>

<P>4- Modify the good_customer rules to use cut to prevent the search of
other cases once we know one has been found. </P>


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
