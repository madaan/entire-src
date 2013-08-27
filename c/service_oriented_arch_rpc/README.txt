-------------------------------------------------------------------------------
Exploring Service oriented architecture using RPC
-------------------------------------------------------------------------------
24/08/2013
-------------------------------------------------------------------------------
Aman Madaan (amanmadaan@cse.iitb.ac.in)
-------------------------------------------------------------------------------
###############
Project description
###############

The motive of the project is to see how the publish-find-bind sequence of events
take place from perspective of RPC.
-------------------------------------------------------------------------------
###############
Dependencies:
###############

The project needs gnu multi precision library.
If you are running Ubuntu, the same can be installed by running:
        
            sudo apt-get install libgmp-dev 

------------------------------------------------------------------------------
###############
Installation
###############

*The whole system can be built by simply executing install.sh
    chmod +x install.sh
    ./install.sh

install.sh internally calles make for the following operations :

1. Cleaning extra files :
    Run : 'make clean'

2. Initialising the server code (running rpcgen, moving files etc)
    Run : 'make initservers'

3.Compiling :
    Run : 'make compile'

Please note that we only need to execute the script "install.sh"
-------------------------------------------------------------------------------
###############
Execution instructions :
###############

Following steps need to be executed in order : 

1. Start the server : (PUBLISH)

    sudo ./arithsv
    the svc_register() function is called and the server is registered with portmapper if everything goes well.

2. Start the client :

    ./arithcl localhost

3. Select a service :

    1. MP Arithmetic

    2. SQRT 

    3. String concatenation

4. Once a service is selected, a call will be made to find the service. (FIND)
    4.1 Find succeededs : (BIND)
        
        A message like : "Service found at port N, connecting..." is displayed, and a call is made to
        bind to the service.
    
    4.2 Find fails :
        
        Program prints the correct message and quits.

