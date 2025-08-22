# SNHU Module 8-1 Journal

## Name: Anthony Ashcroft
## Project: Corner Grocer

### Summarize the project and what problem it was solving.
<p>The project that I decided to upload to the GitHub was Project 3. This was an application to display counts of information from the Corner Store produce sales. I chose this project as it displays all of the skills that I learned while taking this course.</p>

<p>This project was solving a request to display all of the produce sold in the day as a compiled list in the form of Item/Count, Item/Histogram, or individual item search with sould number results.
</p>

### What did you do particularly well?
<p>In this application I feel that I did well in understanding pointer references. This allowed me to keep the memory footprint of my application lower and reduce its processing time.
</p>

### Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
<p>I believe I could enhance my code by making the menu's more attactive. They are currently basic with little grapics, but they are effective. The code could also be enhanced by allowing for the user to provide the file name of the counts. This would allow for multiple files to be parsed for a more robust data representation for the user. I do not believe there are any memory leaks in my code, but would appreciate if this was called out as I would love to correct it. I have two function calls, that have the same basic request; one that prints out the histogram of the counts, and one that prints out the number. I feel like an enhancement would be to combine these into one with an if statement that will do either the counts or the histogram.
</p>

### Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
<p>The most challenging pieces of code to write was definitely all of the refernces to objects. I was constantly meeting errors as I would deference in one area but forget to do it in another part of the code. In the end I did obtain a better understanding in how it all worked and feel like my code is more efficient for the effort.
</p>

### What skills from this project will be particularly transferable to other projects or course work?
<p>The skills I found to be transferrable are the best practice of encapsulation by using separate header and cpp files to enhance the readability of the work done. It is entirely possible to provide everything in a single file, but the resulting file becomes unwieldy and unusable in future applications.
</p>

### How did you make this program maintainable, readable, and adaptable?
<p>I made this program maintainable by providing a separate file for the Grocer class, this allows for portability. Changes can also be made to this file without affecting the main program. In the main program, I made sure not to have any hard encoded items. This allowed for changes to a single variable, like file name, to affect the entire application without the need to replace all instances of the file reference. I also added a contant Sentinal value to exit the application. This can be changed in one location to exit the application while being able to increase the size of the menu to allow for more data manipulation reports.


