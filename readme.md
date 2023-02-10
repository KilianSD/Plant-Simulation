# Plant-Simulation

A gardening journal application that allows a user to keep track of their plants, including information such as planting date, location, and care instructions.

For now it is more of a testing project than anything serious, but i may develop it into something bigger if i really want to, all i have to say about it is that it was a great learning experience and it's probably the beginning of everything.

I was planning into making a GUI so the software actually makes sense (it was not designed as a commandline program), so we might port it to Qt in the coming future.

For those who noticed in the main function there's a discord related part, this is just me fooling around and playing with the Color class i implemented, i felt like it was quite complete and once i finished coding it i felt like using it, then i came across of the [D++ library](https://dpp.dev/) which is a library for discord that does pretty much the same thing as the discord.js library, it allows you to interact with webhooks or make bots really easily and it is also pretty lightweight, go check it out it's worth the time. Anyway so for now the program instantiates a Color which generate 3 random values for the red, green, and blue in RGB, then we are outputting it inside a file using the lodepng library, we are then sending this file through a discord webhook saying "hey, i generated this color : #colorhexcode", this is pretty much all testing. 