# tm-hello-world

## Host Setup

Your host machine will need the librarian set up and running, otherwise you will get segfaults.

## VM Setup

Log in to your one of your node virtual machines with username "l4tm" (no quotes) and password "iforgot" (no quotes).

Install git:

	$ sudo apt-get install git

Clone this repository:

	$ git clone https://www.github.com/FabricAttachedMemory/tm-hello-world

Edit your sources.list file by running

	$ sudo <your favorite text editor> /etc/apt/sources.list

and add the following line:

	deb https://downloads.linux.hp.com/SDR/repo l4fame unstable

Then, install the following packages with sudo apt-get install <package>

	libpmem-dev
	libfam-atomic2-dev

If you haven't already, cd into your tm-hello-world directory, then run "make" (no quotes). If it works, it will print out a line that looks like this:

	cc -O0 -g -o tm-hello-world hello-world.c -lfam_atomic -lpmem -lpthread

Once you have two VM's set up this way, you can test your setup. On the first VM, run

	$ ./tm-hello-world /lfs/hello-world 0 1

On the second VM, run

	$ ./tm-hello-world /lfs/hello-world 1 0

Then, type something in one of the VM's, and if everything is as it should be, what you typed should show up in the other VM.
