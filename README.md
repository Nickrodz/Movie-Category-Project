# Movie-Category-Project
This project is mostly around using Doubly and Circular Linked list to make a Category based program. This project includes a add category function as well as a add to a category function. As well as a delete function. This is similar to a list of Movies sorted into a category.

HOW TO USE?
For the Main Menu once you start the Program
a - go left 
d - go right 
x - select
In the main Menu I display a circular Linked list for the options in the menu

Add a Category
By selecting "Add a Category" your able to add a category for any name and press "Enter".
For example a Movie Category such like action


Add to a Category
By selecting "Add to a Category" your able to first type the name of what you want to add to that category then press "Enter"
and then by typing the number next to the category for which category you want to insert in follow by pressing "Enter"
Example:
1. |Action|    
2. |Adventure|
If I wanted to add to the action category I would type the name first "MAD MAX" then type "1"
Output:
1. |Action|  [MAD MAX]
2. |Adventure|
Once you hit "Enter" then the list above will be your output.

Quit
Will quit the program 

Delete Movie/Category
For this you will be put on a new screen with a "#" symbol starting over the category. The Delete Menu is a whole new menu different from the previous
one
Controls for Delete Menu
w - up
s - down
a - left
d - right
x - Select for the Movie Or Category you want to delete
The Category list is displayed in a doubly linked list while the movies presented in each category is displayed in a circular linked list
.
Action ->  <- MAD MAX ->  <- John Wick -> |back to the start of the list "Action"|
 ↓ ↑
#denture ->  <- Lord of the Rings -> |back to the start of the list "Adventure"|
 .
 By looking at this example you are able to traverse through the categorys and movies by where the arrows are pointing
 The "#" symbol Representing where the person controling the menu is currently at
 once you press "x" on either a movie or category it gets deleted and the list refreshes
 If a category that has movies gets deleted THEN ALL THE MOVIES IN THAT CATEGORY GET DELETED TOO!
