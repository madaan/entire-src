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

<h1>7</h1>
<hr />

<H2>Managing Data</H2>

<P>We have seen that a Prolog program is a logicbase of predicates, and
so far we have entered clauses for those predicates directly in our programs.
Prolog also allows us to manipulate the logicbase directly and provides
built-in predicates to perform this function. The main ones are: </P>

<DL>
<DL>
<DT>asserta(X) </DT>

<DD>Adds the clause X as the first clause for its predicate. Like the other
I/O predicates, it always fails on backtracking and does not undo its work<!AMZI_INDEX= asserta/1>.
</DD>

<DT>assertz(X) </DT>

<DD>Same as asserta/1<!AMZI_INDEX= assertz/1>, only it adds the clause
X as the last clause for its predicate. </DD>

<DT>retract(X) </DT>

<DD>Removes the clause X from the logicbase, again with a permanent effect
that is not undone on backtracking<!AMZI_INDEX= retract/1>. </DD>
</DL>
</DL>

<P>The ability to manipulate the logicbase is obviously an important feature
for Nani Search. With it we can dynamically change the location of the
player, as well as the stuff that has been picked up and moved. </P>

<P>We will first develop goto/1, which moves the player from one room to
another. It will be developed from the top down, in contrast to look/0
which was developed from the bottom up. </P>

<P>When the player enters the command goto, we first check if they can
go to the place and if so move them so they can look around the new place.
Starting from this description of goto/1, we can write the main predicate.
</P>

<UL>
<PRE><FONT COLOR="#000080">goto(Place):-<!AMZI_INDEX= goto/1
>  
  can_go(Place),
  move(Place),
  look.</FONT></PRE>
</UL>

<P>Next we fill in the details. We can go to a room if it connects to where
we are. </P>

<UL>
<PRE><FONT COLOR="#000080">can_go(Place):-<!AMZI_INDEX= can_go/1
> 
  here(X),
  connect(X, Place).</FONT></PRE>
</UL>

<P>We can test can_go/1 immediately (assuming we are in the kitchen). </P>

<UL>
<PRE><FONT COLOR="#000080">?- can_go(office).
yes

?- can_go(hall).
no</FONT></PRE>
</UL>

<P>Now, can_go/1 succeeds and fails as we want it to, but it would be nice
if it gave us a message when it failed. By adding a second clause, which
is tried if the first one fails, we can cause can_go/1 to write an error
message. Since we want can_go/1 to fail in this situation we also need
to add a fail to the second clause. </P>

<UL>
<PRE><FONT COLOR="#000080">can_go(Place):-
  here(X),
  connect(X, Place).
can_go(Place):-
  write('You can''t get there from here.'), nl,
  fail.</FONT></PRE>
</UL>

<P>This version of can_go/1 behaves as we want. </P>

<UL>
<PRE><FONT COLOR="#000080">?- can_go(hall).
You can't get there from here.
no</FONT></PRE>
</UL>

<P>Next we develop move/1, which does the work of dynamically updating
the logicbase to reflect the new location of the player. It retracts the
old clause for here/1 and replaces it with a new one. This way there will
always be only one here/1 clause representing the current place. Because
goto/1 calls can_go/1 before move/1, the new here/1 will always be a legal
place in the game. </P>

<UL>
<PRE><FONT COLOR="#000080">move(Place):-
  retract(here(X)),
  asserta(here(Place)).</FONT></PRE>
</UL>

<P>We can now use goto/1 to explore the game environment. The output it
generates is from look/0, which we developed in chapter 5. </P>

<UL>
<PRE><FONT COLOR="#000080">?- goto(office).
You are in the office
You can see:
  desk
  computer
You can go to:
  hall
  kitchen
yes

?- goto(hall).
You are in the hall
You can see:
You can go to:
  dining room
  office
yes

?- goto(kitchen).
You can't get there from here.
no</FONT></PRE>
</UL>

<P>We will also need 'asserta' and 'retract' to implement 'take' and 'put'
commands in the game. </P>

<P>Here is take/1. For it we will define a new predicate, have/1, which
has one clause for each thing the game player has. Initially, have/1 is
not defined because the player is not carrying anything. </P>

<UL>
<PRE><FONT COLOR="#000080">take(X):-<!AMZI_INDEX= take/1
>  
  can_take(X),
  take_object(X).</FONT></PRE>
</UL>

<P>can_take/1 is analogous to can_go/1. </P>

<UL>
<PRE><FONT COLOR="#000080">can_take(Thing) :-
  here(Place),
  location(Thing, Place).
can_take(Thing) :-
  write('There is no '), write(Thing),
  write(' here.'),
  nl, fail.</FONT></PRE>
</UL>

<P>take_object/1 is analogous to move/1. It retracts a location/2 clause
and asserts a have/1 clause, reflecting the movement of the object from
the place to the player. </P>

<UL>
<PRE><FONT COLOR="#000080">take_object(X):-<!AMZI_INDEX= take_object/1; retract/1; asserta/1
>  
  retract(location(X,_)),
  asserta(have(X)),
  write('taken'), nl.</FONT></PRE>
</UL>

<P>As we have seen, the variables<!AMZI_INDEX= Variables, scope> in a clause
are local to that clause. There are no global variables<!AMZI_INDEX= Variables, global>
in Prolog, as there are in many other languages. The Prolog logicbase serves
that purpose. It allows all clauses to share information on a wider basis,
replacing the need for global variables. 'asserts' and 'retracts' are the
tools used to manipulate this global data. </P>

<P>As with any programming language, global data can be a powerful concept,
easily overused. They should be used with care, since they hide the communication
of information between clauses. The same code will behave differently if
the global data is changed. This can lead to hard-to-find bugs. </P>

<P>Eliminating global<!AMZI_INDEX= Variables, global, eliminating> data
and the 'assert' and 'retract' capabilities of Prolog is a goal of many
logic programmers. It is possible to write Prolog programs without dynamically modifying
the logicbase, thus eliminating the problem of global variables. This is
done by carrying the information as arguments to the predicates. In the
case of an adventure game, the complete state of the game could be represented
as predicate arguments, with each command called with the current state
and returning a new modified state. This approach will be discussed in
more detail in chapter 14. </P>

<P>Although the database-like approach presented here may not be the purest
method from a logical standpoint, it does allow for a very natural representation
of this game application. </P>

<P>Various Prologs provide varying degrees of richness in the area of logicbase
manipulation. The built-in versions are usually unaffected by backtracking.
That is, like the other I/O predicates, they perform their function when
called and do nothing when entered from the redo port. </P>

<P>Sometimes it is desirable to have a predicate retract<!AMZI_INDEX= assert/1, and backtracking>
its assertions when the redo port is entered. It is easy to write versions
of 'assert' and 'retract' that undo their work on backtracking. </P>

<UL>
<PRE><FONT COLOR="#000080">backtracking_assert(X):-<!-AMZI_INDEX= -backtracking_assert/1; asserta/1; retract/1
>  
  asserta(X).
backtracking_assert(X):-
  retract(X),fail.</FONT></PRE>
</UL>

<P>The first time through, the first clause is executed. If a later goal
fails, backtracking will cause the second clause to be tried. It will undo
the work of the first and fail, thus giving the desired effect. </P>

<H3><A NAME="Exercises"></A>Exercises</H3>

<H4>Adventure Game</H4>

<P>1- Write put/1 which retracts a have/1 clause and asserts a location/2
clause in the current room. </P>

<P>2- Write inventory/0 which lists the have/1 things. </P>

<P>3- Use goto/1, take/1, put/1, look/0, and inventory/0 to move about
and examine the game environment so far. </P>

<P>4- Write the predicates turn_on/1 and turn_off/1 for Nani Search. They
will be used to turn the flashlight on or off. </P>

<P>5- Add an open/closed status for each of the doors. Write open and closepredicates
that do the obvious. Fix can_go/1 to check whether a door is open and write
the appropriate error message if its not. </P>

<H4>Customer Order Entry</H4>

<P>6- In the order entry application, write a predicate update_inventory/2
that takes an item name and quantity as input. Have it retract the old
inventory amount, perform the necessary arithmetic and assert the new inventory
amount. </P>

<P>NOTE: retract(inventory(item_id,Q)) binds Q to the old value, thus alleviating
the need for a separate goal to get the old value of the inventory. </P>

<P>7- We can now use the various predicates developed for the customer
order entry system to write a predicate that prompts the user for order
information and generates the order. The predicate can be simply order/0.
</P>

<P>order/0 should first prompt the user for the customer name, the item
name and the quantity. For example </P>

<UL>
<PRE><FONT COLOR="#000080">write('Enter customer name:'),read(C),</FONT></PRE>
</UL>

<P>It should then use the rules for good_customer and valid_order to verify
that this is a valid order. If so, it should assert a new type of record,
order/3, which records the order information. It can then update_inventory
and check whether its time to reorder. </P>

<P>The customer order entry application has been designed from the bottom
up, since that is the way the material has been presented for learning.
The order predicate should suggest that Prolog is an excellent tool for
top-down development as well. </P>

<P>One could start with the concept that processing an order means reading
the date, checking the order, updating inventory, and reordering if necessary.
The necessary details of implementing these predicates could be left for
later. </P>

<H4>Expert System</H4>

<P>8- The expert system currently asks for the same information over and
over again. We can use the logicbase to remember the answers to questions
so that ask/2 doesn't re-ask something. </P>

<P>When ask/2 gets a yes or no answer to a question about an attribute-value
pair, assert a fact in the form </P>

<UL>
<PRE><FONT COLOR="#000080">known(Attribute, Value, YesNo).</FONT></PRE>
</UL>

<P>Add a first clause to ask/2 that checks whether the answer is already
known and, if so, succeeds. Add a second clause that checks if the answer
is known to be false and, if so, fails. </P>

<P>The third clause makes sure the answer is not already known, and then
asks the user as before. To do this, the built-in predicate not/1 is used.
It fails if its argument succeeds. </P>

<UL>
<PRE><FONT COLOR="#000080">not (known(Attr, Val, Answer))</FONT></PRE>
</UL>


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
