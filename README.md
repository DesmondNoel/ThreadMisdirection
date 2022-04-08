# ThreadMisdirection
Attempts to obfuscate the purpose of a thread by modifying the entry point of the thread (get/set thread context)

How does this work?

Main.cpp contains a simple function that modifies the thread memory to change how the thread executes.

Why should I use it?

It makes reverse engineering of your binary harder all while not killing performance too greatly. In its most basic usage found within this repo, it makes IDA believe that the 'fake call' would be executed.


https://i.imgur.com/QGLtsCe.png

https://i.imgur.com/zwlIIKs.png

With more complex functions, the removal of debug information, a pass with your favourite packer of choice and a dedicated system to implement this with more fake function pointers it could prove to be an invaluable tool to hinder the work of reverse engineers. 


