# ThreadMisdirection
Attempts to obfuscate the purpose of a thread by modifying the entry point of the thread (get/set thread context)

How does this work?

Main.cpp contains a simple function that modifies the thread memory to change how the thread executes.

Why should I use it?

It makes reverse engineering of your binary harder all while not killing performance too greatly. In its most basic usage found within this repo, it makes IDA believe that the 'fake call' would be executed.


![main-ida](https://user-images.githubusercontent.com/103238186/162438728-10298ad2-71c1-4261-9129-5a0d6dd0c523.png)


![sub-ida](https://user-images.githubusercontent.com/103238186/162438776-b51c176f-634f-4955-a240-12f697313dd8.png)


With more complex functions, the removal of debug information, a pass with your favourite packer and a dedicated system to implement this with more fake function pointers, it could prove to be an invaluable tool to hinder the work of reverse engineers. 


